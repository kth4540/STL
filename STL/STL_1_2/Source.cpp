//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 3월 4일 화요일 1주 2일차
//
// c++ 복습
//많은 수의 data 다루기
//
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include <random>
#include <algorithm>
using namespace std;

//class Game 
//{
//private:
//	int a;
//public:
//	Game(int num) :a(num){}
//
//	friend void change(Game& a_game, Game& b_game)
//	{
//		int tmp = a_game.a;
//		a_game.a = b_game.a;
//		b_game.a = tmp;
//	}
//
//	friend ostream& const operator << (ostream& out, const Game& game)
//	{
//		out << game.a;
//		return out;
//	}
//};	-> class

//template <typename T>
//void change(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}

default_random_engine dre;	//크기가 너무 커서 stack에 놓으면 안됨


int main()
{
	// [문제] main 변경 없이 실행되도록 하자
	// 앞에서 만든 change()가 다른 자료형도 바꿀 수 있도록 하자	-> template
	// game은 사용자가 정의한 class
	// 화면출력은 2,1

	//int a{ 1 };
	//int b{ 2 };
	//change(a, b);
	//cout << a << ", " << b << endl;

	//int num = 10;
	//int* p = &num;
	//*p = 20;
	//cout << num << endl;
	//int& xxx = num;
	//xxx = 20;
	//cout << num << endl;
	//pointer, reference의 용도 : 다른 scope에서 변수에 접근하기 위함

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	//[문제] int 10개를 저장할 공간을 마련하고, int를 임의의 값으로 만든 후 출력한다.
	//임의값은 랜덤 , 분포로
	//값을 오름차순으로 정렬

	//cout << numeric_limits<int>::max() << endl;
	//cout << numeric_limits<int>::min() << endl;

	int a[10]{};
	uniform_int_distribution uid{ 0,1000 };

	for (auto& n : a)
		n = uid(dre);

	sort(begin(a), end(a), [](int a, int b) {return a > b; });

	for (auto& n : a)
		cout << n << endl;

	save("source.cpp");
	return 0;
}