/*
ID: secondm1
TASK: crypt1
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
typedef pair<int, int> pii;

namespace std_file {
    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }

vector<int> st;
vector<bool> cnt(10, 0);
int N;

bool in_set(string num, int tam) {
    for (int i = 0; i < tam; ++i) {
        if (!cnt[num[i]-'0']) {
            return false;
        }
    }
    return true;
}

bool valid(int abc, int de) {
    if (!in_set(to_string(abc),3) || !in_set(to_string(de),2)) return 0;
    int p1 = de % 10 * abc;
    int p2 = de / 10 * abc;
    int total = p1 + 10 * p2;
    string pp1 = to_string(p1), pp2 = to_string(p2);
    int c1 = pp1.size() == 3 && pp2.size() == 3;
    int c2 = 1;
    if (c1) {
        c2 &= in_set(pp1, 3);
        c2 &= in_set(pp2, 3);
        c2 &= in_set(to_string(total), 4);
    }
    return c1 & c2;
}

int main() {
    using namespace std_file;
    fin >> N;
    st.resize(N);
    for (int i = 0; i < N; ++i) {
        fin >> st[i];
        cnt[st[i]] = 1;
    }

    int total = 0;
    for (int i = 100; i < 1000; ++i) {
        for (int j = 10; j < 100; ++j) {
            if (valid(i, j)) total++;
        }
    }

    fout << total << '\n';
    return 0;
}

