/*
ID: secondm1
TASK: dualpal
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
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");
}

string to = "0123456789";

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
    int N, S; fin >> N >> S;

    int x = S + 1;
    while(N && x < INT_MAX) {
        int cnt = 0;
        for (int B = 2; B <= 10; ++B) {
            if (is_pal(convert(x, B))) cnt++;
            if (cnt == 2) break;
        }
        if (cnt == 2) {
            fout << x << '\n';
            N--;
        }
        x++;
    }
    return 0;
}

