/*
ID: secondm1
TASK: barn1
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
typedef struct Gap Gap;

namespace std_file {
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }

struct Gap {
    int start, end, gap;
};


int main() {
    using namespace std_file;
    int M, S, C; fin >> M >> S >> C;
    vector<int> v(C); for (int& i : v) fin >> i;
    vector<bool> cnt(S + 1, 1);
    sort(v.begin(), v.end());
    vector<Gap> gaps;
    for (int i = 1; i < C; ++i)
        gaps.push_back({v[i - 1], v[i], v[i]-v[i-1]+1});

    fill(cnt.begin(), cnt.begin() + v[0], 0); // Fill w/ 0s leftmost stalls w/o cows in them
    fill(cnt.begin() + v[C - 1] + 1, cnt.end(), 0); // Fill w/ 0s rigtmost stalls w/o cows in them

    auto cmp = [](Gap g1, Gap g2) { return g1.gap > g2.gap; };
    sort(gaps.begin(), gaps.end(), cmp);
    for (int i = 0; i < min(M - 1,C - 1); ++i) {
        int start = gaps[i].start;
        int end = gaps[i].end;
        fill(cnt.begin() + start + 1, cnt.begin() + end, 0);
    }

    for (int i = 1; i <= S; ++i) {
        cout << i << " " << cnt[i] << '\n';
    }
    int total = count(cnt.begin(), cnt.end(), 1);
    fout << total << '\n';
    return 0;
}

