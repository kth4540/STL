//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 3�� 15�� ȭ���� 3�� 1����
//ȣ�� ���� Ÿ���̶�
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <thread>
using namespace std;
default_random_engine dre;
uniform_int_distribution<> uid;
class Dog
{
private:
	string name;	//4
	int id;			//24
	static int cnt;	//4 - Ŭ���� ����
public:
	Dog() :id{ uid(dre) }
	{
		name = "dog"s;
		name += to_string(cnt);
		cnt++;
	}
	Dog(const Dog& d)
	{
		cout << "���� ";
	}

	int getID() const
	{
		return id;
	}

	friend ostream& operator <<(ostream& out, const Dog& d)
	{
		out <<"�̸�: "<< d.name << " ��ȣ: " << d.id;
		return out;
	}
};
int Dog::cnt = { 1 };

void f(int) { cout << "normal function" << endl; }

class TestClass
{

public:
	void operator() (int)
	{
		cout << "Ŭ������ ������ ������()" << endl;
	}

	void(*a)(int) = f;
};

auto x = [](int)->void {cout << "����" << endl; };

void slide() { cout << "slide" << endl; }

void jump() { cout << "jump" << endl; }

void (*left_function)() = jump;

void left()
{
	left_function();
}

int main()
{
	//[����] Dog ��ü�� ����� ���Ͽ� �����ϰ� �ٽ� �о� �����غ���
	//sizeof(Dog)�� Ȯ������ 
	//10000���� ��ü�� ����� "Dog" ���Ͽ� �����϶�
	//���� ũ��� sizeof(Dog)*10000

	//Dog dogs[10];
	//for (const Dog& dog : dogs)
	//	cout << dog << endl;
	//cout << sizeof(Dog) << endl;

	///////////////////////////////////
	
	//for (const Dog& dog : dogs_10000)
	//	cout << dog << endl;
	//Dog dogs_10000[10000];
	//ofstream of("Dog.txt", ios::binary);
	//of.write((char*)&dogs_10000[0], sizeof(dogs_10000));

	///////////////////////////////////////////////

	//[����]""Dog"�� ���̳ʸ����� ������ִ� 10000���� ��ü�� �о��
	//id ������������ ���
	//unique_ptr<Dog[]> d{ new Dog[10000] };
	//ifstream in("Dog.txt");
	//in.read((char*)d.get(), sizeof(Dog) * 10000);

	//sort(&d[0], &d[9999], [](const Dog& a, const Dog& b) {a.getID() < b.getID(); });

	//for (unsigned i = 0; i < 10000; ++i)
	//	cout << d[i] << endl;

	///////////////////////////////////////////////////
	//callable type

	//auto x = []() {cout << "�ȳ�" << endl; };
	//x();
	//auto y = []() {cout << "�ȳ�" << endl; };
	//y();
	//cout << typeid(x).name() << endl;
	//cout << typeid(y).name() << endl;

	////f�� �ٸ� ���� a�� ������ �� �ֳ�?
	//void(*a)(int) = f;
	//a(123);

	//TestClass t;
	//t(5);
	//t.a(123);

	/////////////////////////////////////////////

	//��Ű��
	//���ʹ�ư-����, �����ʹ�ư-�����̵�
	//������ ���� ��ư�� �ٲٸ� ���α׷� ������ ��� �ߴ°�

	//10���� 1���� ����� �ٲ۴�.
	//int cnt = 0;
	//while (true)
	//{
	//	left();
	//	this_thread::sleep_for(500ms);
	//	++cnt;
	//	if (cnt == 10)
	//	{
	//		left_function = slide;
	//	}
	//}

	save("source.cpp");
}