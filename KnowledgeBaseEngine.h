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
	int stepFlag = 0;
	int counter = 0;

public:
	KnowledgeBaseEngine();
	~KnowledgeBaseEngine();
	/*
		serachFunc - ������� ��������� �������� ������ �� �������
									� ����� ������� ������� � ����������� �������� �� ������� ������������,
									���� �������� - ������������ ������ yes | y, ����� ���� ������� ��������� �������
									�������� � ��������� �� � ����� �������
	*/
	int searchFunc(std::string string);
	void readBase(std::string PATH);
	void engine();
	std::string nextQuestion();
	std::string getResultVector();
};

