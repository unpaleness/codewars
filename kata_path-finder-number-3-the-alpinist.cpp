#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void iterate(int n, const vector<int>& m, vector<int>* path, int climbs, int& res_climbs) {
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
    int location { path->back() };
    vector <int> neighbours;
    if (location / n != 0) {
        neighbours.push_back(location - n);
    }
    if (location / n != n - 1) {
        neighbours.push_back(location + n);
    }
    if (location % n != 0) {
        neighbours.push_back(location - 1);
    }
    if (location % n != n - 1) {
        neighbours.push_back(location + 1);
    }
    for (int l : neighbours) {
        bool has_loop { false };
        for (int i = 0; i < int(path->size()); ++i) {
            if (path->at(i) == l) {
                has_loop = true;
                break;
            }
        }
        if (has_loop) {
            continue;
        }
        int delta { abs(m[l] - m[location]) };
        if (l == n * n - 1) {
            if (climbs + delta < res_climbs) {
                res_climbs = climbs + delta;
            }
            if (res_climbs <= 0) {
                path->pop_back();
                return;
            }
        } else if (climbs + delta < res_climbs) {
            path->push_back(l);
            iterate(n, m, path, climbs + delta, res_climbs);
        }
    }
    path->pop_back();
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
    vector <int> m;
    vector <int> path;
    path.push_back(0);
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
            m.push_back(c - 48);
            ++im;
        }
    }
    if (im != n * n) {
        cerr << "Maze has invalid size or invalid content" << endl;
        return -1;    
    }
    iterate(n, m, &path, 0, res_climbs);
    
    return res_climbs;
}

int main() {
    string s =
        "000000\n"
        "000000\n"
        "000000\n"
        "000010\n"
        "000109\n"
        "001010";
    cout << path_finder(s) << endl;
    return 0;
}
