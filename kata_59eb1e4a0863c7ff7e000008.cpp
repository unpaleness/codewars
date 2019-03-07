/*
 * Codewars kata
 * The boolean order (59eb1e4a0863c7ff7e000008)
 */

#include <iostream>
#include <string>

using namespace std;

int64_t fact(size_t n) {
    if (n <= 0) return 0;
    int64_t res { 1 };
    for (size_t i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

void swap(size_t& a, size_t& b) {
    size_t temp = a;
    a = b;
    b = temp;
}

void permutate(size_t* priority, size_t start_i, size_t end_i) {
    if (start_i == end_i) {
        for (size_t i = 0; i <= end_i; ++i) {
            // cout << priority[i];
        }
        // cout << endl;
    } else {
        for (size_t i = start_i; i <= end_i; ++i) {
            swap(priority[start_i], priority[i]);
            permutate(priority, start_i + 1, end_i);
            swap(priority[start_i], priority[i]);
        }
    }
}

int64_t solve(const string &s, const string &ops) {
    if (s.empty()) {
        cerr << "Invalid input: empty boolean values array" << endl;
        return 0;
    }
    if (ops.size() != s.size() - 1) {
        cerr << "Invalid input: amount of values should be one greater then amount of operators" << endl;
        return 0;
    }
    if (s.find_first_not_of("ft") != string::npos) {
        cerr << "Invalid input: values array contains invalid characters" << endl;
        return 0;
    }
    if (ops.find_first_not_of("&^|") != string::npos) {
        cerr << "Invalid input: operators array contains invalid characters" << endl;
        return 0;
    }
    size_t n { ops.size() };
    cout << fact(n) << endl;
    size_t* priority = new size_t [n];
    for (size_t i = 0; i < n; ++i) {
        priority[i] = i;
    }
    permutate(priority, 0, n - 1);
    delete [] priority;
    return 0;
}

int main() {
    cout << solve("ftfttfttttft", "|||||||^||&") << endl;
    return 0;
}
