/**
* Contains support functions for findWordsMain.cpp to load vector,
*  look for a certain word, and fold a string.
*
* @author Chad Manning
* Course: COMP B12
* Instructor: Hal Mendoza
* Date Created: September 5, 2017
* Source: findWords.cpp
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
* Loads all the lexicon words into a vector.
*
* @param lexiconWords: reference to a vector of strings.
* @param filename: name of text file with lexicon words.
*/
void loadLexicon(vector<string>& lexiconWords, string filename)                {
    ifstream lexiconFile(filename.c_str());
    string lexiconWord;

    while(getline(lexiconFile, lexiconWord)){
        lexiconWords.push_back(lexiconWord);
    }
	lexiconFile.close();

    return;
}

/*
* Determines if a word is in the lexicon vector.
*
* @param word: word the vector is being searched for.
* @param lexiconWords: reference to the vector of lexicon words.
* @return: true if word is in vector and false otherwise.
*/
bool findWord(string word, const vector<string>& lexiconWords){
    for(unsigned int i = 0; i < lexiconWords.size(); ++i)
        if(word == lexiconWords[i])
			return true;
    return false;
}

/**
* Folds string unto itself and returns the folded string to the caller.
*
* @param inString: copy of string from lexicon to be folded.
* @return foldedString: Folded string of word from lexicon.
*/
string foldWord(string inString){
    string foldedString = inString;

    for(unsigned int i = 0, j = 0; i < inString.size(); ++i){
        if(i % 2 == 0){
            foldedString[i] = inString[j];
            ++j;
        } else {
            foldedString[i] = inString[inString.size() - j];
        }
    }

    return foldedString;
}

/**
* Searches lexicon to see if the folded string is an actual word.
*
* @param lexicon: reference to lexicon to compare words.
*/
void lookForFoldedWords(const vector<string>& lexicon){
    for (unsigned int i = 0; i < lexicon.size(); ++i){
        string foldedWord = foldWord(lexicon[i]);

         if(findWord(foldedWord, lexicon))
            cout << lexicon[i] << ":" << foldedWord << endl;
    }

    return;
}
