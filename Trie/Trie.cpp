#include "Trie.h"


bool Trie::hasChilds(Node* node) {
	bool hasChilds = false;
	int i = 0;
	while (!hasChilds && i < ALPHABET_SIZE) {
		hasChilds = node->symbols[i] != nullptr;
		i++;
	}
	return hasChilds;
}

bool Trie::remove(Node*& node, string word, int h)
{
	if (node == nullptr && word.length() > 0) {
		return false;
	}


	if (word.length() == h) {
		node->eow = false;
		if (hasChilds(node) == false) {
			delete node;
			node = nullptr;
		}
		return true;
	}

	char symbol = word[h];
	int index = symbol - 'a';
	return remove(node->symbols[index], word, h + 1);
}

Trie::Trie()
{
	root = new Node('/');
}

Trie::~Trie()
{
	clear();
	delete root;
}

void Trie::insert(string word) {
	Node* current = root;
	for (int i = 0; i < word.size(); ++i)
	{
		char symbol = word[i];
		int index = symbol - 'a';
		if (current->symbols[index] == nullptr)
		{
			current->symbols[index] = new Node(symbol);
		}

		current = current->symbols[index];
	}
	current->eow = true;
}

bool Trie::find(string word)
{
	Node* current = root;
	for (int i = 0; i < word.size(); ++i)
	{
		char symbol = word[i];
		int index = symbol - 'a';
		if (current->symbols[index] == nullptr) {
			return false;
		}
		current = current->symbols[index];
	}
	return current->eow;
}


bool Trie::remove(string word)
{
	return remove(root, word, 0);
}

void Trie::deleteAll(Node*& node) {
	if (node != nullptr) {
	for (int i = 0; i < ALPHABET_SIZE; i++) {
			deleteAll(node->symbols[i]);
		}
	delete node;
	node = nullptr;
}
}


void Trie::clear()
{
	for (int i = 0; i < ALPHABET_SIZE; i++) {
			deleteAll(root->symbols[i]);
		}

}

void printRecursive(Node* node, string word, int h) {
	if (node != nullptr) {
		if (node->eow) {
			cout << word + node->c << endl;
		}

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			printRecursive(node->symbols[i], word + node->c, h + 1);
		}

	}
}

void Trie::print()
{
	for (int i = 0; i < ALPHABET_SIZE; i++) {

		printRecursive(root->symbols[i], "", 1);
	}
}




void Trie::removeRecursive(Node*& node, string word, int h, string currentString, bool &found) {
	if (node != nullptr) {
		currentString += node->c;        

		if ((word[h] == node->c)) {
			h++;
		}
		else {
			if (h != word.size()) h = 0;
		};

		if (h == word.size()) found = true;	

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			removeRecursive(node->symbols[i], word, h, currentString, found);
		}

		if ((node->eow) && (currentString.find(word) == string::npos)) found = false;

		if (found) {
			if (node->eow) {
				node->eow = false;
			}
			if (hasChilds(node) == false) {
				delete node;
				node = nullptr;
			}
		}
	}
}


void Trie::removeSubString(string str)
{

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		bool found = false;
		removeRecursive(root->symbols[i], str, 0, "", found);

	}
}



void Trie::printInFileRecursive(Node* node, string word, int h, std::fstream& output) {
	if (node != nullptr) {

		if (node->eow) {
			output << word + node->c << endl;
		}

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			printInFileRecursive(node->symbols[i], word + node->c, h + 1, output);
		}

	}
}


void Trie::printInFile(std::string filename) {
	std::fstream fout(filename);


	for (int i = 0; i < ALPHABET_SIZE; i++) {
		printInFileRecursive(root->symbols[i], "", 1, fout);
	}
};



void Trie::inputFromFile(string filename) {
	std::ifstream fin(filename);

	string temp, word;

	while (!fin.eof()) {

		getline(fin, temp);
		size_t index = 0;
		while (temp[index] != '\0')
		{
			if (!(ispunct((temp[index])) || isspace(temp[index])))
			{
				word += temp[index];
			}
			else
			{
				if (word.length() > 0)
				{
					insert(word);
					word = "";
				}
			}
			index++;
		}
		insert(word);
		word = "";
		temp = "";
		cout << "word = " << word << "\n";
	}

	fin.close();
}



