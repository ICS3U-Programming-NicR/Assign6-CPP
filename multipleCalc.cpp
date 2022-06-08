// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on:April 25 2022
// This program figures out the area of a triangle

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <list>

using std::cin;
using std::cout;
using std::stof;
using std::stoi;
using std::list;
using std::string;

list<string> splitBySpace(string splitSpace) {
    list<string> listWords;
    string word = "";

    // goes through each letters in the splitLists
    for (char letters : splitSpace) {
        // when it reaches a space it will put the word into the list
        if (letters == ' ') {
            listWords.push_back(word);
            word = "";
        } else {
            word += letters;
        }
    }
    // Pushes the final word into the list because there probably wont be a
    // space after it
    listWords.push_back(word);
    word = "";
    return listWords;
}

string palindromCheck(string sentence) {
    for (int i = 0; i < sentence.length() / 2; i++) {

            // If S[i] is not equal to
            // the S[N-i-1]
            if (sentence[i] != sentence[sentence.length() - i - 1]) {
                // Return No
                return " not";
            }
        }
        // Return "Yes"
        return "";
}

string commonElementsCheck(string listOfChar1, string listOfChar2) {
    list<string> listOfChar1Split = splitBySpace(listOfChar1);
    list<string> listOfChar2Split = splitBySpace(listOfChar2);
    string commonElements;

    for (string tempword : listOfChar1Split) {
        for (string tempword2 : listOfChar2Split) {
            if (tempword == tempword2) {
                commonElements += tempword + " ";
            }
        }
    }
    return commonElements;
}

string pigLatinConvert (string response) {
    char consonant[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n','p', 'q', 'r','s', 't', 'w', 'y', 'v', 'x', 'z', '\0'};

char vowel[] = {'a', 'e', 'i', 'o', 'u', '\0'};

//Taking user input

string pigLatin; // creates a variable called response to hold a string
list<string> sentenceArray;
string yay = "yay ";
string ay = "ay";
string space = " ";

sentenceArray = splitBySpace(response);
int counter = 0;
for (string word : sentenceArray) {
//Convert input to lower case
    for (int i=0;i<word.length();i++){

        word[i]=tolower(word[i]);

    }
    //check to see if first letters is a vowel

    for (int i=0;i<5;i++){

      if (word[0] == vowel[i]){
            word = word + yay;
            break;

          }

      }
    // creating new array to hold consonant pig latin answer

    int length = word.length() - 1;


    char new_response[length];
    // check to see if first letters is a consonant

    for (int i=0;i<21;i++){

      if (word[0]==consonant[i]){

            int new_response_index = 0;

            for (int x=1;x<word.length();x++){

                new_response[new_response_index]=word[x];

                new_response_index++;

                }

            new_response[length]='\0';
            char tempChar = word[0];
            word.erase(0, 1);
            word = word + tempChar + ay + space;
            break;

          }
    }
    pigLatin = pigLatin + word;
    }
    return pigLatin;
}

int main() {
    // try again loop
    bool tryAgain = true;
    do {
        string garbage, calc, uSentence, answer = "", pigLatinU = "", stringList1U = "", stringList2U = "";
        try {
            cout << "What would you like to calculate(P = checking if a string is a Palindrome/PL = converts your string into pig latin/CE = Checks for the common elements in two lists): ";
            getline(cin, calc, '\n');
            transform(calc.begin(), calc.end(), calc.begin(), ::toupper);
            if (calc == "P" || calc == "PALINDROME") {
                cout << "What is the string you want me to check: \n";
                cin >> uSentence;
                answer = palindromCheck(uSentence);
                cout << "The string you entered is" << answer << " a palindrome\n";
            } else if (calc == "PL" || calc == "PIGLATIN") {
                cout << "What is the string you would want to convert: \n";
                getline(cin, pigLatinU);
                while (pigLatinU == "") {
                    cout << "It looks like you didn't input anything please try again\n";
                    cout << "What would you like to convert to pig latin: \n";
                    getline(cin, pigLatinU);
                }
                answer = pigLatinConvert(pigLatinU);
                cout << "your string in pig latin is: \n" << answer;
                cout << "\nIf you would like to calculate again just press <enter>: ";
                if (cin.get() == '\n') {
                    continue;
                } else if (cin.get() != '\n') {
                    cin >> garbage;
                    continue;
                }
            } else if (calc == "CE" || calc == "COMMON ELEMENTS") {
                cout << "Enter the first array of characters: \n";
                getline(cin, stringList1U);
                while (stringList1U == "") {
                    cout << "It looks like you didn't input anything please try again\n";
                    cout << "What would you like your first array to be: \n";
                    getline(cin, stringList1U);
                }
                cout << "Enter the second array of characters: \n";
                getline(cin, stringList2U);
                while (stringList2U == "") {
                    cout << "It looks like you didn't input anything please try again\n";
                    cout << "What would you like your second array to be: \n";
                    getline(cin, stringList2U);
                }
                answer = commonElementsCheck(stringList1U, stringList2U);
                if (answer != "") {
                    cout << "The common elements in these two lists are: \n" << answer << "\n";
                } else {
                    cout << "There are no common elements in these two lists\n";
                }
                cout << "\nIf you would like to calculate again just press <enter>: ";
                if (cin.get() == '\n') {
                    continue;
                } else if (cin.get() != '\n') {
                    cin >> garbage;
                    continue;
                }
            } else {
                cout << "You have to input a valid answer\n";
                continue;
            }
        } catch (...) {
            cout << "You have to input valid values\n";
        }
        cin.get();
        cout << "\nIf you would like to calculate again just press <enter>: ";
        if (cin.get() == '\n') {
            continue;
        } else if (cin.get() != '\n') {
            cin >> garbage;
            continue;
        }
    } while (tryAgain == true);
}
