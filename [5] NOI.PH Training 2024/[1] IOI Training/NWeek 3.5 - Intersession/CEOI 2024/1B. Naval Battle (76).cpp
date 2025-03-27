// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

map<char, pair<int, int>> d_to_move = {
    {'N', {0, -1}},
    {'S', {0, 1}},
    {'E', {1, 0}},
    {'W', {-1, 0}}
};

lng getCollisionTime(tuple<int, int, char> &ship1, tuple<int, int, char> &ship2) {
    auto [x1, y1, d1] = ship1;
    auto [x2, y2, d2] = ship2;
    
    if (d1 == d2)
        return INF64;
    
    if (d1 == 'N') {
        if (d2 == 'S') {
            if (x1 == x2 && y1 >= y2 && abs(y1 - y2) % 2 == 0) 
                return abs(y1 - y2) / 2;
            else
                return INF64;
        } else if (d2 == 'E') {
            if (x1 >= x2 && y1 >= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        } else if (d2 == 'W') {
            if (x1 <= x2 && y1 >= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        }
    } else if (d1 == 'S') {
        if (d2 == 'N') {
            if (x1 == x2 && y1 <= y2 && abs(y1 - y2) % 2 == 0) 
                return abs(y1 - y2) / 2;
            else
                return INF64;
        } else if (d2 == 'E') {
            if (x1 >= x2 && y1 <= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        } else if (d2 == 'W') {
            if (x1 <= x2 && y1 <= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        }
    } else if (d1 == 'E') {
        if (d2 == 'N') {
            if (x1 <= x2 && y1 <= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        } else if (d2 == 'S') {
            if (x1 <= x2 && y1 >= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        } else if (d2 == 'W') {
            if (x1 <= x2 && y1 == y2 && abs(x1 - x2) % 2 == 0) 
                return abs(x1 - x2) / 2;
            else
                return INF64;
        }
    } else if (d1 == 'W') {
        if (d2 == 'N') {
            if (x1 >= x2 && y1 <= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        } else if (d2 == 'S') {
            if (x1 >= x2 && y1 >= y2 && abs(x1 - x2) == abs(y1 - y2))
                return abs(x1 - x2);
            else
                return INF64;
        } else if (d2 == 'E') {
            if (x1 >= x2 && y1 == y2 && abs(x1 - x2) % 2 == 0) 
                return abs(x1 - x2) / 2;
            else
                return INF64;
        }
    }

    return -1;
}

void solve() {
    int n;
    cin >> n;
    bool st6_chk = true;
    vector<tuple<int, int, char>> ships(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> get<0>(ships[i]) >> get<1>(ships[i]) >> get<2>(ships[i]);
        st6_chk &= (get<2>(ships[i]) == 'S' || get<2>(ships[i]) == 'E');
    }

    if (n <= 5000) {
        priority_queue<tuple<lng, int, int>, vector<tuple<lng, int, int>>, greater<tuple<lng, int, int>>> pq; 
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                lng t = getCollisionTime(ships[i], ships[j]);

                assert(t != -1);

                if (t == INF64) 
                    continue;

                // cout << t << ' ' << i << ' ' << j << endl;
                pq.push({t, i, j});
            }

        vector<int> death_time(n + 1, -1);
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if ((death_time[i] != -1 && death_time[i] != t) || (death_time[j] != -1 && death_time[j] != t))
                continue;

            death_time[i] = t;
            death_time[j] = t;
        }

        // for (int x : death_time)
        //     cout << x << ' ';
        // cout << endl;

        #ifdef DEBUG
        cout << "ans: ";
        #endif
        for (int i = 1; i <= n; i++)
            if (death_time[i] == -1)
                cout << i << ' ';
        cout << endl;

        #ifndef DEBUG
        return;
        #endif
    }

    if (st6_chk) {
        map<lng, ordered_set<tuple<int, int, int>>> E_grps, S_grps; 
        for (int i = 1; i <= n; i++) {
            auto [x, y, d] = ships[i];

            assert(d == 'E' || d == 'S');

            if (d == 'E') {
                E_grps[x + y].insert({x, y, i});
            } else if (d == 'S') {
                S_grps[x + y].insert({x, y, i});
            }
        }

        vector<bool> is_alive(n + 1, true);
        for (auto &[k, v] : E_grps) {
            for (auto itr = v.rbegin(); itr != v.rend(); itr++) {
                auto [x_i, y_i, i] = *itr;
                
                int idx = S_grps[k].order_of_key({x_i, -INF32, -INF32});
                if (idx == S_grps[k].size())
                    continue;

                auto [x_j, y_j, j] = *S_grps[k].find_by_order(idx);
                is_alive[i] = false;
                is_alive[j] = false;
                S_grps[k].erase({x_j, y_j, j});
            }
        }

        #ifdef DEBUG
        cout << "st6 ans: ";
        #endif
        for (int i = 1; i <= n; i++) 
            if (is_alive[i])
                cout << i << ' ';
        cout << endl;

        return;
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