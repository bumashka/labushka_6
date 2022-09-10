#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Menu() {
	std::cout << "[1] �������� �����\n[2] ������� �����\n[3] ����� �����\n[4] ��������� ������� �� ������\n[5] �������� �������\n[6] ������� ������\n[0] �����\n";
}

int addnumber()
{
	int N; bool trueinput = 0;
	while (!trueinput)
	{
		cout << "\n������� ����� >> ";
		cin >> N;
		if (cin.fail())
		{
			std::cout << "�������� ����!\n";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else trueinput = 1;
	}
	std::cout << "\n";
	return N;
};

string fillFrom() {

	while (true) {

		std::cout << "�������� ������������� :\n[1] ���, ��� �������, ���... [���������� �.�.]\n[2] ��, ��� � ������ ������� [���������� �.�.]\n[3] ��� ��? [������ ������]\n[0] �����\n";
		int number = addnumber();
		switch (number) {
		case 0: {
			return "";
		}
		case 1: {
			std::cout << "++++++ ���, ��� �������, ���... [���������� �.�.] ++++++\n";
			return "����������_1.txt";
		}

		case 2: {
			std::cout << "++++++ ��, ��� � ������ ������� [���������� �.�.] ++++++\n";
			return "����������_2.txt";
		}
		case 3: {
			std::cout << "++++++ ��� ��? [������ ������] ++++++\n";
			return "��� ��.txt";
		}
		default: {
			std::cout << "�������� ����!\n";
			break;
		}
		}
	}

	return "������!\n";
}
void deleteUnwantedCharacters(string& word) {
	string f_element(""", .; :!? ) (\ /...");
	if (word.find_last_of(f_element) != string::npos) {
		word = word.substr(0, word.size() - 1);
	}
}
bool checkInput(string& input) {

	for (int i = 0; i < (int)input.size(); i++) {
		if (input[i] == (char)0xa8 || (input[i] >= (char)0xc0 && input[i] <= (char)0xdf)) {
			if (input[i] == (char)0xa8)input[i] = (char)0xb8;
			else input[i] = input[i] + 32;
		}
		if (input[i] != (char)0xb8 && !(input[i] >= (char)0xe0 && input[i] <= (char)0xff) && input[i] != '-') {
			return false;
		}
	}
	return true;
}

string s_input() {

	bool check = false;
	string s;

	while (!check) {
		cout << "������� ����� >> ";
		cin >> s;
		cin.clear();
		if (s.find_first_not_of("������������������������������������������������������������������-") != string::npos)
		{
			std::cout << "�������� ����!\n";
		}
		else check = true;
	}

	checkInput(s);
	std::cout << "\n";
	return s;
}