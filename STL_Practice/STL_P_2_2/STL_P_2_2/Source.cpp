#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

default_random_engine dre;
uniform_int_distribution<> uid;

template<typename T>
void change(T& x, T& y)
{
	T t{ x };
	x = y;
	y = t;
}
class IntArray
{
private:
	int* ip;
	size_t size;
public:
	IntArray(int num) :size(num), ip(new int[num]) { cout << "constructed" << endl; }
	~IntArray() { delete[] ip; cout << "destroyed" << endl; }
	int& operator [](int num)
	{
		return ip[num];
	}
};

//template<class T>
//class Array
//{
//private:
//	T* tp;
//	int size;
//public:
//	Array(int num) :size(num), tp(new T[num]) { cout << "constructed" << endl; }
//	~Array() { delete[] tp; cout << "destroyed" << endl;}
//
//	T& operator[](int num)
//	{
//		return tp[num];
//	}
//};

template<class T, int N>
class Array
{
private:
	T data[N];
public:
	T& operator[](int num)
	{
		return data[num];
	}
};

int main()
{
	//cout << "start" << endl;
	//this_thread::sleep_for(3s);
	//cout << "3 seconds left" << endl;

	/*----------------------------------*/

	//using namespace chrono;
	//auto start = steady_clock::now();
	//this_thread::sleep_for(3000ms);
	//auto d = duration_cast<milliseconds>(steady_clock::now() - start);
	//cout << d.count() << "ms left" << endl;

	/*-----------------------------------*/

	//int data[10'0000];
	//for (int& d : data)
	//	d = uid(dre);

	//auto start = chrono::steady_clock::now();
	////qsort(data, 10'0000, sizeof(int), [](const void* a, const void* b) {
	////	return *(static_cast<int const*>(a)) - *(static_cast<int const*>(b));
	////	});
	//sort(begin(data), end(data));
	//auto d = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
	//cout << d.count() << "ms left" << endl;
	//cout << data[0] << "---" << data[100000 - 1] << endl;

	/*-------------------------------------*/

	//string a{ "19"s };
	//string b{ "corona" };
	//change(a, b);
	//cout << a << b << endl;

	/*--------------------------------------*/

	//IntArray a(10);
	//for (int i = 0; i < 10; ++i)
	//	a[i] = i;
	//for (int i = 0; i < 10; ++i)
	//	cout << a[i] << " ";
	//cout << endl;

	/*-----------------------------------------*/

	//Array<int> a(10);
	//for (int i = 0; i < 10; ++i)
	//	a[i] = i;
	//for (int i = 0; i < 10; ++i)
	//	cout << a[i] << " ";
	//cout << endl;

	/*--------------------------------------------*/

	Array<string, 10> a;

	cout << a[0] << endl;
	for (int i = 0; i < 10; ++i)
		a[i] = "string"s + to_string(i);
	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl;
}