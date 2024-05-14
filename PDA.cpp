//
// Created by PC on 12/05/2024.
//

#include <queue>
#include "PDA.h"

//Sets the input string and configures the PDA
PDA::PDA(const string& input){
    if(input.empty()){
        inputString = "";
    } else{
        inputString = input;
    }
    configurePDA();
}

//Transition function to handle the character 'a'
void PDA::transitionA(PDAState &current) {
    current.stackAB.push('a'); //Push 'a' to the stackAB for any future 'b' transitions
    current.stackAC.push('a'); //Push 'a' to the stackAC for any future 'c' transitions
    current.state = READ_A; //Change the state to READ_A indicating 'a' is being read
}

//Transition function to handle the character 'b'
void PDA::transitionB(PDAState &current) {
    if (!current.stackAB.empty() && current.stackAB.top() == 'a') {
        current.stackAB.pop(); //Pop 'a' from the stackAB if it is present
        if(current.stackAB.empty()){
            current.state = ACCEPT; //If the stack is empty, change the state to ACCEPT
        } else{
            current.state = READ_B; //If the stack is not empty, change the state to READ_B indicating 'b' is being read
        }
    } else {
        current.stackAB.push('b'); //Push 'b' to the stackAB if 'a' is not present
        current.state = REJECT; //Change the state to REJECT
    }
}

//Transition function to handle the character 'c'
void PDA::transitionC(PDAState &current) {
    if (!current.stackAC.empty() && current.stackAC.top() == 'a') {
        current.stackAC.pop(); //Pop 'a' from the stackAC if it is present
        if(current.stackAC.empty()){
            current.state = ACCEPT; //If the stack is empty, change the state to ACCEPT
        } else{
            current.state = READ_C; //If the stack is not empty, change the state to READ_C indicating 'c' is being read
        }
    } else {
        current.stackAC.push('c'); //Push 'c' to the stackAC if 'a' is not present
        current.state = REJECT; //Change the state to REJECT
    }
}

bool PDA::isAccepted() {
    //If the input string is empty, return true which accepts the string
    if(inputString == ""){
        accepted = true;
        return true;
    }
    accepted = false;
    //Queue to store the current state of the PDA
    queue<PDAState> states;
    //Initialize the PDA with empty state and empty stacks
    states.push({EMPTY, {}, {}});

    for (char ch : inputString) {

        size_t currentLevelSize = states.size(); //Get the current size of the queue

        for(size_t i = 0; i< currentLevelSize; i++){
            PDAState current = states.front(); //Current state gets updated to the front state of the queue
            states.pop(); //Pop the front state of the queue to update the queue with the new state
            switch(ch){
                case 'a':
                    transitionA(current); //Call the transition function for 'a'
                    break;
                case 'b':
                    transitionB(current); //Call the transition function for 'b'
                    break;
                case 'c':
                    transitionC(current); //Call the transition function for 'c'
                    break;
                default:
                    accepted = false;
                    current.state = REJECT; //Change the state to REJECT if the character is not in the alphabet
                    return false;
            }
            if(current.state !=REJECT){
                states.push(current); //Push the updated state to the queue only if the state is not REJECT
            }
        }
    }

    //Check if the final state is ACCEPT
    while(!states.empty()){
        PDAState finalState = states.front();
        states.pop();
        if (finalState.state == ACCEPT){
            accepted = true;
            return true;
        }
    }
    accepted = false;
    return false;
}

//Configures the PDA with states and valid alphabet
void PDA::configurePDA(){
    //Add the states to the PDA
    addState("EMPTY");
    addState("READ_A");
    addState("READ_B");
    addState("READ_C");
    addState("REJECT");
    addState("ACCEPT");
    //Set the alphabets accepted by the PDA
    setAlphabet({'a', 'b', 'c'});
}
