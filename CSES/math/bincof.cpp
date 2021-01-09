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
const int MAXN = 1e6 + 7;

using namespace std;
long long factorials[MAXN];

// O(log MAXN)
void compute_facts() {
    factorials[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        factorials[i] = ( factorials[i - 1] * i ) % MOD;
}

// O(log b)
long long binpow(long long a, long long b) {
    long long ans = 1;
    a %= MOD; b %= MOD;
    while (b > 0) {
        if (b % 2 != 0) {
            ans = (( ans % MOD ) * ( a % MOD )) % MOD;
        }
        a %= MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

long long inverse(long long x) {
    return binpow(x, MOD - 2);
}

// O(log n)
long long nck(long long n, long long k) {
    return factorials[n] * inverse( factorials[k] ) % MOD * inverse( factorials[n - k] ) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    compute_facts();
    int t; cin >> t;
    while (t--) {
        long long a, b; cin >> a >> b;
        long long ans = nck(a, b);
        cout << ans << '\n';
    }
    return 0;
}

