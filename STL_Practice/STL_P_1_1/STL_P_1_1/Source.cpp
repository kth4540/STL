#include <iostream>
using namespace std;

class X
{
private:
	int num;
public:
	X(int n) :num{n} {}

	friend ostream& operator << (ostream & out, const X & x)
	{
		out << x.num;
		return out;
	}
	friend void change(X& x, X& y)
	{
		int tmp = x.num;
		x.num = y.num;
		y.num = tmp;
	}
};

void change( int& x, int& y )
{
	int tmp = x;
	x = y;
	y = tmp;
}



int main()
{
	//int a{ 1 };
	//int b{ 2 };
	//change(a, b);
	//cout << a << ", " << b << endl;

	/*-----------------------------*/
	//[문제] : 위 예제에서 int 대신 class X를 만들어 넣고 실행

	X a{ 1 };
	X b{ 2 };
	change(a, b);
	cout << a << ", " << b << endl;
}