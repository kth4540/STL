#include "save.h"
void save(std::string_view file_name)
{
	// � ������ �����ϴ��� ȭ�鿡 ��� - �����̸��� ũ��
	std::cout << "save: " << file_name << ",size: " << std::filesystem::file_size(file_name) << std::endl;

	std::ofstream out("2021-1 STL tues 5~6, thur 5~6 lecture save.txt", std::ios::app);
	std::ifstream in(file_name);
	int c;
	out << std::endl << std::endl;

	//������ ����� �ð��� ����
	time_t t = time(nullptr);

	out.imbue(std::locale("korean"));

	out << "========================================" << std::endl;
	out << "���� �ð�: " << std::put_time(localtime(&t), "%c %A") << std::endl;
	out << "========================================" << std::endl;


	while ((c = in.get()) != EOF)
		out.put(c);

	//RAII
}