//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 3�� 2�� ȭ���� 1�� 1����
//
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <thread>
#include <fstream>
using namespace std;
int main()
{
	//[����]	int�� �Է¹޾� �հ�� ��հ��� ���
	//vector<int> v;
	//int num;
	//cout << "input number: ";
	//
	//while (cin>>num)
	////num�� ��ȿ�� ���� ������ ��� loop
	//	v.push_back(num);
	//cout << "out of loop" << endl;
	//
	//float sum = 0;
	//int cnt = 0;
	//
	//for (int& n : v)
	//	sum += n;

	//float ev = sum / v.size();

	//cout << sum << " " << ev << endl;

	/*----------------------------------------*/

	//[����] ��ü v�� �����ϴ� �޸� ũ�⸦ ���캻��.

	//vector<int> v{ 1,2,3 };
	//cout << sizeof(v) << endl;

	//[����] vector�� 4byte�� ������� 3���� �ִ�.
	// 	   1���� �����Ҵ��� �޸� �ּ�(Data), �ٸ� 1���� �����ϰ� �ִ� ���� ����(Size), ������ 1���� ���� ������ �ִ� ���� ������.(Capacity)
	// 	   �����Ҵ��� �ּҰ��� �����ͼ� �� �ּ��� ������ v.size()��ŭ ����Ѵٸ� ��� ���Ұ� ȭ�鿡 ���
	// 	   ���� �ð����� �غ���.

	//vector<int>  v{ 1,2,3,10,200,4000,7777777 };
	//for (int i = 0; i < v.size(); ++i)
	//cout << *(v.begin()+i) << " ";

	//int** p = reinterpret_cast<int**>(&v);
	//for (int i = 0; i < v.size(); ++i)
	//	cout << *((*p) + i) << " ";
	//cout << endl;

	//vector<int> v{ 1,2,3 };
	//cout << "v�� ���� ����: "<<v.size() << endl;
	//v.push_back(456);	
	//push_back()�� �߰��� ������ ������ �޸𸮸� Ȯ���� �� �� ����, ���� ���� �޸� ����-> ���Ҵ�
	//capacity�� �ִ�� �Ҵ�Ǿ����� �� push_back() �ϸ� capacity�� 1.5��� ���Ҵ��

	//for (int i = 0; i < v.size(); ++i)
	//	cout << v[i] << endl;

	/*------------------------------------------------------------------------*/

	//vector<int> v{};
	//while (true)
	//{
	//	v.push_back(1);

	//	if(v.size()==v.capacity())
	//	{//cout << "v�� ������ ������ ��ġ - " << v.data() << endl;
	//		v.push_back(1);
	//		cout << "v�� ������ ������ ���� - " << v.size() << endl;
	//		cout << "v�� ���Ҵ� ���� ���� ������ ���� ���� - " << v.capacity() << endl;
	//	}
	//	//this_thread::sleep_for(10ms);
	//}

	/*---------------------------------------------------------------------------*/

	//[����]"source.cpp"�� �о� vector�� ������ �� �Ųٷ� ȭ�鿡 ���
	//�ҹ��ڸ� �빮�ڷ� �ٲ㼭 ȭ�鿡 ���
	ifstream in("source.cpp");
	vector<char> source;
	char c;
	while (/*(c = in.get()) != EOF*/ in >> noskipws >> c)
		source.push_back(c);

	//for (int i = 0; i < source.size(); ++i)
	//	cout << (*(source.rbegin() + i)) << " ";

	//���⿡�� v�� �ִ� ���� �� �ҹ��ڸ� �빮�ڷ� �ٲ۴�.
	for (char& c : source)
		c=toupper(c);	//toupper�� c����Լ��� reference ��� �Ұ�

	for (auto i = source.begin(); i != source.end(); ++i)
		cout <<(*i);
	save("source.cpp");
}