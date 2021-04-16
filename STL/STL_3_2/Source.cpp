//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 3월 2일 화요일 1주 1일차
//
//호출 가능한타입-callable type
//	- STL에서는 알고리즘 함수의 동작을 변형하는 용도로 사용한다.
//	sort(begin,end,정렬순서)
//
//호출할 수 있는 타입이 무한하고 서로 달라서 통일할 수 있으면 좋겠다.->function 타입이 만들어진 이유
//
//
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include <functional>
#include <random>
#include <algorithm>
using namespace std;

default_random_engine dre;
uniform_int_distribution<>uid{'a', 'z'};

void jump(void)
{
	cout << "jump" << endl;
}

void slide(void)
{
	cout << "slide" << endl;
}

///////////////////////////////////

//1. 일반 함수
void f(int)
{
	cout << "일반 함수를 호출" << endl;
}

//2. 함수 객체
class Test
{
public:
	void operator()(int)
	{
		cout << "() operator overloading class" << endl;
	}

	void mf(int)
	{
		cout << "Test member function" << endl;
	}
};
//3. lambda-> [](int){cout<<"called lambda"<<endl;}
auto lambda = [](int) {cout << "called lambda" << endl; };

class String
{
private:
	char* p;	//-> unique_ptr로 해보기
	int number;
public:
	String(int num) :number(num), p{ new char[num] }
	{

		for (int i = 0; i < number; ++i)
			p[i] = uid(dre);
	}
	~String()
	{
		delete[] p;
	}
	//String(const String& other) :number{ other.number }, p{new char[number]}
	//{
	//	memcpy(p, other.p, number);
	//}
	//String& operator=(const String& other)
	//{
	//	if (this != &other)
	//	{
	//		delete[] p;
	//		number = other.number;
	//		p = new char[number];
	//		memcpy(p, other.p, number);
	//		return *this;
	//	}
	//}
	size_t size() const
	{
		return number;
	}

	friend ostream& operator <<(ostream& out, const String& s)
	{
		for (int i=0;i<s.number;++i)
			out << s.p[i] <<" ";
		out << endl;
		return out;
	}
};

int main()
{
	//void (*a)() = jump;
	//a();
	//cout << "address of a: " << a << endl;
	//a = slide;
	//a();
	//cout << "address of a: " << a << endl;
	//cout << "address of main: " << main << endl;
	//cout << "address of 'a': " << &a << endl;
	//cout << typeid(a).name() << endl;
	//cout <<"size of function pointer: "<< sizeof(a) << endl;

	//////////////////////////////////////
	//f(1);	//1. 일반 함수

	//Test t;
	//t(2);	//2. 함수 객체
	//t.mf(2);

	//lambda(3);	//3. lambda
	//cout << typeid(lambda).name() << endl;
	////[문제] callabe type에 각 함수를 저장했다가 호출해보라

	//void(*cf1)(int) = f;

	////cf1 = Test::mf;
	//void(Test:: * pcf1)(int) = &(Test::mf);	//->클래스 멤버함수를 함수 포인터로 가리키는법 검색
	//(t.*pcf1)(4);

	//cf1 = [](int) {cout << "lambda" << endl; };

	//function<void(int)> ct;
	//ct = f;
	//ct = t;
	//ct = [](int) {cout << "lambda" << endl; };
	///////////////////////////////////////////////
	// 
	//[문제] int num을 인자를 받아 메모리를 num바이트 할당받아 임의의 소문자로 채우는 클래스 String을 코딩
	//다음 main 이 수정 없이 의도대로 실행되게

	String a[10]{1,10,20,3,5,7,10,20,30,40};
	
	for (int i = 0; i < size(a); ++i)
		cout << a[i] << endl;

	//각 string을 알파벳 오름차순으로 정렬하라.

	save("source.cpp");
	return 0;
}