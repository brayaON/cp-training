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
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;
const int INF = 1 << 30;

using namespace std;
int cnt[MAX] {};
int value[MAX] {};

int solve(int sm, vector<int>& coins) {
    cnt[0] = 1;
    for (int x = 1; x <= sm; ++x) {
        value[x] = INF;
        for (int c : coins) {
            if (x - c >= 0) {
                cnt[x] += cnt[x-c];
                cnt[x] %= MOD;
            }
        }
    }

    return cnt[sm];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    cout << solve(x, coins) << '\n';
    return 0;
}

