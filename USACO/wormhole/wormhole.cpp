/*
ID: secondm1
TASK: wormhole
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
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }
// (a b) (a c) (a d) (c d) (b d) (b c)

int main() {
    using namespace std_file;
    int N; fin >> N;
    vector<pii> v(N);
    for (int i = 0; i < N; ++i) {
        int x, y; fin >> x >> y;
        v[i] = {y, x};
    }
    return 0;
}

