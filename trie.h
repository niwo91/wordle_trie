#ifndef trie_H
#define trie_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

// Trie node data structure 
struct trie_node {
	string word;
	int word_length; 
	vector<trie_node*> children;
};

// Initiate a trie node
trie_node* new_node(string word); 

// Searches the children list for a specific word 
// Creates it if it's not there
trie_node* child_search(trie_node* node, string word);

// Inserts a word into the tree
void insert(string word, trie_node* root);

// Formats a line, removes punctuation, returns word in all caps
string format_line(string input);

// Reads a dictionary "filename", 
// Returns all words of length five and puts into a trie
void read_dict(string filename, trie_node* root);

// Gets input of known letter positions
// Returns formatted string
string get_input_known();

// Takes input of "endless_possibilities"'s output
// Returns vector of possible words
string get_input_unknown ();

// Searches trie, creates a list of possible words
// Takes known and unknown input;
vector<string> possibilities(trie_node* root, string known, string unknown);

// Helper function for possibilities
void traverse(trie_node* root, vector<int> positions, string known, vector<string>& search);
#endif
