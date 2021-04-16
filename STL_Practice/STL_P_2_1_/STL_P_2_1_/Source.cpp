#include <iostream>
#include <string>
#include <random>
#include <fstream>
using namespace std;
default_random_engine dre;
uniform_int_distribution<> uid;

int dat[1000'0000];

int main()
{
	//int num = 0b0111'1111'1111'1111'1111'1111'1111'1111;

	//cout << "num�� �޸� ũ��� " << sizeof(num) << "byte" << endl;
	//cout << "num�� ����� ���� " << num << endl;

	//string s{ to_string(num) };
	//cout << "num�� ���ڷ� �����Ϸ��� " << size(s) << "byte�� �ʿ�" << endl;

	/*---------------------------------*/

	//[����] ���� 1000���� binary�� �����ϰ� ���� �� �ִ� ���
	
	//int n;
	//ofstream out("1000_int.txt",ios::binary);

	//for (int i = 0; i < 1000; ++i)
	//{
	//	n = uid(dre);
	//	out.write((char*)&n, sizeof(n));
	//}

	//ifstream in("1000_int.txt", ios::binary);
	//int max = 0;
	//for (int i = 0; i < 1000; ++i)
	//{
	//	in.read((char*)&n, sizeof(n));
	//	cout << n << endl;
	//	if (max < n)
	//		max = n;
	//}

	/*----------------------------------------*/
	
	//[����] ���� 1000���� binary�� �о�� �� sort�� ����

	//ifstream in("1000_int.txt", ios::binary);
	//int data[1000];
	//in.read((char*)&data, sizeof(data));
	//sort(begin(data), end(data), [](int a, int b) {return a < b; });

	//for (int n : data)
	//	cout << n << endl;

	/*----------------------------------------*/

	//[����] ���� õ������ ���Ͽ��� �о�� �� sort�� ����
	//������ ���� õ������ dat ���Ϸ� ����

	//ofstream out("1000_thousand.dat", ios::binary);
	//int n;

	//for (int i = 0; i < 10000000; ++i)
	//{
	//	n = uid(dre);
	//	out.write((char*)&n, sizeof(n));
	//}

	ifstream in("1000_thousand.dat", ios::binary);
	for (int i = 0; i < 1000'0000; ++i)
		in.read((char*)&dat[i], sizeof(int));
	sort(begin(dat), end(dat), [](int a, int b) {return a < b; });

	for (int i = 0; i < 10; ++i)
		cout << dat[i] << endl;
	in.close();

	ofstream out("1000_thousand_sort.dat", ios::binary);
	
	out.write((char*)dat, sizeof(dat));
	
}