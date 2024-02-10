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
    int n;
    lng x, y;
    cin >> n >> x >> y;

    bool h_all_ones = true, v_all_ones = true;
    lng h_sum = 0, v_sum = 0;
    vector<pair<int, int>> hs, vs;
    for (int i = 0; i < n; i++) {
        int k;
        char d;
        cin >> k >> d;

        if (d == 'H') {
            h_all_ones &= k == 1;
            h_sum += k;
            hs.push_back({k, i});
        } else if (d == 'V') {
            v_all_ones &= k == 1;
            v_sum += k;
            vs.push_back({k, i});
        }
    }

    if (x == 0 && hs.size() == 1) {
        cout << "NO" << endl;
        return;
    }

    if (y == 0 && vs.size() == 1) {
        cout << "NO" << endl;
        return;
    }

    if (h_sum < abs(x) || v_sum < abs(y)) {
        cout << "NO" << endl;
        return;
    }

    if (h_all_ones && (h_sum % 2 != abs(x) % 2)) {
        cout << "NO" << endl;
        return;
    }

    if (v_all_ones && (v_sum % 2 != abs(y) % 2)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    sort(hs.begin(), hs.end(), greater<pair<int, int>>());
    sort(vs.begin(), vs.end(), greater<pair<int, int>>());

    vector<pair<int, char>> ans(n);
    if (x < 0) {
        if (x == -1) {
            if (hs.size() % 2 != 0) {
                ans[hs[0].second] = {1, 'E'};
                for (int i = 1; i < hs.size(); i++) {
                    ans[hs[i].second] = {1, 'E'};
                    i++;
                    ans[hs[i].second] = {1, 'W'};
                }
            } else {
                ans[hs[0].second] = {2, 'E'};
                ans[hs[1].second] = {1, 'W'};
                for (int i = 2; i < hs.size(); i++) {
                    ans[hs[i].second] = {1, 'E'};
                    i++;
                    ans[hs[i].second] = {1, 'W'};
                }
            }
        } else {
            for (int i = 0; i < hs.size(); i++) {
                if (x < 0) {
                    int cur = min<lng>(hs[i].first, -x);
                    x += cur;
                    ans[hs[i].second] = {cur, 'E'};
                } else if ((hs.size() - i) % 2 != 0) {
                    ans[hs[0].second].first--;
                    ans[hs[i].second] = {1, 'E'};
                } else {
                    ans[hs[i].second] = {1, 'E'};
                    i++;
                    ans[hs[i].second] = {1, 'W'};
                }
            }
        }
    } else if (x == 0) {
        if (hs.size() % 2 == 0) {
            for (int i = 0; i < hs.size(); i++) {
                ans[hs[i].second] = {1, 'E'};
                i++;
                ans[hs[i].second] = {1, 'W'};
            }
        } else {
            ans[hs[0].second] = {2, 'E'};
            ans[hs[1].second] = {1, 'W'};
            ans[hs[2].second] = {1, 'W'};
            for (int i = 3; i < hs.size(); i++) {
                ans[hs[i].second] = {1, 'E'};
                i++;
                ans[hs[i].second] = {1, 'W'};
            }
        }
    } else {
        if (x == 1) {
            if (hs.size() % 2 != 0) {
                ans[hs[0].second] = {1, 'W'};
                for (int i = 1; i < hs.size(); i++) {
                    ans[hs[i].second] = {1, 'E'};
                    i++;
                    ans[hs[i].second] = {1, 'W'};
                }
            } else {
                ans[hs[0].second] = {2, 'W'};
                ans[hs[1].second] = {1, 'E'};
                for (int i = 2; i < hs.size(); i++) {
                    ans[hs[i].second] = {1, 'E'};
                    i++;
                    ans[hs[i].second] = {1, 'W'};
                }
            }
        } else {
            for (int i = 0; i < hs.size(); i++) {
                if (x > 0) {
                    int cur = min<lng>(hs[i].first, x);
                    x -= cur;
                    ans[hs[i].second] = {cur, 'W'};
                } else if ((hs.size() - i) % 2 != 0) {
                    ans[hs[0].second].first--;
                    ans[hs[i].second] = {1, 'W'};
                } else {
                    ans[hs[i].second] = {1, 'E'};
                    i++;
                    ans[hs[i].second] = {1, 'W'};
                }
            }
        }
    }

    if (y < 0) {
        if (y == -1) {
            if (vs.size() % 2 != 0) {
                ans[vs[0].second] = {1, 'N'};
                for (int i = 1; i < vs.size(); i++) {
                    ans[vs[i].second] = {1, 'N'};
                    i++;
                    ans[vs[i].second] = {1, 'S'};
                }
            } else {
                ans[vs[0].second] = {2, 'N'};
                ans[vs[1].second] = {1, 'S'};
                for (int i = 2; i < vs.size(); i++) {
                    ans[vs[i].second] = {1, 'N'};
                    i++;
                    ans[vs[i].second] = {1, 'S'};
                }
            }
        } else {
            for (int i = 0; i < vs.size(); i++) {
                if (y < 0) {
                    int cur = min<lng>(vs[i].first, -y);
                    y += cur;
                    ans[vs[i].second] = {cur, 'N'};
                } else if ((vs.size() - i) % 2 != 0) {
                    ans[vs[0].second].first--;
                    ans[vs[i].second] = {1, 'N'};
                } else {
                    ans[vs[i].second] = {1, 'N'};
                    i++;
                    ans[vs[i].second] = {1, 'S'};
                }
            }
        }
    } else if (y == 0) {
        if (vs.size() % 2 == 0) {
            for (int i = 0; i < vs.size(); i++) {
                ans[vs[i].second] = {1, 'N'};
                i++;
                ans[vs[i].second] = {1, 'S'};
            }
        } else {
            ans[vs[0].second] = {2, 'N'};
            ans[vs[1].second] = {1, 'S'};
            ans[vs[2].second] = {1, 'S'};
            for (int i = 3; i < vs.size(); i++) {
                ans[vs[i].second] = {1, 'N'};
                i++;
                ans[vs[i].second] = {1, 'S'};
            }
        }
    } else {
        if (y == 1) {
            if (vs.size() % 2 != 0) {
                ans[vs[0].second] = {1, 'S'};
                for (int i = 1; i < vs.size(); i++) {
                    ans[vs[i].second] = {1, 'N'};
                    i++;
                    ans[vs[i].second] = {1, 'S'};
                }
            } else {
                ans[vs[0].second] = {2, 'S'};
                ans[vs[1].second] = {1, 'N'};
                for (int i = 2; i < vs.size(); i++) {
                    ans[vs[i].second] = {1, 'N'};
                    i++;
                    ans[vs[i].second] = {1, 'S'};
                }
            }
        } else {
            for (int i = 0; i < vs.size(); i++) {
                if (y > 0) {
                    int cur = min<lng>(vs[i].first, y);
                    y -= cur;
                    ans[vs[i].second] = {cur, 'S'};
                } else if ((vs.size() - i) % 2 != 0) {
                    ans[vs[0].second].first--;
                    ans[vs[i].second] = {1, 'S'};
                } else {
                    ans[vs[i].second] = {1, 'N'};
                    i++;
                    ans[vs[i].second] = {1, 'S'};
                }
            }
        }
    }

    for (auto &[k, d] : ans) {
        cout << k << ' ' << d << endl;
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}