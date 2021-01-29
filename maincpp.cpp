#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include "KnowledgeBaseEngine.h"


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	KnowledgeBaseEngine kbe;

	std::string PATH_Base = "C:\\Users\\looto\\source\\repos\\knowledgebase\\base.txt";

	kbe.readBase(PATH_Base);
	kbe.engine();
	std::cout << kbe.getResultVector() << std::endl;
	

	return 0;
}

