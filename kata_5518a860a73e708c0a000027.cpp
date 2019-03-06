/*
 * Codewars kata
 * Last digit of a huge number (5518a860a73e708c0a000027)
 */

#include <list>
#include <iostream>
#include <cmath>

using namespace std;

int last_digit(list<int> array) {
    int accuracy { 100000 };
    if (array.empty()) return 1;
    if (array.size() == 1) return array.back() % 10;
    long long int last { array.back() == 0 ? 0 : (array.back() - 1) % accuracy + 1 };
    array.pop_back();
    while (!array.empty()) {
        // cout << last << endl;
        long long int before_last { array.back() == 0 ? 0 : (array.back() - 1) % accuracy + 1 };
        array.pop_back();
        if (before_last == 0) {
            if (last == 0) last = 1; else last = 0;
        } else {
            long long int temp { 1 };
            for (int i = 0; i < last; ++i) {
                temp = (temp * before_last - 1) % accuracy + 1;
            }
            last = temp;
        }
        // cout << last << endl;
        // cout << endl;
    }
    return last % 10;
}

int main() {
    cout << last_digit({937640,767456,981242}) << endl;
    return 0;
}
