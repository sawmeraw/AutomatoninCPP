//
// Created by PC on 12/05/2024.
//


#include "DFA.h"
#include "PDA.h"
#include <iostream>
using namespace std;

void testDFA(){
    cout<< "Testing DFA"<<endl;
    struct {
        char* input;
        bool expected;
    }testCases[] = {
            {"0", false },
            {"1", false },
            {"00", true },
            {"000", true },
            {"01", false },
            {"001", true },
            {"011", false },
            {"0001", true },
            {"00000001", true },
            {"000000011", false },
            {"101111", false },
            {"111111", false },
            {"", false },
            {"end", false }
    } ;

    for (int i=0; testCases[i].input != "end"; i++){
        DFA dfa(testCases[i].input);
        bool result = dfa.isAccepted();
        printf("Test Case %d - Input: %s, Expected: %d, Got: %d - %s\n", i+1, testCases[i].input,
               testCases[i].expected, result, (testCases[i].expected == result) ? "PASSED" : "FAILED");
    }
}

void testPDA(){
    cout<< "Testing PDA"<<endl;
    struct{
        char *input;
        int expected;
    } testCases[] = {
            {"a", 0},
            {"ab", 1},
            {"bc", 0},
            {"ac", 1},
            {"abc", 1},
            {"aabc", 0},
            {"aabbcc", 1},
            {"abbccc", 0},
            {"cccbbb", 0},
            {"aabbccaabbcc", 1},
            {"", 1},
            {"end", 0}
    };

    for (int i=0; testCases[i].input != "end"; i++){
        PDA pda(testCases[i].input);
        int result = pda.isAccepted();
        printf("Test Case %d - Input: %s, Expected: %d, Got: %d - %s\n", i+1, testCases[i].input,
               testCases[i].expected, result, (testCases[i].expected == result) ? "PASSED" : "FAILED");
    }
}

int main(){

    testDFA();
//    cout<<endl;
//    testPDA();
    return 0;
}

