//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 4�� 29�� ȭ���� 9�� 1����
//
// Container - String
// Algorithm - String_iterator, String_reverse_iterator
// Iterator - 
// 
//����� �� ���� �ҽ������� �����Ѵ�.
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

	//[����] String_iterator ���� "�ʴ� � ������ �ݺ��ڴ�?"��� �������

	//cout << typeid(iterator_traits<String_iterator>::iterator_category).name() << endl;

	/*--------------------------------------------------------------------------*/

	//String s{ "The quick brown fox jumps over the lazy dog" };
	////[����] s�� ã�� ���ڰ� �ִ��� , ������ ���° �ִ��� Ȯ��
	////�� ���α׷��� ���� ���� ���ư����� �ڵ�
	//cout << "���ڸ� �Է��ϸ� ã���ϴ�" << endl;
	//while (true)
	//{
	//	char c;
	//	cout << "���ڸ� �Է��ϼ���: ";
	//	cin >> c;
	//	auto p = Myfind(s.begin(), s.end(), c);
	//	if (p != s.end())
	//		cout << c << "�� " << distance(s.begin(), p) + 1 << "��° �����Դϴ�" << endl;
	//	else
	//		cout << "ã�� ���߽��ϴ�" << endl;
	//	cout << endl;
	//}
	
	/*--------------------------------------------------*/

	vector<String> v{ "123","4567","abc" };
	//[����] �� main�� �������� ����ǵ��� �϶�
	
	auto p = find(v.begin(), v.end(), String{ "abc" });
	cout << *p << endl;
	//abc�� ��µǾ�� �Ѵ�.
	//save("source.cpp");
}