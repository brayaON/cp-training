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

#define _(x) { cout << #x << " = " << x << " "; }

const double E = 1e-8;
const double PI = acos(-1);
const int MAX = 1000000;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    vector<int> v(MAX + 1, 0);
    for (int i = 1; i <= MAX; ++i) {
        for (int j = i; j <= MAX; j += i) {
            v[j]++;
        }
    }

    while (t--) {
        int n; cin >> n;
        cout << v[n] << '\n';
    }
    return 0;
}

