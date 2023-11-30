#include "math_functions.h"
#include "input_function.h"
#include "output_functions.h"
//Астахов Артем Сергеевич
//решение задачи с хранением в map указателей на лямбда функции


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

    for (auto item : result){
        auto name = item.first;
        result[name]();
    }

    PrintMap(result);

    return 0;
}
