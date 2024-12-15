#include "trie.h"

int main() {
	cout << "    --------------------" << endl;
	cout << "   |NICK'S WORDLE HELPER|" << endl;
	cout << "    --------------------" << endl;
	trie_node* root = new_node ("");
	string file = "dictionary.txt";
	read_dict(file, root);
	string known = get_input_known();
	string unknown = get_input_unknown();
	vector<string> words;
	words = possibilities(root, known, unknown);
	return 0;

}
