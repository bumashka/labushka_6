/***********************************************************************************************
*
* ������ ������
* ��������� ����� ����������, 3530201/00001
*
* ������������ ������ %6
*
1.��� ���������� ������ �� ������� ����� ��������� ������� �� ������ ������-������ ��������. ����������� ������� ����������, �������� ��� ������ �����.
(������ ������������ ������� ��������� ������!!!). �������� ������� ������ ������� ������� � ���������� ������� �� ���������� �����.
*
2.����������� ��������� ������ - ���-�������, ��� ������� ���������� ��������: ����������, �������� � ������.
�� �� ������ ����������� ���������� - �������. � �������� ���-�������, ����� ������� ������������ �������, ��������, ����� ������ ����� �����.
*
3.��� ���������� ������ �� ������� ����� ��������� ������� �� ������ B+-��������. ����������� ������� ����������, �������� ��� ������ �����.
(������ ������������ ������� ��������� ������!!!). �������� ������� ������ ������� ������� � ���������� ������� �� ���������� �����.
*
4.����������� ���������� �������� ���� ������ 1 � 2, ���� ����� 2 � 3. ���������� ���������� - ��� ��� ������.
������������ ���������� ����� �������� ����������� ����������� ������� (��������, ����� ������������� ������������ ���� � ������ ������;
����� ������� �������� - 2/3 ����� �����). ����� ����, ������� ������� �������� � ������� - �� �������������.  ������������ ������� ������� �� ���������� STL �� �����������.
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
	std::cout << "++++++ ������������ ������6 ++++++\n\n";

	RedBlackTree tree;

	bool tables = false;

	int number;

	while (!tables) {
		std::cout << "�������� ��������� ������:\n[1]���-�������\n[2]������-������ �������\n[0]�����\n";
		number = addnumber();
		switch (number) {

		case 1: {
			bool hash_b = false;
			hash_table hash;
			while (!hash_b) {
				std::cout << "\n+++++���-�������+++++\n";
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
					//std::cout << " [2] ������� �����\n";
					string input = s_input();
					std::cout << hash.erase(input);
					break;
				}
				case 3: {
					//std::cout << " [3] ����� �����\n";
					string input = s_input();
					std::cout << hash.find(input);
					break;
				}
				case 4: {
					//std::cout << " [4] ��������� ������� � ������� ������\n";
					hash.fill_from_book(fillFrom());
					break;
				}
				case 5: {
					//std::cout << " [5] �������� �������\n";
					hash.clear();
					break;
				}
				case 6: {
					hash.printInformation();
					break;
				}
				default: {
					std::cout << "�������� ����!\n";
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
				std::cout << "\n+++++������-������ ������+++++\n";
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
					std::cout << "�������� ����!\n";
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
			std::cout << "�������� ����!\n";
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