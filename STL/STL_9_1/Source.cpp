//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 4�� 29�� ȭ���� 9�� 1����
//
// �����̳�,�˰����� �׸��� �� ���� �����ϴ� �ݺ���
// 
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	String s{ "1357924680" };
	//ostream_iterator<char> outiter{ cout };
	//outiter = 'c';
	//outiter = '+';
	//outiter = '+';

	for (auto i = s.rbegin(); i != s.rend(); ++i)
		cout << (*i) << " - ";

	//save("source.cpp");
}