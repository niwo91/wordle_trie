# Wordle_trie

## Background
* This program was created for CSPB 2270 to showcase the "trie" data structure. The program's intent is to help you solve the online game Worlde. Worlde is a game which gives you 6 guesses to guess a 5 letter word. After each incorrect guess, the game will let you know if you have a known letter with a known position or a known letter with an unknown position.
* The program's front end is a command line interface which allows you first put in known letters and their known positions, and then known letters which you don't know the positions of. The program will then print a list of possible words to the screen
* The program uses a trie data structure on the back-end. The trie data structure is a type of tree for searching words. My trie has nodes which contain data about the string the node contains, the string's size and each node's "children."
  * "Children" here is based off the prior node's character(s) in the string. For instance the node with the string "A" has, as children, all two letter strings which start with "A", like "AA", "AB", etc. All one letter words have two letter children, and two letter children have three letter children, and so on and so forth until there are nodes with 5 letter strings. Since each word in wordle is 5 letters exactly, I only need to search the bottom part of the trie for valid words.
  * This structure supports searching the trie quickly. For instance if I want to search the trie for a Word that starts with A and has a third letter of C, I can first search the first children of "A" only, then when I reach the third character I can include strings that only have "C".
  * The root node of the tree has an empty string of "".
  * My trie uses a function to read a dictionary (dictionary.txt in the program) and place each 5 letter word into the trie based off the word's characters.

## Downloading the program
* This program has been tested and runs in the csel JupyterHub environment.
* In order to download the program, click on the green "code" button on the project repository, ensure https is selected, and copy the url to the clipboard. The url should be: https://github.com/niwo91/wordle_trie.git.
* In the csel environment, (or any other compatible linux environment) type `git clone https://github.com/niwo91/wordle_trie.git`, using ctrl+v, and press enter.
* A new folder should be visible called "wordle_trie." Type `cd wordle_trie` and then press enter to enter this folder.
* Compile the program by typing `g++ -0 wordle trie.cpp wordle.cpp` and pressing enter.
* Run the program with `./wordle`

## Using the program
* To use this program, you'll first enter letters with known position. You will enter the letter first, press enter, and then the positon (12345) of the letter in the word. You should enter "!" if there are no more letters with known positions. The program is not case-sensitive and will an error if a letter is not entered.
* Next, you'll enter any letters with unknown positions. You don't need to enter a letter postion here, simply the letter itself. You should enter "!" if there are no more letters with unknown positions.
* Finally, a list of possible word will print to the screen.

## Example Output
```
    --------------------
   |NICK'S WORDLE HELPER|
    --------------------

First, please enter letters with known positions

Enter the letter first, then the position

Please enter a letter(A-Z) with a known position or ! if there's no more letters with known positions: A
Please enter the letter's position (12345): 1

Please enter a letter(A-Z) with a known position or ! if there's no more letters with known positions: B
Please enter the letter's position (12345): 2

Please enter a letter(A-Z) with a known position or ! if there's no more letters with known positions: !

Next, please enter any known letters without known positions 

Enter a known letter with unknown position, or ! if there are no more known letters: u

Enter a known letter with unknown position, or ! if there are no more known letters: !

Your word options are: 
ABDUL
ABRUS
ABUJA
ABUNA
ABUNE
ABUSE
ABUTS
ABUZZ
ABOUT
```

## Possible Future additions
* Including a menu for the program with the option to add your own dictionary
* Including an option for input of letters you know are not in the word


