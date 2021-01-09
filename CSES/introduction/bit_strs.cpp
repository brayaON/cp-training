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
const ll MOD = 1e9 + 7;

using namespace std;

ll mod_pow(ll n) {
    ll x = 2;
    ll ans = 1;
    while (n > 0) {
        if (n & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << mod_pow(n) << '\n';
    return 0;
}

