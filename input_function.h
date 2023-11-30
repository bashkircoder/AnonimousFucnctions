#ifndef INC_2811CLASS_INPUT_FUNCTION_H
#define INC_2811CLASS_INPUT_FUNCTION_H
#include <string>
#include <iostream>
#include <fstream>

vector<int> FillArrayFromFile(string input_path){
    vector<int> array;
    ifstream file;
    file.open(input_path);
    while (!file.eof()){
        string str;
        getline(file, str);
        while (!str.empty()){
            array.push_back(stoi(Parser(&str, ' ')));
        }
    }
    file.close();
    return array;
}


#endif //INC_2811CLASS_INPUT_FUNCTION_H
