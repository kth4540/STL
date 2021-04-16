#include <iostream>
#include <functional>
using namespace std;


void jump() { cout << "jump" << endl; }
void slide() { cout << "slide" << endl; }

class Dog
{
public:
	Dog() { cout << "Constructed" << endl; }
	~Dog() { cout << "Destroyed" << endl; }
	void show() { cout << "Dog" << endl; }
	void operator()(int n)
	{
		cout << n << "- function object" << endl;
	}
};
//void f(int n)
//{
//	cout << n << "normal function" << endl;
//}
void f(Dog* pDog)
{
	pDog->show();
	delete pDog;
}
//void (*fp)(int) = f;
auto lambda = [](int n) {cout << "lambda" << endl; };
int main()
{
	//f(1);	//-> 일반 호출
	//(*f)(2);//-> 함수 이름은 함수의 시작번지를 가리키는 포인터

	//void* p = f;
	//cout << "address of func f" << p << endl;
	//
	//int n{};
	//cout << "address of stack" << &n << endl;

	//(*(void(*)(int))p)(3);	//-> 주소 p를 함수로 바꿔 인자 3으로 호출

	/*-------------------------*/

	//char key;
	//bool flag{ false };

	//void(*func1)() = jump;
	//void(*func2)() = slide;
	//while (true)
	//{
	//	cout << "input a or d, q to quit: ";
	//	cin >> key;

	//	switch(key)
	//	{
	//	case 'a':
	//	case 'A':
	//		func1();
	//		break;
	//	case'd':
	//	case'D':
	//		func2();
	//		break;
	//	case'c':
	//	case'C':
	//		func1 = slide;
	//		func2 = jump;
	//		break;
	//	case'q':
	//	case'Q':
	//		flag = true;
	//		break;
	//	default:
	//		break;
	//	}
	//	if (flag == true)
	//		break;
	//}

	/*-----------------------------*/

	//auto callableType = []() {cout << "lambda" << endl; };
	//callableType();
	//cout << typeid(callableType).name() << endl;

	/*--------------------------------*/

	//function<void(int)> func;
	//cout << typeid(func).name() << endl;
	//
	//func = f;
	//func(1);

	//func = Dog();
	//func(2);

	//func = fp;
	//func(3);

	//func = lambda;
	//func(4);

	/*------------------------------*/

	//unique_ptr<Dog>p{ new Dog };
	//p->show();
	//cout << sizeof(p) << endl;

	/*-------------------------------*/

	//auto dog = make_unique<Dog>();
	//unique_ptr<Dog>dogs{ new Dog[3] };
	unique_ptr<Dog[]>dogs = make_unique<Dog[]>(5);
	unique_ptr<Dog[]>dogs2{ new Dog[2] };
}