// 2021. 1�б� STL ȭ78 �� 23 - 3�� 23�� ȭ���� 4�� 1��
//
//STL�� ���θ� ������ �� �ִ� �ڿ��� Ȯ���ϴ� Ŭ������ �����.
//-----------------------------------------------------------

#include<iostream>
#include<random>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
#include<fstream>
#include "save.h"
#include "String.h"
using namespace std;


int main()
{
	//String s1[5]{ 10,5,20,3,7 };

	//for (String& s : s1)
	//	cout << s << endl;
	//
	//sort(begin(s1), end(s1), [](const String& a, const String& b) {return a.size() < b.size(); });
	//cout << "after sort" << endl;

	//for (const String& s : s1)
	//	cout << s << endl;

	/*------------------------------*/

	//String s1{ 1234 };
	//String s2 = s1;
	//String s3 = s1;
	//String s4 = s1;

	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;

	//char* p = new char[300];
	//char* q, * r, * s;
	//q = p;
	//r = p;
	//s = p;
	//delete[]p;
	//delete[]q;
	//delete[]r;
	//delete[]s;

	/*--------------------------*/

	//String s1{ 10 };
	//cout << s1 << endl;

	//String s2{ s1 };
	//cout << s2 << endl;

	//String s3{ 100 };
	//cout << s3 << endl;

	//s3 = s1;
	//cout << s3 << endl;

	/*--------------------------*/

	//String s[10]{10,20,30,40,50,60,70,80,90,100};

	//for (String& s1 : s)
	//	s1.SortClass();

	//sort(begin(s), end(s), [](const String& a, const String& b) {return a.size() > b.size(); });

	//for (String& s1 : s)
	//	cout << s1 << endl;

	/*-----------------------------*/
	//vector<string> v{ istream_iterator<string>{cin},{} };
	////�Է��� �޾Ƽ� v�� �߰�
	//sort(v.begin(), v.end());
	//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));

	//ifstream in{ "source.cpp" };
	//vector<string> v{ istream_iterator<string>{in},{} };
	//-> �Է��� �޾Ƽ� v�� �߰�
	//sort(v.begin(), v.end());
	//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));

	save("source.cpp");
}
