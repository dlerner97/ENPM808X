// Copyright [2021] Dani Lerner
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief findBeginning finds and returns the initial position of a list of chars in text.
 * 
 * @param array_to_search 
 * @param array_to_search_length 
 * @param text 
 * @param text_length 
 * @return int 
 */
int findBeginning(char *array_to_search, int array_to_search_length,
                  char *text, int text_length) {
    int i, j;
    for (i=0; i < text_length-array_to_search_length+1; i++) {
        bool found = true;
        for (j=0; j < array_to_search_length; j++)
            if (text[i+j] != array_to_search[j])
                found = false;
        if (found) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Declares and prints first position of char array in text.
 * 
 */
void printPosition() {
    char text[1024]="1234567890";
    int text_length = 10;
    char array_to_search1[4]="23";
    int array_to_search1_length = 2;
    int position1 = findBeginning(array_to_search1, array_to_search1_length,
                                  text, text_length);

    cout << position1 << endl;
}
