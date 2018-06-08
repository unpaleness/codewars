#include <string>
#include <deque>
#include <cmath>
#include <iostream>

using namespace std;

void tick(size_t &i, const string &input, unsigned char &memory, size_t &pos, deque<unsigned char> &cells, string &result) {
    cout << input << endl;
    for (size_t j = 0; j < i; ++j) { cout << ' '; }
    cout << '^' << endl;
    switch(input[i]) {
        case '+':
            ++cells[pos];
            break;
        case '-':
            --cells[pos];
            break;
        case '>':
            ++pos;
            if (pos == cells.size()) {
                cells.push_back((unsigned char)0);
            }
            break;
        case '<':
            if (pos == 0) {
                cells.push_front((unsigned char)0);
            } else {
                --pos;
            }
            break;
        case 'c':
            memory = cells[pos];
            break;
        case 'p':
            cells[pos] = memory;
            break;
        case 'W':
            if (cells[pos] == 0) {
                size_t loop_begin { 0 }, loop_end { 0 };
                for (; i < input.size(); ++i) {
                    if (input[i] == 'W') { ++loop_begin; }
                    if (input[i] == 'E') { ++loop_end; }
                    if (loop_begin == loop_end) { break; }
                }
            }
            break;
        case 'E':
            if (cells[pos] != 0) {
                size_t loop_begin { 0 }, loop_end { 0 };
                for (int j = i; j >= 0; --j) {
                    --i;
                    if (input[j] == 'W') { ++loop_begin; }
                    if (input[j] == 'E') { ++loop_end; }
                    if (loop_begin == loop_end) { break; }
                }
            }
            break;
        case 'P':
            result += cells[pos];
            break;
        case 'N':
            result += to_string((unsigned int) cells[pos]);
            break;
        case 'T':
            cells[pos] = ((unsigned int) cells[pos] * 2) % 256;
            break;
        case 'Q':
            cells[pos] = ((unsigned int) cells[pos] * (unsigned int) cells[pos]) % 256;
            break;
        case 'U':
            cells[pos] = (unsigned int) round(sqrt((double) cells[pos])) % 256;
            break;
        case 'L':
            cells[pos] += 2;
            break;
        case 'I':
            cells[pos] -= 2;
            break;
        case 'V':
            cells[pos] = (unsigned int) round((double) cells[pos] / 2.0) % 256;
            break;
        case 'A':
            cells[pos] += memory;
            break;
        case 'B':
            cells[pos] -= memory;
            break;
        case 'Y':
            cells[pos] = ((unsigned int) cells[pos] * (unsigned int) memory) % 256;
            break;
        case 'D':
            cells[pos] = (unsigned int) round((double) cells[pos] / (double) memory) % 256;
            break;
        default:
            break;
    }
    cout << " Memory: " << (unsigned int) memory << endl;
    cout << " Position: " << pos << endl;
    cout << " Cells:";
    for (size_t j = 0; j < cells.size(); ++j) {
        cout << ' ' << (unsigned int) cells[j];
    }
    cout << endl;
    cout << " Result: " << result << endl;
}

const char *poohbear (const char* sourcecode) {
    string input(sourcecode);
    string result("");
    deque<unsigned char> cells(1, 0);
    size_t pos { 0 };
    unsigned char memory { 0 };
    for (size_t i = 0; i < input.size(); ++i) {
        tick(i, input, memory, pos, cells, result);
    }
    return result.c_str();
}

int main(int argc, char *argv[]) {
    if (argc < 1) {
        cerr << "Not enough arguments" << endl;
    }
    cout << string(poohbear(argv[1])) << endl;
    return 0;
}

