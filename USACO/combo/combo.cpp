/*
ID: secondm1
TASK: combo
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
    ofstream fout("combo.out");
    ifstream fin("combo.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }
vector<int> v_perm1(3), v_perm2(3);
vector<int> st;
int total = 0, N;

bool valid(vector<int> p, vector<int> val) {
    bool ok = 1;
    for (int i = 0; i < 3; ++i) {
        bool cu = 0;
        for (int x = 0; x < 3; ++x) {
            if (p[i] == val[i] || mod(val[i] + x, N) == p[i] || mod(val[i]-x,N) == p[i] || mod(p[i] + x, N) == val[i] || mod(p[i] - x, N) == val[i]) {
                cu = 1;
            }
        }
        if (!cu) ok = 0;
    }

    return ok;
}

int main() {
    using namespace std_file;
    fin >> N;
    st.resize(N);
    for (int i = 0; i < N; ++i) st[i] = i + 1;
    for (int i = 0; i < 3; ++i) fin >> v_perm1[i];
    for (int i = 0; i < 3; ++i) fin >> v_perm2[i];
    int total = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int k = 1; k <= N; ++k)
                if (valid({i, j, k}, v_perm1) || valid({i,j,k}, v_perm2)) total++;
    fout << total << '\n';
    return 0;
}

