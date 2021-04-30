//-----------------------------------------------------------------------------
// String.h - STL ���� ������ �����ϱ� ���� ���� �ڿ��� Ȯ���ϴ� Ŭ����
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <random>
#include <string>
using std::cout;
using std::endl;

//#define ����			// �� �ּ��� Ǯ�� special member�� ������ �� �� �ִ�.

std::default_random_engine dre;
std::uniform_int_distribution<> uidAlpha{ 'a', 'z' };

//String�� �ܺο� �����ϴ� �ݺ���
class String_iterator :
	public std::iterator<std::random_access_iterator_tag, char>
{
	char* p{ nullptr };
public:
	String_iterator(char* p) :p{ p } {};
	String_iterator() = default;

	//_ULast- _UFirst
	int operator -(const String_iterator& rhs) const
	{
		return p - rhs.p;
	}
	bool operator !=(const String_iterator& rhs) const
	{
		return (p != rhs.p);
	}
	String_iterator& operator ++()
	{
		++p;
		return *this;
	}
	String_iterator& operator --()
	{
		--p;
		return *this;
	}
	String_iterator operator +(int n)const
	{
		return String_iterator{ p + n };
	}
	String_iterator operator -(int n)const
	{
		return String_iterator{ p - n };
	}
	bool operator <(const String_iterator& rhs) const
	{
		return p < rhs.p;
	}
	bool operator ==(const String_iterator& rhs) const
	{
		return p == rhs.p;
	}
	char& operator *()
	{
		return *p;
	}
	char& operator *() const
	{
		return *p;
	}
};

class String_reverse_iterator
{
	char* p{ nullptr };
public:
	String_reverse_iterator(char* p) :p{ p } {}

	bool operator !=(const String_reverse_iterator& rhs)
	{
		return p != rhs.p;
	}

	String_reverse_iterator& operator++()
	{
		--p;
		return*this;
	}

	String_reverse_iterator& operator--()
	{
		++p;
		return*this;
	}

	char& operator*()
	{
		return *(p - 1);
	}
};

class String {
	using iterator = String_iterator;
	using reverse_iterator = String_reverse_iterator;
	using value_type = char;
public:

	String() :num{ 0 }, p{ nullptr }
	{
#ifdef ����
		cout << "������() (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	String(size_t n) : num{ n }, p{ new char[num] } {
#ifdef ����
		cout << "������(int) (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif

		for (int i = 0; i < num; ++i)
			p[i] = uidAlpha(dre);
	}
	String(const char* s) :num(strlen(s)), p(new char[num])
	{
		memcpy(p, s, num);
#ifdef ����
		cout << "������(const char*) (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif

	}

	~String() {
#ifdef ����
		cout << "�Ҹ��� (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif
		delete[] p;
	}

	// ���������
	String(const String& other) : num{ other.num }, p{ new char[num] } {
		memcpy(p, other.p, num);

#ifdef ����
		cout << "��������� (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	// �����Ҵ翬����
	String& operator=(const String& other) {
		if (this != &other) {
			delete[] p;		//this->~String();
			num = other.num;
			p = new char[num];
			memcpy(p, other.p, num);
		}

#ifdef ����
		cout << "�����Ҵ翬���� (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif

		return *this;
	}

	// �̵�������
	String(String&& other) noexcept : num{ other.num }	//noexcept�� ����� �����͸� ������ �� ����
	{
		p = other.p;
		other.p = nullptr;
		other.num = 0;

#ifdef ����
		cout << "�̵������� (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	// �̵��Ҵ翬����
	String& operator=(String&& other)noexcept {
		if (this != &other) {
			delete[] p;	//this->String();
			num = other.num;
			p = other.p;

			other.num = 0;
			other.p = nullptr;
		}

#ifdef ����
		cout << "�̵��Ҵ翬���� (this:" << this << ") - ����: "
			<< num << ", ��ġ:" << (void*)p << endl;
#endif

		return *this;
	}

	size_t size() const {
		return num;
	}

	//Ȯ���� �ڿ��� std::stringó�� �̿��� �� �ְ� ����
	std::string getString() const
	{
		return std::string(p, p + num);
	}

	//STLó�� begin()�� ����� �� �ְ� ����
	iterator begin()
	{
		return iterator{ p };
	}
	iterator end()
	{
		return iterator{ p + num };
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator{ p + num };
	}
	reverse_iterator rend()
	{
		return reverse_iterator{ p };
	}

	bool operator ==(const String& rhs)const
	{
		if (num != rhs.num)
			return false;
		for (int i = 0; i < num; ++i)
			if (p[i] != rhs.p[i])
				return false;
		return true;
	}

private:
	size_t num;							// Ȯ���� �ڿ��� ��
	char* p;							// Ȯ���� �ڿ��� ��ġ

	friend std::ostream& operator<<(std::ostream&, const String&);
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}


