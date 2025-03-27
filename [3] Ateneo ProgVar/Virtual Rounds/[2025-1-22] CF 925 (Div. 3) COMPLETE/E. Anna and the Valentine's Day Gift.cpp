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
    vector<string> A(n);
    for (auto &a : A)
        cin >> a;

    // no. of trailing zeroes, no. of digits
    deque<pair<int, int>> V;
    for (auto a : A) {
        int cnt = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] != '0')
                break;
        
            cnt++;
        }

        V.pb({cnt, a.size()});
    }

    sort(V.begin(), V.end(), greater<pair<int, int>>());
    
    V.pb({0, V[0].se - V[0].fi});
    V.pop_front();
    for (int i = 0; i < n - 1; i++) {
        V[1].se += V[0].se;
        V.pop_front();

        V.pb({0, V[0].se - V[0].fi});
        V.pop_front();
    }

    cout << (V[0].se >= m + 1 ? "Sasha" : "Anna") << endl;
    
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