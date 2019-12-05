//
//  main.cpp
//  CECS328_P4
//
//  Created by Mayra Sanchez on 11/23/19.
//  Copyright © 2019 Mayra Sanchez. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

#include "functions.h"

using namespace std;
using namespace std::chrono; //needed to get the running times of the algorithms

int main() {
    bool running = true; //keeps the loop running
    int menuOption, n, k, n1, m, binaryInt;
    string binaryString, intString;
    
    while(running) {
        cout << "\n----Menu----\n"
        << "1) K-Bit Binary Representation\n" //done
        << "2) Interpret Decimal Value of String\n" //done
        << "3) Radix and QuickSort \n" //done
        << "4) Generate Random Array\n" //done
        << "5) Quit Program" << endl; //done
        cin >> menuOption;
        
        switch(menuOption){
            case 1:
                cout << "Please input a non-negative number (n): ";
                cin >> n;
                
                cout << "Please enter a number to represent the number to represent the number of bit places (k): ";
                cin >> k;
                
                cout << "Kth bit set number = ";
                cout << KBit(n,k) << endl; //kBit function made to get the k-bit binary represenatation
                
                
                break;
            case 2:
                cout << "Please input a string of 1s and 0s to be interpreted as a binary number: " << endl;
                cin >> binaryInt; //gets binary numbers
                cout << "Decimal Value of " << binaryInt << " is : " << BinaryToDec(binaryInt) << endl; //conversion occurs here
                break;
            case 3:{
                cout << "Enter a comma separated list of integers" << endl;
                cin.ignore();
                getline(cin, intString);
                
                /*Getting rid of the commas and making the array of integers*/
                string noSpaces;
                int numCommas = 1;
                for (int i = 0; i < intString.length(); i++){
                    if (intString[i] == ',') {
                        numCommas++; //counting the amount of commas
                    }
                    if (intString[i] != ' ') {
                        noSpaces += intString[i];
                    }
                }
                //cout << noSpaces; //testing
                stringstream ss(noSpaces);
                
                string temp;
                int x = 0;
                int intArray[numCommas];
                //array made here 
                while (getline(ss, temp, ',')) {
                    intArray[x] = stoi(temp);
                    x++;
                }
                //printing for testing
//                for (int i = 0; i < numCommas; i++) {
//                    cout << intArray[i] << " ";
//                }
                
                radixSort(intArray, (numCommas - 1));
                cout << "Radix Sort: ";
                printArray(intArray, numCommas - 1);//print the arrays
                quickSort(intArray, 0, (numCommas - 1));
                cout << "QuickSort: ";
                printArray(intArray, numCommas - 1);//print the arrays
                
                break;
            }
            case 4:{
                cout << "Please enter a positive integer (n): ";
                cin >> n1;
                
                cout << "Please enter another positive integer (m): ";
                cin >> m;
                
                srand(time(0));
                int randArray[n1];
                
                for (int i = 0; i < n1; i++) {
                    int r = rand() % m;
                    randArray[i] = r;
                }
                
                
                auto start = high_resolution_clock::now(); //start time
                radixSort(randArray, n1);
                auto stop = high_resolution_clock::now(); //end time

                auto duration = duration_cast<microseconds>(stop - start);
                
                if (n <= 100){
                    cout << "Radix Sorted Array: ";
                    printArray(randArray, n1);//print the arrays
                }
                
                srand(time(0));
                int randArray2[n1];
                
                for (int i = 0; i < n1; i++) {
                    int r = rand() % m;
                    randArray2[i] = r;
                }
                    
                
                auto start1 = high_resolution_clock::now(); //start time
                quickSort(randArray2, 0, n1);
                auto stop1 = high_resolution_clock::now(); //end time

                auto duration1 = duration_cast<microseconds>(stop1 - start1);
                
                if (n <= 100){
                    cout << "QuickSort array: " ;
                    printArray(randArray2, n1);//print the arrays
                }
                /* Printing out running times of the different algorithms*/
                cout << "Running time for Radix Sort: " << duration.count()<< " milliseconds." <<  endl;
                cout << "Running time for QuickSort: " << duration1.count() << " milliseconds." << endl;
                break;
            }
            case 5: //ending the program by exiting the loop
                cout << "Quitting the program. \nThank you for participating" << endl;
                running = false;
                break;
            default:
                cout << "That was not a valid option. Please try again." << endl;
                break;
        }
    }
    return 0;
}
