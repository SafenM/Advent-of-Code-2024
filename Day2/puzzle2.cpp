#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// it's far from optimal solution, but it works just fine for such data set

bool isSimpleInc(const vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] <= vec[i - 1] || vec[i] > vec[i - 1] + 3) return false;
    }
    return true;
}

bool isSimpleDec(const vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] >= vec[i - 1] || vec[i] < vec[i - 1] - 3) return false;
    }
    return true;
}

bool isCorrect(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        vector<int> vec_tmp;
        for (int j = 0; j < vec.size(); ++j) {
            if (j != i) vec_tmp.push_back(vec[j]);
        }
        if (isSimpleDec(vec_tmp) || isSimpleInc(vec_tmp)) return true;
    }
    return false;
}

int main() {
    ifstream input;
    input.open("input1.txt", ifstream::in);

    string line;

    int res = 0;
    int line_nr = 0;

    while (getline(input, line)) {
        stringstream ss(line);
        vector<int> vec;
        while (ss.good()) {
            int n;
            ss >> n;
            vec.push_back(n);
        }
        if (isCorrect(vec)) ++res;
    }

    cout << "result is: " << res << endl;

    return 0;
}