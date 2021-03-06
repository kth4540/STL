//-----------------------------------------------------------------------------
// String.h - STL 내부 동작을 관찰하기 위해 만든 자원을 확보하는 클래스
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <random>
#include <string>
using std::cout;
using std::endl;

//#define 관찰			// 이 주석을 풀면 special member의 동작을 알 수 있다.

std::default_random_engine dre;
std::uniform_int_distribution<> uidAlpha{ 'a', 'z' };

//String이 외부에 제공하는 반복자
class String_iterator
{
	char* p{ nullptr };
public:
	String_iterator(char* p) :p{ p } {};

	

	int operator-(const String_iterator& rhs)const
	{
		return p - rhs.p;
	}
	bool operator!=(const String_iterator& rhs)const
	{
		return p != rhs.p;
	}
	bool operator==(const String_iterator& rhs)const
	{
		return p == rhs.p;
	}
	String_iterator& operator++()
	{
		++p;
		return* this;
	}String_iterator& operator--()
	{
		--p;
		return*this;
	}
	bool operator<(const String_iterator& rhs)const
	{
		return p < rhs.p;
	}

};

class String {
	using iterator = String_iterator;
	using value_type = char;
public:

	String() :num{ 0 }, p{ nullptr }
	{
#ifdef 관찰
		cout << "생성자() (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif
	}

	String(size_t n) : num{ n }, p{ new char[num] } {
#ifdef 관찰
		cout << "생성자(int) (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif

		for (int i = 0; i < num; ++i)
			p[i] = uidAlpha(dre);
	}
	String(const char* s) :num(strlen(s)), p(new char[num])
	{
		memcpy(p, s, num);
#ifdef 관찰
		cout << "생성자(const char*) (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif

	}

	~String() {
#ifdef 관찰
		cout << "소멸자 (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif
		delete[] p;
	}

	// 복사생성자
	String(const String& other) : num{ other.num }, p{ new char[num] } {
		memcpy(p, other.p, num);

#ifdef 관찰
		cout << "복사생성자 (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif
	}

	// 복사할당연산자
	String& operator=(const String& other) {
		if (this != &other) {
			delete[] p;		//this->~String();
			num = other.num;
			p = new char[num];
			memcpy(p, other.p, num);
		}

#ifdef 관찰
		cout << "복사할당연산자 (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif

		return *this;
	}

	// 이동생성자
	String(String&& other) noexcept : num{ other.num }	//noexcept를 사용해 데이터를 보장할 수 있음
	{
		p = other.p;
		other.p = nullptr;
		other.num = 0;

#ifdef 관찰
		cout << "이동생성자 (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif
	}

	// 이동할당연산자
	String& operator=(String&& other)noexcept {
		if (this != &other) {
			delete[] p;	//this->String();
			num = other.num;
			p = other.p;

			other.num = 0;
			other.p = nullptr;
		}

#ifdef 관찰
		cout << "이동할당연산자 (this:" << this << ") - 갯수: "
			<< num << ", 위치:" << (void*)p << endl;
#endif

		return *this;
	}

	size_t size() const {
		return num;
	}

	//확보한 자원을 std::string처럼 이용할 수 있게 하자
	std::string getString() const
	{
		return std::string(p, p + num);
	}

	//STL처럼 begin()을 사용할 수 있게 하자
	iterator begin()
	{
		return iterator{ p };
	}
	iterator end()
	{
		return iterator{ p + num };
	}


private:
	size_t num;							// 확보한 자원의 수
	char* p;							// 확보한 자원의 위치

	friend std::ostream& operator<<(std::ostream&, const String&);
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}



