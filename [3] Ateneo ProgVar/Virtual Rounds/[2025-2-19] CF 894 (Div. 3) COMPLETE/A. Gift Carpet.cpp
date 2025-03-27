// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> V(26, vector<bool>(m));
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < m; i++)
            V[s[i] - 'a'][i] = true;   
    }

    int cur_idx = -1;
    vector<int> ord = {21, 8, 10, 0};
    for (int x : ord) {
        bool chk = false;
        for (int nxt_idx = cur_idx + 1; nxt_idx < m; nxt_idx++)
            if (V[x][nxt_idx]) {
                cur_idx = nxt_idx;
                chk = true;
                break;
            }

        if (!chk) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;

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