//
// Created by PC on 12/05/2024.
//

#include "Automata.h"
#include <vector>
#include <string>

using namespace std;

//Constructor sets the accepted flag to false
Automata::Automata() : accepted(false){}

//Add a new state to the list of states of the automata
void Automata::addState(const string& state){
    states.push_back(state);
}

//Set the accepted alphabets of the automata
void Automata::setAlphabet(const vector<char>& inputAlphabet){
    alphabet = inputAlphabet;
}

