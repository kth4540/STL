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
	void render() { cout << "����" << "{" << x << "," << y << "}" << endl; }
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
		cout <<"�ӵ�: "<< (*start).getSpeed()<<" ";
		(*start).render();	
		++start;
	}
}

int main()
{
	list<Cherry> data;

	//1��
	default_random_engine dre;
	uniform_int_distribution<int> dx(0, 1023);
	uniform_int_distribution<int> dspeed(1, 10);

	for (int i = 0; i < 100; ++i)
	{
		data.push_back(Cherry(dx(dre), 0, dspeed(dre)));
	}

	//2��
	cout << "-------------------------------" << endl;
	cout << "[����2] ����Ʈ�� ���Ҹ� �����(6��° ���Һ��� 10��)" << endl;
	cout << "-------------------------------" << endl;
	cout << "������ ��: " << data.size() << endl;
	print(data, 5, 10);

	//3��
	int n = 10;
	while (0 < n)
	{
		//[����3] ����Ʈ�� ��� ���Ҹ� �ݺ��� p�� ����Ͽ� ��ȸ�ϸ鼭 render()�� update()�� ȣ���϶�
		list<Cherry>::iterator p;
		for (p=data.begin(); p != data.end(); ++p)
		{
			(*p).update();
			(*p).render();
			--n;
		}
	}

	//4��
	n = 70;
	while (0 < n)
	{
		//[���� 4] ������� for loop�� ����Ͽ� ����Ʈ ������ render()�� update()�� ȣ���϶�
		for (auto& k : data)
		{
			k.update();
			k.render();
			--n;
		}
	}
}