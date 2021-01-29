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
	std::string sFlag = " "; // Обнуляем флаг ответа пользователя
	int FLAG = 0;	// Обнуляем флаг добавления результа

	char* str = _strdup(string.c_str()); // дублируем строку, так как изначально строка имеет вид const char*, а для работы с strtok нужна строка char*
	char* tok = std::strtok(str, "IF:THEN;"); // производим поиск лексем
	std::cout << tok << std::endl; // выводим условие 

	while (tok != NULL)
	{
		if (*tok == ' ') // когда выведенно условие пользователю, пользователя спрашивают нужно ли ему это
		{
			while (1)
			{
				std::cout << '\n' << "Enter yes(y) or no(n)" << std::endl;
				std::cin >> sFlag; // запись ответа пользователя

				// если ввод был коректным он сохраняется и выходит с цикла while(1)
				if (sFlag == "yes" || sFlag == "y" || sFlag == "n" || sFlag == "no")
				{
					break;
				}
			}

			// установака результирующего флага в зависимости от ответов пользователя
			if (sFlag == "yes" || sFlag == "y")
			{
				FLAG = 1;
			}
			else if (sFlag == "no" || sFlag == "n")
			{
				FLAG = -1;
			}

		}
		tok = std::strtok(NULL, "IF:THEN;"); // получение следующей лексемы

		// проверка результирующего флага 
		if (FLAG == 1)
		{
			res.push_back(tok); // добавления данных действия в конец результирующего вектора
			return 0; // выходи из функции
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