#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class Treasure
{
	string name{ "특급" };	//이름
	int rank{ 0 };			//등급
	int mag{ 0 };			//자력
	int coin{ 0 };			//코인능력

public:
	Treasure() {}
	Treasure(string name, int rank, int mag, int coin) :name(name), rank(rank), mag(mag), coin(coin) {}

	//getter
	string getName()const { return name; }
	int getRank() const { return rank; }
	int getMag() const { return mag; }
	int getCoin() const { return coin; }
};

void print(list<Treasure> t, int pass, int cnt)
{
	list<Treasure>::iterator itr = t.begin();
	advance(itr, pass);
	for (int i = 0; i < cnt; ++i)
	{
		cout << "보물" << pass + i + 1 << ", 등급 " << (*itr).getRank() << ", 자력 " << (*itr).getMag() << ", 코인 " << (*itr).getCoin() << endl;
		++itr;
	}
}

ostream& operator<<(ostream& os, const list<Treasure>& t)
{
	for (auto it = t.begin(); it != t.end(); ++it)
		os << (*it).getName() << "\t" << (*it).getRank() << "\t" << (*it).getMag() << "\t" << (*it).getCoin() << endl;
	return os;
}


istream& operator>>(istream& is, list<Treasure>& t)
{
	int size;
	is >> size;

	string name;
	int rank;
	int mag;
	int coin;

	for (int i = 0; i < size; ++i)
	{
		is >> name;
		is >> rank;
		is >> mag;
		is >> coin;
		t.emplace_back(name, rank, mag, coin);
	}
	return is;
}



int main()
{
	list<Treasure> box;

	default_random_engine dre;
	uniform_int_distribution<int> ui(0, 20);
	string name;
	char buf[10];

	//[문제1]보물함에 보물 500개를 넣어라
	for (int i = 0; i < 500; ++i)
		box.emplace_back(Treasure("보물"+to_string(i), ui(dre), ui(dre), ui(dre)));

	//[문제2] 지정위치에서 지정한 갯수를 출력하는 함수 print()를 작성
	print(box, 20, 5);

	////[문제3] 보물함의 모든 능력의 합을 기준으로 내림차순 정렬하라
	box.sort([](const Treasure& a, const Treasure& b)
		{return a.getCoin() + a.getMag() + a.getRank() > b.getCoin() + b.getMag() + b.getRank(); });
	print(box, 0, 10);


	////[문제4] 능력 합계값이 30인 보물을 찾아 앞 뒤 5개의 보물을 출력하라
	list<Treasure>::iterator sum_30 = find_if(box.begin(), box.end(),
		[](const Treasure& a) {return a.getCoin() + a.getMag() + a.getRank() == 30; });
	for (int i = 0; i < 5; ++i)
	{
		cout << (*sum_30).getName() <<", 등급 "<<(*sum_30).getRank()<<", 자력 "<<(*sum_30).getMag()<<", 코인"<<(*sum_30).getCoin()<< endl;
		--sum_30;
	}
	advance(sum_30, 5);
	cout <<"***"<< (*sum_30).getName() << ", 등급 " << (*sum_30).getRank() << ", 자력 " << (*sum_30).getMag() << ", 코인" << (*sum_30).getCoin() << endl;

	for (int i = 0; i < 5; ++i)
	{
		cout << (*sum_30).getName() << ", 등급 " << (*sum_30).getRank() << ", 자력 " << (*sum_30).getMag() << ", 코인" << (*sum_30).getCoin() << endl;
		++sum_30;
	}


	//[문제5] 보물함을 파일에 저장하라
	ofstream out("보물함.txt");
	out << box.size() << endl;
	out << box;
	out.close();

	box.clear();
	ifstream in("보물함.txt");
	in >> box;

	//print(box, 0, 10);
}