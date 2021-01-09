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
typedef long long ll;

const double E = 1e-8;
const double PI = acos(-1);
const int MOD = 1000000007;

using namespace std;

vector<vector<ll>> mul(vector<vector<ll>> X, vector<vector<ll>> Y) {
    ll x1 = ( X[0][0] * Y[0][0] ) % MOD + ( X[0][1] * Y[1][0] ) % MOD;
    ll x2 = ( X[0][0] * Y[0][1] ) % MOD + ( X[0][1] * Y[1][1] ) % MOD ;
    ll x3 = ( X[1][0] * Y[0][0] ) % MOD + ( X[1][1] * Y[1][0] ) % MOD ;
    ll x4 = ( X[1][0] * Y[0][1] ) % MOD + ( X[1][1] * Y[1][1] ) % MOD ;
    vector<vector<ll>> ans = { {x1, x2}, {x3, x4} };
    return ans;
}

vector<ll> modpow(ll n) {
    vector<vector<ll>> ans = {{1, 0}, {0, 1}};
    vector<int> v = {0, 1};
    vector<vector<ll>> X = {{0, 1}, {1, 1}};
    while (n > 0) {
        if (n & 1) ans = mul(ans, X);
        X = mul(X, X);
        n >>= 1;
    }

    vector<ll> fi = { ans[0][1] * v[1] % MOD, ans[1][1] * v[1] % MOD};
    return fi;
}

ll fib(ll n) {
    auto f = modpow(n);
    return f[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;
    ll ans = fib(n);
    cout << ans << '\n';
    return 0;
}

