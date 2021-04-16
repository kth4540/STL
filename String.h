//-----------------------------------------------------------------------------
// String.h - STL ���� ������ �����ϱ� ���� ���� �ڿ��� Ȯ���ϴ� Ŭ����
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <random>

using std::cout;
using std::endl;

// #define ����			// �� �ּ��� Ǯ�� special member�� ������ �� �� �ִ�.

std::default_random_engine dre;
std::uniform_int_distribution<> uidAlpha{ 'a', 'z' };

class String {
public:
	String(size_t n): num{ n }, p{ new char[num] } {
		#ifdef ����
			cout << "������(int) (this:" << this << ") - ����: "
				<< num << ", ��ġ:" << (void*)p << endl;
		#endif

		for ( int i = 0; i < num; ++i )
			p[i] = uidAlpha(dre);
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
		if ( this != &other ) {
			this->~String();
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
	String(String&& other) : num{ other.num } {
		p = other.p;
		other.p = nullptr;
		other.num = 0;

		#ifdef ����
			cout << "�̵������� (this:" << this << ") - ����: "
				<< num << ", ��ġ:" << (void*)p << endl;
		#endif
	}

	// �̵��Ҵ翬����
	String& operator=(String&& other) {
		if ( this != &other ) {
			this->~String();
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

private:
	size_t num;							// Ȯ���� �ڿ��� ��
	char* p;							// Ȯ���� �ڿ��� ��ġ

	friend std::ostream& operator<<(std::ostream&, const String&);
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for ( int i = 0; i < s.num; ++i )
		os << s.p[i];
	return os;
}


