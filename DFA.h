//
// Created by PC on 12/05/2024.
//

#ifndef ASSIGNMENT_2_DFA_H
#define ASSIGNMENT_2_DFA_H
#include "Automata.h"
#include <string>
#include <map>
#include <vector>
using namespace std;


class DFA : public Automata {
private:
    string currentState; //Current state of the DFA
    string startState; //Start state of the DFA

    map<pair<string, char>, string> transitionMap; //Map to store the transitions on specific input
    vector<string> finalStates; //List of final states of the DFA

public:
    DFA(const string& input);
    bool isAccepted();

private:
    void addTransition(const string& from, char input, const string& to);
    void setStartState(const string& state);
    void setFinalState(const string& state);
    void reset();
    void configureDFA();
};


#endif //ASSIGNMENT_2_DFA_H
