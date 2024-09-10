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
            return -1;  // Return -1 to indicate value is not found
        }
        else if ( array[count] == usrInput) {
            return count; // Return the index of the matching element
        }
        count++;
    }
}

int ReaplceArr(int array[], int& usrInput, int& index, int& size) {
    int oldValue = array[index];
    if (index >= size)
        return -2;  // Return -2 to indicate invalid index
    array[index] = usrInput; 
    return oldValue; // Return the old value that was replaced
}

int* AddToArr(int* array, int& usrInput, int& size) {
    int newSize = size + 1; 
    int* tempArr = new int[newSize];
    copy(array, array + size, tempArr);  // Copy the contents of the old array to the new array
    delete[] array; // Free the memory of the old array
    array = tempArr; // Point the original array pointer to the new array
    array[size] = usrInput;
    size += 1;
    return array;
}

int* RemoveFromArr(int* array, int& index, int& size) {
    array[index] = 0;
    int newSize = size - 1;
    int* tempArr = new int[newSize];
    int count = -1;
    // Copy the contents of the old array to the new array
    for (int x = 0; x < size; x++) {
        if (array[x] == 0) // Skip the element that should be deleted
            continue;
        count++;
        tempArr[count] = array[x];
    }

    delete[] array; // Free the memory of the old array
    array = tempArr; // Point the original array pointer to the new array
    size = newSize;
    return array;
}

