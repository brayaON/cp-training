/*
ID: secondm1
TASK: palsquare
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;
const int MOD = 1000000007;
typedef long long ll;

namespace std_file {
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");
}

vector<char> to = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string convert(int N, int B) {
    string NN;
    while (N > 0) {
        int mod = N % B;
        NN.push_back(to[mod]);
        N /= B;
    }
    reverse(NN.begin(), NN.end());
    return NN;
}

bool is_pal(string N) {
    string T(N.rbegin(), N.rend());
    return T == N;
}

int main() {
    using namespace std_file;
    int B; fin >> B;
    vector<pair<string, string>> ans;
    for (int N = 1; N <= 300; ++N) {
        string sq = convert(N * N, B);
        if (is_pal(sq)) {
            fout << convert(N, B) << " " << sq << '\n';
        }
    }

    return 0;
}

