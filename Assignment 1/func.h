#pragma once
#include <iostream>
#include <fstream>
using namespace std;
void gui();
void PrintArr(int array[], int &size); 
int SearchArr(int array[], int &usrInput, int& size);
int ReaplceArr(int array[], int& usrInput, int& index, int& size);
int* AddToArr(int* array, int& usrInput, int& size);
int* RemoveFromArr(int* array, int& index, int& size);