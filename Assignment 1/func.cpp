#include "func.h"

void gui() {
    cout << "\nOPTIONS\n1). Print Array\n2). Search Array\n3). Replace a Value at index\n4). Add Value to End of Array\n5). Remove Value at Index\n6). End Program\n";
}

void PrintArr(int array[], int& size) {
    for (int x = 0; x < size; x++)
        cout << " [" << array[x] << "] ";
}

int SearchArr(int array[], int &usrInput, int &size) {
    int count = 0;
    while (true) {
        if (count == size) {
            return -1;
        }
        else if ( array[count] == usrInput) {
            return count;
        }
        count++;
    }
}

int ReaplceArr(int array[], int& usrInput, int& index, int& size) {
    int oldValue = array[index];
    if (index >= size)
        return -2;
    array[index] = usrInput;
    return oldValue;
}

int* AddToArr(int* array, int& usrInput, int& size) {
    int newSize = size + 1; 
    int* tempArr = new int[newSize];
    copy(array, array + size, tempArr);
    delete[] array;
    array = tempArr;
    array[size] = usrInput;
    size += 1;
    return array;
}

int* RemoveFromArr(int* array, int& index, int& size) {
    array[index] = 0;
    int newSize = size - 1;
    int* tempArr = new int[newSize];
    int count = -1;
    for (int x = 0; x < size; x++) {
        if (array[x] == 0)
            continue;
        count++;
        tempArr[count] = array[x];
    }
    delete[] array;
    array = tempArr;
    size = newSize;
    return array;
}

