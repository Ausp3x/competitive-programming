// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

bool is_valid(int grid) {
    int exp = 0;
    while (!(grid & (1 << exp))) {
        exp++;
    }

    int vst = 0;
    queue<int> q;
    q.push(exp);
    vst |= 1 << exp;
    while (!q.empty()) {
        int cur_exp = q.front();
        q.pop();

        if (cur_exp > 3) {
            if ((grid & (1 << (cur_exp - 4))) && !(vst & (1 << (cur_exp - 4)))) {
                q.push(cur_exp - 4);
                vst |= 1 << (cur_exp - 4);
            }
        }

        if (cur_exp < 12) {
            if ((grid & (1 << (cur_exp + 4))) && !(vst & (1 << (cur_exp + 4)))) {
                q.push(cur_exp + 4);
                vst |= 1 << (cur_exp + 4);
            }
        }

        if (cur_exp % 4 != 0) {
            if ((grid & (1 << (cur_exp - 1))) && !(vst & (1 << (cur_exp - 1)))) {
                q.push(cur_exp - 1);
                vst |= 1 << (cur_exp - 1);
            }
        }

        if (cur_exp % 4 != 3) {
            if ((grid & (1 << (cur_exp + 1))) && !(vst & (1 << (cur_exp + 1)))) {
                q.push(cur_exp + 1);
                vst |= 1 << (cur_exp + 1);
            }
        }
    }

    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            if (grid & (1 << (i * 4 + j))) {
                continue;
            }

            if (grid & (1 << ((i - 1) * 4 + j)) &&
                grid & (1 << (i * 4 + j - 1)) &&
                grid & (1 << (i * 4 + j + 1)) &&
                grid & (1 << ((i + 1) * 4 + j))
            ) {
                return false;
            } 
        }
    }

    bool chk = false;
    if ((grid & 32) && (grid & 64) && (grid & 512) && (grid & 1024)) {
        chk = true;
    }
    if (!(grid & 32)) {
        if (!((grid & 2) && (grid & 16))) {
            chk = true;
        }
    } 
    if (!(grid & 64)) {
        if (!((grid & 4) && (grid & 128))) {
            chk = true;
        }
    }
    if (!(grid & 512)) {
        if (!((grid & 256) && (grid & 8192))) {
            chk = true;
        }
    }
    if (!(grid & 1024)) {
        if (!((grid & 2048) && (grid & 16384))) {
            chk = true;
        }
    }

    if (!chk) {
        return false;
    }

    return vst == grid;

    /*
    if (vst == grid) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << (grid & 1) << ' ';
                grid >>= 1;
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }

    return false;
    //*/
}

void solve() {
    int grid = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            bool a;
            cin >> a;
            grid |= a << (i * 4 + j);
        }
    }

    // cout << grid << endl;

    int ans = 0;
    // int cnt = 0;
    for (int cur_grid = 1; cur_grid < 65536; cur_grid++) {
        if ((cur_grid & grid) == grid) {
            ans += is_valid(cur_grid);
            // cnt++;
        }
    }

    cout << ans << endl;
    // cout << cnt << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}