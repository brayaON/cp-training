/*
ID: secondm1
TASK: milk2
LANG: C++
*/
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
#include <fstream>
#include <string>

using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pii;

namespace std_file {
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }

int main() {
    using namespace std_file;
    int n; fin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        int a, b; fin >> a >> b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end());
    int start = v[0].first, end = v[0].second;
    int longest_milked = end - start;
    int longest_idle = 0;
    bool fl = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i].first <= end) { 
            end = max(end, v[i].second);
            if (i == n - 1) fl = 1;
        }
        else {
            longest_milked = max(longest_milked, end - start);
            longest_idle = max(longest_idle, v[i].first - end);
            start = v[i].first;
            end = v[i].second;
            longest_milked = max(longest_milked, end - start);
        }
    }
    if (fl) longest_milked = max(longest_milked, v[n - 1].second - start);
    fout << longest_milked << " " << longest_idle << '\n';
    return 0;
}

