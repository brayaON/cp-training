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
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << 1 << '\n';
        return 0;
    }
    char e = s[0]; 
    int ans = -1;
    int maxe = 1;
    for (int i = 1; i < s.size(); ++i) {
        if(s[i] == e) maxe++;
        else {
            e = s[i];
            maxe = 1;
        }
        ans = max(maxe, ans);
    }
    cout << ans << '\n';
    return 0;
}

