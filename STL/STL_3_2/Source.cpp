//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 3�� 2�� ȭ���� 1�� 1����
//
//ȣ�� ������Ÿ��-callable type
//	- STL������ �˰��� �Լ��� ������ �����ϴ� �뵵�� ����Ѵ�.
//	sort(begin,end,���ļ���)
//
//ȣ���� �� �ִ� Ÿ���� �����ϰ� ���� �޶� ������ �� ������ ���ڴ�.->function Ÿ���� ������� ����
//
//
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include <functional>
#include <random>
#include <algorithm>
using namespace std;

default_random_engine dre;
uniform_int_distribution<>uid{'a', 'z'};

void jump(void)
{
	cout << "jump" << endl;
}

void slide(void)
{
	cout << "slide" << endl;
}

///////////////////////////////////

//1. �Ϲ� �Լ�
void f(int)
{
	cout << "�Ϲ� �Լ��� ȣ��" << endl;
}

//2. �Լ� ��ü
class Test
{
public:
	void operator()(int)
	{
		cout << "() operator overloading class" << endl;
	}

	void mf(int)
	{
		cout << "Test member function" << endl;
	}
};
//3. lambda-> [](int){cout<<"called lambda"<<endl;}
auto lambda = [](int) {cout << "called lambda" << endl; };

class String
{
private:
	char* p;	//-> unique_ptr�� �غ���
	int number;
public:
	String(int num) :number(num), p{ new char[num] }
	{

		for (int i = 0; i < number; ++i)
			p[i] = uid(dre);
	}
	~String()
	{
		delete[] p;
	}
	//String(const String& other) :number{ other.number }, p{new char[number]}
	//{
	//	memcpy(p, other.p, number);
	//}
	//String& operator=(const String& other)
	//{
	//	if (this != &other)
	//	{
	//		delete[] p;
	//		number = other.number;
	//		p = new char[number];
	//		memcpy(p, other.p, number);
	//		return *this;
	//	}
	//}
	size_t size() const
	{
		return number;
	}

	friend ostream& operator <<(ostream& out, const String& s)
	{
		for (int i=0;i<s.number;++i)
			out << s.p[i] <<" ";
		out << endl;
		return out;
	}
};

int main()
{
	//void (*a)() = jump;
	//a();
	//cout << "address of a: " << a << endl;
	//a = slide;
	//a();
	//cout << "address of a: " << a << endl;
	//cout << "address of main: " << main << endl;
	//cout << "address of 'a': " << &a << endl;
	//cout << typeid(a).name() << endl;
	//cout <<"size of function pointer: "<< sizeof(a) << endl;

	//////////////////////////////////////
	//f(1);	//1. �Ϲ� �Լ�

	//Test t;
	//t(2);	//2. �Լ� ��ü
	//t.mf(2);

	//lambda(3);	//3. lambda
	//cout << typeid(lambda).name() << endl;
	////[����] callabe type�� �� �Լ��� �����ߴٰ� ȣ���غ���

	//void(*cf1)(int) = f;

	////cf1 = Test::mf;
	//void(Test:: * pcf1)(int) = &(Test::mf);	//->Ŭ���� ����Լ��� �Լ� �����ͷ� ����Ű�¹� �˻�
	//(t.*pcf1)(4);

	//cf1 = [](int) {cout << "lambda" << endl; };

	//function<void(int)> ct;
	//ct = f;
	//ct = t;
	//ct = [](int) {cout << "lambda" << endl; };
	///////////////////////////////////////////////
	// 
	//[����] int num�� ���ڸ� �޾� �޸𸮸� num����Ʈ �Ҵ�޾� ������ �ҹ��ڷ� ä��� Ŭ���� String�� �ڵ�
	//���� main �� ���� ���� �ǵ���� ����ǰ�

	String a[10]{1,10,20,3,5,7,10,20,30,40};
	
	for (int i = 0; i < size(a); ++i)
		cout << a[i] << endl;

	//�� string�� ���ĺ� ������������ �����϶�.

	save("source.cpp");
	return 0;
}