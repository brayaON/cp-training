/*
ID: secondm1
TASK: transform
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
    ofstream fout("transform.out");
    ifstream fin("transform.in");
}

void t_90(vector<vector<char>>& m, int N) {
    for (int x = 0; x < N / 2; ++x) {
        for (int y = x; y < N - x - 1; ++y) {
            char tmp = m[x][y];
            m[x][y] = m[N - y - 1][x]; // left -> top 
            m[N - 1 - y][x] = m[N - x - 1][N - y - 1]; // bottom -> left
            m[N - x - 1][N - y - 1] = m[y][N - x - 1]; // rigth -> bottom
            m[y][N - x - 1] = tmp; // top -> rigth;
        }
    }
}

void t_180(vector<vector<char>>& m, int N) {
    t_90(m, N);
    t_90(m, N);
}

void t_270(vector<vector<char>>& m, int N) {
    t_90(m, N);
    t_90(m, N);
    t_90(m, N);
}

void reflect(vector<vector<char>>& m, int N) {
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N / 2; ++y) {
            char tmp = m[x][y];
            m[x][y] = m[x][N - y - 1];
            m[x][N - y - 1] = tmp;
        }
    }
}

int main() {
    using namespace std_file;

    int N; fin >> N;
    vector<vector<char>> o_grid(N, vector<char>(N));
    vector<vector<char>> a_grid(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        string s; fin >> s;
        for (int j = 0; j < N; ++j) {
            o_grid[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; ++i) {
        string s; fin >> s;
        for (int j = 0; j < N; ++j) {
            a_grid[i][j] = s[j];
        }
    }

    int ans = -1;
    for (int i = 1; i <= 6; ++i) {
        vector<vector<char>> aux_g(o_grid);
        switch(i) {
            case 1:
                t_90(aux_g, N);
                break;
            case 2:
                t_180(aux_g, N);
                break;
            case 3:
                t_270(aux_g, N);
                break;
            case 4:
                reflect(aux_g, N);
                break;
            case 5:
                reflect(aux_g, N);
                for (int j = 1; j <= 3; ++j) {
                    vector<vector<char>> aux_g2(aux_g);
                    if (j == 1) t_90(aux_g, N);
                    else if (j == 2) t_180(aux_g, N);
                    else t_270(aux_g, N);
                    if (aux_g2 == a_grid) {
                        aux_g = aux_g2;
                        break;
                    }
                }
                break;
        }
        if (aux_g == a_grid) {
            ans = i;
            break;
        }
    }
    fout << (ans == -1 ? 7 : ans) << '\n';
    return 0;
}

