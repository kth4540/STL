//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 4월 13일 화요일 7주 1일차
//
// deque - vector와 유사하지만 다른점?
// ->실제 메모리가 연속적이지 않다. - 그런 척 할 뿐인다.(메모리 접근이 vector보다 느림)
// 대신 vector보다 원소를 더 많이 담을 수 있음
//
// C++ 20에는 메모리가 연속된 컨테이너를 나타내는 span template class가 추가되었다.
// 
// sequence container - list, forward_list -> 메모리를 희생해서 추가/삭제의 편의성 확보(추가/삭제의 동작이 O(1)) 
// STL contiguous containter - array, vector, deque + [], string
// 
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <deque>
#include <algorithm>
#include <span>
#include <string>
#include <list>
using namespace std;

class Test
{
	char c[1024];
public:
	void show() const
	{
		cout << this << endl;
	}
};
template<typename T>
void print(span<T> s)
{
	for (int i = 0; i < s.size(); ++i)
		cout << s[i] << ' ';
}
int main()
{
	//deque<int> d{ 1,2,3,4,5 };
	//for (int i = 0; i < d.size(); ++i)
	//	cout << d[i] << endl;	//->연속적인 메모리 : 접근이 상수시간으로 되기 때문에 사용
	//try{ cout << d.at(5) << endl; }
	//catch (exception& e) { cout << e.what() << endl; }

	/*------------------------------------------------*/

	//deque<Test> d(10);
	//d.push_front({});	//->메모리 출력시 혼자 다름 -> 메모리가 연속적이지 않음 -> 접근이 상수시간에 도달하지 못함
	//for (int i = 0; i < d.size(); ++i)
	//	d[i].show();

	/*-------------------------------------------------*/
	//[실험] Vector에 int를 하나씩 push_back()하며 몇 개까지 저장할 수 있는지 출력

	//vector<int> v; -> 최대 136216567 -> 메모리가 실제로 연속적이기 때문에 deque보다 메모리 제한이 작음
	//deque<int> v; //-> 최대 268435452
	//cout << "최대 담을 수 있는 int 수: " << v.max_size() << endl;

	//while (1)
	//{
	//	try
	//	{
	//		v.push_back(1);
	//	}
	//	catch (exception& e)
	//	{
	//		cout << e.what() << endl;
	//		cout << "no more " << v.size() << endl;
	//		break;
	//	}
	//}

	/*--------------------------------------------------------*/

	//vector<String> v{ 1,2,3,4,5,6,7,8,9,10 };
	////v.erase(remove_if(v.begin(), v.end(), [](const String& a) {return a.size() & 1; }), v.end()); -> 너무 복잡함
	//erase_if(v, [](const String& a) {return a.size() & 1; });	// -> 자료구조와 알고리즘은 반복자를 통해서만 상호작용한다는 원칙이 깨짐
	////[문제]글자수가 홀수이면 제거

	//for (int i = 0; i < v.size(); ++i)
	//	cout << v[i] << endl;

	/*--------------------------------------------------------*/

	//int a[10]{ 1,2,3,4,5,6,7,8,9,10 };
	//print(span<int>{a});

	//vector<String> v{ 10,20,30 };
	//print(span<String>{v});
	//string s{ "jasdloas" };
	//print(span<char>{s});

	/*-------------------------------------------------------*/

	list<String> c{ 1,3,5,7,9,2,4,6,8,10 };
	// 전체를 반복자로 순회하며 출력
	//for (auto k = c.cbegin(); k != c.cend(); ++k)
	//{
	//	cout << *k << ' ';
	//}
	c.reverse();
	c.sort([](const String& a, const String& b) {return a.size() < b.size(); });
	for (const String& s : c)
		cout << s << endl;

	//save("source.cpp");
}