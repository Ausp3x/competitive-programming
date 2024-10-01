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
    int S, T;
    cin >> S >> T;
    vector<int> ss(S);
    for (int &s : ss) {
        cin >> s;
    }
    vector<int> ts(T);
    for (int &t : ts) {
        cin >> t;
    }

    if (T == 0) {
        cout << 1 << endl;
        return;
    }

    stack<int> s_stk;
    for (int i = S - 1; i >= 0; i--) {
        s_stk.push(ss[i]);
    }
    stack<int> t_stk;
    for (int i = T - 1; i >= 0; i--) {
        t_stk.push(ts[i]);
    }

    if (S + T <= 1000) {
        int moves = 0;
        while (true) {
            moves++;

            if (t_stk.empty()) {
                break;
            }

            if (s_stk.empty()) {
                s_stk.push(t_stk.top());
                t_stk.pop();
                continue;
            }
            
            int s = s_stk.top(), t = t_stk.top();
            s_stk.pop(), t_stk.pop();

            if (s > t) {
                t_stk.push(s);
                t_stk.push(t);
            } else {
                s_stk.push(s);
                s_stk.push(t);
            }
        }

        cout << moves << endl;
        return;
    }

    if (S == 0) {
        lng ans = T + 1;
        map<int, int> in_set_cnt;
        tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> previous_numbers;
        previous_numbers.insert({ts[0], 0});
        in_set_cnt[ts[0]]++; 
        for (int i = 1; i < T; i++) {
            int cur = i - previous_numbers.order_of_key({ts[i], INF32});
            ans += 2 * cur;
            
            previous_numbers.insert({ts[i], in_set_cnt[ts[i]]});
            in_set_cnt[ts[i]]++; 
        }

        cout << ans << endl;
        return;
    }

    int t_min = INF32;
    for (int i = 0; i < T; i++) {
        t_min = min(t_min, ts[i]);
    }

    reverse(ts.begin(), ts.end());
    
    lng ans = T + 1;
    for (int i = 0; i < S; i++) {
        if (ss[i] > t_min) {
            T++;
            ts.push_back(ss[i]);
        } else {
            break;
        }
    }

    reverse(ts.begin(), ts.end());

    map<int, int> in_set_cnt;
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> previous_numbers;
    previous_numbers.insert({ts[0], 0});
    in_set_cnt[ts[0]]++; 
    for (int i = 1; i < T; i++) {
        int cur = i - previous_numbers.order_of_key({ts[i], INF32});
        ans += 2 * cur;
        
        previous_numbers.insert({ts[i], in_set_cnt[ts[i]]});
        in_set_cnt[ts[i]]++; 
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