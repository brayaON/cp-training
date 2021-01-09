/*
ID: secondm1
TASK: beads
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

namespace std_file {
    ofstream fout("beads.out");
    ifstream fin("beads.in");
}

int mod(int x, int n) { if (x < 0) x += n; return x % n; }

int main() {
    using namespace std_file;
    int n; fin >> n;
    string neck; fin >> neck;
    int max_beads = -1;
    for (int i = 0; i < n; ++i) {
        vector<bool> is_used(n, false);
        int ii = i;
        is_used[ii] = true;
        int curr_beads_f = 1;
        while (!is_used[mod(ii,n)] && neck[mod(ii,n)] == 'w') {
            ii++;
            curr_beads_f++;
            is_used[mod(ii,n)] = true;
        }
        int j = ii + 1;
        j = mod(j,n);
        while (!is_used[j] && (neck[j] == neck[ii % n] || neck[j] == 'w')) {
            curr_beads_f++;
            is_used[j % n] = true;
            j++;
            j = mod(j,n);
        }

        ii = mod(i - 1, n);
        int curr_beads_b = 0;
        if (!is_used[ii]) {
            curr_beads_b++;
            while (!is_used[ii] && neck[ii] == 'w') {
                ii--;
                ii = mod(ii, n);
                curr_beads_b++;
                is_used[ii] = true;
            }
            j = mod(ii - 1, n);
            while (!is_used[(j + n) % n] && (neck[(j + n) % n] == neck[(ii + n) % n] || neck[(j + n) % n] == 'w')) {
                curr_beads_b++;
                is_used[(j + n) % n] = true;
                j--;
            }
        }

        max_beads = max(max_beads, curr_beads_b + curr_beads_f);
    }
    fout << max_beads << '\n';
    return 0;
}

