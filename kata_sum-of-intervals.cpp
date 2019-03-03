/*
 * Codewars kata
 * Sum of Intervals (sum-of-intervals)
 */

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool less_pair(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first < b.first) {
        return true;
    }
    if (a.first == b.first && a.second < b.second) {
        return true;
    }
    return false;
}

int sum_intervals(vector<pair<int, int>> intervals) {
    vector<pair<int, int>> optimized_intervals;
    sort(intervals.begin(), intervals.end(), less_pair);
    for (auto i : intervals) {
        // cout << i.first << ' ' << i.second << endl;
        bool is_interval_processed { false };
        for (auto& oi : optimized_intervals) {
            if (i.first <= oi.second) {
                // cout << i.first << " < " << oi.second << endl;
                if (i.second > oi.second) {
                    // cout << i.second << " > " << oi.second << endl;
                    oi.second = i.second;
                }
                is_interval_processed = true;
                break;
            }
        }
        if (!is_interval_processed) {
            // cout << "adding " << i.first << ';' << i.second << endl;
            optimized_intervals.push_back(i);
        }
    }
    // cout << endl;
    int res { 0 };
    for (auto oi : optimized_intervals) {
        // cout << oi.first << ' ' << oi.second << endl;
        res += oi.second - oi.first;
    }
    // cout << endl;
    return res;
}

int main() {
    vector<pair<int, int>> intervals = {{1, 2}, {8, 15}, {6, 10}};
    cout << sum_intervals(intervals) << endl;
    return 0;
}
