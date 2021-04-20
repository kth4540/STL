#include "save.h"
void save(std::string_view file_name)
{
	// 어떤 파일을 저장하는지 화면에 출력 - 파일이름과 크기
	std::cout << "save: " << file_name << ",size: " << std::filesystem::file_size(file_name) << std::endl;

	std::ofstream out("2021-1 STL tues 5~6, thur 5~6 lecture save.txt", std::ios::app);
	std::ifstream in(file_name);
	int c;
	out << std::endl << std::endl;

	//파일을 기록한 시간도 저장
	time_t t = time(nullptr);

	out.imbue(std::locale("korean"));

	out << "========================================" << std::endl;
	out << "저장 시간: " << std::put_time(localtime(&t), "%c %A") << std::endl;
	out << "========================================" << std::endl;


	while ((c = in.get()) != EOF)
		out.put(c);

	//RAII
}