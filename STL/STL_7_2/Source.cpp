//-----------------------------------
//������ x86 release ���� compile �Ѵ�
//2021 1�б� STL ȭ(5~6) ��(5~6) 4�� 15�� ����� 7�� 2����
//
//����� �� ���� �ҽ������� �����Ѵ�.
//-----------------------------------
#include "save.h"
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
using namespace std;


void print(const list<int>& cont)
{
	for (int n : cont)
		cout << n << " ";
	cout << endl;
}

int main()
{
	//[����]"source.cpp"������ ����Ʈ�� ����� ���� �� �Ųٷ� ���
	//���Ͽ� �ҹ��ڴ� ��������� ���
	//ifstream in("source.cpp");
	//list<char> lt(istream_iterator<string>{in}, {});

	//copy(lt.cbegin(), lt.cend(), ostream_iterator<char>{cout});
	//cout << endl;

	//cout<<count_if(lt.cbegin(), lt.cend(), [](char c) {return islower(c); })<<endl;
	//

	//[����]���Ͽ� using �̶�� �ܾ �ִٸ� �� ��° �ִ��� ���
	
	//list<string> lt(istream_iterator<string>{in}, {});

	//auto p = find(lt.cbegin(), lt.cend(), "using"s);
	//if (p != lt.end())
	//{
	//	cout << distance(lt.cbegin(), p)+1 << "��°" << endl;
	//}
	//else
	//	cout << "failed" << endl;

	/*----------------------------------------------------*/

	//[��������] "source.cpp"�� �ִ� �ܾ ������ ����϶�

	//list<int> con1{5,7,3,1,9 };
	//list<int> con2{ 4,8,6,10,2 };

	////[����] con1�� con2�� �ִ� ������ con3�� merge�϶�

	//list<int>con3;
	//con3.merge(con1);
	//con3.merge(con2);
	////merge() -> ������ ���� ��� �� �κ��� �����, �׷��� ������ �ܼ� ����, ���� �����ʹ� ����

	//print(con1);
	//print(con2);
	//print(con3);

	/*-------------------------------*/
	list<int> con{ 1,3,5,7,7,7,7,7,9,2,4,7,6,8,10 };
	//con.sort([](int a, int b) {return a > b; });
	print(con);

	con.unique();	//-> �������� �ߺ��� ���� �� �ϳ��� ����� ������ ����
	print(con);
	save("source.cpp");
}