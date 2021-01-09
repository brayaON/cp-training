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
    vector<bool> v(n+7, false);
    for (int i = 0, a; i < n-1; ++i) {
        cin >> a;
        v[a] = true;
    }

    for (int i = 1; i <= n; ++i)
        if (!v[i]) cout << i << '\n';
    return 0;
}

