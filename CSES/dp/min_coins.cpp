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
const int INF = 1 << 30;

using namespace std;
const int max_v = 1e6+3;
int value[max_v] {};

int solve(int s, vector<int>& coins) {
    value[0] = 0;
    for (int x = 1; x <= s; ++x) {
        value[x] = INF;
        for (int c : coins) {
            if (x-c >= 0) {
                value[x] = min(value[x], value[x-c]+1);
            }
        }
    }
    return value[s];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    int ans =  solve(x, coins);
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}

