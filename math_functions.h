#ifndef INC_2811CLASS_MATH_FUNCTIONS_H
#define INC_2811CLASS_MATH_FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

enum ArrayFunctionType{
    Zero, Positive, Negative, Maximum, Minimum, Max_Count, Min_count
};

typedef int (*Action)();
typedef map<ArrayFunctionType, Action> Result;

int maximum, minimum;
vector<int> Array;

string Parser(string* str, char delimiter) {
    auto position = str->find(delimiter);
    auto result = str->substr(0, position);
    *str = str->substr(position + 1);

    return result;
}

int CountZero (){
    int count = 0;
    for (int i = 0; i < Array.size(); ++i) {
        if (Array[i] == 0) count++;
    }
    return count;
}

int CountPositiveNumbers (){
    int count = 0;
    for (int i = 0; i < Array.size(); ++i) {
        if (Array[i] >= 0) count++;
    }
    return count;
}

int CountNegativeNumbers (){
    int count = 0;
    for (int i = 0; i < Array.size(); ++i) {
        if (Array[i] < 0) count++;
    }
    return count;
}

int FindMaxNumber (){
    maximum = Array[0];
    for (int i = 1; i < Array.size(); ++i) {
        if (Array[i] > maximum) maximum = Array[i];
    }
    return maximum;
}
int FindMinNumber (){
    minimum = Array[0];
    for (int i = 1; i < Array.size(); ++i) {
        if (Array[i] < minimum) minimum = Array[i];
    }
    return minimum;
}

int CountMax (){
    int count = 0;
    for (int i = 0; i < Array.size(); ++i) {
        if (Array[i] == maximum) count++;
    }
    return count;
}

int CountMin (){
    int count = 0;
    for (int i = 0; i < Array.size(); ++i) {
        if (Array[i] == minimum) count++;
    }
    return count;
}

#endif //INC_2811CLASS_MATH_FUNCTIONS_H
