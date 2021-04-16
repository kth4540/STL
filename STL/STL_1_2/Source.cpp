//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 3�� 4�� ȭ���� 1�� 2����
//
// c++ ����
//���� ���� data �ٷ��
//
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include <random>
#include <algorithm>
using namespace std;

//class Game 
//{
//private:
//	int a;
//public:
//	Game(int num) :a(num){}
//
//	friend void change(Game& a_game, Game& b_game)
//	{
//		int tmp = a_game.a;
//		a_game.a = b_game.a;
//		b_game.a = tmp;
//	}
//
//	friend ostream& const operator << (ostream& out, const Game& game)
//	{
//		out << game.a;
//		return out;
//	}
//};	-> class

//template <typename T>
//void change(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}

default_random_engine dre;	//ũ�Ⱑ �ʹ� Ŀ�� stack�� ������ �ȵ�


int main()
{
	// [����] main ���� ���� ����ǵ��� ����
	// �տ��� ���� change()�� �ٸ� �ڷ����� �ٲ� �� �ֵ��� ����	-> template
	// game�� ����ڰ� ������ class
	// ȭ������� 2,1

	//int a{ 1 };
	//int b{ 2 };
	//change(a, b);
	//cout << a << ", " << b << endl;

	//int num = 10;
	//int* p = &num;
	//*p = 20;
	//cout << num << endl;
	//int& xxx = num;
	//xxx = 20;
	//cout << num << endl;
	//pointer, reference�� �뵵 : �ٸ� scope���� ������ �����ϱ� ����

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	//[����] int 10���� ������ ������ �����ϰ�, int�� ������ ������ ���� �� ����Ѵ�.
	//���ǰ��� ���� , ������
	//���� ������������ ����

	//cout << numeric_limits<int>::max() << endl;
	//cout << numeric_limits<int>::min() << endl;

	int a[10]{};
	uniform_int_distribution uid{ 0,1000 };

	for (auto& n : a)
		n = uid(dre);

	sort(begin(a), end(a), [](int a, int b) {return a > b; });

	for (auto& n : a)
		cout << n << endl;

	save("source.cpp");
	return 0;
}