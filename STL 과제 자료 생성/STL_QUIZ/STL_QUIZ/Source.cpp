#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

//출력 이쁘게, 출력 함수로 바꾸기
class Player
{
private:
	string name;		//이름
	int score;			//점수
	int id;				//ID
	size_t num;			//확보한 메모리 바이트 수
	char* p;			//확보한 메모리의 시작번지

public:
	//생성자
	Player() :name{ "" }, score{ 0 }, id{ 0 }, num{ 0 }, p{ nullptr }{}
	
	//소멸자
	~Player() 
	{
		delete[] p;
	}

	//복사생성자
	Player(const Player& other) : num{ other.num }, p{ new char[num] } 
	{
		name = other.name;
		score = other.score;
		id = other.id;
		memcpy(p, other.p, num);
	}

	// 복사할당연산자
	Player& operator=(const Player& other) 
	{
		if (this != &other) {
			delete[] p;		//this->~String();
			name = other.name;
			score = other.score;
			id = other.id;
			num = other.num;
			p = new char[num];
			memcpy(p, other.p, num);
		}
		return *this;
	}

	// 이동생성자
	Player(Player&& other) : num{ other.num } {
		
		name = other.name;
		score = other.score;
		id = other.id;

		p = other.p;
		other.p = nullptr;
		other.num = 0;
	}

	// 이동할당연산자
	Player& operator=(Player&& other) {
		if (this != &other) {
			delete[] p;	//this->String();

			name = other.name;
			score = other.score;
			id = other.id;

			num = other.num;
			p = other.p;

			other.num = 0;
			other.p = nullptr;
		}
		return *this;
	}
	size_t getSize()
	{
		return num;
	}
	int getScore()
	{
		return score;
	}
	int getID()
	{
		return id;
	}
	string getName()
	{
		return name;
	}

	friend ostream& operator <<(ostream& os, const Player& pl)
	{
		os << "이름: " << pl.name << "\t점수: " << pl.score << "\tID: " << pl.id << "\t자원수: " << pl.num;
		return os;
	}

	void read(istream& is)
	{
		if(p!=nullptr)
		{
			num = 0;
			delete[]p;
		}
		is.read((char*)this, sizeof(Player));
		p = new char[num];
		is.read((char*)p, num);
	}
	void write(ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p, num);
	}
};

list<Player> v(1'000'000);
int main()
{
	ifstream in("2021 STL 과제 파일", ios::binary);

	for (auto& tmp : v)
		tmp.read(in);

	//마지막 객체 출력
	cout << (v.back()) << endl;

	//평균 출력
	double sum = 0.0f;

	for (auto itr = v.begin(); itr != v.end(); ++itr)
		sum += (*itr).getScore();

	cout << "평균: " << sum / 1'000'000 << endl;
	in.close();

	//바이트 수가 500인 객체를 파일에 복사
	ofstream out("바이트 수가 500", ios::binary);
	int cnt = 0;
	for (auto itr=v.begin();itr!=v.end();++itr)
	{
		if ((*itr).getSize() == 500)
			(*itr).write(out);
	}
	out.close();

	//ID값 기준으로 출력
	int num{};
	while (true)
	{
		cin >> num;
		//ID순 출력
		cout << "ID순 출력:" << endl;
		v.sort([](Player& a, Player& b) {return a.getID() < b.getID(); });
		for (auto itr = v.begin(); itr != v.end(); ++itr)
		{
			if ((*itr).getID() == num)
			{
				if (itr == v.begin())
				{
					cout << *itr << endl;
					cout << *(++itr) << endl;
				}
				else if (itr == (--v.end()))
				{
					cout << *(--itr) << endl;
					cout << *(++itr) << endl;
				}
				else
				{
					cout << *(--itr) << endl;
					cout << *(++itr) << endl;
					cout << *(++itr) << endl;
				}
			}
		}
		cout << endl << endl;

	//	//이름순 출력
		cout << "이름순 출력:" << endl;
		v.sort([](Player& a, Player& b) {return a.getName() < b.getName(); });
		for (auto itr = v.begin(); itr != v.end(); ++itr)
		{
			if ((*itr).getID() == num)
			{
				if (itr == v.begin())
				{
					cout << *itr << endl;
					cout << *(++itr) << endl;
				}
				else if (itr == (--v.end()))
				{
					cout << *(--itr) << endl;
					cout << *(++itr) << endl;
				}
				else
				{
					cout << *(--itr) << endl;
					cout << *(++itr) << endl;
					cout << *(++itr) << endl;
				}
			}
		}
		cout << endl << endl;

	//	//점수순 출력
		cout << "점수순 출력:" << endl;
		v.sort([](Player& a, Player& b) {return a.getScore() < b.getScore(); });
		for (auto itr = v.begin(); itr != v.end(); ++itr)
		{
			if ((*itr).getID() == num)
			{
				if (itr == v.begin())
				{
					cout << *itr << endl;
					cout << *(++itr) << endl;
				}
				else if (itr == (--v.end()))
				{
					cout << *(--itr) << endl;
					cout << *(++itr) << endl;
				}
				else
				{
					cout << *(--itr) << endl;
					cout << *(++itr) << endl;
					cout << *(++itr) << endl;
				}
			}
		}
		cout << endl << endl;
	}
}