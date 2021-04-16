//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 4월 6일 화요일 6주 1일차
//
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector는 멤버 변수 3개가 있다
//첫째는 free store에 확보한 메모리의 시작번지를 저장하고있다.
//[문제] 첫번째 변수를 이용하여 실제 데이터를 access하라

int main()
{
	//vector<int> v{ 1,22,333,4444,55555 };
	//int** p = reinterpret_cast<int**>(&v);	//p -> v -> (1,22,333,4444,55555)
	//cout << **p << endl;
	//cout << *(*p+1) << endl;	//*p는 v가 실제 값을 가리키는 주소

	//for (int i = 0; i < v.size(); ++i)
	//	cout << *(*p + i) << endl;

	//int* dp = v.data();	//-> v의 실제 데이터 값 주소를 바로 받아옴
	//for (int i = 0; i < v.size(); ++i)
	//	cout << *(dp + i) << endl;

	/*------------------------------------------------------*/
	//[문제] vector가 진짜 데이터를 관리할 수 있게 하자
	// - 사용자 정의 자료형이 자원을 획득,관리하고 있다면
	// - 이동생성과 이동할당연산자를 '반드시' 구현해야 한다
	// - 자료구조에 원소를 추가할 때 emplace를 이용하자
/*----------------------------------------------------------*/

	//vector<String> v{ "hello","vector" };	// 임시 객체를 stack에 생성->v(heap)에 복사 -> 임시객체 해제 순으로 진행됨
	
	//vector<String> v;
	//v.reserve(3);	//미리 공간만 잡아둠(원소 3개치의 메모리 미리 확보, 현재 갯수 = 0, capacity = 3)
	////v.push_back("안녕");
	////v.push_back("벡터야");
	//v.emplace_back("안녕");	//-> emplace_back() : 이동생성자를 사용하지 않고 바로 vector에 확보한 메모리에 바로 작성
	//v.emplace_back("벡터야");
	//
	////for (String& s : v)
	////	cout << s << endl;

	//cout << endl;
	//cout << "---추가하기 전---------" << endl;
	//cout << endl;

	////v.push_back("helloooooo");
	//v.emplace_back("hellooooo");
	//// 일단 임시객체를 stack에 생성 후 heap에 이동생성자로 이동, 이후 원래 있던 값을 새로운 주소로 복사 후 기존 값 해제(데이터의 안정성 때문에 원본을 두고 복사)
	//// noexcept를 사용하면 기존값을 이동생성자로 옮길 수 있음
	//cout << endl;
	//cout << "---추가한 후---------" << endl;
	//cout << endl;

	/*--------------------------------------------*/

	vector<String> v{ 20,10,30 };
	//v를 길이 오름차순으로 정렬

	cout << endl;
	cout << "-------- before sort ---------" << endl;
	cout << endl;

	sort(v.begin(), v.end(), [](const String& a, const String& b) {return a.size() < b.size(); });

	cout << endl;
	cout << "-------- after sort ---------" << endl;
	cout << endl;
	
	//다음시간 예고
	//vector<int>에서 짝수를 삭제한다
	//vector<int> 중간에 원소를 추가해본다.

	//save("source.cpp");
}