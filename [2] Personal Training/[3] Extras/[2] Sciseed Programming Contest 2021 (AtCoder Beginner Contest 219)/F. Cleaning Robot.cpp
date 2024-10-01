// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void shift(lng &x, lng &y, char c) {
    if (c == 'L') {
        x--;
    } else if (c == 'R') {
        x++;
    } else if (c == 'U') {
        y--;
    } else if (c == 'D') {
        y++;
    }

    return;
}

pair<lng, lng> residualize(pair<lng, lng> cor, int x_new, int y_new) {
    if (y_new < 0) {
        x_new = -x_new;
        y_new = -y_new;
    }

    lng q = cor.second / y_new;

    cor.first -= q * x_new;
    cor.second -= q * y_new;

    if (cor.second < 0) {
        cor.first += x_new;
        cor.second += y_new;
    }

    return cor;
}

void solve() {
    string s;
    cin >> s;
    lng k;
    cin >> k;

    lng x_new = 0, y_new = 0;
    for (char &c : s) {
        shift(x_new, y_new, c);
    }

    if (x_new == 0 && y_new == 0) {
        lng x_cur = 0, y_cur = 0;
        map<pair<lng, lng>, bool> visited;
        visited[{0, 0}] = true;
        for (char &c : s) {
            shift(x_cur, y_cur, c);
            visited[{x_cur, y_cur}] = true;
        }

        cout << int(visited.size()) << endl;

        return;
    }

    if (y_new == 0) {
        lng x_cur = 0, y_cur = 0;
        map<pair<lng, lng>, vector<lng>> groups;
        groups[{0, 0}].push_back(0);
        for (char &c : s) {
            shift(x_cur, y_cur, c);
            groups[{(x_cur % x_new + x_new) % x_new, y_cur}].push_back(x_cur);
        }

        lng ans = 0;
        for (auto &[grp, elems] : groups) {
            if (x_new < 0) {
                sort(elems.begin(), elems.end(), greater<lng>());
            } else {
                sort(elems.begin(), elems.end());
            }

            lng x_l = elems[0], x_r = elems[0] + (k - 1) * x_new;
            for (int i = 1; i < int(elems.size()); i++) {
                if ((x_r >= elems[i] && x_new > 0) || (x_r <= elems[i] && x_new < 0)) {
                    x_r = elems[i] + (k - 1) * x_new;
                } else {
                    ans += (x_r - x_l) / x_new + 1;
                    x_l = elems[i];
                    x_r = elems[i] + (k - 1) * x_new;
                }
            }
            
            ans += (x_r - x_l) / x_new + 1;
        }

        cout << ans << endl;

        return;
    }

    lng x_cur = 0, y_cur = 0;
    map<pair<lng, lng>, vector<lng>> groups;
    groups[{0, 0}].push_back(0);
    for (char &c : s) {
        shift(x_cur, y_cur, c);
        groups[residualize({x_cur, y_cur}, x_new, y_new)].push_back(y_cur);
    }

    lng ans = 0;
    for (auto &[grp, elems] : groups) {
        if (y_new <= 0) {
            sort(elems.begin(), elems.end(), greater<lng>());
        } else {
            sort(elems.begin(), elems.end());
        }

        lng y_l = elems[0], y_r = elems[0] + (k - 1) * y_new;
        for (int i = 1; i < int(elems.size()); i++) {
            if ((y_r >= elems[i] && y_new > 0) || (y_r <= elems[i] && y_new < 0)) {
                y_r = elems[i] + (k - 1) * y_new;
            } else {
                ans += (y_r - y_l) / y_new + 1;
                y_l = elems[i];
                y_r = elems[i] + (k - 1) * y_new;
            }
        }

        ans += (y_r - y_l) / y_new + 1;
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