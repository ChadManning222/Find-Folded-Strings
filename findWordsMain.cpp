/**
* Creates a vector of strings from the lexicon then folds every word
*  to see if the folded word is also in the lexicon.
*
* @author Chad Manning
* Course: COMP B12
* Instructor: Hal Mendoza
* Date Created: September 5, 2017
* Source: findWordsMain.cpp
*/
#include <iostream>
#include <vector>
#include <string>
#define NAEBL "North American Enhanced Benchmark Lexicon.txt"
using namespace std;

void loadLexicon(vector<string>& lexicon, string filename = NAEBL);
void lookForFoldedWords(const vector<string>& lexicon);

int main(int argc, char *argv[]) {
    vector<string> lexiconWords;

    if(argc > 1){
    	loadLexicon(lexiconWords, argv[1]);
	} else {
		loadLexicon(lexiconWords);
	}

	lookForFoldedWords(lexiconWords);

    return 0;
}
