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

using namespace std;

long long exp(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        long long a, b; cin >> a >> b;
        long long ans = exp(a, b);
        cout << ans << '\n';
    }
    return 0;
}

