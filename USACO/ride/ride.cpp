/*
ID: secondm1
TASK: ride
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
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string a, b;
    fin >> a >> b;
    ll ta = 1, tb = 1;
    for  (int i = 0; i < (int)a.size(); ++i){
        ta *= ((a[i] - 'A') + 1);
    }
    for  (int i = 0; i < (int)b.size(); ++i){
        tb *= ((b[i] - 'A') + 1);
    }
    if ((ta % 47) == (tb % 47) ) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}

