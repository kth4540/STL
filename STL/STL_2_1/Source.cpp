//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 3�� 9�� ȭ���� 2�� 1����

//������ �ø��� �ڷᰡ ����Ǵ� ����� �˾ƺ���
//���� ���� �ڷḦ �����ϴ� ����� �˾ƺ���

//�˰����� �ð����
//����Ʈ ������
//������ ����� ������ class �����α�
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <string_view>
#include <numeric>

using namespace std;

default_random_engine dre;

int num;
bool x(int a, int b)
{
	num += 1;
	cout << a << "---" << b << endl;
	return a > b;
}

//int a[100]{};

int main()
{
	//[����] int 100���� ������ ������ ���� �޸� ������ �����Ѵ�
	//���ǰ��� ���������� ������
	//���� ������������ ����
	//���ĵ� ���� ���� "upsort.txt"�� �����Ѵ�
	//������ ���� ������������ ���ĵǾ��� Ȯ���Ѵ�
	//uniform_int_distribution uid{ 0,100 };

	//for (auto& n : a)
	//	n = uid(dre);

	////[����] sort�� x�� �� �� ȣ���ϴ°�?0
	//sort(begin(a), end(a)[](int ,int){});
	////lambda -> �ڵ��� �ζ���ȭ -> �ӵ� ���
	////lambda ��ġ�� �Լ��� ������ ���� �ӵ��� ������ 

	//cout << "ó�� ������ ��: " << *begin(a) << endl;
	//cout << "������ ������ ��: " << *(end(a)-1) << endl;	//end()�� ������ ���� ������ �ּҸ� ���

	////���Ͽ� �����϶�
	//ofstream out("upsort.txt"s);
	//for (int n : a)
	//	out << n<<" ";

	//[����] ���������� ���� ���� "upsort.txt"�� �ִ�
	//�о ȭ�鿡 ����Ѵ�

	//string_view sv = "upsort.txt"sv;
	//ifstream in(sv);
	//if (!in)
	//{
	//	cout << sv << "file can't open" << endl;
	//	exit(0);
	//}
	//int arr[100];
	//for (int& n : a)
	//	in >> n;

	//for (int d : a)
	//	cout << d << ' ';
	//cout << endl;

	//[����] ���� 100���� 400����Ʈ ������ �������
	//int a[100]�� ���� 1~100���� ä��� ���� "int_100.txt"�� ����ϴ�
	//���� ũ��� 400byte�� �Ǿ�� �Ѵ�

	//int a[100];
	//iota(begin(a), end(a), 1);
	//for (int a : a)
	//	cout << a << endl;

	//ofstream out("int_100.txt",ios::binary);
	//out.write((char*)a, 100 * sizeof(int));

	//[����] "int_100.txt"�� ���̳ʸ��� ����� 100���� �ִ�
	//���� ������ �������� ������ �� ���
	ifstream in("int_100.txt"s,ios::binary);
	if (!in)
		exit(0);

	int n[100];
	in.read((char*)n, sizeof(int) * 100);

	sort(begin(n), end(n), [](int a, int b) {return a > b; });
	for (int e : n)
		cout << e << " ";
	//save("Source.cpp");
	return 0;
}