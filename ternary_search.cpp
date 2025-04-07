//Jared Adamson 
//Assignment 2
//Design and Analysis of Algorithms: CS627

#include <iostream> 
#include <string> 
#include <cctype>
using namespace std;

// Recursive search function using divide and conqure.  Inputs a song name and returns the index of the song.  return -1 if song not found.
int tSearch(string playlist[], const string& song, int left, int right) {
    if (left > right) return -1; // song not found retun -1

    int third = (right - left) / 3; // Dividing it into 3 sections to search
    int mid1 = left + third;
    int mid2 = right - third;

    // Checks the midpoint for song.
    if (playlist[mid1] == song) return mid1;
    if (playlist[mid2] == song) return mid2;

    // Find section to search.
    if (song < playlist[mid1]) {
        // first grouping.
        return tSearch(playlist, song, left, mid1 - 1);
    } else if (song > playlist[mid2]) {
        // Second group.
        return tSearch(playlist, song, mid2 + 1, right);
    } else {
        // Third group.
        return tSearch(playlist, song, mid1 + 1, mid2 - 1);
    }
}


int main() {
    // A playlist array to test the algorithm.
    string playlist[] = {
       "all of me", "believer", "counting stars", "demons", "apt",
        "imagine", "pink pony club", "photograph", "radioactive", "shape of you"
    };

    // Checks array size.
    int aSize = sizeof(playlist) / sizeof(playlist[0]);

    // Asks the user for a song to look for.
    string song;
    cout << "Enter the name of the song to search: ";
    getline(cin, song); // Read the line & allow spaces.
    
    //Convert input to lower for easier compare 
    for (char &c : song) {
        c = tolower(c);
    }
    //Testing the lowercase convertion of user input.
    //cout << "Lowercase song title: " << song << endl;
    
    // Perform the search & returns an index or -1.
    int i = tSearch(playlist, song, 0, aSize - 1);

    // Output the result.
    if (i != -1)
        cout << "\"" << song << "\" was found at index: " << i << " " << endl;
    else
        cout << "\"" << song << "\" was not found in the playlist." << endl;

    return 0;
}
