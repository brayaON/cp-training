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

using namespace std;
int dp[MAX] {};

int solve(int sum) {
    dp[0] = 1;
    for (int x = 1; x <= sum; ++x) {
        for (int j = 1; j <= 6; ++j) {
            if (x - j >= 0) {
                dp[x] += dp[x-j];
                dp[x] %= MOD;
            }
        }
    }

    return dp[sum];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    cout << solve(x) << '\n';
    return 0;
}

