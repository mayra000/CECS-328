//
//  heap.h
//  CECS328_P3
//
//  Created by Mayra Sanchez on 11/22/19.
//  Copyright © 2019 Mayra Sanchez. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <iostream>

using namespace std;

int size = 0;

void printHeap(int arr[], int n);

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2
  
    /* n = node */
    // If left child is larger than root
    if ( left < n && arr[left] > arr[largest])
        largest = left;
  
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
  
// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void min_heapify(int *a, int i, int n) {
    int j, temp;
    j = 2*i;
    temp = a[i];
    
    while ( j <= n) {
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j]) {
            a[j/2] = a[j];
            j = j *2;
        }
    }
    a[j/2] = temp;
    return;
}

void build_minHeap(int *a, int n) {
    int i;
    for (i = n/2; i >= 1; i--) {
        min_heapify(a, i,n);
    }
    //printHeap(a, n);
}

void insertElement(int arr[], int &size, int data) {
    size++;
    arr[size - 1] = data;
    build_minHeap(arr, data);
}

void popElement(int arr[], int &size, int data) {
    int i;
    for (i = 0; i < size; i++){
        /*Looking for element in the array*/
        if(arr[i] == data)
            break;
    if (i < size) {
        size--;
        for (int j = i; j < size; j++){
            arr[j] = arr[j+1];
        }
    }
    }
    
}



#endif /* heap_h */
