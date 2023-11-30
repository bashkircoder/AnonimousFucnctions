#ifndef INC_2811CLASS_OUTPUT_FUNCTIONS_H
#define INC_2811CLASS_OUTPUT_FUNCTIONS_H

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


#endif //INC_2811CLASS_OUTPUT_FUNCTIONS_H
