#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <iterator>
#include <vector>
#include <list>
using namespace std;
class C
{
	string name;
	int id;
public:

	friend istream& operator >>(istream& is, C& c)
	{
		is>>c.name>>c.id;
		return is;
	}
	
	string getName()const
	{
		return name;
	}
	int getID()const
	{
		return id;
	}
	size_t getLength() const
	{
		return name.size();
	}
	void Change()
	{
		name[0]=toupper(name[0]);
	}
};
int main()
{
	string fileName{ "중간시험.dat"s };
	string a{ "hello" };
	ifstream in{ fileName };
	if (!in)
	{
		cout << fileName << "파일을 열 수 없습니다" << endl;
		exit(0);
	}
	size_t FileSize = filesystem::file_size(fileName);
	cout << fileName << "의 크기 - " << FileSize << "바이트" << endl;

	//1번
	//변수가 가변이기 때문에 파일 크기로 갯수를 정확히 알 수 없음

	//2번
	vector<C> v(istream_iterator<C>{in}, {});
	cout << v.size() << endl;

	//3번
	for (auto& k : v)
		k.Change();
	auto k = find_if(v.begin(), v.end(), [](const C& c) {return c.getName() == "Stlcontainer"s; });
	if (k != v.end())
		cout << distance(v.begin(), k) +1<< "에서 찾음" << endl;
	else
		cout << "못찾았음" << endl;
	//4번
	cout << "id를 검색합니다" << endl;
	while (true)
	{
		int id;
		cout << "찾으려는 id를 입력하세요: ";
		cin >> id;
		if (id < 1 or 3000 < id)
		{
			cout << "유효한 id는 [1-3000]입니다. " << endl << endl;
			continue;
		}
		vector<C> v2;

		int n = count_if(v.begin(), v.end(), [id, &v2](const C& a) {if (a.getID() == id)
		{
			v2.push_back(a);
			return true;
		}
		else
			return false;
		});
		cout << n << "개의 객체" << endl;

		sort(v2.begin(), v2.end(), [](const C& a, const C& b) {return a.getLength() < b.getLength(); });
		for (auto& k : v2)
			cout << k.getID() << " " << k.getName() << endl;
	}
}