//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 4월 15일 목요일 7주 2일차
//
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
using namespace std;


void print(const list<int>& cont)
{
	for (int n : cont)
		cout << n << " ";
	cout << endl;
}

int main()
{
	//[문제]"source.cpp"파일을 리스트를 사용해 읽은 후 거꾸로 출력
	//파일에 소문자는 몇글자인지 출력
	ifstream in("source.cpp");
	list<string> lt(istream_iterator<string>{in}, {});
	for (auto itr = lt.begin(); itr != lt.end(); ++itr)
		reverse((*itr).begin(), (*itr).end());
	copy(lt.cbegin(), lt.cend(), ostream_iterator<string>{cout,"\n"});
	cout << endl;

	//cout<<count_if(lt.cbegin(), lt.cend(), [](char c) {return islower(c); })<<endl;
	

	//[문제]파일에 using 이라는 단어가 있다면 몇 번째 있는지 출력	
	
	//list<string> lt(istream_iterator<string>{in}, {});

	//auto p = find(lt.cbegin(), lt.cend(), "using"s);
	//if (p != lt.end())
	//{
	//	cout << distance(lt.cbegin(), p)+1 << "��°" << endl;
	//}
	//else
	//	cout << "failed" << endl;

	/*----------------------------------------------------*/

	//[도전문제] "source.cpp"에 있는 단어를 뒤집어 출력하라

	//list<int> con1{5,7,3,1,9 };
	//list<int> con2{ 4,8,6,10,2 };

	////[문제] con1과 con2에 있는 내용을 con3에 merge하라

	//list<int>con3;
	//con3.merge(con1);
	//con3.merge(con2);
	////merge() -> 순서를 맞출 경우 그 부분은 보장됨, 그렇지 않으면 단순 병합, 원래 데이터는 삭제

	//print(con1);
	//print(con2);
	//print(con3);

	/*-------------------------------*/
	//list<int> con{ 1,3,5,7,7,7,7,7,9,2,4,7,6,8,10 };
	////con.sort([](int a, int b) {return a > b; });
	//print(con);

	//con.unique();	//-> 연속으로 중복된 원소 중 하나만 남기고 나머지 삭제
	//print(con);
	//save("source.cpp");




}