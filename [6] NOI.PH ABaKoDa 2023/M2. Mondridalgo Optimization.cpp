// 人外有人，天外有天
// author: Ausp3x
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target ("avx2")
 
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;
 
int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;
 
void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> us(r + 2, vector<int>(c + 2, -INF32));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> us[i][j];
        }
    } 
    vector<vector<int>> vs(r + 2, vector<int>(c + 2, -INF32));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> vs[i][j];
        }
    }
 
    if (k <= 2) {
        lng ans = INF64;
        for (int i = 1; i < r; i++) {
            lng alice_happy1 = 0, cindy_happy1 = 0;
            lng alice_happy2 = 0, cindy_happy2 = 0;
            for (int ii = 1; ii <= r; ii++) {
                for (int jj = 1; jj <= c; jj++) {
                    if (ii <= i && jj <= c) {
                        alice_happy1 += us[ii][jj];
                        cindy_happy2 += vs[ii][jj];
                    } else {
                        cindy_happy1 += vs[ii][jj];
                        alice_happy2 += us[ii][jj];
                    }
                }
            }
            ans = min(ans, abs(alice_happy1 - cindy_happy1));
            ans = min(ans, abs(alice_happy2 - cindy_happy2));
        }
 
        for (int j = 1; j < c; j++) {
            lng alice_happy1 = 0, cindy_happy1 = 0;
            lng alice_happy2 = 0, cindy_happy2 = 0;
            for (int ii = 1; ii <= r; ii++) {
                for (int jj = 1; jj <= c; jj++) {
                    if (ii <= r && jj <= j) {
                        alice_happy1 += us[ii][jj];
                        cindy_happy2 += vs[ii][jj];
                    } else {
                        cindy_happy1 += vs[ii][jj];
                        alice_happy2 += us[ii][jj];
                    }
                }
            }
            ans = min(ans, abs(alice_happy1 - cindy_happy1));
            ans = min(ans, abs(alice_happy2 - cindy_happy2));
        }
 
        if (k == 1) {
            cout << ans << endl;
            return;
        }
 
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                lng alice_happy1 = 0, cindy_happy1 = 0;
                lng alice_happy2 = 0, cindy_happy2 = 0;
                for (int ii = 1; ii <= r; ii++) {
                    for (int jj = 1; jj <= c; jj++) {
                        if (ii <= i && jj <= j) {
                            alice_happy1 += us[ii][jj];
                            cindy_happy2 += vs[ii][jj];
                        } else {
                            cindy_happy1 += vs[ii][jj];
                            alice_happy2 += us[ii][jj];
                        }
                    }
                }
                ans = min(ans, abs(alice_happy1 - cindy_happy1));
                ans = min(ans, abs(alice_happy2 - cindy_happy2));
            }
        }
 
        for (int i = 1; i < r; i++) {
            for (int j = c; j > 1; j--) {
                lng alice_happy1 = 0, cindy_happy1 = 0;
                lng alice_happy2 = 0, cindy_happy2 = 0;
                for (int ii = 1; ii <= r; ii++) {
                    for (int jj = 1; jj <= c; jj++) {
                        if (ii <= i && jj >= j) {
                            alice_happy1 += us[ii][jj];
                            cindy_happy2 += vs[ii][jj];
                        } else {
                            cindy_happy1 += vs[ii][jj];
                            alice_happy2 += us[ii][jj];
                        }
                    }
                }
                ans = min(ans, abs(alice_happy1 - cindy_happy1));
                ans = min(ans, abs(alice_happy2 - cindy_happy2));
            }
        }
 
        for (int i = r; i > 1; i--) {
            for (int j = 1; j < c; j++) {
                lng alice_happy1 = 0, cindy_happy1 = 0;
                lng alice_happy2 = 0, cindy_happy2 = 0;
                for (int ii = 1; ii <= r; ii++) {
                    for (int jj = 1; jj <= c; jj++) {
                        if (ii >= i && jj <= j) {
                            alice_happy1 += us[ii][jj];
                            cindy_happy2 += vs[ii][jj];
                        } else {
                            cindy_happy1 += vs[ii][jj];
                            alice_happy2 += us[ii][jj];
                        }
                    }
                }
                ans = min(ans, abs(alice_happy1 - cindy_happy1));
                ans = min(ans, abs(alice_happy2 - cindy_happy2));
            }
        }
 
        for (int i = r; i > 1; i--) {
            for (int j = c; j > 1; j--) {
                lng alice_happy1 = 0, cindy_happy1 = 0;
                lng alice_happy2 = 0, cindy_happy2 = 0;
                for (int ii = 1; ii <= r; ii++) {
                    for (int jj = 1; jj <= c; jj++) {
                        if (ii >= i && jj >= j) {
                            alice_happy1 += us[ii][jj];
                            cindy_happy2 += vs[ii][jj];
                        } else {
                            cindy_happy1 += vs[ii][jj];
                            alice_happy2 += us[ii][jj];
                        }
                    }
                }
                ans = min(ans, abs(alice_happy1 - cindy_happy1));
                ans = min(ans, abs(alice_happy2 - cindy_happy2));
            }
        }
        cout << ans << endl;
 
        return;
    }
 
    if (r <= 4 && c <= 4) {
        lng ans = INF64;
        for (int bit = 0; bit < (1 << r * c); bit++) {
            vector<vector<char>> grid(r + 2, vector<char>(c + 2, 'X'));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (bit & (1 << (i * c + j))) {
                        grid[i + 1][j + 1] = 'A';
                    } else {
                        grid[i + 1][j + 1] = 'C';
                    }
                }
            }
 
            bool a_edge = false, c_edge = false;
            for (int i = 1; i <= r; i++) {
                if (grid[i][1] == 'A' || grid[i][c] == 'A') {
                    a_edge = true;
                }
            
                if (grid[i][1] == 'C' || grid[i][c] == 'C') {
                    c_edge = true;
                }
            }
            for (int j = 1; j <= c; j++) {
                if (grid[1][j] == 'A' || grid[r][j] == 'A') {
                    a_edge = true;
                }
            
                if (grid[1][j] == 'C' || grid[r][j] == 'C') {
                    c_edge = true;
                }
            }
 
            if ((!a_edge) || (!c_edge)) {
                continue;
            }
 
            int a_partitions = 0;
            vector<vector<bool>> vst(r + 2, vector<bool>(c + 2, false));
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] != 'A') {
                        continue;
                    }
 
                    if (vst[i][j]) {
                        continue;
                    }
 
                    a_partitions++;
 
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vst[i][j] = true;
                    while (!q.empty()) {
                        auto [i_cur, j_cur] = q.front();
                        q.pop();
 
                        vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                        for (auto [di, dj] : di_djs) {
                            if (grid[i_cur + di][j_cur + dj] != 'A') {
                                continue;
                            }
                            
                            if (vst[i_cur + di][j_cur + dj]) {
                                continue;
                            }
 
                            q.push({i_cur + di, j_cur + dj});
                            vst[i_cur + di][j_cur + dj] = true;
                        }
                    }
                }
            }
 
            if (a_partitions != 1) {
                continue;
            }
 
            int c_partitions = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] != 'C') {
                        continue;
                    }
 
                    if (vst[i][j]) {
                        continue;
                    }
 
                    c_partitions++;
 
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vst[i][j] = true;
                    while (!q.empty()) {
                        auto [i_cur, j_cur] = q.front();
                        q.pop();
 
                        vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                        for (auto [di, dj] : di_djs) {
                            if (grid[i_cur + di][j_cur + dj] != 'C') {
                                continue;
                            }
                            
                            if (vst[i_cur + di][j_cur + dj]) {
                                continue;
                            }
 
                            q.push({i_cur + di, j_cur + dj});
                            vst[i_cur + di][j_cur + dj] = true;
                        }
                    }
                }
            }
            
            if (c_partitions != 1) {
                continue;
            }
 
            int cnt = 0;
            for (int i = 1; i < r; i++) {
                int prv = -1;
                for (int j = 1; j <= c; j++) {
                    if ((grid[i][j] == 'A' && grid[i + 1][j] == 'C') || (grid[i][j] == 'C' && grid[i + 1][j] == 'A')) {
                        if (j - prv > 1) {
                            cnt++;
                        }
                        prv = j;
                    }
                }
            }
            for (int j = 1; j < c; j++) {
                int prv = -1;
                for (int i = 1; i <= r; i++) {
                    if ((grid[i][j] == 'A' && grid[i][j + 1] == 'C') || (grid[i][j] == 'C' && grid[i][j + 1] == 'A')) {
                        if (i - prv > 1) {
                            cnt++;
                        }
                        prv = i;
                    }
                }
            }
            
            if (cnt > k) {
                continue;
            }
            
            lng alice_happy = 0, cindy_happy = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] == 'A') {
                        alice_happy += us[i][j];
                    } else {
                        cindy_happy += vs[i][j];
                    }
                }
            }
            ans = min(ans, abs(alice_happy - cindy_happy));
        }
        cout << ans << endl;
 
        return;
    }
 
    lng ans = INF64;
 
    int bit = pow(c + 1, r);
    for (int i = 0; i < bit; i++) {
        int cur = i, pow_c = pow(c + 1, r - 1), ii = 1;
        vector<vector<char>> grid(r + 2, vector<char>(c + 2, 'X'));
        while (pow_c > 0) {
            for (int j = 1; j <= cur / pow_c; j++) {
                grid[ii][j] = 'A';
            }
            for (int j = cur / pow_c + 1; j <= c; j++) {
                grid[ii][j] = 'C';
            }
 
            cur %= pow_c;
            pow_c /= (c + 1);
            ii++;
        }
 
        bool a_edge = false, c_edge = false;
        for (int i = 1; i <= r; i++) {
            if (grid[i][1] == 'A' || grid[i][c] == 'A') {
                a_edge = true;
            }
        
            if (grid[i][1] == 'C' || grid[i][c] == 'C') {
                c_edge = true;
            }
        }
        for (int j = 1; j <= c; j++) {
            if (grid[1][j] == 'A' || grid[r][j] == 'A') {
                a_edge = true;
            }
        
            if (grid[1][j] == 'C' || grid[r][j] == 'C') {
                c_edge = true;
            }
        }
 
        if ((!a_edge) || (!c_edge)) {
            continue;
        }
 
        int a_partitions = 0;
        vector<vector<bool>> vst(r + 2, vector<bool>(c + 2, false));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] != 'A') {
                    continue;
                }
 
                if (vst[i][j]) {
                    continue;
                }
 
                a_partitions++;
 
                queue<pair<int, int>> q;
                q.push({i, j});
                vst[i][j] = true;
                while (!q.empty()) {
                    auto [i_cur, j_cur] = q.front();
                    q.pop();
 
                    vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                    for (auto [di, dj] : di_djs) {
                        if (grid[i_cur + di][j_cur + dj] != 'A') {
                            continue;
                        }
                        
                        if (vst[i_cur + di][j_cur + dj]) {
                            continue;
                        }
 
                        q.push({i_cur + di, j_cur + dj});
                        vst[i_cur + di][j_cur + dj] = true;
                    }
                }
            }
        }
 
        if (a_partitions != 1) {
            continue;
        }
 
        int c_partitions = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] != 'C') {
                    continue;
                }
 
                if (vst[i][j]) {
                    continue;
                }
 
                c_partitions++;
 
                queue<pair<int, int>> q;
                q.push({i, j});
                vst[i][j] = true;
                while (!q.empty()) {
                    auto [i_cur, j_cur] = q.front();
                    q.pop();
 
                    vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                    for (auto [di, dj] : di_djs) {
                        if (grid[i_cur + di][j_cur + dj] != 'C') {
                            continue;
                        }
                        
                        if (vst[i_cur + di][j_cur + dj]) {
                            continue;
                        }
 
                        q.push({i_cur + di, j_cur + dj});
                        vst[i_cur + di][j_cur + dj] = true;
                    }
                }
            }
        }
        
        if (c_partitions != 1) {
            continue;
        }
 
        int cnt = 0;
        for (int i = 1; i < r; i++) {
            int prv = -1;
            for (int j = 1; j <= c; j++) {
                if ((grid[i][j] == 'A' && grid[i + 1][j] == 'C') || (grid[i][j] == 'C' && grid[i + 1][j] == 'A')) {
                    if (j - prv > 1) {
                        cnt++;
                    }
                    prv = j;
                }
            }
        }
        for (int j = 1; j < c; j++) {
            int prv = -1;
            for (int i = 1; i <= r; i++) {
                if ((grid[i][j] == 'A' && grid[i][j + 1] == 'C') || (grid[i][j] == 'C' && grid[i][j + 1] == 'A')) {
                    if (i - prv > 1) {
                        cnt++;
                    }
                    prv = i;
                }
            }
        }
        
        if (cnt > k) {
            continue;
        }
        
        lng alice_happy1 = 0, cindy_happy1 = 0;
        lng alice_happy2 = 0, cindy_happy2 = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] == 'A') {
                    alice_happy1 += us[i][j];
                    cindy_happy2 += vs[i][j];
                } else {
                    cindy_happy1 += vs[i][j];
                    alice_happy2 += us[i][j];
                }
            }
        } 
        
        ans = min(ans, abs(alice_happy1 - cindy_happy1));
        ans = min(ans, abs(alice_happy2 - cindy_happy2));
    }
 
    bit = pow(r + 1, c);
    for (int j = 0; j < bit; j++) {
        int cur = j, pow_r = pow(r + 1, c - 1), jj = 1;
        vector<vector<char>> grid(r + 2, vector<char>(c + 2, 'X'));
        while (pow_r > 0) {
            for (int i = 1; i <= cur / pow_r; i++) {
                grid[i][jj] = 'A';
            }
            for (int i = cur / pow_r + 1; i <= r; i++) {
                grid[i][jj] = 'C';
            }
 
            cur %= pow_r;
            pow_r /= (r + 1);
            jj++;
        }
 
        bool a_edge = false, c_edge = false;
        for (int i = 1; i <= r; i++) {
            if (grid[i][1] == 'A' || grid[i][c] == 'A') {
                a_edge = true;
            }
        
            if (grid[i][1] == 'C' || grid[i][c] == 'C') {
                c_edge = true;
            }
        }
        for (int j = 1; j <= c; j++) {
            if (grid[1][j] == 'A' || grid[r][j] == 'A') {
                a_edge = true;
            }
        
            if (grid[1][j] == 'C' || grid[r][j] == 'C') {
                c_edge = true;
            }
        }
 
        if ((!a_edge) || (!c_edge)) {
            continue;
        }
 
        int a_partitions = 0;
        vector<vector<bool>> vst(r + 2, vector<bool>(c + 2, false));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] != 'A') {
                    continue;
                }
 
                if (vst[i][j]) {
                    continue;
                }
 
                a_partitions++;
 
                queue<pair<int, int>> q;
                q.push({i, j});
                vst[i][j] = true;
                while (!q.empty()) {
                    auto [i_cur, j_cur] = q.front();
                    q.pop();
 
                    vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                    for (auto [di, dj] : di_djs) {
                        if (grid[i_cur + di][j_cur + dj] != 'A') {
                            continue;
                        }
                        
                        if (vst[i_cur + di][j_cur + dj]) {
                            continue;
                        }
 
                        q.push({i_cur + di, j_cur + dj});
                        vst[i_cur + di][j_cur + dj] = true;
                    }
                }
            }
        }
 
        if (a_partitions != 1) {
            continue;
        }
 
        int c_partitions = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] != 'C') {
                    continue;
                }
 
                if (vst[i][j]) {
                    continue;
                }
 
                c_partitions++;
 
                queue<pair<int, int>> q;
                q.push({i, j});
                vst[i][j] = true;
                while (!q.empty()) {
                    auto [i_cur, j_cur] = q.front();
                    q.pop();
 
                    vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                    for (auto [di, dj] : di_djs) {
                        if (grid[i_cur + di][j_cur + dj] != 'C') {
                            continue;
                        }
                        
                        if (vst[i_cur + di][j_cur + dj]) {
                            continue;
                        }
 
                        q.push({i_cur + di, j_cur + dj});
                        vst[i_cur + di][j_cur + dj] = true;
                    }
                }
            }
        }
        
        if (c_partitions != 1) {
            continue;
        }
 
        int cnt = 0;
        for (int i = 1; i < r; i++) {
            int prv = -1;
            for (int j = 1; j <= c; j++) {
                if ((grid[i][j] == 'A' && grid[i + 1][j] == 'C') || (grid[i][j] == 'C' && grid[i + 1][j] == 'A')) {
                    if (j - prv > 1) {
                        cnt++;
                    }
                    prv = j;
                }
            }
        }
        for (int j = 1; j < c; j++) {
            int prv = -1;
            for (int i = 1; i <= r; i++) {
                if ((grid[i][j] == 'A' && grid[i][j + 1] == 'C') || (grid[i][j] == 'C' && grid[i][j + 1] == 'A')) {
                    if (i - prv > 1) {
                        cnt++;
                    }
                    prv = i;
                }
            }
        }
        
        if (cnt > k) {
            continue;
        }
        
        lng alice_happy1 = 0, cindy_happy1 = 0;
        lng alice_happy2 = 0, cindy_happy2 = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] == 'A') {
                    alice_happy1 += us[i][j];
                    cindy_happy2 += vs[i][j];
                } else {
                    cindy_happy1 += vs[i][j];
                    alice_happy2 += us[i][j];
                }
            }
        } 
        
        ans = min(ans, abs(alice_happy1 - cindy_happy1));
        ans = min(ans, abs(alice_happy2 - cindy_happy2));
    }
 
    for (int i1 = 1; i1 <= r; i1++) {
    for (int j1 = 1; j1 <= c; j1++) {
    for (int i2 = i1 + 1; i2 <= r; i2++) {
    for (int j2 = j1 + 1; j2 <= c; j2++) {
        if (i1 != 1 && j1 != 1 && i2 != r && j2 != c) {
            continue;
        }
 
        if (i1 == 1 && j1 == 1 && i2 == r && j2 == c) {
            continue;
        }
 
        int rr = i2 - i1 + 1, cc = j2 - j1 + 1; 
 
        if (rr < 3 || cc < 3 || rr * cc < 6) {
            continue;
        }
        
        int bit = pow(2 * cc, rr);
        for (int b = 0; b < bit; b++) {
            int prv = -1, chk = 0;
            int cur = b, pow_cc = pow(2 * cc, rr - 1);
            while (pow_cc > 0) {
                int d = cur / pow_cc;
                if (d != prv) {
                    chk++;
                }
                prv = d;

                cur %= pow_cc;
                pow_cc /= (2 * cc);
            }
            if (chk < 2 || chk > 3) {
                continue;
            } 

            vector<vector<char>> grid(r + 2, vector<char>(c + 2, 'X'));
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    grid[i][j] = 'C';
                }
            }
            
            cur = b, pow_cc = pow(2 * cc, rr - 1);
            int di = 0;
            while (pow_cc > 0) {
                int d = cur / pow_cc;

                if (d <= cc) {
                    for (int dj = 0; dj < d; dj++) {
                        grid[i1 + di][j1 + dj] = 'A';
                    }
                } else {
                    d = 2 * cc - d;
                    for (int dj = d; dj < cc; dj++) {
                        grid[i1 + di][j1 + dj] = 'A';
                    }
                }

                cur %= pow_cc;
                pow_cc /= (2 * cc);
                di++;
            }
 
            bool a_edge = false, c_edge = false;
            for (int i = 1; i <= r; i++) {
                if (grid[i][1] == 'A' || grid[i][c] == 'A') {
                    a_edge = true;
                }
            
                if (grid[i][1] == 'C' || grid[i][c] == 'C') {
                    c_edge = true;
                }
            }
            for (int j = 1; j <= c; j++) {
                if (grid[1][j] == 'A' || grid[r][j] == 'A') {
                    a_edge = true;
                }
            
                if (grid[1][j] == 'C' || grid[r][j] == 'C') {
                    c_edge = true;
                }
            }
 
            if ((!a_edge) || (!c_edge)) {
                continue;
            }
 
            int a_partitions = 0;
            vector<vector<bool>> vst(r + 2, vector<bool>(c + 2, false));
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] != 'A') {
                        continue;
                    }
 
                    if (vst[i][j]) {
                        continue;
                    }
 
                    a_partitions++;
 
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vst[i][j] = true;
                    while (!q.empty()) {
                        auto [i_cur, j_cur] = q.front();
                        q.pop();
 
                        vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                        for (auto [di, dj] : di_djs) {
                            if (grid[i_cur + di][j_cur + dj] != 'A') {
                                continue;
                            }
                            
                            if (vst[i_cur + di][j_cur + dj]) {
                                continue;
                            }
 
                            q.push({i_cur + di, j_cur + dj});
                            vst[i_cur + di][j_cur + dj] = true;
                        }
                    }
                }
            }
 
            if (a_partitions != 1) {
                continue;
            }
 
            int c_partitions = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] != 'C') {
                        continue;
                    }
 
                    if (vst[i][j]) {
                        continue;
                    }
 
                    c_partitions++;
 
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vst[i][j] = true;
                    while (!q.empty()) {
                        auto [i_cur, j_cur] = q.front();
                        q.pop();
 
                        vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                        for (auto [di, dj] : di_djs) {
                            if (grid[i_cur + di][j_cur + dj] != 'C') {
                                continue;
                            }
                            
                            if (vst[i_cur + di][j_cur + dj]) {
                                continue;
                            }
 
                            q.push({i_cur + di, j_cur + dj});
                            vst[i_cur + di][j_cur + dj] = true;
                        }
                    }
                }
            }
            
            if (c_partitions != 1) {
                continue;
            }
 
            int cnt = 0;
            for (int i = 1; i < r; i++) {
                int prv = -1;
                for (int j = 1; j <= c; j++) {
                    if ((grid[i][j] == 'A' && grid[i + 1][j] == 'C') || (grid[i][j] == 'C' && grid[i + 1][j] == 'A')) {
                        if (j - prv > 1) {
                            cnt++;
                        }
                        prv = j;
                    }
                }
            }
            for (int j = 1; j < c; j++) {
                int prv = -1;
                for (int i = 1; i <= r; i++) {
                    if ((grid[i][j] == 'A' && grid[i][j + 1] == 'C') || (grid[i][j] == 'C' && grid[i][j + 1] == 'A')) {
                        if (i - prv > 1) {
                            cnt++;
                        }
                        prv = i;
                    }
                }
            }
            
            if (cnt > k) {
                continue;
            }
            
            lng alice_happy1 = 0, cindy_happy1 = 0;
            lng alice_happy2 = 0, cindy_happy2 = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] == 'A') {
                        alice_happy1 += us[i][j];
                        cindy_happy2 += vs[i][j];
                    } else {
                        cindy_happy1 += vs[i][j];
                        alice_happy2 += us[i][j];
                    }
                }
            } 
            
            ans = min(ans, abs(alice_happy1 - cindy_happy1));
            ans = min(ans, abs(alice_happy2 - cindy_happy2));
        }
    }
    }
    }
    }
 
    for (int i1 = 1; i1 <= r; i1++) {
    for (int j1 = 1; j1 <= c; j1++) {
    for (int i2 = i1 + 1; i2 <= r; i2++) {
    for (int j2 = j1 + 1; j2 <= c; j2++) {
        if (i1 != 1 && j1 != 1 && i2 != r && j2 != c) {
            continue;
        }
 
        if (i1 == 1 && j1 == 1 && i2 == r && j2 == c) {
            continue;
        }
 
        int rr = i2 - i1 + 1, cc = j2 - j1 + 1; 
 
        if (rr < 3 || cc < 3 || rr * cc < 6) {
            continue;
        }
        
        int bit = pow(2 * rr, cc);
        for (int b = 0; b < bit; b++) {
            int prv = -1, chk = 0;
            int cur = b, pow_rr = pow(2 * cc, rr - 1);
            while (pow_rr > 0) {
                int d = cur / pow_rr;
                if (d != prv) {
                    chk++;
                }
                prv = d;

                cur %= pow_rr;
                pow_rr /= (2 * cc);
            }
            if (chk != 3) {
                continue;
            }
            
            vector<vector<char>> grid(r + 2, vector<char>(c + 2, 'X'));
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    grid[i][j] = 'C';
                }
            }

            cur = b, pow_rr = pow(2 * rr, cc - 1);
            int dj = 0;
            while (pow_rr > 0) {
                int d = cur / pow_rr;
                
                if (d <= rr) {
                    for (int di = 0; di < d; di++) {
                        grid[i1 + di][j1 + dj] = 'A';
                    }
                } else {
                    d = 2 * rr - d;
                    for (int di = d; di < rr; di++) {
                        grid[i1 + di][j1 + dj] = 'A';
                    }
                }
                
                cur %= pow_rr;
                pow_rr /= (2 * rr);
                dj++;
            }
 
            bool a_edge = false, c_edge = false;
            for (int i = 1; i <= r; i++) {
                if (grid[i][1] == 'A' || grid[i][c] == 'A') {
                    a_edge = true;
                }
            
                if (grid[i][1] == 'C' || grid[i][c] == 'C') {
                    c_edge = true;
                }
            }
            for (int j = 1; j <= c; j++) {
                if (grid[1][j] == 'A' || grid[r][j] == 'A') {
                    a_edge = true;
                }
            
                if (grid[1][j] == 'C' || grid[r][j] == 'C') {
                    c_edge = true;
                }
            }
 
            if ((!a_edge) || (!c_edge)) {
                continue;
            }
 
            int a_partitions = 0;
            vector<vector<bool>> vst(r + 2, vector<bool>(c + 2, false));
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] != 'A') {
                        continue;
                    }
 
                    if (vst[i][j]) {
                        continue;
                    }
 
                    a_partitions++;
 
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vst[i][j] = true;
                    while (!q.empty()) {
                        auto [i_cur, j_cur] = q.front();
                        q.pop();
 
                        vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                        for (auto [di, dj] : di_djs) {
                            if (grid[i_cur + di][j_cur + dj] != 'A') {
                                continue;
                            }
                            
                            if (vst[i_cur + di][j_cur + dj]) {
                                continue;
                            }
 
                            q.push({i_cur + di, j_cur + dj});
                            vst[i_cur + di][j_cur + dj] = true;
                        }
                    }
                }
            }
 
            if (a_partitions != 1) {
                continue;
            }
 
            int c_partitions = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] != 'C') {
                        continue;
                    }
 
                    if (vst[i][j]) {
                        continue;
                    }
 
                    c_partitions++;
 
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vst[i][j] = true;
                    while (!q.empty()) {
                        auto [i_cur, j_cur] = q.front();
                        q.pop();
 
                        vector<pair<int, int>> di_djs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                        for (auto [di, dj] : di_djs) {
                            if (grid[i_cur + di][j_cur + dj] != 'C') {
                                continue;
                            }
                            
                            if (vst[i_cur + di][j_cur + dj]) {
                                continue;
                            }
 
                            q.push({i_cur + di, j_cur + dj});
                            vst[i_cur + di][j_cur + dj] = true;
                        }
                    }
                }
            }
            
            if (c_partitions != 1) {
                continue;
            }
 
            int cnt = 0;
            for (int i = 1; i < r; i++) {
                int prv = -1;
                for (int j = 1; j <= c; j++) {
                    if ((grid[i][j] == 'A' && grid[i + 1][j] == 'C') || (grid[i][j] == 'C' && grid[i + 1][j] == 'A')) {
                        if (j - prv > 1) {
                            cnt++;
                        }
                        prv = j;
                    }
                }
            }
            for (int j = 1; j < c; j++) {
                int prv = -1;
                for (int i = 1; i <= r; i++) {
                    if ((grid[i][j] == 'A' && grid[i][j + 1] == 'C') || (grid[i][j] == 'C' && grid[i][j + 1] == 'A')) {
                        if (i - prv > 1) {
                            cnt++;
                        }
                        prv = i;
                    }
                }
            }
            
            if (cnt > k) {
                continue;
            }
            
            lng alice_happy1 = 0, cindy_happy1 = 0;
            lng alice_happy2 = 0, cindy_happy2 = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] == 'A') {
                        alice_happy1 += us[i][j];
                        cindy_happy2 += vs[i][j];
                    } else {
                        cindy_happy1 += vs[i][j];
                        alice_happy2 += us[i][j];
                    }
                }
            } 
            
            ans = min(ans, abs(alice_happy1 - cindy_happy1));
            ans = min(ans, abs(alice_happy2 - cindy_happy2));
        }
    }
    }
    }
    }
 
    cout << ans << endl;
 
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