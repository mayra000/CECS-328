//
//  main.cpp
//  CECS328_Project2
//
//  Created by Mayra Sanchez on 10/28/19.
//  Copyright © 2019 Mayra Sanchez. All rights reserved.
//
#include "Operator.h"
#include "parseTree.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <array>


using namespace std;

void makeOpArray(string expArray[], int n);

int main() {
    int userin;
    string aExpression;
    string noSpaces = "";
    bool run = true;
    while (run) {
        cout <<"\n======Menu======\n"
        << "1) Arithmetic Expression\n"
        << "2) Quit" << endl; //done
        cin >> userin;
        switch (userin) {
            case 1:{
                cout << "Insert Arithmetic Expressions: ";
                //cin.ignore();
                getline(cin, aExpression);
                
                /* Getting rid of the spaces in the string */
                for (int i = 0; i < aExpression.length(); i++) {
                    if (aExpression[i] != ' ') {
                        noSpaces += aExpression[i];
                    }
                }
                
                string expArr[noSpaces.length()]; //expression array being created
                int index = 0;
                for (int i = 0; i < noSpaces.length(); i++) {
                    if (noSpaces[i] == '+' || noSpaces[i] == '/' || noSpaces[i] == '*' || noSpaces[i] =='^') {
                        expArr[index] = noSpaces[i];
                        index++; //to keep in mind how many items are added to the array
                    }
                    else if(noSpaces[i] == '-') {
                        expArr[index] = '-';
                        if(isdigit(noSpaces[i - 1])) {
                            index++;
                        }
                    }
                    if (isdigit(noSpaces[i])) {
                        if(expArr[index] != "-")
                            expArr[index] = "";
                        while(isdigit(noSpaces[i]) && i< noSpaces.length()){
                            if(isdigit(noSpaces[i])){
                                expArr[index] += noSpaces[i];
                            }
                            i++;
                        }
                        index++;
                        i--;
                    }
                }
                
                makeOpArray(expArr, index);

                break;
            }
            case 2:
                cout << "Quitting the program. " << endl;
                run = false;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}

void makeOpArray(string expArray[], int n) {
    Operator *opArray[n];
    for (int i = 0; i < n; i++) {
        if(expArray[i] == "+") {
            opArray[i] = new Plus();
        }
        else if (expArray[i] == "-") {
            opArray[i] = new Minus();
        }
        else if (expArray[i] == "*") {
            opArray[i] = new Times();
        }
        else if (expArray[i] == "/") {
            opArray[i] = new Divide();
        }
        else if (expArray[i] == "^") {
            opArray[i] = new Power();
        }
        else {
            opArray[i] = new Integer(expArray[i]);
        }
    }
    
    makePTree(opArray, n);
    
    for (int i = 0; i < n; i ++) {
        delete opArray[i];
    }
}




