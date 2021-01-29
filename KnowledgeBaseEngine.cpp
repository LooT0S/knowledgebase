#include "KnowledgeBaseEngine.h"

KnowledgeBaseEngine::KnowledgeBaseEngine()
{

}

KnowledgeBaseEngine::~KnowledgeBaseEngine()
{

}

void KnowledgeBaseEngine::readBase(std::string PATH)
{
	std::string line;
	std::ifstream in(PATH.c_str());
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			ifthen.push_back(line);
		}
	}
	in.close();
}

int KnowledgeBaseEngine::searchFunc(std::string string)
{
	std::string sFlag = " "; // �������� ���� ������ ������������
	int FLAG = 0;	// �������� ���� ���������� ��������

	char* str = _strdup(string.c_str()); // ��������� ������, ��� ��� ���������� ������ ����� ��� const char*, � ��� ������ � strtok ����� ������ char*
	char* tok = std::strtok(str, "IF:THEN;"); // ���������� ����� ������
	std::cout << tok << std::endl; // ������� ������� 

	while (tok != NULL)
	{
		if (*tok == ' ') // ����� ��������� ������� ������������, ������������ ���������� ����� �� ��� ���
		{
			while (1)
			{
				std::cout << '\n' << "Enter yes(y) or no(n)" << std::endl;
				std::cin >> sFlag; // ������ ������ ������������

				// ���� ���� ��� ��������� �� ����������� � ������� � ����� while(1)
				if (sFlag == "yes" || sFlag == "y" || sFlag == "n" || sFlag == "no")
				{
					break;
				}
			}

			// ���������� ��������������� ����� � ����������� �� ������� ������������
			if (sFlag == "yes" || sFlag == "y")
			{
				FLAG = 1;
			}
			else if (sFlag == "no" || sFlag == "n")
			{
				FLAG = -1;
			}

		}
		tok = std::strtok(NULL, "IF:THEN;"); // ��������� ��������� �������

		// �������� ��������������� ����� 
		if (FLAG == 1)
		{
			res.push_back(tok); // ���������� ������ �������� � ����� ��������������� �������
			return 0; // ������ �� �������
		}
	}

}

std::string KnowledgeBaseEngine::nextQuestion()
{
	int sizeIFTHEN = ifthen.size();
	std::string info = ifthen[stepFlag];
	stepFlag++;
	
	if (stepFlag == sizeIFTHEN)
	{
		stepFlag = 0;
	}

	return info;
}

void KnowledgeBaseEngine::engine()
{
	while (counter != ifthen.size())
	{
		searchFunc(nextQuestion());
		++counter;
	}
}

std::string KnowledgeBaseEngine::getResultVector()
{
	std::string result;

	for (auto& iter : res)
	{
		result += iter + " ";
	}
	return result;
}