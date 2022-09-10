#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Menu() {
	std::cout << "[1] ƒобавить слово\n[2] ”далить слово\n[3] Ќайти слово\n[4] ƒополнить словарь из текста\n[5] ќчистить словарь\n[6] ¬ывести данные\n[0] ¬ыход\n";
}

int addnumber()
{
	int N; bool trueinput = 0;
	while (!trueinput)
	{
		cout << "\n¬ведите номер >> ";
		cin >> N;
		if (cin.fail())
		{
			std::cout << "Ќеверный ввод!\n";
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

		std::cout << "¬ыберите стихотворение :\n[1] ѕей, мо€ девочка, пей... [¬ертинский ј.Ќ.]\n[2] “о, что € должен сказать [¬ертиснкий ј.Ќ.]\n[3] √де ты? [ƒуглас ’енсон]\n[0] ¬ыход\n";
		int number = addnumber();
		switch (number) {
		case 0: {
			return "";
		}
		case 1: {
			std::cout << "++++++ ѕей, мо€ девочка, пей... [¬ертинский ј.Ќ.] ++++++\n";
			return "¬ертинский_1.txt";
		}

		case 2: {
			std::cout << "++++++ “о, что € должен сказать [¬ертинский ј.Ќ.] ++++++\n";
			return "¬ертинский_2.txt";
		}
		case 3: {
			std::cout << "++++++ √де ты? [ƒуглас ’енсон] ++++++\n";
			return "√де ты.txt";
		}
		default: {
			std::cout << "Ќеверный ввод!\n";
			break;
		}
		}
	}

	return "ќшибка!\n";
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
		cout << "¬ведите слово >> ";
		cin >> s;
		cin.clear();
		if (s.find_first_not_of("®Є…й÷ц”у к≈еЌн√гЎшўщ«з’хЏъ‘фџы¬вјаѕп–рќоЋлƒд∆жЁэя€„ч—сћм»и“т№ьЅбёю-") != string::npos)
		{
			std::cout << "Ќеверный ввод!\n";
		}
		else check = true;
	}

	checkInput(s);
	std::cout << "\n";
	return s;
}