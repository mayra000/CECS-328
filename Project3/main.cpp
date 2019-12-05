////
////  main.cpp
////  CECS328_P3
////
////  Created by Mayra Sanchez on 11/18/19.
////  Copyright © 2019 Mayra Sanchez. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <sstream>
//#include "heap.h"
//using namespace std;
//
//int MAX = 1000;
//int MIN = -1000;
//
//int commaArray[0];
//
//
//int main() {
//    bool running = true;
//    int userin;
//    int count = 0;
//    string intString;
//    //stringstream ss(intString);
//    //queue
//
//    while (running){
//        cout << "\n-----Menu-----\n"
//        << "1) Min Heap\n" //should be done
//        << "2) Build and Min Heap\n" //done
//        << "3) Insert Single Element into the heap\n"
//        << "4) Pop Element from the heap\n"
//        << "5) Heap Sort\n"
//        << "6) Random Array\n"
//        << "7) Quit the program\n" << endl; //done
//
//        cin >> userin;
//        switch(userin)
//        {
//            // 1. Allow the user to create an empty min heap
//            case 1:
//            {
//                cout << "Creating an empty Min Heap" << endl;
//                build_minHeap(0, 0);
//                cout << "Empty Min Heap created. " << endl;
//                break;
//            }
//
//            // 2. Allow the user to input a comma-separated list of integers, and use the
//            //    build heap() operation to create a min heap with the given intergers.
//            //    Display the heap to the user as an array
//            case 2:
//            {
//                cout << "Enter a comma separated list of integers" << endl;
//                cin.ignore();
//                getline(cin, intString);
//
//                string noSpaces;
//                int numCommas = 1;
//                for (int i = 0; i < intString.length(); i++){
//                    if (intString[i] == ',') {
//                        numCommas++;
//                    }
//                    if (intString[i] != ' ') {
//                        noSpaces += intString[i];
//                    }
//                }
//                //cout << noSpaces; //testing
//                stringstream ss(noSpaces);
//
//                string temp;
//                int x = 0;
//                int intArray[numCommas];
//
//                while (getline(ss, temp, ',')) {
//                    intArray[x] = stoi(temp);
//                    x++;
//                }
//                //printing for testing
////                for (int i = 0; i < numCommas; i++) {
////                    cout << intArray[i] << " ";
////                }
//                int n = sizeof(intArray) / sizeof(intArray[0]);
//                //cout << n << endl;
//
//                //buildHeap(intArray, n);
//                build_minHeap(intArray, numCommas);
//                /*Printing minheap */
//                cout << "Min Heap: " ;
//                for (int i = 0; i <= numCommas; i++){
//                    if (intArray[i] != 0)
//                        cout<< intArray[i]<< " ";
//                }
//
//                //printHeap(intArray, n);
//
//                break;
//            }
//
//            // 3. Allow the user to insert a single element into the heap reated in either
//            //    Option 1 or 2. Display the resulting heap.
//            case 3:
//                cout << "Insert single element into heap created in either Option 1 or 2" << endl;
//                cout << "Please enter your option: " ;
//                int opt;
//                cin >> opt;
//                if (opt == 1){
//
//                }
//                else if (opt == 2){
//
//                }
//                else{
//                    cout << "That was not a valid option" << endl;
//                }
//                break;
//
//            // 4. Allow the user to pop an element from the heap created in either Option 1   or 2. Display the resulting heap.
//            case 4:
//                cout << "Pop a single element from the heap created in either Option 1 or 2" << endl;
//                cout << "Please enter your option: " ;
//                int opt_pop;
//                cin >> opt_pop;
//                if (opt_pop == 1){
//
//                }
//                else if (opt_pop == 2){
//
//                }
//                else{
//                    cout << "That was not a valid option" << endl;
//                }
//                break;
//
//            // 5. Display the integers in the heap in sorted order by using the heapsort()    operation.
//            case 5:
//                cout << "Displaying Heap in sorted order using heap sort()" << endl;
//                break;
//
//            // 6. Allow the user to provide a length n so that the computer may generate a random array a of length n, where a[i] is an assigned integer selected uniformly at random from the interval [-1000,1000], for all i = 0,...,n-1. The program then first sorts a with heapsort(), followed by sorting a with a standard libary sorting algorithm. Display the elasped running time (in milliseconds if less than 1 sec, in seconds if at least one second) of each algorithm).
//            case 6:{
//                // Step 1: Allow the user to provide a length n so that the computer may generate a random array a of length n.
//
//                // 1. Declare variable n for "Length" of array
//                // 2. Declare array variable a to store random array with the amount of length.
//                int n = 0;
//                int a[n];
//
//                // Ask the user for the lenggth
//                cout << "Enter an integer n: ";
//
//                // Store the users value into n
//                cin >> n;
//
//                // Size of the Array
//                int sizeOfArray = *(&a + 1) - a;
//
//                // Step 2: Generate values from [-1000,1000] to store into the array a.
//                srand((unsigned)time(0));
//                for (int i = 0; i < n; i++)
//                {
//                    // Common set up to use "range" for random.
//                    // MAX = 1000 (Global Variable)
//                    // MIN = -1000 (Global Variable)
//                    a[i] = MIN + rand() % ((MAX + 1) - MIN);
//
//                    // Display the generated random value
//                    cout << a[i] << endl;
//                }
//
//                // Step 3: Utilize heapsort() to sort the array a
//                //         Utilize standard library sorting algorithm to sort the array a
//                //         (Your choice)
//
//
//                // Step 4: Display the elasped running time in milliseconds of each
//                //         algorithm
//
//
////                // Testing Purposes to Print out Array
////                cout << "Array: " ;
////                for (int i = 0; i < sizeOfArray; i++)
////                {
////                        cout<<a[i]<< " ";
////                }
////                break;
//
//            // 7. Quit the program
//            }
//            case 7:
//                cout << "Ending the program" << endl;
//                running = false;
//                break;
//            default:
//                cout << "That was not a valid option. Please try again." << endl;
//                break;
//        }
//    }
//    return 0;
//}
//
//int * makeCommaArray() {
//
//    return commaArray;
//}
