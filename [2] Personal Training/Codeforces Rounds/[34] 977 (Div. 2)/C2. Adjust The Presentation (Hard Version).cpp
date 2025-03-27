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
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> i_to_v(n + 1), v_to_i(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        i_to_v[i] = a;
        v_to_i[a] = i;
    }
    vector<int> B(m + 1);
    vector<set<int>> idxs(n + 1, {INF32});
    for (int i = 1; i <= m; i++) {
        cin >> B[i];

        idxs[B[i]].insert(i);
    }

    // for (int b : B)
    //     cout << b << ' ';
    // cout << endl; 

    function<bool(int)> isGood = [&](int i) {
        if (i < 1 || i > n - 1)
            return true;
        
        return *idxs[i_to_v[i]].begin() <= *idxs[i_to_v[i + 1]].begin();
    };

    int cnt = 0;
    vector<bool> chks(n + 1);
    chks[0] = chks[n] = true;
    for (int i = 1; i < n; i++) {
        if (isGood(i)) {
            cnt++;
            chks[i] = true;
        }
    }

    cout << (cnt == n - 1 ? "YA" : "TIDAK") << endl;

    while (q--) {
        int s, b_new;
        cin >> s >> b_new;
        
        int b_old = B[s]; 
        B[s] = b_new;
        idxs[b_old].erase(s);
        idxs[b_new].insert(s);

        int b_io = v_to_i[b_old];
        cnt += isGood(b_io - 1) - chks[b_io - 1];
        chks[b_io - 1] = isGood(b_io - 1);
        cnt += isGood(b_io) - chks[b_io];
        chks[b_io] = isGood(b_io);
        
        int b_in = v_to_i[b_new];
        cnt += isGood(b_in - 1) - chks[b_in - 1];
        chks[b_in - 1] = isGood(b_in - 1);
        cnt += isGood(b_in) - chks[b_in];
        chks[b_in] = isGood(b_in);

        // for (int b : B)
        //     cout << b << ' ';
        // cout << endl; 

        cout << (cnt == n - 1 ? "YA" : "TIDAK") << endl;
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