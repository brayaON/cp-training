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
const int MOD = 1000000007;
const long long MAX = 1e12 + 7;

using namespace std;
int arr[MAX] {};

vector<int> factors(int n) {
    vector<int> facts(n+1);
    set<int> st;
    for (int x = 2; x * x <= n; ++x) {
        while (n % x == 0) {
            if (st.count(x)) {
                facts[x] += 1;
            } else {
                st.insert(x);
                facts[x] = 1;
            }
            n /= x;
        }
    }
    if (n > 1) facts[n] = 1;
    return facts;
}

long long sum(long long x) {
    long long ans = 0;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ans = (ans + i) % MOD;
            if (i != x / i)
                ans = (ans + x / i) % MOD;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n; cin >> n;
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
        ans = (ans + sum(i)) % MOD;
    }
    vector<int> facts = factors(12246);
    for (int i = 2; i <= n; ++i) {
        if (facts[i]) {
            cout << i << "^" << facts[i] << " * ";
        }
    }
    cout << '\n';
    return 0;
}

