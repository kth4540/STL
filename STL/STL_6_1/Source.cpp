//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 4�� 6�� ȭ���� 6�� 1����
//
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include "String.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector�� ��� ���� 3���� �ִ�
//ù°�� free store�� Ȯ���� �޸��� ���۹����� �����ϰ��ִ�.
//[����] ù��° ������ �̿��Ͽ� ���� �����͸� access�϶�

int main()
{
	//vector<int> v{ 1,22,333,4444,55555 };
	//int** p = reinterpret_cast<int**>(&v);	//p -> v -> (1,22,333,4444,55555)
	//cout << **p << endl;
	//cout << *(*p+1) << endl;	//*p�� v�� ���� ���� ����Ű�� �ּ�

	//for (int i = 0; i < v.size(); ++i)
	//	cout << *(*p + i) << endl;

	//int* dp = v.data();	//-> v�� ���� ������ �� �ּҸ� �ٷ� �޾ƿ�
	//for (int i = 0; i < v.size(); ++i)
	//	cout << *(dp + i) << endl;

	/*------------------------------------------------------*/
	//[����] vector�� ��¥ �����͸� ������ �� �ְ� ����
	// - ����� ���� �ڷ����� �ڿ��� ȹ��,�����ϰ� �ִٸ�
	// - �̵������� �̵��Ҵ翬���ڸ� '�ݵ��' �����ؾ� �Ѵ�
	// - �ڷᱸ���� ���Ҹ� �߰��� �� emplace�� �̿�����
/*----------------------------------------------------------*/

	//vector<String> v{ "hello","vector" };	// �ӽ� ��ü�� stack�� ����->v(heap)�� ���� -> �ӽð�ü ���� ������ �����
	
	//vector<String> v;
	//v.reserve(3);	//�̸� ������ ��Ƶ�(���� 3��ġ�� �޸� �̸� Ȯ��, ���� ���� = 0, capacity = 3)
	////v.push_back("�ȳ�");
	////v.push_back("���;�");
	//v.emplace_back("�ȳ�");	//-> emplace_back() : �̵������ڸ� ������� �ʰ� �ٷ� vector�� Ȯ���� �޸𸮿� �ٷ� �ۼ�
	//v.emplace_back("���;�");
	//
	////for (String& s : v)
	////	cout << s << endl;

	//cout << endl;
	//cout << "---�߰��ϱ� ��---------" << endl;
	//cout << endl;

	////v.push_back("helloooooo");
	//v.emplace_back("hellooooo");
	//// �ϴ� �ӽð�ü�� stack�� ���� �� heap�� �̵������ڷ� �̵�, ���� ���� �ִ� ���� ���ο� �ּҷ� ���� �� ���� �� ����(�������� ������ ������ ������ �ΰ� ����)
	//// noexcept�� ����ϸ� �������� �̵������ڷ� �ű� �� ����
	//cout << endl;
	//cout << "---�߰��� ��---------" << endl;
	//cout << endl;

	/*--------------------------------------------*/

	vector<String> v{ 20,10,30 };
	//v�� ���� ������������ ����

	cout << endl;
	cout << "-------- before sort ---------" << endl;
	cout << endl;

	sort(v.begin(), v.end(), [](const String& a, const String& b) {return a.size() < b.size(); });

	cout << endl;
	cout << "-------- after sort ---------" << endl;
	cout << endl;
	
	//�����ð� ����
	//vector<int>���� ¦���� �����Ѵ�
	//vector<int> �߰��� ���Ҹ� �߰��غ���.

	//save("source.cpp");
}