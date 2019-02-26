#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static unordered_map<string, int> insts {
    { "mov", 1 },
    { "inc", 2 },
    { "dec", 3 },
    { "jnz", 4 }
};

inline bool is_space(char c) {
    return isspace(c);
}

inline bool is_not_space(char c) {
    return !isspace(c);
}

vector<string> split(const string& s) {
    vector<string> ret;
    string::const_iterator i = s.begin();
    while (i != s.end()){
        i = find_if(i, s.end(), is_not_space); // find the beginning of a word
        string::const_iterator j= find_if(i, s.end(), is_space); // find the end of the same word
        if (i != s.end()){
            ret.push_back(string(i, j)); //insert the word into vector
            i = j; // repeat 1,2,3 on the rest of the line.
        }
    }
    return ret;
}

unordered_map<string, int> assembler(const vector<string>& program) {
    unordered_map<string, int> reg_indexes;
    int reg_index { 0 };
    vector<int> reg_values;
    vector< vector<int> > commands;
    for (size_t i = 0; i < program.size(); ++i) {
        // cout << i << '\t' << program[i] << endl;
        vector<string> parts { split(program[i]) };
        vector<int> command;
        for (size_t j = 0; j < parts.size(); ++j) {
            switch(j) {
                case 0:
                    command.push_back(insts[parts[j]]);
                    break;
                case 1:
                    if (reg_indexes.count(parts[j]) == 0) {
                        reg_indexes[parts[j]] = reg_index++;
                        reg_values.push_back(0);
                    }
                    command.push_back(reg_indexes[parts[j]]);
                    break;
                case 2:
                    if (reg_indexes.count(parts[j]) == 0 || insts[parts[j]] == 4) {
                        command.push_back(0);
                        command.push_back(stoi(parts[j]));
                    } else {
                        command.push_back(1);
                        command.push_back(reg_indexes[parts[j]]);
                    }
                    break;
            }
        }
        commands.push_back(command);
    }
    size_t it { 0 };
    for (size_t i = 0; i < commands.size(); ++i) {
        // cout << it << '\t';
        if (commands[i][0] == insts["mov"]) {
            if (commands[i][2]) {
                reg_values[commands[i][1]] = reg_values[commands[i][3]];
            } else {
                reg_values[commands[i][1]] = commands[i][3];
            }
            // cout << '#' << commands[i][1] << '=' << reg_values[commands[i][1]];
        }
        if (commands[i][0] == insts["inc"]) {
            ++reg_values[commands[i][1]];
            // cout << '#' << commands[i][1] << '=' << reg_values[commands[i][1]];
        }
        if (commands[i][0] == insts["dec"]) {
            --reg_values[commands[i][1]];
            // cout << '#' << commands[i][1] << '=' << reg_values[commands[i][1]];
        }
        if (commands[i][0] == insts["jnz"]) {
            if (reg_values[commands[i][1]] != 0) {
                i = i - 1 + commands[i][3];
            }
        }
        // cout << endl;
        ++it;
    }
    unordered_map<string, int> regs;
    for (auto ri : reg_indexes) {
        regs[ri.first] = reg_values[ri.second];
    }
    return regs;
}
