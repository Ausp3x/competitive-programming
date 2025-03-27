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

int X = 200'000;
vector<vector<int>> facs(X + 1);

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    lng a_sum = 0;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        a_sum += a;
    }
    lng b_sum = 0;
    vector<int> B(m);
    for (int &b : B) {
        cin >> b;
        b_sum += b;
    }
    
    unordered_map<lng, bool> Ac;
    for (int i = 0; i < n; i++) 
        Ac[a_sum - A[i]] = true;
    unordered_map<lng, bool> Bc;
    for (int i = 0; i < m; i++) 
        Bc[b_sum - B[i]] = true;

    while (q--) {
        int x;
        cin >> x;

        bool chk = false;
        if (x > 0)
            for (int f : facs[x]) {
                int g = x / f;

                if (Ac[f] && Bc[g])
                    chk = true;

                if (Ac[-f] && Bc[-g])
                    chk = true;

                if (Ac[g] && Bc[f])
                    chk = true;

                if (Ac[-g] && Bc[-f])
                    chk = true;
            }
        else if (x < 0)
            for (int f : facs[abs(x)]) {
                int g = abs(x) / f;

                if (Ac[-f] && Bc[g])
                    chk = true;

                if (Ac[f] && Bc[-g])
                    chk = true;

                if (Ac[-g] && Bc[f])
                    chk = true;

                if (Ac[g] && Bc[-f])
                    chk = true;
            }

        cout << (chk ? "YES" : "NO") << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i * i <= X; i++) 
        for (int j = i * i; j <= X; j += i)
            facs[j].pb(i);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}