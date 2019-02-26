#include <iostream>

#include "kata_roman-numerals-helper.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "No input number to translate" << endl;
        return 1;
    }
    string input { argv[1] };
    int number { 0 };
    try {
        number = stoi(input);
    } catch (...) {}
    RomanNumeralsClass RomanNumerals;
    if (number > 0) {
        cout << number << " -> " << RomanNumerals.to_roman(number) << endl;
    } else {
        cout << input << " -> " << RomanNumerals.from_roman(input) << endl;
    }
    return 0;
}
