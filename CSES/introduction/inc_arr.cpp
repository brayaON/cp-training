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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < n-1; ++i) {
        int a = v[i+1] - v[i];
        if (a < 0) {
            ans += a;
            v[i+1] = v[i];
        }
    }

    cout << abs(ans) << '\n';
    return 0;
}

