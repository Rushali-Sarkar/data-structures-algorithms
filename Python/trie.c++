#include <iostream>

using namespace std;

struct Trienode {
    char value;
    Trienode* children[26];
};

void initialize(Trienode* node) {

    for (int i = 0; i < 26; i++)
        node -> children[i] = nullptr;
    return;
}

class Trie {

    public:
        
        Trienode* table;

        Trie() {
            table = new Trienode();
            initialize(table);
        }

        void insert(string word) {
            if (word.size() == 0)
                return;
            insert(word, this -> table);
        }

        void insert(string word, Trienode* table) {
            
            if (word.size() == 0)
                return;

            for (int i = 0; i < word.size(); i++) {
                int index = int(word[i]) - 90;
                if (this -> table -> children[index] == nullptr) {
                    Trienode* new_element = new Trienode();
                    new_element -> value = word[i];
                    initialize(new_element);
                    this -> table -> children[index] = new_element;
                }
                insert(word.substr(1, word.size()));
            }
            return;
        }

        void print(Trienode* table) {
            for (int i = 0; i < 26; i++) {
                if (table -> children[i] != nullptr) {
                    cout << table -> children[i] -> value << " ";
                    print(table -> children[i]);
                }
                cout << endl;
            }
            return;
        }
};

int main(int argc, char* argv[]) {

    Trie t;
    t.insert("apple");
    t.print(t.table);
    return 0;
}
