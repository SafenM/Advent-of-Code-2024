#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;
using uint = unsigned int;

// unordered_map::contains requires you to compile with C++20 

uint find_similarity(const unordered_map<uint, uint>& m1, const unordered_map<uint, uint>& m2) {
    uint result = 0;

    for (auto& pair: m1) {
        if (m2.contains(pair.first)) {
            result += pair.first * pair.second * m2.at(pair.first);
        }
    }

    return result;
}

int main() {
    ifstream input;
    input.open("input1.txt", ifstream::in);
    
    unordered_map<uint, uint> map1;
    unordered_map<uint, uint> map2;

    uint n1;
    uint n2;

    while (input.good()) {
        input >> n1 >> n2;
        map1[n1]++;
        map2[n2]++;
    }

    cout << "result is: " << find_similarity(map1, map2) << endl;

    return 0;
}