//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 3월 30일 화요일 5주 1일차
//
// String.h를 eclass에서 새로 다운받아 공통된 관찰을 해 본다.
// 
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	// [문제] String이 const char*를 인자로 받도록 하자

	//cout << "make string" << endl;
	//String s{ "hello world" };
	//cout << s << endl;

	/*------------------------------------------------*/

	//[문제] STL 표준 컨테이너에 String을 element로 넣어본다.

	//array<String, 3> words{ "다음주","과제를","준비" };
	//-> array의 <>는 절대 생략 불가능,array는 동적 할당이 아니기 때문에 갯수 지정

	//array<String, 3> words{ 10,20,30 };
	//for (const String& s : words)
	//	cout << s << endl;

	//[문제]사전순서(lexicographical)로 오름차순 정렬한다.

	//sort(words.begin(), words.end(), [](const String& a, const String& b) {return a.getString() < b.getString(); });
	//for (const String& s : words)
	//	cout << s << endl;

	//[질문] []와 array는 무엇이 다른가? 무엇을 사용하는게 좋은가?

	//int a[10]{};
	//array<int, 10> aa{};
	//메모리 상의 장단점은 없다
	//array는 부가 기능이 있다 (aa.~~~())

	/*--------------------------------------------------------*/

	//[문제] vector란 무엇인가 - 동적(compile time에는 크기를 알 수 없는) 배열
	
	vector<int> v{ 1,2,3 };	//compile time에 크기를 결정하지 않음
	cout << "number of elements: " << v.size() << endl;
	
	v.push_back(10);
	cout << "number of elements: " << v.size() << endl;

	//save("source.cpp");
}