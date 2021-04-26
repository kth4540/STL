#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class Treasure
{
	string name{ "Ư��" };	//�̸�
	int rank{ 0 };			//���
	int mag{ 0 };			//�ڷ�
	int coin{ 0 };			//���δɷ�

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
		cout << "����" << pass + i + 1 << ", ��� " << (*itr).getRank() << ", �ڷ� " << (*itr).getMag() << ", ���� " << (*itr).getCoin() << endl;
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

	//[����1]�����Կ� ���� 500���� �־��
	for (int i = 0; i < 500; ++i)
		box.emplace_back(Treasure("����"+to_string(i), ui(dre), ui(dre), ui(dre)));

	//[����2] ������ġ���� ������ ������ ����ϴ� �Լ� print()�� �ۼ�
	print(box, 20, 5);

	////[����3] �������� ��� �ɷ��� ���� �������� �������� �����϶�
	box.sort([](const Treasure& a, const Treasure& b)
		{return a.getCoin() + a.getMag() + a.getRank() > b.getCoin() + b.getMag() + b.getRank(); });
	print(box, 0, 10);


	////[����4] �ɷ� �հ谪�� 30�� ������ ã�� �� �� 5���� ������ ����϶�
	list<Treasure>::iterator sum_30 = find_if(box.begin(), box.end(),
		[](const Treasure& a) {return a.getCoin() + a.getMag() + a.getRank() == 30; });
	for (int i = 0; i < 5; ++i)
	{
		cout << (*sum_30).getName() <<", ��� "<<(*sum_30).getRank()<<", �ڷ� "<<(*sum_30).getMag()<<", ����"<<(*sum_30).getCoin()<< endl;
		--sum_30;
	}
	advance(sum_30, 5);
	cout <<"***"<< (*sum_30).getName() << ", ��� " << (*sum_30).getRank() << ", �ڷ� " << (*sum_30).getMag() << ", ����" << (*sum_30).getCoin() << endl;

	for (int i = 0; i < 5; ++i)
	{
		cout << (*sum_30).getName() << ", ��� " << (*sum_30).getRank() << ", �ڷ� " << (*sum_30).getMag() << ", ����" << (*sum_30).getCoin() << endl;
		++sum_30;
	}


	//[����5] �������� ���Ͽ� �����϶�
	ofstream out("������.txt");
	out << box.size() << endl;
	out << box;
	out.close();

	box.clear();
	ifstream in("������.txt");
	in >> box;

	//print(box, 0, 10);
}