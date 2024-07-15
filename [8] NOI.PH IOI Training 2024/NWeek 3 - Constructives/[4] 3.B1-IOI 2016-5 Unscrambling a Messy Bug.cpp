// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "messy.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

#ifdef DEBUG
int n;
vector<int> P;

vector<string> DS;
void add_element(string x) {
    DS.pb(x);

    return;
}

map<string, bool> chk;
void compile_set() {
    for (auto &x : DS) {
        string nx(n, 'X');
        for (int i = 0; i < n; i++)
            nx[i] = x[P[i]];

        chk[nx] = true;    
        x = nx;
    }

    return;
}

bool check_element(string x) {
    return chk[x];
}
#endif

vector<int> restore_permutation(int n, int w, int r) {
    int n2 = 1;
    while (n2 < n) {
        n2 *= 2;
    }

    for (int i = n2; i >= 2; i /= 2) {
        string inp(n, '1');
        for (int j = 0; j < n; j += i) {
            if (j + i / 2 >= n)
                continue;

            for (int k = j; k < min(j + i, n); k++)
                inp[k] = '0';

            for (int k = j; k < min(j + i / 2, n); k++) {
                inp[k] = '1';
                add_element(inp);
                // cout << inp << endl;
                inp[k] = '0';
            }

            for (int k = j; k < min(j + i, n); k++)
                inp[k] = '1';
        }
        // cout << endl;
    }

    compile_set();

    vector<int> V(n);
    iota(V.begin(), V.end(), 0);
    map<vector<int>, vector<int>> bgn_end;
    bgn_end[V] = V;
    bgn_end[{}] = {};
    for (int i = n2; i >= 2; i /= 2) {
        vector<vector<int>> ends;
        for (int j = 0; j < n; j += i) {
            vector<int> bgn;
            for (int k = j; k < min(j + i, n); k++)
                bgn.push_back(k);
            
            ends.push_back(bgn_end[bgn]);
        }

        string inp(n, '1');
        for (int j = 0; j < n; j += i) {
            if (j + i / 2 >= n)
                continue;

            for (int x : ends[j / i])
                inp[x] = '0';

            vector<int> b1;
            for (int k = j; k < min(j + i / 2, n); k++)
                b1.pb(k);
            vector<int> b2;
            for (int k = min(j + i / 2, n); k < min(j + i, n); k++)
                b2.pb(k);

            vector<int> e1, e2;
            for (int k = 0; k < n; k++) {
                if (inp[k] == '1')
                    continue;
                inp[k] = '1';

                // cout << inp << ' ';
                if (check_element(inp))
                    e1.push_back(k);
                else
                    e2.push_back(k);
            
                inp[k] = '0';
            }
            // cout << endl;

            // for (int x : e1)
            //     cout << x << ' ';
            // cout << endl;
            // for (int x : e2)
            //     cout << x << ' ';
            // cout << endl;

            bgn_end[b1] = e1;
            bgn_end[b2] = e2;

            for (int x : ends[j / i])
                inp[x] = '1';
        }
        // cout << endl;
    }

    // for (auto [x, y] : bgn_end) {
    //     for (int z : x)
    //         cout << z << ' ';
    //     cout << "-> ";
    //     for (int z : y)
    //         cout << z << ' ';
    //     cout << endl; 
    // }

    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[bgn_end[{i}].back()] = i;
    // for (int x : res)
    //     cout << x << ' ';
    // cout << endl;
    return res;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int w, r;
        cin >> n >> w >> r;
        P.clear();
        P.resize(n);
        for (int &p : P)
            cin >> p;

        restore_permutation(n, w, r);
    }

    return 0;
}
#endif