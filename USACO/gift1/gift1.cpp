/*
ID: secondm1
TASK: gift1
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

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int np; fin >> np;
    map<string, int> mp;
    map<int, string> mp2;
    vector<int> cost(np, 0);
    for (int i = 0; i < np; ++i) {
        string s; fin >> s;
        mp[s] = i;
        mp2[i] = s;
    }

    for (int i = 0; i < np; ++i) {
        string name; fin >> name;
        int amount, count; fin >> amount >> count;
        if (count == 0 || amount == 0) continue;
        cost[mp[name]] = (cost[mp[name]] - amount) + (amount % count);
        int mgive = amount / count;
        for (int j = 0; j < count; ++j) {
            string name_2; fin >> name_2;
            cost[mp[name_2]] += mgive;
        }
    }

    for (int i = 0; i < np; ++i) {
        fout << mp2[i] << " " << cost[i] << endl;
    }

    return 0;
}

