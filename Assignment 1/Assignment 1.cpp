// Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "func.h"

using namespace std;

int main() {
    // Initialize variables
    int size = 100, input = 0, c = 0, i = 0;
    int* arr = new int[size];

    // Open input file and check if there is an error 
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    // Read data from file into the array
    while (fin.good()) {
        fin >> arr[c];
        c++;
    }
    fin.close();

   
    cout << "Welcome to Array Manager!\n";
    while (true) {
        
        string option = "0";
        gui(); // Display menu options



        cin.exceptions(ios::failbit); // Exception handling for invalid input
        cout << "Enter Option: ";
        cin >> option;

        // Print the array
        if (option == "1")
            PrintArr(arr, size);

        // Search for a value in the array
        else if (option == "2") {
            cout << "Enter Value to Search For: ";
            try {
                cin >> input;
            }
            catch (const exception& e) {
                cout << "You Must Enter an Integer" << endl;
                cin.clear();
                continue;
            }
            int index = SearchArr(arr, input, size); // Search for the value in the array
            if (index == -1) { // Check if value exists
                cout << "That Value Does Not Exist In The Array\n";
                continue;
            }
            cout << "The Index For That Value is {" << index << "}\n";
        }

        // Replace a value in the array
        else if (option == "3") {
            cout << "Enter New Value: ";
            try {
                cin >> input;
            }
            catch (const exception& e) {
                cout << "You Must Enter an Integer" << endl;
                cin.clear();
                continue;
            }
            cout << "Enter Index: ";
            try {
                cin >> i;
            }
            catch (const exception& e) {
                cout << "You Must Enter an Integer" << endl;
                cin.clear();
                continue;
            }
            int oldvalue = ReaplceArr(arr, input, i, size); // Replace the value at the given index
            if (oldvalue == -2) { // Check if index is out of bounds
                cout << "That Index is Out Of Bounds\n";
                continue;
            }
            cout << "The Value That Was Replace Is {" << oldvalue << "} With {" << input << "}\n";
        }

        // Add a new value to the end of the array
        else if (option == "4") {
            cout << "Enter Value To Add To The End Of The Array: ";
            try {
                cin >> input;
            }
            catch (const exception& e) {
                cout << "You Must Enter an Integer" << endl;
                cin.clear();
                continue;
            }
            arr = AddToArr(arr, input, size); // Add the value to the end of the array
            cout << "Value Has Been Added\n";
        }

        // Delete a value from the array
        else if (option == "5") {
            cout << "Enter Index To Delete: ";
            try {
                cin >> i;
            }
            catch (const exception& e) {
                cout << "You Must Enter an Integer" << endl;
                cin.clear();
                continue;
            }
            arr = RemoveFromArr(arr, i, size); // Remove the value from the array
            cout << "Value Has Been Deleted\n";
        }
        // Exit the program
        else if (option == "6")
            break;        
        else{ // Handle invalid option input
            cout << "You Must Enter an Integer" << endl;
        }
    }
}