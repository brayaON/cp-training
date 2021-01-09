/*
ID: secondm1
TASK: skidesign
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
    ofstream fout("skidesign.out");
    ifstream fin("skidesign.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }

int main() {
    using namespace std_file;
    int N; fin >> N;
    vector<ll> v(N); for (ll& i : v) fin >> i;
    int final_cost = INT_MAX;
    for (int i = 0; i < 84; ++i) {
        int h = i + 17;
        int part_cost = 0;
        for (int j = 0; j < N; ++j) {
            if (v[j] > h) part_cost += (h - v[j])*(h-v[j]);
            else if (v[j] < i) part_cost += (v[j]-i)*(v[j]-i);
        }
        final_cost = min(final_cost, part_cost);
    }
    fout << final_cost << '\n';
    return 0;
}

