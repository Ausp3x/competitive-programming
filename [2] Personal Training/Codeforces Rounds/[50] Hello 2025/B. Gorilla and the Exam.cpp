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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    map<int, int> cnts;
    for (int &a : A) {
        cin >> a;
        cnts[a]++;
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    deque<pair<int, int>> V;
    for (auto &[a, b] : cnts)
        V.pb({b, a});

    sort(V.begin(), V.end(), greater<pair<int, int>>());

    V.pop_front();
    while (k > 0 && !V.empty()) {
        int cur = min(k, V.back().fi);

        k -= cur;
        V.back().fi -= cur;

        if (V.back().fi == 0)
            V.pop_back();
    }

    cout << 1 + V.size() << endl;
    
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