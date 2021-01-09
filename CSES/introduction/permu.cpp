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
    vector<int> p;
    vector<int> im;
    if (n == 1) {
        cout << n << '\n';
        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 2; i <= n; i+=2) {
        p.push_back(i);
        im.push_back(i-1);
    }
    im.push_back(n);
    vector<int> ans(p.begin(),p.end());
    for (int i = 0; i < im.size(); ++i) ans.push_back(im[i]);

    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        if (!flag){
            cout << ans[i];
            flag = !flag;
        } else
            cout << " " << ans[i];
    }
    return 0;
}

