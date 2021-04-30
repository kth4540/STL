//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 4월 29일 화요일 9주 1일차
//
// 컨테이너,알고리즘 그리고 이 둘을 연결하는 반복자
// 
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	String s{ "1357924680" };
	//ostream_iterator<char> outiter{ cout };
	//outiter = 'c';
	//outiter = '+';
	//outiter = '+';

	for (auto i = s.rbegin(); i != s.rend(); ++i)
		cout << (*i) << " - ";

	//save("source.cpp");
}