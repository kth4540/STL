//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 3월 15일 화요일 3주 1일차
//호출 가능 타입이란
//실행될 때 마다 소스파일을 저장한다.
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
	static int cnt;	//4 - 클래스 공통
public:
	Dog() :id{ uid(dre) }
	{
		name = "dog"s;
		name += to_string(cnt);
		cnt++;
	}
	Dog(const Dog& d)
	{
		cout << "복사 ";
	}

	int getID() const
	{
		return id;
	}

	friend ostream& operator <<(ostream& out, const Dog& d)
	{
		out <<"이름: "<< d.name << " 번호: " << d.id;
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
		cout << "클래스가 구현한 연산자()" << endl;
	}

	void(*a)(int) = f;
};

auto x = [](int)->void {cout << "람다" << endl; };

void slide() { cout << "slide" << endl; }

void jump() { cout << "jump" << endl; }

void (*left_function)() = jump;

void left()
{
	left_function();
}

int main()
{
	//[문제] Dog 객체를 만들어 파일에 저장하고 다시 읽어 정렬해본다
	//sizeof(Dog)를 확인하자 
	//10000개의 객체를 만들어 "Dog" 파일에 저장하라
	//파일 크기는 sizeof(Dog)*10000

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

	//[문제]""Dog"에 바이너리모드로 저장되있는 10000개의 객체를 읽어라
	//id 오름차순으로 출력
	//unique_ptr<Dog[]> d{ new Dog[10000] };
	//ifstream in("Dog.txt");
	//in.read((char*)d.get(), sizeof(Dog) * 10000);

	//sort(&d[0], &d[9999], [](const Dog& a, const Dog& b) {a.getID() < b.getID(); });

	//for (unsigned i = 0; i < 10000; ++i)
	//	cout << d[i] << endl;

	///////////////////////////////////////////////////
	//callable type

	//auto x = []() {cout << "안녕" << endl; };
	//x();
	//auto y = []() {cout << "안녕" << endl; };
	//y();
	//cout << typeid(x).name() << endl;
	//cout << typeid(y).name() << endl;

	////f를 다른 변수 a에 저장할 수 있나?
	//void(*a)(int) = f;
	//a(123);

	//TestClass t;
	//t(5);
	//t.a(123);

	/////////////////////////////////////////////

	//쿠키런
	//왼쪽버튼-점프, 오른쪽버튼-슬라이드
	//설정에 가서 버튼을 바꾸면 프로그램 구현은 어떻게 했는가

	//10번에 1번은 기능을 바꾼다.
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