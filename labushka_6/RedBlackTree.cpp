#include "RedBlackTree.h"

void RedBlackTree::leftRotate(Node* node) {
	Node* tmp = node->right;
	node->right = tmp->left;
	if (node->right != NULL) {
		node->right->parent = node;
		node->right->isLeftChild = false;
	}
	//if we're the root node
	if (node->parent == NULL) {
		m_root = tmp;
		tmp->parent = NULL;
	}
	//if we're no a root node!
	else {
		tmp->parent = node->parent;
		if (node->isLeftChild) {
			tmp->isLeftChild = true;
			tmp->parent->left = tmp;
		}
		else {
			tmp->isLeftChild = false;
			tmp->parent->right = tmp;
		}
	}
	tmp->left = node;
	node->isLeftChild = true;
	node->parent = tmp;
}
void RedBlackTree::clear(Node* node) {
	if (node == NULL)return;

	if (node->left)clear(node->left);

	if (node->right)clear(node->right);

	if (node != m_root)delete node;
	else m_root = NULL;
}
void RedBlackTree::rightRotate(Node* node) {
	Node* tmp = node->left;
	node->left = tmp->right;
	if (node->left != NULL) {
		node->left->parent = node;
		node->left->isLeftChild = true;
	}
	//if we're the root node
	if (node->parent == NULL) {
		m_root = tmp;
		tmp->parent = NULL;
	}
	//if we're no a root node!
	else {
		tmp->parent = node->parent;
		if (node->isLeftChild) {
			tmp->isLeftChild = true;
			tmp->parent->left = tmp;
		}
		else {
			tmp->isLeftChild = false;
			tmp->parent->right = tmp;
		}
	}
	tmp->right = node;
	node->isLeftChild = false;
	node->parent = tmp;
}

bool RedBlackTree::contains(string word, Node* node) {
	if (node == NULL)return false;
	if (node->value == word)return true;
	if (node->value < word) return contains(word, node->right);
	else return contains(word, node->left);
}
void RedBlackTree::add(Node* parent, Node* newNode) {

	if (newNode->value > parent->value) {
		if (parent->right == NULL) {
			parent->right = newNode;
			newNode->parent = parent;
			newNode->isLeftChild = false;
			newNode->black = false;
			checkColor(newNode);
			return;
		}
		else return add(parent->right, newNode);
	}
	else {
		if (parent->left == NULL) {
			parent->left = newNode;
			newNode->parent = parent;
			newNode->isLeftChild = true;
			newNode->black = false;
			checkColor(newNode);
			return;
		}
		else return add(parent->left, newNode);
	}
}
void RedBlackTree::checkColor(Node* node) {

	if (node == m_root) {
		if (!node->black)node->black = true;
		return;
	}
	//if node is red and parent is red == two consecutive red nodes!
	if (!node->black && !node->parent->black) correctTree(node);
	if (node->parent)checkColor(node->parent);
}

void RedBlackTree::correctTree(Node* problem_node) {
	//aunt is node->parent->parent->right!
	if (problem_node->parent->isLeftChild) {
		//if aunt is not null or black!
		if (problem_node->parent->parent->right == NULL ||
			problem_node->parent->parent->right->black) {
			return rotate(problem_node);
		}
		if (problem_node->parent->parent->right != NULL) {
			//aunt is red! do colorFlip!
			problem_node->parent->parent->right->black = true;
			problem_node->parent->parent->black = false;
			problem_node->parent->black = true;
			return;
		}
	}
	else {
		//aunt is node->parent-parent->left!
		if (problem_node->parent->parent->left == NULL ||
			problem_node->parent->parent->left->black) {
			return rotate(problem_node);
		}
		if (problem_node->parent->parent->left != NULL) {
			problem_node->parent->parent->left->black = true;
			problem_node->parent->parent->black = false;
			problem_node->parent->black = true;
			return;
		}
	}
}
void RedBlackTree::rotate(Node* node) {
	if (node->isLeftChild) {
		if (node->parent->isLeftChild) {
			rightRotate(node->parent->parent);
			node->black = false;
			node->parent->black = true;
			if (node->parent->right != NULL) {
				node->parent->right->black = false;
			}
			return;
		}
		rightLeftRotate(node->parent->parent);
		node->black = true;
		node->right->black = false;
		node->left->black = false;
		return;
	}
	else {
		if (!node->parent->isLeftChild) {
			leftRotate(node->parent->parent);
			//after left rotate
			node->black = false;
			node->parent->black = true;
			if (node->parent->left != NULL) {
				node->parent->left->black = false;
			}
			return;
		}
		leftRightRotate(node->parent->parent);
		node->black = true;
		node->right->black = false;
		node->left->black = false;
		return;
	}
}

void RedBlackTree::checkDoubleBlack(Node* doubleBlack) {
	if (doubleBlack == m_root)
		// Reached root
		return;

	Node* sib = sibling(doubleBlack), * parent = doubleBlack->parent;

	if (sib == NULL) {
		// No sibiling, double black pushed up
		checkDoubleBlack(parent);
	}

	else {
		if (!sib->black) {
			// Sibling red

			parent->black = false;
			sib->black = true;

			if (sib->isLeftChild) {
				// left case
				rightRotate(parent);
			}
			else {
				// right case
				leftRotate(parent);
			}
			checkDoubleBlack(doubleBlack);
		}
		else {
			// Sibling black
			if ((sib->left != NULL && !sib->left->black) ||
				(sib->right != NULL && !sib->right->black)) {
				// at least 1 red children
				if (sib->left != NULL && !sib->left->black) {
					if (sib->isLeftChild) {
						// left left
						// CHECK THE COLORS!!!
						sib->left->black = sib->black;
						sib->black = parent->black;
						rightRotate(parent);
					}
					else {
						// right left
						//CHECK THE COLORS
						sib->left->black = parent->black;
						rightRotate(sib);
						leftRotate(parent);
					}
				}
				else {
					if (sib->isLeftChild) {
						// left right
						sib->right->black = parent->black;
						leftRotate(sib);
						rightRotate(parent);
					}
					else {
						// right right
						sib->right->black = sib->black;
						sib->black = parent->black;
						leftRotate(parent);
					}
				}
				parent->black = true;
			}
			else {
				// 2 black children
				sib->black = false;
				if (parent->black)
					checkDoubleBlack(parent);
				else
					parent->black = true;
			}
		}
	}
}
void RedBlackTree::deleteNode(Node* node) {

	Node* replace = BSTreplace(node);

	// True when replace and node are both black
	bool bothBlack = ((replace == NULL || replace->black) && (node->black));

	//Node* parent = node->parent;

	//when node ia a leaf!
	if (replace == NULL) {
		// replace is NULL therefore node is leaf
		if (node == m_root) {
			// node is root, making root null
			m_root = NULL;
		}
		else {
			if (bothBlack) {
				// replace and node both black
				// node is leaf, fix double black at v
				checkDoubleBlack(node);
			}
			else {
				// if replace or node is red
				if (sibling(node) != NULL)
					// sibling is not null, make it red"
					sibling(node)->black = false;
			}

			// delete node from the tree
			if (node->isLeftChild) {
				node->parent->left = NULL;
			}
			else {
				node->parent->right = NULL;
			}
		}
		delete node;
		m_size--;
		return;
	}
	//NODE ia not a leaf!!!
	if (node->left == NULL || node->right == NULL) {
		// node has 1 child
		if (node == m_root) {
			// node is root, assign the value of replace to node, and delete replace
			node->value = replace->value;
			node->left = node->right = NULL;
			node->isLeftChild = false;
			delete replace;
		}
		else {//if node is not a root!
			// Detach node from tree and move replace up
			if (node->isLeftChild) {
				node->parent->left = replace;
				replace->isLeftChild = true;
			}
			else {
				node->parent->right = replace;
				replace->isLeftChild = false;
			}
			replace->parent = node->parent;
			delete node;
			if (bothBlack) {
				// u and v both black, fix double black at u
				checkDoubleBlack(replace);
			}
			else {
				// u or v red, color u black
				replace->black = true;
			}
		}
		m_size--;
		return;
	}

	// node has 2 children, swap values with successor and recurse
	string val = replace->value;
	replace->value = node->value;
	node->value = val;

	deleteNode(replace);

};

RedBlackTree::Node* RedBlackTree::BSTreplace(Node* node) {
	// when node have 2 children
	if (node->left != NULL and node->right != NULL)
		return successor(node->right);

	// when leaf
	if (node->left == NULL and node->right == NULL)
		return NULL;

	// when single child
	if (node->left != NULL)
		return node->left;
	else
		return node->right;
};

RedBlackTree::Node* RedBlackTree::sibling(Node* node) {
	// sibling null if no parent
	if (node->parent == NULL)
		return NULL;
	//if node is a left child then it's sibling is a right child;
	if (node->isLeftChild)
		return node->parent->right;
	//else if node is right child then it's sibling is a left child;
	return node->parent->left;
};

RedBlackTree::Node* RedBlackTree::successor(Node* node) {
	Node* temp = node;

	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}
RedBlackTree::Node* RedBlackTree::find(string word) {
	if (!contains(word, m_root)) return NULL;
	Node* tmp = m_root;

	while (tmp->value != word) {
		if (tmp->value < word) {
			tmp = tmp->right;
		}
		else if (tmp->value > word) {
			tmp = tmp->left;
		}
	}
	return tmp;
}
