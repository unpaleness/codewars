#include <iostream>

#include "kata_simple-assembler-interpreter.h"

int main() {
    // vector<string> program { "mov a 5", "inc a", "dec a", "dec a",
    //   "jnz a -1", "inc a" };
    vector<string> program { "mov a -10000000", "inc a", "jnz a -1" };
    unordered_map<string, int> out = assembler(program);
    for (auto& reg : out) {
        cout << reg.first << ' ' << reg.second << endl;
    }
    return 0;
}
