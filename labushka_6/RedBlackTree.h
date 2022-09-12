#pragma once

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void deleteUnwantedCharacters(string& word);
bool checkInput(string& word);

class RedBlackTree {
	struct Node {
		string value;
		Node* parent, * right, * left;
		bool isLeftChild, black;
		Node(string value) :value(value), parent(NULL), right(NULL), left(NULL), isLeftChild(false), black(false) {};
		void printNode() {
			std::cout << "+++ Значение узла << " << value << " >> +++\n";
			if (!black) std::cout << "+++ КРАСНЫЙ\n";
			else cout << "+++ ЧЁРНЫЙ\n";
			//if (root == m_root)std::cout << "+++ Kорень\n";
			if (isLeftChild)std::cout << "+++ Левый ребёнок\n";
			else std::cout << "+++ Правый ребёнок\n";

			if (left)std::cout << "+++ Есть левый ребёнок << " << this->left->value << " >>\n";
			if (right)std::cout << "+++ Есть правый ребёнок << " << this->right->value << " >>\n";
			std::cout << "\n";
		}
	};

	Node* m_root;
	int m_size;

	Node* successor(Node* node);
	Node* BSTreplace(Node* node);
	//Node* find(string word);
	Node* sibling(Node* node);
	void checkDoubleBlack(Node* doubleBlack);
	void deleteNode(Node* node);
	void leftRotate(Node* node);
	void rightRotate(Node* node);
	void leftRightRotate(Node* node) {
		leftRotate(node->left);
		rightRotate(node);
	}
	void rightLeftRotate(Node* node) {
		rightRotate(node->right);
		leftRotate(node);
	}
	void rotate(Node* node);
	void correctTree(Node* problem_node);
	void checkColor(Node* node);
	void add(Node* parent, Node* newNode);
	Node* contains(string word, Node* node);
	void clear(Node* node);
public:
	RedBlackTree() {
		m_root = NULL;
		m_size = 0;
	};
	~RedBlackTree() {
		clear(m_root);
		delete m_root;
	}

	void clear() {
		if (m_root == NULL) {
			std::cout << "Словарь пуст!\n";
			return;
		}
		clear(m_root);
		m_size = 0;
		std::cout << "Словарь был очищен!\n";
	}
	string erase(string word) {
		string message;
		Node* node = contains(word,m_root);
		if (node==NULL) {
			message = "Слово << " + word + " >> не может быть удалено, потому что оно отсутствует в словаре!\n";
			return message;
		}
		deleteNode(node);
		message = "Слово << " + word + " >> было удалено!\n";
		return message;
	}
	string add(string word) {

		string message;

		if (contains(word, m_root)!=NULL) {
			message = "Слово << " + word + " >> не может быть добавлено, потому что оно уже присутствует в словаре!\n";
			return message;
		}

		Node* node = new Node(word);

		message = "Слово << " + word + " >> было добавлено в словарь!\n";

		if (m_root == NULL) {
			m_root = node;
			m_root->black = true;
			m_size++;
			return message;
		}
		add(m_root, node);
		m_size++;
		return message;
	}
	string contains(string word) {
		string message;
		if (contains(word, m_root)!=NULL) {
			message = "Слово << " + word + " >> содержиться в словаре!\n";
			return message;
		}
		message = "Слово << " + word + " >> отсутствует!\n";
		return message;
	}
	void pre_order_print(Node* root) {
		if (root == NULL)return;
		root->printNode();
		pre_order_print(root->left);
		pre_order_print(root->right);
	}
	void printInformation() {
		int number = 0;
		std::cout << " --- Pre-Order Traversal ---\n";
		if (m_root != NULL) std::cout << " --- Корень дерева << " << m_root->value << " >> --- \n";
		else {
			std::cout << "Дерево пустое!\n"; return;
		}
		std::cout << " --- Размер дерева " << m_size << " --- \n\n";
		pre_order_print(m_root);

	}
	void fill_from_book(string filename) {

		string line;
		ifstream file(filename);
		while (getline(file, line))
		{
			istringstream input(line);
			string word;
			while (input >> word) {
				deleteUnwantedCharacters(word);
				checkInput(word);
				add(word);
			}
		}
		file.close();
		//printInformation();
	}

};


