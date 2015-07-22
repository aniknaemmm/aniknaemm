#include <iostream>
#include <string>
#include <fstream>

bool chekStartComment(std::string buff, size_t pos,size_t point);

int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");

	std::ofstream fout("edittxt.cpp");
	std::ifstream fin("txt.cpp");

	if (!fout)
	{
		std::cerr << "The file can not be opened or created";
		return 1;
	}
	if (!fin)
	{
		std::cerr << "The file can not found";
		return 1;
	}

	std::string buf;
	std::size_t foundStart, foundEnd, pointer;

	while (!fin.eof())
	{
		std::getline(fin, buf);//Get line

		foundStart = buf.find("/*");
		if (buf.find("//") < foundStart)//if // before /*
			foundStart = std::string::npos;

		foundEnd = std::string::npos;
		pointer = 0;// pointer to start position for copy

		while (foundStart != std::string::npos)
		{
			if (chekStartComment(buf, foundStart,pointer))// chek he is comment>?
			{
				fout << buf.substr(pointer, foundStart - pointer);
				std::cout << buf.substr(pointer, foundStart - pointer);

				foundEnd = buf.find("*/", foundStart);

				while (foundEnd == std::string::npos)//is not found */ in buff
				{
					std::getline(fin, buf);//load next line
					foundEnd = buf.find("*/");
				}

				pointer = foundEnd + 2;//add two symbols */
			}
			foundStart = buf.find("/*", foundEnd);
		}

		if (foundEnd == std::string::npos)//if no /*
			foundStart = buf.find("//");
		else
			foundStart = buf.find("//", foundEnd);

		while (!chekStartComment(buf, foundStart,pointer) && foundStart != std::string::npos)//chek comment //
			foundStart = buf.find("//", foundStart + 1);

		if (foundStart != std::string::npos)//if found //
		{
			fout << buf.substr(pointer, foundStart - pointer);
			std::cout << buf.substr(pointer, foundStart - pointer);
		}
		else
		{
			fout << buf.substr(pointer);
			std::cout << buf.substr(pointer);
		}

		fout << std::endl;
		std::cout << std::endl;


	}

	fout.close();

	fin.close();

	getc(stdin);
	return 0;
}


bool chekStartComment(std::string buff, size_t pos,size_t point)
{
	std::size_t foundNext, foundfirst = buff.find('"',point);//found first "
	while (foundfirst != std::string::npos)
	{
		foundNext = buff.find('"', foundfirst + 2);//found next "
		if (foundfirst == std::string::npos && foundNext == std::string::npos)//if not found first or second
			return false;
		if (foundfirst < pos && foundNext > pos)//pos Input Range " "
			return false;
		foundfirst = buff.find('"', foundNext + 1);//found first
	}
	return true;
}
