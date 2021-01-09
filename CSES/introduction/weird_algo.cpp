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
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    cout << n << " ";
    while (n > 2) {
        if (n % 2) {
            n = 3 * n + 1;
            cout << n << " ";
        }
        else {
            n /= 2;
            cout << n << " ";
        }
    }

    cout << 1 << '\n';
    return 0;
}

