//
// Created by PC on 12/05/2024.
//

#include "DFA.h"
#include <iostream>
using namespace std;
DFA::DFA(const string& input){
    if(input.empty()){
        inputString = "";
    } else{
        inputString = input;
    }
    configureDFA();
}

//Add a transition from one state to another on a given input
void DFA::addTransition(const string& from, char input, const string& to){
    transitionMap[{from, input}] = to;
}

//Set the start state and current state to the given state
void DFA::setStartState(const string& state){
    startState = state;
    currentState = state;
}

//Add final state to the list of final states
void DFA::setFinalState(const string& state){
    finalStates.push_back(state);
}

//Reset the current state to the start state
void DFA::reset(){
    currentState = startState;
    accepted = false;
}

void DFA::configureDFA(){
    //Define the states and transitions for the DFA
    transitionMap.clear();
    addState("START");
    addState("ONE_ZERO");
    addState("ONE_ONE");
    addState("ONE_ZERO_ONE_ONE");
    addState("ACCEPT");
    addState("MULTIPLE_ZERO");
    addState("ACCEPT_PLUS_ONE");
    addState("REJECT");


    setAlphabet({'0', '1'});

    addTransition("START", '0', "ONE_ZERO");
    addTransition("START", '1', "ONE_ONE");
    addTransition("ONE_ZERO", '0', "ACCEPT");
    addTransition("ONE_ZERO", '1', "ONE_ZERO_ONE_ONE");
    addTransition("ONE_ONE", '0', "ONE_ZERO_ONE_ONE");
    addTransition("ONE_ONE", '1', "REJECT");
    addTransition("ACCEPT", '0',"MULTIPLE_ZERO");
    addTransition("ACCEPT", '1',"ACCEPT_PLUS_ONE");
    addTransition("ONE_ZERO_ONE_ONE", '0', "ACCEPT_PLUS_ONE");
    addTransition("ONE_ZERO_ONE_ONE", '1', "REJECT");
    addTransition("ACCEPT_PLUS_ONE", '0', "ACCEPT_PLUS_ONE");
    addTransition("ACCEPT_PLUS_ONE", '1', "REJECT");
    addTransition("MULTIPLE_ZERO", '0', "MULTIPLE_ZERO");
    addTransition("MULTIPLE_ZERO", '1', "ACCEPT_PLUS_ONE");
    addTransition("REJECT", '0', "REJECT");
    addTransition("REJECT", '1', "REJECT");

    // Define the initial and final states
    setStartState("START");
    setFinalState("ACCEPT");
    setFinalState("ACCEPT_PLUS_ONE");
    setFinalState("MULTIPLE_ZERO");
}
bool DFA::isAccepted(){
    //Set the current state to the start state
    reset();
    //Iterate over the input string and update the current state based on the transition map
    for(char c : inputString){
        if (transitionMap.find({currentState, c}) != transitionMap.end()){
            currentState = transitionMap[{currentState, c}];
        } else{
            accepted = false;
            return false;
        }
    }
    //Check if the state is a final state

    for(const string& state : finalStates){
        if(currentState == state){
            accepted = true;
            return true;
        }
    }
    accepted = false;
    return false;
}

