//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 4�� 8�� ȭ���� 6�� 2����
//�߰���� - 4�� 22�� (8�� 2����)
//����� �� ���� �ҽ������� �����Ѵ�.
//-�ڷᱸ���� ������ �ڵ��� �ϸ� �ڷᱸ���� �ٲ���� �ڵ�� ������� ����
//-�����̳��� ũ�Ⱑ ���� ����ȴٸ� �ڷᱸ���� �ٲ���Ѵ�.
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
	////[����] v�� 3�� ���� �־�� ->{1,2,3,4,5}

	//auto p = v.begin();
	//advance(p, 2);		//p�� ����Ű�°��� 2��ŭ �ű�
	//v.insert(p, {3});	//insert(a,(b),c)->a ��ġ�� b������ŭ c���� �ִ´�
	//
	////for (int i = 0; i < v.size(); ++i)	//-> �޸𸮰� �������� ��Ȳ������ ��� ����(array,vector ��)
	////	cout << v[i] << " ";

	//for (auto i = v.cbegin(); i != v.cend(); ++i)	//-> Ư�� �ڷ����� ���ѵ��� ����
	//	cout << *i << " ";
	//cout << endl;

/*--------------------------------------------*/

	//vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	////[����] v���� ¦���� ����
	//auto p=remove_if(v.begin(), v.end(), [](int value)
	//	{return (value & 1); });
	////remove�� ����°� ��¥�� �ƴϰ�, ������ ����°� �ڷᱸ���� ���� �ؾ���
	////remove_if()-> ������ ���� �տ� ���Ƴְ�, �����Ⱚ�� �� ���� �����͸� return
	////{2,4,6,8,10,6,7,8,9,10}���� 6�� ���� �����͸� return

	//cout << "v�� Ȯ���� �޸�" << v.capacity() << endl;

	//v.erase(p,v.end());
	////-> ���� p���� v�� ������ erase
	////-> erase �ص� capacity�� �״��

	//cout << "erase()�� �� �޸�" << v.capacity() << endl;
	//v.shrink_to_fit();
	//cout << "���� �޸� ����ȭ" << v.capacity() << endl;

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