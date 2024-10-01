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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

vector<string> IT = {"BG", "BR", "BY", "GR", "GY", "RY"};
map<string, int> TI = {{"BG", 0}, {"BR", 1}, {"BY", 2}, {"GR", 3}, {"GY", 4}, {"RY", 5}};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> P(n + 1);
    map<string, ordered_set<int>> M;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        if (P[i] != "BG" && TI[P[i]] + 0 != 5)
            M["BG"].insert(i);
        if (P[i] != "BR" && TI[P[i]] + 1 != 5)
            M["BR"].insert(i);
        if (P[i] != "BY" && TI[P[i]] + 2 != 5)
            M["BY"].insert(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        
        if (TI[P[x]] + TI[P[y]] != 5) {
            cout << y - x << endl;
            continue;
        }

        int idx = min(TI[P[x]], TI[P[y]]);
        if (M[IT[idx]].empty()) {
            cout << -1 << endl;
            continue;
        }

        int xi = M[IT[idx]].order_of_key(x), yi = M[IT[idx]].order_of_key(y + 1);

        if (xi != yi) {
            cout << y - x << endl;
            continue;
        }

        int ans = INF32;
        if (xi - 1 >= 0)
            ans = min(ans, y - x + 2 * (x - *M[IT[idx]].find_by_order(xi - 1)));
        if (xi < M[IT[idx]].size())
            ans = min(ans, y - x + 2 * (*M[IT[idx]].find_by_order(xi) - y));

        cout << ans << endl;
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