//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 4�� 13�� ȭ���� 7�� 1����
//
// deque - vector�� ���������� �ٸ���?
// ->���� �޸𸮰� ���������� �ʴ�. - �׷� ô �� ���δ�.(�޸� ������ vector���� ����)
// ��� vector���� ���Ҹ� �� ���� ���� �� ����
//
// C++ 20���� �޸𸮰� ���ӵ� �����̳ʸ� ��Ÿ���� span template class�� �߰��Ǿ���.
// 
// sequence container - list, forward_list -> �޸𸮸� ����ؼ� �߰�/������ ���Ǽ� Ȯ��(�߰�/������ ������ O(1)) 
// STL contiguous containter - array, vector, deque + [], string
// 
//����� �� ���� �ҽ������� �����Ѵ�.
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
	//	cout << d[i] << endl;	//->�������� �޸� : ������ ����ð����� �Ǳ� ������ ���
	//try{ cout << d.at(5) << endl; }
	//catch (exception& e) { cout << e.what() << endl; }
	
	/*------------------------------------------------*/

	//deque<Test> d(10);
	//d.push_front({});	//->�޸� ��½� ȥ�� �ٸ� -> �޸𸮰� ���������� ���� -> ������ ����ð��� �������� ����
	//for (int i = 0; i < d.size(); ++i)
	//	d[i].show();

	/*-------------------------------------------------*/
	//[����] Vector�� int�� �ϳ��� push_back()�ϸ� �� ������ ������ �� �ִ��� ���

	//vector<int> v; -> �ִ� 136216567 -> �޸𸮰� ������ �������̱� ������ deque���� �޸� ������ ����
	//deque<int> v; //-> �ִ� 268435452
	//cout << "�ִ� ���� �� �ִ� int ��: " << v.max_size() << endl;

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
	////v.erase(remove_if(v.begin(), v.end(), [](const String& a) {return a.size() & 1; }), v.end()); -> �ʹ� ������
	//erase_if(v, [](const String& a) {return a.size() & 1; });	// -> �ڷᱸ���� �˰������� �ݺ��ڸ� ���ؼ��� ��ȣ�ۿ��Ѵٴ� ��Ģ�� ����
	////[����]���ڼ��� Ȧ���̸� ����

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
	// ��ü�� �ݺ��ڷ� ��ȸ�ϸ� ���
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