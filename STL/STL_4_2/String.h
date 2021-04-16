#pragma once
#include <iostream>
#include <random>
#include <algorithm>
std::mt19937 dre;
std::uniform_int_distribution<> uid{ 'a','z' };
std::uniform_int_distribution<> uidLen{ 1,200 };

#define check

class String
{
private:
	char* p;	//-> unique_ptr로 해보기
	int number;

public:
	String() :p{ nullptr }, number{0} {}

	String(int num) :number{ num }, p{ new char[num] }
	{
#ifdef check
		std::cout << "string(int) construct" << std::endl;
#endif

		for (int i = 0; i < number; ++i)
			p[i] = uid(dre);
	}

	//String(const String& s)
	//{
	//	cout << "copy" << endl;
	//}

	String(const String& other) :number{ other.number }, p{ new char[other.number] }
	{
#ifdef check
		std::cout << "string()-copy" << std::endl;
#endif
		memcpy(p, other.p, other.number);
		std::cout << "deep copy" << std::endl;
	}

	~String()
	{
#ifdef check
			std::cout << "string()-destroy" << std::endl;
#endif
			std::cout << "~String() - p:" << (void*)p << std::endl;
			delete[]p;
	}

	size_t size() const
	{
		return number;
	}

	friend std::ostream& operator <<(std::ostream& out, const String& s)
	{
		for (int i = 0; i < s.number; ++i)
			out << s.p[i] << " ";
		out << std::endl;
		return out;
	}

	void SortClass()
	{
		std::sort(p, p + number);
	}

	//String& operator=(const String& s)
	//{
	//	cout << "assign" << endl;
	//	return*this;
	//}
	String& operator=(const String& other)
	{
		if (this != &other)
		{
			delete[]p;
			number = other.number;
			p = new char[number];
			memcpy(p, other.p, number);
		}
		return*this;
	}
};
