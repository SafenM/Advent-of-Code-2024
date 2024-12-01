#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int find_difference(vector<int>& v1, vector<int>& v2) {
    unsigned int result = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); ++i) {
        result += abs(v1[i] - v2[i]);
    }
    return result;
}

int main() {
    ifstream input;
    input.open("input1.txt", ifstream::in);
    
    vector<int> vec1;
    vector<int> vec2;

    int n1;
    int n2;

    while (input.good()) {
        input >> n1 >> n2;
        vec1.push_back(n1);
        vec2.push_back(n2);
    }

    cout << "result is: " << find_difference(vec1, vec2) << endl;

    return 0;
}