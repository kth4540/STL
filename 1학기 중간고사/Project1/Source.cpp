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
	string fileName{ "�߰�����.dat"s };
	string a{ "hello" };
	ifstream in{ fileName };
	if (!in)
	{
		cout << fileName << "������ �� �� �����ϴ�" << endl;
		exit(0);
	}
	size_t FileSize = filesystem::file_size(fileName);
	cout << fileName << "�� ũ�� - " << FileSize << "����Ʈ" << endl;
	//2��
	vector<C> v(istream_iterator<C>{in}, {});
	cout << v.size() << endl;

	//3��
	for (auto& k : v)
		k.Change();
	auto k=find_if(v.begin(), v.end(), [](const C& c) {return c.getName() == "Stlcontainer"s; });
	cout << (*k).getID() << " "<<(*k).getName()<<endl;

	//4��
	cout << "id�� �˻��մϴ�" << endl;
	while (true)
	{
		int id;
		cout << "ã������ id�� �Է��ϼ���: ";
		cin >> id;
		if (id < 1 or 3000 < id)
		{
			cout << "��ȿ�� id�� [1-3000]�Դϴ�. " << endl << endl;
			continue;
		}
		sort(v.begin(), v.end(), [](const C& a, const C& b) {return a.getLength() < b.getLength(); });
		auto p = v.begin();
		while (p != v.end())
		{
			p = find_if(p, v.end(), [id](const C& c) {return c.getID() == id; });
			cout << (*p).getName() << endl;
			if (p != v.end())
				++p;
		}
	}
}