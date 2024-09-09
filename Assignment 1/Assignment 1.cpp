// Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "func.h"

using namespace std;

int main() {
    int size = 100, input = 0, c = 0, i = 0;
    int* arr = new int[size];


    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    while (fin.good()) {
        fin >> arr[c];
        c++;
    }
    fin.close();

    cout << "Welcome to Array Manager!\n";
    while (true) {
        
        string option = "0";
        gui();



        cin.exceptions(ios::failbit);
        cout << "Enter Option: ";
        cin >> option;


        if (option == "1")
            PrintArr(arr, size);


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
            int index = SearchArr(arr, input, size);
            if (index == -1) {
                cout << "That Value Does Not Exist In The Array\n";
                continue;
            }
            cout << "The Index For That Value is {" << index << "}\n";
        }


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
            int oldvalue = ReaplceArr(arr, input, i, size);
            if (oldvalue == -2) {
                cout << "That Index is Out Of Bounds\n";
                continue;
            }
            cout << "The Value That Was Replace Is {" << oldvalue << "} With {" << input << "}\n";
        }


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
            arr = AddToArr(arr, input, size);
            cout << "Value Has Been Added\n";
        }


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
            arr = RemoveFromArr(arr, i, size);
            cout << "Value Has Been Deleted\n";
        }
        else if (option == "6")
            break;        
        else{
            cout << "You Must Enter an Integer" << endl;
        }
    }
}