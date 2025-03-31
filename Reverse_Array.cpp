// Jared Adamson
// Assignment 1  
// Design and Analysis of Algorithms: CS627

#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to reverse array in-place.
void revArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to create an array filled with random ints.
int* arrGen(int size) {
    int* rndArr = new int[size];  

    // cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        rndArr[i] = rand() % 101;
      //cout << rndArr[i] << " ";
    }
    //cout << endl << endl;

    return rndArr;
}

// Function to print the array.
void printA(int arr[], int size) {
    cout << "Reversed array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrLength1 = 500;
    int arrLength2 = 1500;
    int arrLength3 = 2000;

    // Creates three arrays that can be timed
    int* rndArr1 = arrGen(arrLength1);
    int* rndArr2 = arrGen(arrLength2);
    int* rndArr3 = arrGen(arrLength3);

    // Run 1
    auto start1 = high_resolution_clock::now();
    revArray(rndArr1, arrLength1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << endl << "Runtime for array of size " << arrLength1 << ": " << duration1.count() << " microseconds" << endl;

    // Run 2
    auto start2 = high_resolution_clock::now();
    revArray(rndArr2, arrLength2);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << endl << "Runtime for array of size " << arrLength2 << ": " << duration2.count() << " microseconds" << endl;

    // Run 3
    auto start3 = high_resolution_clock::now();
    revArray(rndArr3, arrLength3);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << endl << "Runtime for array of size " << arrLength3 << ": " << duration3.count() << " microseconds" << endl;

    // Print reversed arrays
    //printA(rndArr1, arrLength1);
    //printA(rndArr2, arrLength2);
    //printA(rndArr3, arrLength3);


    return 0;
}
