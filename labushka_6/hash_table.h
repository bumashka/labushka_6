#pragma once

#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#define TABLE_SIZE 2503

using namespace std;

void deleteUnwantedCharacters(string& word);
bool checkInput(string& word);

class hash_table {

private:
	vector<list<string>*> table;
	int number_of_elements;
	int hash(string word);
public:
	hash_table() {
		table.resize(TABLE_SIZE, NULL);
		number_of_elements = 0;
	};
	~hash_table() {
		for (int i = 0; i < (int)table.size(); i++) {
			if (table[i] != NULL) {
				table[i]->clear();
				delete table[i];
			}
		}
		table.clear();
	};
	void clear();
	void fill_from_book(string filename);
	string erase(string word);
	string insert(string word);
	string find(string word);
	void printInformation() {
	std::cout << "--- Хэш-таблица ---\n";
		std::cout << "--- Количество элементов: " << number_of_elements << " ---\n\n";
		for (int i = 0; i < (int)table.size(); i++) {
			if (table[i] != NULL) {
				for (string b : *table[i]) {
					std::cout <<"--- " << b << "\n";
				}
			}
		}
	}
};

