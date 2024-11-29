#include <iostream>
#include <vector>

struct Node {
public:
	int key;
	Node* right;
	Node* left;
	Node(int k) : key(k), right(nullptr), left(nullptr) {};
};

class Tree {
public:
	Tree() : root(nullptr) {};

	void insert(int key) {
		if (!root) {
			root = new Node(key);
		}
		else {
			insertNode_(root, key);
		}
	}

	void leftPreOrderTraversal(std::vector<int>& keys) {
		leftPreOrderTraversal_(root, keys);
	}
	void rightPreOrderTraversal(std::vector<int>& keys) {
		rightPreOrderTraversal_(root, keys);
	}
	void leftPostOrderTraversal(std::vector<int>& keys) {
		leftPostOrderTraversal_(root, keys);
	}
	void rightPostOrderTraversal(std::vector<int>& keys) {
		rightPostOrderTraversal_(root, keys);
	}
	void leftInOrderTraversal(std::vector<int>& keys) {
		leftInOrderTraversal_(root, keys);
	}
	void rightInOrderTraversal(std::vector<int>& keys) {
		rightInOrderTraversal_(root, keys);
	}

private:
	Node* root;
	void insertNode_(Node* node, int key) {
		if (key < node->key) {
			if (node->left) {
				insertNode_(node->left, key);
			}
			else {
				node->left = new Node(key);
			}
		}
		else if (key > node->key) {
			if (node->right) {
				insertNode_(node->right, key);
			}
			else {
				node->right = new Node(key);
			}
		}
	}

	void leftPreOrderTraversal_(Node* node, std::vector<int>&result) {
		if (node) {
			result.push_back(node->key);
			leftPreOrderTraversal_(node->left, result);
			leftPreOrderTraversal_(node->right, result);
		}
	}

	void rightPreOrderTraversal_(Node* node, std::vector<int>& result) {
		if (node) {
			result.push_back(node->key);
			rightPreOrderTraversal_(node->right, result);
			rightPreOrderTraversal_(node->left, result);
		}
	}

	void leftPostOrderTraversal_(Node* node, std::vector<int>& result) {
		if (node) {
			leftPostOrderTraversal_(node->left, result);
			leftPostOrderTraversal_(node->right, result);
			result.push_back(node->key);
		}
	}

	void rightPostOrderTraversal_(Node* node, std::vector<int>& result) {
		if (node) {
			rightPostOrderTraversal_(node->right, result);
			rightPostOrderTraversal_(node->left, result);
			result.push_back(node->key);
		}
	}

	void leftInOrderTraversal_(Node* node, std::vector<int>& result) {
		if (node) {
			leftInOrderTraversal_(node->left, result);
			result.push_back(node->key);
			leftInOrderTraversal_(node->right, result);
		}
	}

	void rightInOrderTraversal_(Node* node, std::vector<int>& result) {
		if (node) {
			rightInOrderTraversal_(node->right, result);
			result.push_back(node->key);
			rightInOrderTraversal_(node->left, result);
		}
	}
};


int main() {
	int root, numOfNodes, key;
	std::cout << "enter number of nodes in tree\n";
	std::cin >> numOfNodes;
	std::cout << "enter keys of nodes\n";
	std::cin >> root;
	Tree tree;
	tree.insert(root);


	for (int i = 0; i < numOfNodes - 1; ++i) {
		std::cin >> key;
		tree.insert(key);
	}

	std::cout << "\nLeft Pre Order Traversal:\n";
	std::vector<int>resultOfPreOrderTraversal;
	tree.leftPreOrderTraversal(resultOfPreOrderTraversal);
	for (auto& r : resultOfPreOrderTraversal) {
		std::cout << r << " ";
	}	

	std::cout << "\nRight Post Order Traversal:\n";
	std::vector<int>resultOfPostOrderTraversal;
	tree.rightPostOrderTraversal(resultOfPostOrderTraversal);
	for (auto& r : resultOfPostOrderTraversal) {
		std::cout << r << " ";
	}

	std::cout << "\nLeft In Order Traversal:\n";
	std::vector<int>resultOfInOrderTraversal;
	tree.leftInOrderTraversal(resultOfInOrderTraversal);
	for (auto& r : resultOfInOrderTraversal) {
		std::cout << r << " ";
	}
}