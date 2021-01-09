/*
ID: secondm1
TASK: milk
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
    ofstream fout("milk.out");
    ifstream fin("milk.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }

int main() {
    using namespace std_file;
    int N, M; fin >> N >> M;
    vector<pii> v(M);
    for (int i = 0; i < M; ++i) {
        int a, b; fin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());
    ll total = 0;
    for (int i = 0; i < M && N; ++i) {
        int units = min(N, v[i].second);
        total += v[i].first * units;
        N -= units;
    }
    fout << total << '\n';
    return 0;
}

