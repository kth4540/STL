//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 3월 25일 목요일 4주 2일차
// 
//containers are objects that store other objects.
// 
// Sequence Container
// 1. Array
// 2. vector
// 3. deque
// 4. forward-list
// 5. list
// 
// 관찰 class에 이동기능 코딩 - sort함수로 확인
// 
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include <vector>
#include<iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <array>
#include "String.h"
using namespace std;

template <typename T, int N>
class Array
{
	T data[N]{ 0 };
public:

	Array() {}

	size_t size() const
	{
		return N;
	}
	T operator[](int idx)const
	{
		return data[idx];
	}
	T& operator[](int idx)
	{
		return data[idx];
	}
	T* begin()
	{
		return data;
	}
	T* end()
	{
		return data+N;
	}
	
};

int main()
{	
	//vector<int> v{1, 2, 3};
	//for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	//	cout << *i << endl;

	//vector<vector<int>> vv{ {1,2,3}, {4,5,6},{100,200,300} };
	//for (auto i = vv.begin(); i != vv.end(); ++i)
	//{
	//	auto t = *i;
	//	for (auto ti = t.begin(); ti != t.end(); ++ti)
	//		cout << *ti <<" ";
	//	cout << endl;
	//}

	/*--------------------------------------------*/

	// 	   [문제] array의 특성을 알아본다

	//int a[10]{ 1,2,3,4,5 };	//->이제 이런식으로 쓰지 않음
	//cout << *(a + 0) << endl;
	//cout << *(a + 3) << endl;

	//array<int, 10> a{ 1,2,3,4,5 };	
	//array<int, 100> b;	//-> 크기도 type의 일부분
	//cout << a[0] << endl;
	
	//a = b;	-> type 이 다르므로 error
	//cout << sizeof(a) << " " << sizeof(b) << endl;
	// while (true)
	//{
	//	try
	//	{
	//		cout << "input number: ";
	//		int number;
	//		cin >> number;
	//		cout << a.at(number) << endl;
	//	}
	//	catch (exception& e)
	//	{
	//		cout << "input between 0~" << a.size() - 1 << endl;
	//		continue;
	//	}
	//}

	/*----------------------------------------*/
	//[문제] main 변화 없이 실행되게 코딩

	Array<String, 10> a;
	for (int i = 0; i < a.size(); ++i)
	{
		a[i] = i * i;
	}
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << endl;
	}

	for (auto i = a.begin(); i != a.end(); ++i)
		cout << *i << endl;

	save("source.cpp");
}