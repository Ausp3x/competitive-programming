// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    map<string, int> move_idxs = {
        {"ROCK", 0},
        {"PAPER", 1},
        {"SCISSORS", 2},
        {"GUN", 3},
        {"SLAP", 4}
    };

    // row is Pering the Platypus
    // col is Dr. Oof
    // -1 Pering wins, 0 tie, 1 Oof wins
    vector<vector<int>> match_results = {
        {0, 1, -1, 1, -1},
        {-1, 0, 1, 1, -1},
        {1, -1, 0, 1, -1},
        {-1, -1, -1, 0, 1},
        {1, 1, 1, -1, 0}
    };

    string p_move, o_move;
    cin >> p_move >> o_move;

    int res = match_results[move_idxs[p_move]][move_idxs[o_move]];

    if (res == -1) {
        cout << "PLATYPUS" << endl;
    } else if (res == 0) {
        cout << "TIE" << endl;
    } else if (res == 1) {
        cout << "OOF" << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}