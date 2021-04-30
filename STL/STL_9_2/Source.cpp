//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 4월 29일 화요일 9주 1일차
//
// Container - String
// Algorithm - String_iterator, String_reverse_iterator
// Iterator - 
// 
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
template <typename Iter, typename Val>

Iter Myfind(Iter begin, Iter end, Val value)
{
	for (; begin != end; ++begin)
	{
		if ((*begin) == value)
			return begin;
	}
	return end;
}

int main()
{
	//String s{ "1357924680" };
	//
	//sort(s.begin(), s.end());
	//cout << s << endl;

	//[문제] String_iterator 에게 "너는 어떤 종류의 반복자니?"라고 물어봐라

	//cout << typeid(iterator_traits<String_iterator>::iterator_category).name() << endl;

	/*--------------------------------------------------------------------------*/

	//String s{ "The quick brown fox jumps over the lazy dog" };
	////[문제] s에 찾는 문자가 있는지 , 있으면 몇번째 있는지 확인
	////이 프로그램이 문제 없이 돌아가도록 코딩
	//cout << "글자를 입력하면 찾습니다" << endl;
	//while (true)
	//{
	//	char c;
	//	cout << "글자를 입력하세요: ";
	//	cin >> c;
	//	auto p = Myfind(s.begin(), s.end(), c);
	//	if (p != s.end())
	//		cout << c << "는 " << distance(s.begin(), p) + 1 << "번째 글자입니다" << endl;
	//	else
	//		cout << "찾지 못했습니다" << endl;
	//	cout << endl;
	//}
	
	/*--------------------------------------------------*/

	vector<String> v{ "123","4567","abc" };
	//[문제] 이 main이 문제없이 실행되도록 하라
	
	auto p = find(v.begin(), v.end(), String{ "abc" });
	cout << *p << endl;
	//abc가 출력되어야 한다.
	//save("source.cpp");
}