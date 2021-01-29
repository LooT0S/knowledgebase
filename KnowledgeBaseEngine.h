#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class KnowledgeBaseEngine
{
private:
	std::vector<std::string> res;
	std::vector<std::string> ifthen;

public:
	KnowledgeBaseEngine();
	~KnowledgeBaseEngine();
	/*
		serachFunc - функция разбивает входящую строку на лексемы
									и затем выводит условие и запрашивает подходит ли условие пользователю,
									если подходит - пользователь вводит yes | y, после чего функция извлекает даннные
									действия и вставляет их в конец вектора
	*/
	int searchFunc(std::string string);
	void readBase(std::string PATH);
	void engine();
	std::string nextQuestion();
};

