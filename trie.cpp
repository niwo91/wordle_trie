#include "trie.h"

trie_node* new_node (string word) {
	trie_node* ret_node = new trie_node;
	ret_node->word = word;
	ret_node->word_length = word.length();
	return ret_node;
}

trie_node* child_search (trie_node* node, string word) {
	trie_node* ret_node;
	if (node->children.size() == 0) {
		ret_node = new_node(word);
		node->children.push_back(ret_node);
		return ret_node;
	}
	for (int i = 0; i < node->children.size(); i++) {
		if(node->children[i]->word == word) {
			ret_node = node->children[i];
			return ret_node;
		}
	}
	ret_node = new_node(word);
	node->children.push_back(ret_node);
	return ret_node;
}

void insert (string word, trie_node* root) {	
	string search;
	trie_node* node_search = root;
	int i = 0;
	while (search.length() < 5) {
		char x = word[i];
		search = search + x;
		node_search = child_search(node_search, search); 
		i++;
	}
}

string format_line (string input) {
	string output;
	for (int i = 0; i < 5; i++) {
		if (isalpha(input[i])) {
			char x = toupper(input[i]);
			output = output + x;
		}
	}
	return output;
}

void read_dict (string filename, trie_node* root) {
	string line;
	fstream fstrm(filename);
	while(getline (fstrm, line)) {
		if(line.length() == 5) {
			string output = format_line(line);
			if(output.length() == 5) {
				insert(output, root);
			}
		}
	}
	fstrm.close();
}

string get_input_known() {
	cout << "\nFirst, please enter letters with known positions" << endl;
	cout << "\nEnter the letter first, then the position" << endl;
	string ret_str = "aaaaa";
	string chr;
	char c;
	int i;
	bool entering = true;
	while (entering) {
		cout << "\nPlease enter a letter(A-Z) with a known position or ! if there's no more letters with known positions: ";
		cin >> chr;
		// Input Validation
		if (chr.length() != 1) {
			cout << "Invalid input!" << endl;
			continue;
		}
		c = chr[0];
		if (c == '!') {
			break;
		}
		if (!isalpha(c)) {
			cout << "Invalid input!" << endl;
			continue;
		}
		c = toupper(c);

		cout << "Please enter the letter's position (12345): ";
		cin >> i;
		// Input Invalidation
		if (cin.fail()) {
			cin.clear();
			string error;
			cin >> error;
			cout << "Invalid input!" << endl;
			continue;
		}
		if ( i < 1 || i > 5 ) {
			cout << "Invalid input!" << endl;
			continue;
		}


		ret_str[i-1] = c;
	}
	return ret_str;
}


string get_input_unknown() {
	cout << "\nNext, please enter any known letters without known positions " << endl;
	string letters = "";
	string chr;
	char c;
	int i = 0;
	bool entering = true;
	while (entering) {
		cout << "\nEnter a known letter with unknown position, or ! if there are no more known letters: " ;
		cin >> chr;
		// Input Validation
		if (chr.length() != 1) {
			cout << "Invalid input!" << endl;
			continue;
		}
		c = chr[0];
		if (c == '!') {
			break;
		}
		if (!isalpha(c)) {
			cout << "Invalid input!" << endl;
			continue;
		}
		c = toupper(c);
		i++;
		if (i > 5) {
			cout << "You've entered too many letters!" << endl;
			break;
		}
		letters = letters + c;
	}
	return letters;
}

vector<string> possibilities(trie_node* root, string known, string unknown) {
	vector<string> search;
	vector<int> positions;
	for (int i = 0; i < 5; i++) {
		if (known.at(i) != 'a') {
			positions.push_back(i);
		}
	}
	traverse(root, positions, known, search);
	int j = 0;
	if (unknown.size() > 0) {
		while (j < search.size()) {
			string s = search.at(j);
			for (int k = 0; k < unknown.size(); k++) {
				char c = unknown.at(k);
				if (c == s[0] || c == s[1] || c == s[2] || c == s[3] || c == s[4]) {
					j++;
				}
				else {
					search.erase(search.begin() + j);
				}
			}
		}
	}
	cout << "\nYour word options are: " << endl;
	for (int l = 0; l < search.size(); l++) {
		cout << search[l] << endl;
	}
	return search;
}

void traverse(trie_node* root, vector<int> positions, string known, vector<string>& search) {

	if (root->word_length == 5 && known.at(4) == 'a') {
		search.push_back(root->word);
	}
	else if (root->word_length == 5 && known.at(4) != root->word.at(4)) {
		return;
	}
	if (!positions.empty()) {
	for (int i = 0; i < positions.size(); i++) {
		int pos = positions.at(i);
		if (root->word_length - 1 == positions.at(i) && known.at(pos) != root->word.at(pos)) {
			return;
		}
	}
	}
	for (int j = 0; j < root->children.size(); j++) {
		traverse(root->children[j], positions, known, search);
	}
	return;
}
