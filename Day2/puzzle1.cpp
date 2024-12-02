#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream input;
    input.open("input1.txt", ifstream::in);

    string line;

    int res = 0;

    while (getline(input, line)) {
        stringstream ss(line);
        int prev;
        int curr;
        ss >> prev;
        ss >> curr;
        bool is_correct = true;
        if (curr > prev && curr < prev + 4) {
            while (ss.good()) {
                prev = curr;
                ss >> curr;
                if (curr <= prev || curr > prev + 3) {
                    is_correct = false;
                    break;
                }
            }
        }
        else if (curr < prev && curr > prev - 4) {
            while (ss.good()) {
                prev = curr;
                ss >> curr;
                if (curr >= prev || curr < prev - 3) {
                    is_correct = false;
                    break;
                }
            }
        }
        else continue;
        if (is_correct) ++res;
    }

    cout << "result is: " << res << endl;

    return 0;
}