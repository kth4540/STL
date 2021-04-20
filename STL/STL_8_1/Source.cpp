//-----------------------------------
//앞으로 x86 release 에서 compile 한다
//2021 1학기 STL 화(5~6) 목(5~6) 4월 20일 화요일 8주 1일차
//
// 반복자는 커너테이너가 제공하는 인터페이스다 (책 31~41, 123~136) -> Design Pattern 중 Iterator Pattern
//실행될 때 마다 소스파일을 저장한다.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <string>
#include <vector>
#include <iterator>
#include <forward_list>
#include <list>
#include <fstream>
using namespace std;

template <typename iter>
void showIteratorCategory(const iter& it)
{
	cout << typeid(iterator_traits<iter>::iterator_category).name() << endl;
}
int main()
{
	//String s{ "The quick brown fox jumps over the lazy dog" };
	//for (char c : s)
	//	cout << c << ' ';
	//cout << endl;

	//sort(s.begin(), s.end());
	//cout << s << endl;
	
	/*--------------------------------------------------------*/
	//[문제] 반복자를 인자로 받은 함수는 그것이 무엇인이 어떻게 아는가

	//vector<int> v;

	//showIteratorCategory(istream_iterator<char>{cin});
	//showIteratorCategory(ostreambuf_iterator<char>{cout});
	//showIteratorCategory(forward_list<int>::iterator());
	//showIteratorCategory(list<int>::iterator());
	//showIteratorCategory(vector<int>::iterator());
	//showIteratorCategory(String().begin());

	/*-------------------------------------------------------*/

	String s{ "135924680" };
	sort(s.begin(), s.end());

	//save("source.cpp");
}