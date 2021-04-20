//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 4�� 20�� ȭ���� 8�� 1����
//
// �ݺ��ڴ� Ŀ�����̳ʰ� �����ϴ� �������̽��� (å 31~41, 123~136) -> Design Pattern �� Iterator Pattern
//����� �� ���� �ҽ������� �����Ѵ�.
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
	//[����] �ݺ��ڸ� ���ڷ� ���� �Լ��� �װ��� �������� ��� �ƴ°�

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