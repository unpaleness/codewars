/*
 * Codewars kata
 * Hamming Numbers (526d84b98f428f14a60008da)
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

uint64_t hamber(int n)
{
    std::vector<uint64_t> hams{1};
    uint64_t ham2 {2};
    uint64_t ham3 {3};
    uint64_t ham5 {5};
    size_t i2 {0};
    size_t i3 {0};
    size_t i5 {0};
    while (hams.size() < static_cast<uint64_t>(n))
    {
        hams.push_back(std::min({ham2, ham3, ham5}));
        if (ham2 == hams.back())
        {
            ham2 = hams[++i2] * 2;
        }
        if (ham3 == hams.back())
        {
            ham3 = hams[++i3] * 3;
        }
        if (ham5 == hams.back())
        {
            ham5 = hams[++i5] * 5;
        }
    }
    return hams.back();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No input number\n";
        return 1;
    }
    int n { 1 };
    try {
        n = atoi(argv[1]);
    } catch(...) {
        std::cerr << "Argument is not a number\n";
        return 1;
    }
    if (n < 1) {
        std::cerr << "Argument is below 1\n";
        return 1;
    }

    std::cout << hamber(n) << '\n';

    return 0;
}
