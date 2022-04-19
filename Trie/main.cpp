#include <string>;
#include <iostream>
#include "Trie.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    Trie* trie = new Trie();

    cout << "\t\tTrie Tree\n" << '\n';

    cout << "1  -  Insert word\n" << '\n';

    cout << "2  -  Remove word" << '\n';
    cout << "3  -  Remove SubString" << '\n';
    cout << "4  -  Find word" << '\n';
    cout << "5  -  Print\n" << '\n';

    cout << "6  -  Clear\n" << '\n';

    cout << "7  -  Test words" << '\n';
    cout << "8  -  Test substring\n" << '\n';

    cout << "0  -  Exit" << '\n';


    cout << "Enter command: ";
    int command;
    cin >> command;
    while (command != 0) {
        switch (command) {
        case 1:
        {
            string str;
            cin >> str;
            trie->insert(str);
        }
        break;

        case 2:
        {
            string str;
            cin >> str;
            if (trie->remove(str)) cout << "Word has been deleted.\n";
            else cout << "Error\n";
        }
        break;

        case 3:
        {
            string str;
            cout << "Enter string: ";
            cin >> str;
            trie->removeSubString(str);
        }
        break;

        case 4:
        {
            string str;
            cin >> str;
            if (trie->find(str)) cout << "Word found\n";
        }
        break;

        case 5:
        {
            trie->print();
            cout << "\n";
        }
        break;

        case 6:
        {
            trie->clear();
            cout << "\n";
        }
        break;

        case 7:
        {
            trie->insert("programming");
            trie->insert("amm");
            trie->insert("amb");
            trie->insert("ammm");
            trie->insert("am");
            trie->insert("dpmas");
            trie->insert("b");
            trie->insert("p");
            trie->insert("dcfam");
            trie->insert("dpmams");
            cout << "Test\n";
        }
        break;

        case 8:
        {
            cout << "am\n";
            trie->removeSubString("am");
        }
        break;

        default:
            std::cout << "Wrong number\n";
            break;

        }

        cout << "\nEnter command: ";
        std::cin >> command;
    }

    return 0;
}