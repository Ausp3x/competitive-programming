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
    vector<lng> A(3);
    cin >> A[0] >> A[1] >> A[2];
    
    if ((A[0] + A[1] + A[2]) % 3 != 0) {
        cout << -1 << endl;
        return;
    }

    vector<pair<lng, int>> V(3);
    for (int i = 0; i < 3; i++) {
        V[i].fi = A[i];
        V[i].se = i;
    }
    
    sort(V.begin(), V.end(), greater<pair<lng, lng>>());
    
    lng d1 = V[0].fi - V[1].fi;
    lng d2 = V[1].fi - V[2].fi;

    assert(d1 % 3 == d2 % 3);

    lng req = abs(d1 - d2) / 3;
    if (d1 > d2) {
        cout << 2 << endl;
        vector<lng> out1(3);
        out1[V[0].se] = 1;
        out1[V[1].se] = 3;
        out1[V[2].se] = 2;
        cout << req << endl;
        cout << out1[0] << ' ' << out1[1] << ' ' << out1[2] << endl;
        
        V[0].fi += req;
        V[1].fi += 3 * req;
        V[2].fi += 2 * req;

        assert(V[0].fi - V[1].fi == V[1].fi - V[2].fi);

        lng d = V[0].fi - V[1].fi;
        vector<lng> out2(3);
        out2[V[0].se] = 1;
        out2[V[1].se] = 2;
        out2[V[2].se] = 3;
        cout << d << endl;
        cout << out2[0] << ' ' << out2[1] << ' ' << out2[2] << endl;
    } else if (d1 < d2) {
        cout << 2 << endl;
        vector<lng> out1(3);
        out1[V[0].se] = 2;
        out1[V[1].se] = 1;
        out1[V[2].se] = 3;
        cout << req << endl;
        cout << out1[0] << ' ' << out1[1] << ' ' << out1[2] << endl;

        V[0].fi += 2 * req;
        V[1].fi += req;
        V[2].fi += 3 * req;

        assert(V[0].fi - V[1].fi == V[1].fi - V[2].fi);

        lng d = V[0].fi - V[1].fi;
        vector<lng> out2(3);
        out2[V[0].se] = 1;
        out2[V[1].se] = 2;
        out2[V[2].se] = 3;
        cout << d << endl;
        cout << out2[0] << ' ' << out2[1] << ' ' << out2[2] << endl;
    } else {
        cout << 1 << endl;

        assert(V[0].fi - V[1].fi == V[1].fi - V[2].fi);

        lng d = V[0].fi - V[1].fi;
        vector<lng> out2(3);
        out2[V[0].se] = 1;
        out2[V[1].se] = 2;
        out2[V[2].se] = 3;
        cout << d << endl;
        cout << out2[0] << ' ' << out2[1] << ' ' << out2[2] << endl;
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