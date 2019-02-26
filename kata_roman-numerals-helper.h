#pragma once

#include <string>

class RomanNumeralsClass {
public:
    RomanNumeralsClass() {};

    std::string to_roman(int n) {
        std::string result;
        for (int i = 0; i < n / 1000; ++i) {
            result += 'M';
        }
        n -= n / 1000 * 1000;
        if (n >= 900) {
            result += "CM";
        } else if (n >= 500) {
            result += 'D';
            for (int i = 0; i < (n - 500) / 100; ++i) {
                result += 'C';
            }
        } else if (n >= 400) {
            result += "CD";
        } else if (n >= 100) {
            for (int i = 0; i < n / 100; ++i) {
                result += 'C';
            }
        }
        n -= n / 100 * 100;
        if (n >= 90) {
            result += "XC";
        } else if (n >= 50) {
            result += 'L';
            for (int i = 0; i < (n - 50) / 10; ++i) {
                result += 'X';
            }
        } else if (n >= 40) {
            result += "XL";
        } else if (n >= 10) {
            for (int i = 0; i < n / 10; ++i) {
                result += 'X';
            }
        }
        n -= n / 10 * 10;
        if (n >= 9) {
            result += "IX";
        } else if (n >= 5) {
            result += 'V';
            for (int i = 0; i < n - 5; ++i) {
                result += 'I';
            }
        } else if (n >= 4) {
            result += "IV";
        } else if (n >= 1) {
            for (int i = 0; i < n; ++i) {
                result += 'I';
            }
        }
        return result;
    }

    int from_roman(char c) {
        switch (c) {
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: return 0; break;
        }
    }

    int from_roman(std::string s) {
        char init_c { '0' };
        char prev_c { init_c };
        int result { 0 };
        for (char c : s) {
            switch (c) {
                case 'M':
                    if (prev_c == 'C') {
                        result += 800;
                    } else if (prev_c == init_c || prev_c == 'M') {
                        result += 1000;
                    } else {
                        return 0;
                    }
                    break;
                case 'D':
                    if (prev_c == 'C') {
                        result += 300;
                    } else if (prev_c == init_c || prev_c == 'M' || prev_c == 'D') {
                        result += 500;
                    } else {
                        return 0;
                    }
                    break;
                case 'C':
                    if (prev_c == 'X') {
                        result += 80;
                    } else if (prev_c == init_c || prev_c == 'M' || prev_c == 'D' || prev_c == 'C') {
                        result += 100;
                    } else {
                        return 0;
                    }
                    break;
                case 'L':
                    if (prev_c == 'X') {
                        result += 30;
                    } else if (prev_c == init_c || prev_c == 'M' || prev_c == 'D' || prev_c == 'C' || prev_c == 'L') {
                        result += 50;
                    } else {
                        return 0;
                    }
                    break;
                case 'X':
                    if (prev_c == 'I') {
                        result += 8;
                    } else if (prev_c == init_c || prev_c == 'M' || prev_c == 'D' || prev_c == 'C' || prev_c == 'L' || prev_c == 'X') {
                        result += 10;
                    } else {
                        return 0;
                    }
                    break;
                case 'V':
                    if (prev_c == 'I') {
                        result += 3;
                    } else if (prev_c == init_c || prev_c == 'M' || prev_c == 'D' || prev_c == 'C' || prev_c == 'L' || prev_c == 'X' || prev_c == 'V') {
                        result += 5;
                    } else {
                        return 0;
                    }
                    break;
                case 'I':
                    if (prev_c == init_c || prev_c == 'M' || prev_c == 'D' || prev_c == 'C' || prev_c == 'L' || prev_c == 'X' || prev_c == 'V' || prev_c == 'I') {
                        result += 1;
                    } else {
                        return 0;
                    }
                    break;
                default:
                    break;
            }
            prev_c = c;
        }
        return result;
    }
};
