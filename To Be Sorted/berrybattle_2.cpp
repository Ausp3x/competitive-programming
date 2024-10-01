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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s; 
    s = "X" + s;

    // cout << s << endl;
    
    // index, number of berries
    map<int, int> i_nb;
    // number of berries, index
    set<pair<int, int>> nb_i;
    for (int i = 1; i + 3 <= n; i++) {
        int cnt = 0;
        for (int j = i; j < i + 4; j++)
            cnt += s[j] == 'b';

        i_nb[i] = cnt;
        nb_i.insert({cnt, i});
    }

    // for (auto &[nb, idx] : nb_i)
    //     cout << nb << ' ' << idx << endl;

    int ttl_berries = n / 2;
    while (ttl_berries > 0) {
        int idx;
        cin >> idx;
        int nb = i_nb[idx];

        ttl_berries -= nb;
        map<int, int> to_minus;       
        for (int i = idx; i < idx + 4; i++) {
            if (s[i] != 'b')
                continue;

            for (int j = max(i - 3, 1); j <= i; j++)
                to_minus[j]++;
        
            s[i] = '.';
        }

        for (auto &[idx2, minus] : to_minus) {
            nb_i.erase({i_nb[idx2], idx2});
            i_nb[idx2] -= minus;
            nb_i.insert({i_nb[idx2], idx2});
        }

        // cout << s << endl;

        if (ttl_berries == 0)
            break;

        nb = prev(nb_i.end())->fi;
        idx = prev(nb_i.end())->se;

        cout << idx << endl;

        ttl_berries -= nb;
        to_minus.clear();
        for (int i = idx; i < idx + 4; i++) {
            if (s[i] != 'b')
                continue;

            for (int j = max(i - 3, 1); j <= i; j++)
                to_minus[j]++;
        
            s[i] = '.';
        }

        for (auto &[idx2, minus] : to_minus) {
            nb_i.erase({i_nb[idx2], idx2});
            i_nb[idx2] -= minus;
            nb_i.insert({i_nb[idx2], idx2});
        }

        // cout << s << endl;        
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