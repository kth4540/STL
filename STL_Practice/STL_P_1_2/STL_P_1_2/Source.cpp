#include <iostream>
#include <random>
#include <fstream>
#include <numeric>
using namespace std;

int main()
{
	default_random_engine dre;
	uniform_int_distribution<> uid;

	//	ofstream out("1000_int.txt");
	//	for (int i = 0; i < 1000; ++i)
	//		out << uid(dre) << endl;
	//
	//	ifstream in("1000_int.txt");
	//	int n{};
	//	int max{0};
	//	int i{ 0 };
	//	while (in >> n)
	//	{
	//		cout << ++i << "-" << n << endl;
	//		if (max < n)
	//			max = n;
	//	}
	//	cout << "max number: " << max << endl;
	//}

	/*--------------------------------*/
	//[문제] 1000개의 int를 바이너리로 저장 후 출력

	int n[1000];
	iota(begin(n), end(n), 1);

	ofstream out("1000_int_binary", ios::binary);
	out.write((char*)n, sizeof(int) * 1000);

	ifstream in("1000_int_binary", ios::binary);
	in.read((char*)n, sizeof(int)*1000);

	for (int i = 0; i < 1000; ++i)
		cout << n[i] << endl;

}