#include <iostream>
using namespace std;
class Model
{
private:
	char* data;
	size_t size;

public:
	Model()
	{
		cout << "constructor-ID: " << &data << endl;
	}	//-> 持失切
	Model(int num) :size(num), data(new char[size])
	{
		cout << size << " char constructed" << endl;
	}
	~Model()
	{
		cout << "destroyer-ID:" << &data << endl;
	}	//-> 社瑚切

	Model(Model& m)
	{
		cout << "copy constructor" << endl;
	}
	Model& operator =(Model& m)
	{

		cout << "copy assignment constructor" << endl;
		return*this;
	}

	Model(Model&& m) :data{ nullptr }, size{ m.size }
	{
		cout << "move constructor" << endl;
		data = m.data;
		m.data = nullptr;
		m.size = 0;
	}
};
int main()
{
	//Model a;
	//Model b{ 1000 };
	//Model c = b;
	//a = c;

	Model a{ 1000 };
	Model b = move(a);
}