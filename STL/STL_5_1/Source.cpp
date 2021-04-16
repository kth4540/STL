//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 3�� 30�� ȭ���� 5�� 1����
//
// String.h�� eclass���� ���� �ٿ�޾� ����� ������ �� ����.
// 
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	// [����] String�� const char*�� ���ڷ� �޵��� ����

	//cout << "make string" << endl;
	//String s{ "hello world" };
	//cout << s << endl;

	/*------------------------------------------------*/

	//[����] STL ǥ�� �����̳ʿ� String�� element�� �־��.

	//array<String, 3> words{ "������","������","�غ�" };
	//-> array�� <>�� ���� ���� �Ұ���,array�� ���� �Ҵ��� �ƴϱ� ������ ���� ����

	//array<String, 3> words{ 10,20,30 };
	//for (const String& s : words)
	//	cout << s << endl;

	//[����]��������(lexicographical)�� �������� �����Ѵ�.

	//sort(words.begin(), words.end(), [](const String& a, const String& b) {return a.getString() < b.getString(); });
	//for (const String& s : words)
	//	cout << s << endl;

	//[����] []�� array�� ������ �ٸ���? ������ ����ϴ°� ������?

	//int a[10]{};
	//array<int, 10> aa{};
	//�޸� ���� ������� ����
	//array�� �ΰ� ����� �ִ� (aa.~~~())

	/*--------------------------------------------------------*/

	//[����] vector�� �����ΰ� - ����(compile time���� ũ�⸦ �� �� ����) �迭
	
	vector<int> v{ 1,2,3 };	//compile time�� ũ�⸦ �������� ����
	cout << "number of elements: " << v.size() << endl;
	
	v.push_back(10);
	cout << "number of elements: " << v.size() << endl;

	//save("source.cpp");
}