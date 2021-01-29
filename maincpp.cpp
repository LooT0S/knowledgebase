#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include "KnowledgeBaseEngine.h"


int main(int argc, char* argv[])
{
	KnowledgeBaseEngine kbe;

	std::string PATH_Base = "C:\\Users\\looto\\source\\repos\\knowledgebase\\base.txt";

	kbe.readBase(PATH_Base);
	kbe.searchFunc("IFa ti sosesh: THENJS, Java, C++");
	kbe.searchFunc("IFa ti debil: THENC++");
	kbe.searchFunc("IFÎÎÏ: THENÑ#, Java, C++");

	return 0;
}

