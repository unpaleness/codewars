#include <iostream>
#include <cstdlib>

#include "kata_5672682212c8ecf83e000050.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "No input number" << endl;
        return 1;
    }
    int n { 0 };
    try {
        n = atoi(argv[1]);
    } catch(...) {
        cerr << "Argument is not a number" << endl;
    }
    if (n < 0) {
        cerr << "Argument is below zero" << endl;
    }
    cout << DoubleLinear::dblLinear(n) << endl;
    return 0;
}
