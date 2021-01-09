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
const int MOD_INT = 1000000007;

using namespace std;

long long exp(long long a, long long b, long long MOD) {
    long long ans = 1;
    a %= MOD; b %= MOD;
    while (b > 0) {
        if (b % 2 != 0) {
            ans = ((ans % MOD) * (a % MOD)) % MOD;
        }
        a %= MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        long long a, b, c; cin >> a >> b >> c;
        cout << exp(6, 17-2, 17) << '\n';
        long long cans = exp(b, c, MOD_INT - 1);
        cout << exp(a, cans, MOD_INT) << '\n';
    }
    return 0;
}

