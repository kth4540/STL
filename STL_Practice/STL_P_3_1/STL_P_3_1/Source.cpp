#include <iostream>
#include <thread>
#include <random>
#include <fstream>
#include <algorithm>
using namespace std;
int gid{};
default_random_engine dre;
uniform_int_distribution<int> uidAge{1,12};
uniform_int_distribution<int> uidName{ 'a','z' };
uniform_int_distribution<int> uidNameLen{ 3,15 };
class Dog
{
	string name;
	int age;
	int id;
public:
	Dog(const string D_name, int num) :name(D_name), age(num),id(gid++)
	{
		cout << "Data set" << endl;
	}
	Dog() :id(gid++)
	{
		int len = uidNameLen(dre);
		age = uidAge(dre);
		for (int i = 0; i < len; ++i)
			name += uidName(dre);
	}
	friend ostream& operator<<(ostream& out, const Dog& d)
	{
		out << d.name << " " << d.age << " " << d.id;
		return out;
	}
	string& getName()
	{
		return name;
	}

};

int main()
{
	//size_t memSize(100'000'000);
	//while (true)
	//{
	//	new char[memSize];
	//	cout << memSize << "byte get" << "\n";
	//	this_thread::sleep_for(100ms);
	//}	-> memory leak
	
	//while (true)
	//{
	//	char* p = new char[memSize];
	//	cout << memSize << "byte get" << "\n";
	//	this_thread::sleep_for(100ms);
	//	delete[]p;
	//}

	/*-------------------------------------------*/

	//cout << "size of Dog's memory - " << sizeof(Dog) << endl;
	//Dog dog{ "pup",3 };
	//Dog tmp;
	//cout << dog << tmp << endl;

	ofstream out("10000_Dogs", ios::binary);
	for (int i = 0; i < 10000; ++i)
	{
		Dog d;
		out.write((char*)& d, sizeof(Dog));
	}
	out.close();
	ifstream in("10000_Dogs", ios::binary);
	Dog d[10000];
	for (int i = 0; i < 10000; ++i)
	{
		in.read((char*)&d[i], sizeof(Dog));
	}

	sort(begin(d), end(d), [](Dog& a, Dog& b) {return a.getName() < b.getName(); });

	cout << *(begin(d)) << " " << *(end(d) - 1) << endl;
}