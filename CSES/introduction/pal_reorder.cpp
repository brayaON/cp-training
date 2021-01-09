#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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
    string s;
    cin >> s;
    bool p = 0;
    int n = s.size();
    if (n % 2) p = 1;

    if (n == 1) {
        cout << s << '\n';
        return 0;
    }

    map<char, int> m;
    for (int i = 0; i < n; ++i) m[s[i]]++;

    int cnt = 0;
    char mid {};
    for (auto e : m){
        if (e.second % 2){
            cnt++;
            mid = e.first;
        }
    } 

    if (p^cnt) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string t1 = "",t2 = "";
    for (auto e : m) {
        string t(e.second/2,e.first);
        t1 = t1 + t;
        t2 = t + t2;
    }
    cout << (p ? (t1+mid+t2) : t1+t2) << '\n';
    return 0;
}

