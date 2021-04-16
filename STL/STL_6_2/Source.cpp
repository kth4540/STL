//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 4월 8일 화요일 6주 2일차
//중간고사 - 4월 22일 (8주 2일차)
//실행될 때 마다 소스파일을 저장한다.
//-자료구조에 무관한 코딩을 하면 자료구조가 바뀌더라도 코드는 변경되지 않음
//-컨테이너의 크기가 자주 변경된다면 자료구조를 바꿔야한다.
//-----------------------------------
#include "save.h"
#include <vector>
#include <list>
#include <unordered_set>
#include <deque>
#include <algorithm>
#include "String.h"
using namespace std;
int main()
{
	//vector<int> v{ 1,2,4,5 };
	////[문제] v에 3을 끼워 넣어본다 ->{1,2,3,4,5}

	//auto p = v.begin();
	//advance(p, 2);		//p가 가리키는값을 2만큼 옮김
	//v.insert(p, {3});	//insert(a,(b),c)->a 위치에 b갯수만큼 c값을 넣는다
	//
	////for (int i = 0; i < v.size(); ++i)	//-> 메모리가 연속적인 상황에서만 사용 가능(array,vector 등)
	////	cout << v[i] << " ";

	//for (auto i = v.cbegin(); i != v.cend(); ++i)	//-> 특정 자료형에 국한되지 않음
	//	cout << *i << " ";
	//cout << endl;

/*--------------------------------------------*/

	//vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	////[문제] v에서 짝수를 제거
	//auto p=remove_if(v.begin(), v.end(), [](int value)
	//	{return (value & 1); });
	////remove가 지우는건 진짜가 아니고, 실제로 지우는건 자료구조가 직접 해야함
	////remove_if()-> 정리된 값을 앞에 몰아넣고, 쓰레기값이 된 곳의 포인터를 return
	////{2,4,6,8,10,6,7,8,9,10}에서 6의 값의 포인터를 return

	//cout << "v가 확보한 메모리" << v.capacity() << endl;

	//v.erase(p,v.end());
	////-> 이후 p부터 v의 끝까지 erase
	////-> erase 해도 capacity는 그대로

	//cout << "erase()된 후 메모리" << v.capacity() << endl;
	//v.shrink_to_fit();
	//cout << "남는 메모리 최적화" << v.capacity() << endl;

	//for (int n : v)
	//	cout << n << " ";
	//cout << endl;

	/*-------------------------------------------*/

	deque<String> d;
	//d.emplace_back("back");
	//d.emplace_front("front");
	//d.emplace(d.end(), "backback");
	//d.emplace(d.begin(), "frontfront");

	d.emplace(d.end(), "1");
	d.emplace(d.end(), "2");
	d.emplace(d.end(), "3");

	for (const String& s : d)
		cout << s << " ";
	cout << endl;
	//save("source.cpp");
}