//
// Created by PC on 12/05/2024.
//

#ifndef ASSIGNMENT_2_AUTOMATA_H
#define ASSIGNMENT_2_AUTOMATA_H

#include <string>
#include <vector>
using namespace std;

//Base class for all automata
class Automata {

protected:
    string inputString; //String to be processed
    vector<string> states; //List of states
    vector<char> alphabet; //Valid character to be set for the automata
    bool accepted; //Flag to check if the input string is accepted

public:
    Automata();
    void addState(const string& state);
    void setAlphabet(const vector<char>& inputAlphabet);
};


#endif //ASSIGNMENT_2_AUTOMATA_H
