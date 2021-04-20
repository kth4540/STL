#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

//��� �̻ڰ�, ��� �Լ��� �ٲٱ�
class Player
{
private:
	string name;		//�̸�
	int score;			//����
	int id;				//ID
	size_t num;			//Ȯ���� �޸� ����Ʈ ��
	char* p;			//Ȯ���� �޸��� ���۹���

public:
	//������
	Player() :name{ "" }, score{ 0 }, id{ 0 }, num{ 0 }, p{ nullptr }{}
	
	//�Ҹ���
	~Player() 
	{
		delete[] p;
	}

	//���������
	Player(const Player& other) : num{ other.num }, p{ new char[num] } 
	{
		name = other.name;
		score = other.score;
		id = other.id;
		memcpy(p, other.p, num);
	}

	// �����Ҵ翬����
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

	// �̵�������
	Player(Player&& other) : num{ other.num } {
		
		name = other.name;
		score = other.score;
		id = other.id;

		p = other.p;
		other.p = nullptr;
		other.num = 0;
	}

	// �̵��Ҵ翬����
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
		os << "�̸�: " << pl.name << "\t����: " << pl.score << "\tID: " << pl.id << "\t�ڿ���: " << pl.num;
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
	ifstream in("2021 STL ���� ����", ios::binary);

	for (auto& tmp : v)
		tmp.read(in);

	//������ ��ü ���
	cout << (v.back()) << endl;

	//��� ���
	double sum = 0.0f;

	for (auto itr = v.begin(); itr != v.end(); ++itr)
		sum += (*itr).getScore();

	cout << "���: " << sum / 1'000'000 << endl;
	in.close();

	//����Ʈ ���� 500�� ��ü�� ���Ͽ� ����
	ofstream out("����Ʈ ���� 500", ios::binary);
	int cnt = 0;
	for (auto itr=v.begin();itr!=v.end();++itr)
	{
		if ((*itr).getSize() == 500)
			(*itr).write(out);
	}
	out.close();

	//ID�� �������� ���
	int num{};
	while (true)
	{
		cin >> num;
		//ID�� ���
		cout << "ID�� ���:" << endl;
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

	//	//�̸��� ���
		cout << "�̸��� ���:" << endl;
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

	//	//������ ���
		cout << "������ ���:" << endl;
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