#include <iostream>
#include <list>
#include <memory>
#include <random>
#include <algorithm>
#include <fstream>
using namespace std;

class Cherry
{
	int x{ 0 }, y{ 768 };
	int speed{ 0 };
	bool alive{ true };
public:
	Cherry(int x, int y, int speed) :x(x), y(768), speed(speed) {}

	//getter
	pair<int, int>getXY()const { return make_pair(x, y); }
	int getSpeed()const { return speed; }
	bool isAlive() const { return alive; }
	void render() { cout << "꽃잎" << "{" << x << "," << y << "}" << endl; }
	void update()
	{
		if (alive)
			y -= speed;
		if (y < 0)
			alive = false;
	}
};

void print(list<Cherry> l,int pass, int cnt)
{
	auto start = l.begin();
	for (int i = 0; i < pass; ++i)
		++start;
	for (int i = 0; i < cnt; ++i)
	{
		cout <<"속도: "<< (*start).getSpeed()<<" ";
		(*start).render();	
		++start;
	}
}

int main()
{
	list<Cherry> data;

	//1번
	default_random_engine dre;
	uniform_int_distribution<int> dx(0, 1023);
	uniform_int_distribution<int> dspeed(1, 10);

	for (int i = 0; i < 100; ++i)
	{
		data.push_back(Cherry(dx(dre), 0, dspeed(dre)));
	}

	//2번
	cout << "-------------------------------" << endl;
	cout << "[문제2] 리스트의 원소를 출력함(6번째 원소부터 10개)" << endl;
	cout << "-------------------------------" << endl;
	cout << "꽃잎의 수: " << data.size() << endl;
	print(data, 5, 10);

	//3번
	int n = 10;
	while (0 < n)
	{
		//[문제3] 리스트의 모든 원소를 반복자 p를 사용하여 순회하면서 render()와 update()를 호출하라
		list<Cherry>::iterator p;
		for (p=data.begin(); p != data.end(); ++p)
		{
			(*p).update();
			(*p).render();
			--n;
		}
	}

	//4번
	n = 70;
	while (0 < n)
	{
		//[문제 4] 범위기반 for loop를 사용하여 리스트 원소의 render()와 update()를 호출하라
		for (auto& k : data)
		{
			k.update();
			k.render();
			--n;
		}
	}
}