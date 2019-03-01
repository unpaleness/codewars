#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void iterate(int n, const int* m, int*& path, int& ip, int climbs, int& res_climbs) {
    // vector<int> temp = m;
    // cout << "path:";
    // for (int p : *path) {
    //     temp[p] = -2;
    //     cout << ' ' << p;
    // }
    // for (int i = 0; i < n * n; ++i) {
    //     if (i % n == 0) {
    //         cout << endl;
    //     }
    //     cout << char(temp[i] + 48);
    // }
    // cout << endl << "length: " << climbs << '(' << res_climbs << ')' << endl << endl;
    int location { path[ip - 1] };
    int neighbours[4];
    int in { 0 };
    if (location / n != 0) {
        neighbours[in++] = location - n;
    }
    if (location / n != n - 1) {
        neighbours[in++] = location + n;
    }
    if (location % n != 0) {
        neighbours[in++] = location - 1;
    }
    if (location % n != n - 1) {
        neighbours[in++] = location + 1;
    }
    for (int k = 0; k < in; ++k) {
        for (int j = k + 1; j < in; ++j) {
            if (abs(m[path[ip - 1]] - m[neighbours[j]]) < abs(m[path[ip - 1]] - m[neighbours[k]])) {
                neighbours[k] -= neighbours[j];
                neighbours[j] += neighbours[k];
                neighbours[k] = neighbours[j] - neighbours[k];
            }
        }
    }
    for (int j = 0; j < in; ++j) {
        bool has_loop { false };
        for (int i = 0; i < ip; ++i) {
            if (path[i] == neighbours[j]) {
                has_loop = true;
                break;
            }
        }
        if (has_loop) {
            continue;
        }
        int delta { abs(m[neighbours[j]] - m[location]) };
        if (neighbours[j] == n * n - 1) {
            if (climbs + delta < res_climbs) {
                res_climbs = climbs + delta;
            }
            if (res_climbs <= 0) {
                --ip;
                return;
            }
        } else if (climbs + delta < res_climbs) {
            path[ip++] = neighbours[j];
            iterate(n, m, path, ip, climbs + delta, res_climbs);
        }
    }
    --ip;
}

int path_finder(string maze) {
    if (maze.empty()) {
        cerr << "Maze is empty" << endl;
        return -1;
    }
    if (maze.size() == 1) {
        return 0;
    }
    int n = maze.find_first_of('\n');
    if (n == int(string::npos)) {
        cerr << "Maze has invalid content: couldn't detect any newline symbol" << endl;
        return -1;
    }
    int* m = new int [n * n];
    int* path = new int [n * n];
    path[0] = 0;
    int ip { 1 };
    int res_climbs { 9 * n * n };
    int im { 0 };
    for (char c : maze) {
        if (im > n * n) {
            break;
        }
        if (!isspace(c)) {
            if(c < 48 || c > 57) {
                break;
            }
            m[im++] = c - 48;
        }
    }
    if (im != n * n) {
        cerr << "Maze has invalid size or invalid content" << endl;
        delete [] m;
        delete [] path;
        return -1;    
    }
    iterate(n, m, path, ip, 0, res_climbs);
    
    delete [] m;
    delete [] path;
    return res_climbs;
}

int main() {
    string s =
        // "000000\n"
        // "000000\n"
        // "000000\n"
        // "000010\n"
        // "000109\n"
        // "001010";
        // "0101010101\n"
        // "1010101010\n"
        // "0101010101\n"
        // "1010101010\n"
        // "0101010101\n"
        // "1010101010\n"
        // "0101010101\n"
        // "1010101010\n"
        // "0101010101\n"
        // "1010101010";
        "123456789\n"
        "987654321\n"
        "123456789\n"
        "987654321\n"
        "123456789\n"
        "987654321\n"
        "123456789\n"
        "987654321\n"
        "123456789";
    cout << path_finder(s) << endl;
    return 0;
}
