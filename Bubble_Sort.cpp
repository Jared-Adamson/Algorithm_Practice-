// Bubble Sort Practice Assignment 
#include <iostream>
using namespace std;
#include <random>

int main() {
    //Create & print array with random ints.
    int rando;
    int arrLength = 100;
    int rndArr[arrLength];
    for (int i = 0; i < arrLength; i++) {
        rando = rand() % 101;
        rndArr[i] = rando;
        cout << rndArr[i] << " ";
    }
    cout << endl << endl;
    // Bubble Sort Algorithm
    bool swap = true;
    while (swap == true) {
        int value;
        swap = false;
        for (int y = 0; y < arrLength-1; y++) {
            if(rndArr[y] > rndArr[y+1]){
                value = rndArr[y]; 
                rndArr[y] = rndArr[y+1];
                rndArr[y+1] = value;
                swap = true;
            }
        }
    }
    //Print sorted array.
       for (int i = 0; i < arrLength; i++) {
        cout << rndArr[i] << " ";
    }
    
    return 0;
}
