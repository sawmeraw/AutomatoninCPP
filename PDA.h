//
// Created by PC on 12/05/2024.
//

#ifndef ASSIGNMENT_2_PDA_H
#define ASSIGNMENT_2_PDA_H

#include <stack>
#include "Automata.h"
using namespace std;

class PDA : public Automata {

public:
    //Enum for the states of the PDA
    enum State { EMPTY, READ_A, READ_B, READ_C, REJECT, ACCEPT };
    //Constructor for the PDA
    PDA(const string& input);
    //Function to check the validity of the input string
    bool isAccepted();

private:
    //Struct to represent the current state of the PDA along with states of the two stacks
    struct PDAState{
        State state; //Current state of the PDA
        std::stack<char> stackAB; //Stack used for transitions involving 'a' and 'b'
        std::stack<char> stackAC; //Stack used for transitions involving 'a' and 'c'
    };
    void transitionA(PDAState& current);
    void transitionB(PDAState& current);
    void transitionC(PDAState& current);
    void configurePDA();
};


#endif //ASSIGNMENT_2_PDA_H
