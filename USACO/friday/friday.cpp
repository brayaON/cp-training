/*
ID: secondm1
TASK: friday
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

struct Day {
    int c_pos;
    int i_pos;
    int count;
};

namespace std_file {
    ofstream fout("friday.out");
    ifstream fin("friday.in");
}

typedef struct Day Day;

void print(vector<Day>& v) {
    using namespace std_file;
    fout << v[5].count << " " << v[6].count;
    for (int i = 0; i < 5; ++i) {
        fout << " " << v[i].count;
    }
    fout << '\n';
}

void update(vector<Day>& v, int init) {
    vector<Day> cp(v.begin(), v.end());
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (v[j].c_pos == (i + init) % 7) cp[j].c_pos = i;
        }
    }
    v = cp;
}

void increment_13(vector<Day>& v) {
    for (int i = 0; i < 7; ++i) {
        if (v[i].c_pos == 5) v[i].count++;
    }
}

int main() {
    using namespace std_file;
    int n; fin >> n;
    vector<int> total_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<Day> week(7);
    for (int i = 0; i < 7; ++i) {
        week[i].c_pos = i;
        week[i].i_pos = i;
        week[i].count = 0;
    }
    int first_d = 0;
    for (int year = 1900; year < 1900 + n; year++) {
        bool is_leap = false;
        if (year % 100 == 0 && (year % 400 != 0 || year % 4 == 0)) is_leap = true;
        if (is_leap) total_days[1] = 29;
        else total_days[1] = 28;

        for (int month = 0; month < 12; month++) {
            increment_13(week);
            first_d = total_days[month] % 7;
            update(week, first_d);
        }
    }
    print(week);
    return 0;
}

