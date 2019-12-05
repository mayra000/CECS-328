//
//  functions.h
//  CECS328_P4
//
//  Created by Mayra Sanchez on 11/23/19.
//  Copyright © 2019 Mayra Sanchez. All rights reserved.
//
\
#ifndef functions_h
#define functions_h

#include <string>
#include <sstream>

using namespace std;

/*Predefining the function names to avoid compiling errors*/
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
int partition(int arr[] , int left, int right);

/*Used in case 1*/
int KBit(int n, int k) {
    return ((1 << k) | n);
}

/*Used in case 2*/
int BinaryToDec(int n) {
    int binNum = n;
    //int binNum = stoi(n); //converting string to int
    int decNum = 0; //setting starting value
    
    int base = 1;
    int temp = binNum;
    
    while (temp) {
        int lastNum = temp % 10; //getting modulo of 10
        temp /= 10;
        decNum += lastNum * base;
        
        base *= 2;
    }
    return decNum;
}

/* Used in case 3 and 4*/
void radixSort(int arr[], int n) {
    int mx;
    mx = getMax(arr, n);
    
    for (int exp = 1; mx/exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

/*Used in case 3 and 4*/
void quickSort(int arr[], int left, int right) {
    if (left < right ) {
        int piv = partition(arr, left, right);
        
        quickSort(arr, left, piv + 1);
        quickSort(arr, piv + 1, right);
        
    }
}

/*
 Getting the max number in the array in order to conduct the radix code
 */
int getMax(int arr[], int n){
    int maxNum = 0;
    /* If number is greater than maxNum then the maxNum is replaced with that number*/
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxNum)
            maxNum = arr[i];
    }
    return maxNum;
}

// A function to do counting sort of arr[] according to
// the number represented by exp.
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int count[10] = {0};
  
    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
  
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
  
    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
  
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

/*Utilized in the quicksort algorithm as part of moving around the elements*/
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*Partition in quickort*/
int partition(int arr[] , int left, int right) {
    int p = arr[right];
    int index = left - 1;
    
    for (int i = left; i <= right; i++){
        if (arr[i] < p){
            index++;
            swap(&arr[index], &arr[i]);
        }
    }
    swap(&arr[index+1], &arr[left]);
    return (index + 1);
}

/* Function to print an array */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


#endif /* functions_h */
