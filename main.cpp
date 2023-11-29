#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
//Астахов Артем Сергеевич
//решение задачи с хранением в map указателей на лямбда функции

using namespace std;

vector<int> Array;

enum ArrayFunctionType{
    Zero, Positive, Negative, Maximum, Minimum, Max_Count, Min_count
};

typedef int (*Action)();
typedef map<ArrayFunctionType, Action> Result;

string Parser(string* str, char delimiter);
vector<int> FillArrayFromFile(string input_path);
int maximum, minimum;
int CountZero ();
int CountPositiveNumbers ();
int CountNegativeNumbers ();
int FindMaxNumber ();
int FindMinNumber ();
int CountMax ();
int CountMin ();
string SubstitutionText (ArrayFunctionType);
void PrintMap (map<ArrayFunctionType, Action> result);


int main() {
    string input_path = "D:\\Study\\2811Class\\array.dat";
    Result result;
    Array = FillArrayFromFile(input_path);

    result.emplace(Zero, CountZero);
    result.emplace(Positive, CountPositiveNumbers);
    result.emplace(Negative, CountNegativeNumbers);
    result.emplace(Maximum, FindMaxNumber);
    result.emplace(Minimum, FindMinNumber);
    result.emplace(Max_Count, CountMax);
    result.emplace(Min_count, CountMin);

    result[Zero]();
    result[Positive]();
    result[Negative]();
    result[Maximum]();
    result[Minimum]();
    result[Max_Count]();
    result[Min_count]();

    PrintMap(result);



    return 0;
}

string Parser(string* str, char delimiter) {
    auto position = str->find(delimiter);
    auto result = str->substr(0, position);
    *str = str->substr(position + 1);

    return result;
}

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

string SubstitutionText (ArrayFunctionType type){
    string text;
    switch (type) {
        case Zero:{
            text = "Count of zero is: ";
            break;
        }
        case Positive:{
            text = "Count of positive numbers: ";
            break;
        }
        case Negative:{
            text = "Count of negative numbers: ";
            break;
        }
        case Maximum:{
            text = "Maximium number: ";
            break;
        }
        case Minimum:{
            text = "Minimum number: ";
            break;
        }
        case Max_Count:{
            text = "Count of maximum: ";
            break;
        }
        case Min_count:{
            text = "Count of minimum: ";
            break;
        }
    }
    return text;
}

void PrintMap (map<ArrayFunctionType, Action> result){
    for (auto item : result){
        string str;
        str = SubstitutionText(item.first);
        cout << str << item.second() << endl;
    }
}
