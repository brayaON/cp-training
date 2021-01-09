/*
ID: secondm1
TASK: namenum
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
const int MAX = 8;
typedef long long ll;

namespace std_file {
    ofstream fout("namenum.out");
    ifstream fin("namenum.in");
}

vector<char> to[] = { {'A','B','C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W', 'X', 'Y'} };
vector<string> dict;

void read_dict() {
    ifstream dict_file ("dict.txt");
    if (dict_file.is_open()) {
        string line;
        while (getline(dict_file, line)) {
            dict.push_back(line);
        }
        dict_file.close();
    }
}

string perm;
vector<string> ans;
bool print = false;

void gen_names(string N, int start) {
    if (perm.size() == N.size()) {
        auto it = lower_bound(dict.begin(), dict.end(), perm);
        if (*it == perm) {
            std_file::fout << perm << '\n';
            print = true;
        }
    } else {
        for (int i = start; i < (int)N.size(); ++i){
            for (int j = 0; j < 3; ++j) {
                if (i == start) {
                    perm.push_back(to[(N[i] - '0') - 2][j]);
                    gen_names(N, start + 1);
                    perm.pop_back();
                }
            }
        }
    }
}

int main() {
    using namespace std_file;
    string N; fin >> N;
    read_dict();
    gen_names(N, 0);
    if (!print) { fout << "NONE\n"; }
    return 0;
}

