//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 3�� 11�� ȭ���� 2�� 2����
//
//[
//
//
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include <iostream>
#include "save.h"
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>
using namespace std;
int main()
{
	//[����] ����ڰ� ���ϴ� ���� num ��ŭ int�� ������ ������ Ȯ���Ѵ�.
	// �� ������ 1���� num���� ���ڷ� ä���
	// ó���� ������ ���� ����Ѵ�

	//cout << "���� ����: " << endl;
	//int num;
	//cin >> num;
	//vector<int>my_arr;
	////	[]->contiguous(�������� ���Ӽ�)
	//try
	//{
	//	my_arr.resize(num);
	//}
	//catch (exception& e)
	//{
	//	cout << e.what() << endl;
	//}
	//iota(begin(my_arr), end(my_arr), 1);

	//cout << *(begin(my_arr)) << " " << *(end(my_arr) - 1) << endl;

	//[����]�ý����� �޸𸮸� �� �� ���������� �޸𸮸� 3�ʿ� 1���� ��û�Ѵ�
	//500mb�� ��� �������� �ʰ� ��û�Ѵ�.

	//int cnt = 0;
	//while (true)
	//{
	//	new char[200'000'000];
	//	cout << ++cnt << "�Ҵ� ����" << endl;
	//	//this_thread::sleep_for(1s);
	//}

	//C++ Core Guide - raw pointer�� ������� �� ��

	//while (true)
	//{
	//	int cnt = 0;
	//	unique_ptr<char[]>p{ new char[50000] };
	//	cout << p[0] << endl;
	//}

	auto b = chrono::steady_clock::now();	//����

	this_thread::sleep_for(100ms);

	using namespace std::chrono;

	cout << "����ð� - " << duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
	save("source.cpp");
	//-> �ð� ���
	return 0;

}