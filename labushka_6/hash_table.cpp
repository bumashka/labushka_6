#include "hash_table.h"

int hash_table::hash(string word) {
	int g = 31;
	int hash = 0;
	for (int i = 0; i < (int)word.size(); i++) {
		hash = hash * g + word[i];
	}
	return hash;
};

string hash_table::erase(string word) {

	string message;

	int index = (hash(word) & 0x7fffffff) % TABLE_SIZE;

	if (table[index] != NULL)
	{
		auto it = std::find(table[index]->begin(), table[index]->end(), word);
		if (it != table[index]->end()) {
			table[index]->erase(it);
			number_of_elements--;
			message = "Слово << " + word + " >> было удалено!\n";
			return message;
		}
	}
	message = "Слово << " + word + " >> не может быть удалено, потому что оно отсутствует в словаре!\n";
	return message;
};
void hash_table::clear() {

	for (int i = 0; i < (int)table.size(); i++) {
		if (table[i] != NULL) {
			table[i]->clear();
			table[i] = NULL;
		}
	}
	number_of_elements = 0;
	std::cout << "Словарь был очищен!\n";
};
string hash_table::insert(string word) {

	int hashval = hash(word);
	hashval = hashval & 0x7fffffff;
	int index = hashval % TABLE_SIZE;
	if (table[index] != NULL) {

		auto it = std::find(table[index]->begin(), table[index]->end(), word);
		if (it != table[index]->end()) {
			string message = "Слово << " + word + " >> не может быть добавлено, потому что оно уже присутствует в словаре!\n";
			return message;
		}
		table[index]->push_back(word);
	}
	else {
		table[index] = new list<string>;
		table[index]->push_back(word);
	}
	number_of_elements++;
	string message = "Слово << " + word + " >> было добавлено в словарь!\n";
	return message;
};
string hash_table::find(string word) {

	int index = (hash(word) & 0x7fffffff) % TABLE_SIZE;

	string message;

	if (table[index] != NULL)
	{
		auto it = std::find(table[index]->begin(), table[index]->end(), word);
		if (it != table[index]->end()) {
			message = "Слово << " + word + " >> содержиться в словаре!\n";
			return message;
		}
	}

	message = "Слово << " + word + " >> отсутствует!\n";

	return message;

};
void hash_table::fill_from_book(string filename) {

	string line;
	ifstream file(filename);
	while (getline(file, line))
	{
		istringstream input(line);
		string word;
		while (input >> word) {
			deleteUnwantedCharacters(word);
			checkInput(word);
			insert(word);
		}
	}
	file.close();
	//printInformation();
};