#pragma once

#include <vector>

class DoubleLinear
{
public:
    static int dblLinear(int n);
};

int DoubleLinear::dblLinear(int n) {
    std::vector<long long> seq({ 1 });
    int iy { 0 }, iz { 0 };
    for (int i = 1; i <= n; ++i) {
        long long y { 2 * seq[iy] + 1 };
        long long z { 3 * seq[iz] + 1 };
        if (y < z) {
            seq.push_back(y);
            ++iy;
        }
        if (y > z) {
            seq.push_back(z);
            ++iz;
        }
        if (y == z) {
            seq.push_back(y);
            ++iy;
            ++iz;
        }
    }
    return seq[n];
}
