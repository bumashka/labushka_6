/***********************************************************************************************
*
* Теория графов
* Булдакова Мария Алексеевна, 3530201/00001
*
* Лабораторная работа %6
*
1.Для выбранного текста на русском языке построить словарь на основе красно-черных деревьев. Реализовать функции добавления, удаления или поиска слова.
(НЕЛЬЗЯ использовать готовые структуры данных!!!). Добавить функцию полной очистки словаря и дополнения словаря из текстового файла.
*
2.Реализовать структуру данных - хеш-таблицу, для которой характерны операции: добавления, удаления и поиска.
На ее основе реализовать приложение - словарь. В качестве хеш-функции, можно выбрать произвольную функцию, например, брать первую букву слова.
*
3.Для выбранного текста на русском языке построить словарь на основе B+-деревьев. Реализовать функции добавления, удаления или поиска слова.
(НЕЛЬЗЯ использовать готовые структуры данных!!!). Добавить функцию полной очистки словаря и дополнения словаря из текстового файла.
*
4.Минимальная реализация включает либо пункты 1 и 2, либо пункт 2 и 3. Улучшенная реализация - все три пункта.
Максимальная реализация также включает возможность оптимизации словаря (например, поиск потенциальных однокоренных слов в разных формах;
самый простой критерий - 2/3 длины слова). Выбор слов, которые следует оставить в словаре - за пользователем.  Использовать готовые решения из библиотеки STL не разрешается.
************************************************************************************************/
#include "windows.h"
#include <stdlib.h>  
#include <crtdbg.h>       //for malloc and free


#define _CRTDBG_MAP_ALLOC //to get more details

#include "RedBlackTree.h"
#include "hash_table.h"
//#include "menu.h"

void deleteUnwantedCharacters(string& word);
bool checkInput(string& word);
int addnumber();
void Menu();
string s_input();
string fillFrom();

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//setlocale(LC_ALL, "Russian");
	std::cout << "++++++ Лабораторная работа№6 ++++++\n\n";

	RedBlackTree tree;

	bool tables = false;

	int number;

	while (!tables) {
		std::cout << "Выберите структуру данных:\n[1]Хэш-таблица\n[2]Красно-чёрное деревья\n[0]Выход\n";
		number = addnumber();
		switch (number) {

		case 1: {
			bool hash_b = false;
			hash_table hash;
			while (!hash_b) {
				std::cout << "\n+++++Хэш-таблица+++++\n";
				Menu();
				number = addnumber();
				switch (number) {
				case 0: {
					hash_b = true;
					break;
				}
				case 1: {
					string input = s_input();
					std::cout << hash.insert(input);
					break;
				}
				case 2: {
					//std::cout << " [2] Удалить слово\n";
					string input = s_input();
					std::cout << hash.erase(input);
					break;
				}
				case 3: {
					//std::cout << " [3] Найти слово\n";
					string input = s_input();
					std::cout << hash.find(input);
					break;
				}
				case 4: {
					//std::cout << " [4] Дополнить словарь с помощью текста\n";
					hash.fill_from_book(fillFrom());
					break;
				}
				case 5: {
					//std::cout << " [5] Очистить словарь\n";
					hash.clear();
					break;
				}
				case 6: {
					hash.printInformation();
					break;
				}
				default: {
					std::cout << "Неверный ввод!\n";
					break;
				}
				}
			}
			break;
		}

		case 2: {
			bool rbt_b = false;
			RedBlackTree tree;
			while (!rbt_b) {
				std::cout << "\n+++++Красно-чёрное дерево+++++\n";
				Menu();
				number = addnumber();
				switch (number) {
				case 0: {
					rbt_b = true;
					break;
				}
				case 1: {
					string input = s_input();
					std::cout << tree.add(input);
					break;
				}
				case 2: {
					string input = s_input();
					std::cout << tree.erase(input);
					break;
				}
				case 3: {
					string input = s_input();
					std::cout << tree.contains(input);
					break;
				}
				case 4: {
					tree.fill_from_book(fillFrom());
					break;
				}
				case 5: {
					tree.clear();
					break;
				}
				case 6: {
					tree.printInformation();
					break;
				}
				default: {
					std::cout << "Неверный ввод!\n";
					break;
				}
				}
			}
			break;
		}

		case 0: {
			tables = true;
			break;
		}

		default: {
			std::cout << "Неверный ввод!\n";
			break;
		}
		}
	}


	/*_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld); //take a snapshot



	_CrtMemCheckpoint(&sNew); //take a snapshot

	if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
	{
		OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
		_CrtMemDumpStatistics(&sDiff);
		OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
		_CrtMemDumpAllObjectsSince(&sOld);
		OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
		_CrtDumpMemoryLeaks();
	}
	*/
	return 0;
}