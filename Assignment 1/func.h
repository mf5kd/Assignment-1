#pragma once
#include <iostream>
#include <fstream>
using namespace std;
void gui();
void PrintArr(int array[], int &size); 
int SearchArr(int array[], int &usrInput, int& size); // search for a value in the array and return its index
int ReaplceArr(int array[], int& usrInput, int& index, int& size);// replace a value in the array at a specified index
int* AddToArr(int* array, int& usrInput, int& size); // add a new value to the end of the array
int* RemoveFromArr(int* array, int& index, int& size); // remove a value from the array at a specified index