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

int const MOD = 1e9 + 7;

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

    vector<int> As(5);
    for (int i = 0; i < 5; i++) {
        string A;
        cin >> A;
        As[i] = move_idxs[A];
    }
    string a_str;
    cin >> a_str;
    int a = move_idxs[a_str];
    
    vector<int> Bs(5);
    for (int i = 0; i < 5; i++) {
        string B;
        cin >> B;
        Bs[i] = move_idxs[B];
    }
    string b_str;
    cin >> b_str;
    int b = move_idxs[b_str];
    
    // for (int A : As) {
    //     cout << A << ' ';
    // }
    // cout << endl;
    // for (int B : Bs) {
    //     cout << B << ' ';
    // }
    // cout << endl;

    lng x, y;
    cin >> x >> y;
    double m_d = pow(x, y);
    lng m = m_d;

    if (m_d <= 100) {
        int p_win = 0, o_win = 0;
        for (int i = 0; i < m; i++) {
            int res = match_results[a][b];

            // cout << a << ' ' << b << endl;
            
            if (res == -1) {
                p_win++;
            } else if (res == 1) {
                o_win++;
            }

            int tmp = a;
            a = As[b];
            b = Bs[tmp];
        }

        cout << p_win << ' ' << o_win << endl;
        // cout << endl;
        return;
    }

    int i = 0, cycle_len = -1;
    lng p_wins = 0, o_wins = 0;
    vector<pair<int, int>> cycle, wins;
    vector<vector<int>> is_visited(5, vector<int>(5, -1));
    while (true) {
        if (is_visited[a][b] != -1) {
            cycle_len = i - is_visited[a][b];
            
            if (m_d <= 1e15) {
                for (int j = 0; j < min<lng>(is_visited[a][b], m); j++) {
                    p_wins += wins[j].first;
                    o_wins += wins[j].second;
                }
                m -= is_visited[a][b];
            }
            
            for (int j = is_visited[a][b] + 1; j < i; j++) {
                wins[j].first += wins[j - 1].first;
                wins[j].second += wins[j - 1].second;
            }
            i = is_visited[a][b];
            break;
        }

        cycle.push_back({a, b});
        if (match_results[a][b] == -1) {
            wins.push_back({1, 0});
        } else if (match_results[a][b] == 0) {
            wins.push_back({0, 0});
        } else if (match_results[a][b] == 1) {
            wins.push_back({0, 1});
        }
        is_visited[a][b] = i;

        int tmp = a;
        a = As[b];
        b = Bs[tmp];
        i++;
    }
    
    // cout << cycle_len << endl;
    // for (int i = 0; i < cycle.size(); i++) {
    //     cout << cycle[i].first << ' ' << cycle[i].second << ' ';
    //     cout << wins[i].first << ' ' << wins[i].second << endl;
    // }
    // cout << endl;

    if (m_d <= 1e15) {
        lng q = m / cycle_len, r = m % cycle_len;
        p_wins += q * wins[i + cycle_len - 1].first;
        p_wins %= MOD;
        o_wins += q * wins[i + cycle_len - 1].second;
        o_wins %= MOD;
        if (r != 0) {
            p_wins += wins[i + r - 1].first;
            p_wins %= MOD;
            o_wins += wins[i + r - 1].second;
            o_wins %= MOD;
        }

        // cout << q << ' ' << r << endl;
        cout << p_wins << ' ' << o_wins << endl;
        // cout << endl;
        return;
    }

    lng q_1 = x / cycle_len, r_1 = x % cycle_len;
    lng q = 0, r = 1;
    while (y > 0) {
        if (y & 1) {
            q = q * q_1 % MOD * cycle_len % MOD + q * r_1 % MOD + r * q_1 % MOD;
            q %= MOD;
            r *= r_1;
            q += r / cycle_len;
            r %= cycle_len;
        }

        y >>= 1;
        q_1 = q_1 * q_1 % MOD * cycle_len % MOD + q_1 * r_1 % MOD + r_1 * q_1 % MOD;
        q_1 %= MOD;
        r_1 *= r_1;
        q_1 += r_1 / cycle_len;
        r_1 %= cycle_len;
    }

    // for (int i = 1; i < y; i++) {
    //     q = q * q_1 % MOD * cycle_len % MOD + q * r_1 % MOD + r * q_1 % MOD;
    //     q %= MOD;
    //     r *= r_1;
    //     q += r / cycle_len;
    //     r %= cycle_len;
    // }

    for (int j = 0; j < i; j++) {
        p_wins += wins[j].first;
        o_wins += wins[j].second;
    }
    r -= i;

    while (r < 0) {
        r += cycle_len;
        q--;
    }
    if (q < 0) {
        q += MOD;
    }

    p_wins += q * wins[i + cycle_len - 1].first;
    p_wins %= MOD;
    o_wins += q * wins[i + cycle_len - 1].second;
    o_wins %= MOD;
    if (r != 0) {
        p_wins += wins[i + r - 1].first;
        p_wins %= MOD;
        o_wins += wins[i + r - 1].second;
        o_wins %= MOD;
    }

    // cout << q << ' ' << r << endl;
    cout << p_wins << ' ' << o_wins << endl;
    // cout << endl;

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