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
    vector<pair<lng, lng>> D(n);
    for (int i = 0; i < n; i++)
        cin >> D[i].se;
    for (int i = 0; i < n; i++)
        cin >> D[i].fi;
    vector<pair<lng, lng>> C(m);
    for (int i = 0; i < m; i++)
        cin >> C[i].se;
    for (int i = 0; i < m; i++)
        cin >> C[i].fi;

    vector<pair<lng, lng>> D_copy = D, C_copy = C;
    sort(D_copy.begin(), D_copy.end());
    sort(C_copy.begin(), C_copy.end());

    lll ans_max = 0;
    while (!D_copy.empty() && !C_copy.empty()) {
        lll cur = min(D_copy.back().se, C_copy.back().se);
        ans_max += cur * D_copy.back().fi * C_copy.back().fi;

        D_copy.back().se -= cur;
        C_copy.back().se -= cur;
        if (D_copy.back().se == 0)
            D_copy.pop_back();
        if (C_copy.back().se == 0) 
            C_copy.pop_back();
    }

    D_copy = D;
    C_copy = C;
    sort(D_copy.begin(), D_copy.end(), greater<pair<lng, lng>>());
    sort(C_copy.begin(), C_copy.end());

    lll ans_min = 0;
    while (!D_copy.empty() && !C_copy.empty()) {
        lll cur = min(D_copy.back().se, C_copy.back().se);
        ans_min += cur * D_copy.back().fi * C_copy.back().fi;

        D_copy.back().se -= cur;
        C_copy.back().se -= cur;
        if (D_copy.back().se == 0)
            D_copy.pop_back();
        if (C_copy.back().se == 0) 
            C_copy.pop_back();
    }

    string s_ans_max = "";
    while (ans_max > 0) {
        s_ans_max += '0' + (ans_max % 10);
        ans_max /= 10;
    }
    reverse(s_ans_max.begin(), s_ans_max.end());

    string s_ans_min = "";
    while (ans_min > 0) {
        s_ans_min += '0' + (ans_min % 10);
        ans_min /= 10;
    }
    reverse(s_ans_min.begin(), s_ans_min.end());

    cout << s_ans_max << ' ' << s_ans_min << endl;
    
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