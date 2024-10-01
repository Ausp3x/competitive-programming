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
    int n;
    cin >> n;
    lng A_sum = 0;
    vector<lng> A(n);
    for (lng &a : A) {
        cin >> a;
        A_sum += a;
    }

    // maximize the minimum
    lng l = 0, r = 1'000'000'000'001;
    while (r - l > 1) {
        lng md = (l + r) / 2;

        bool chk = true;
        vector<lng> AA = A;
        for (int i = 0; i < n; i++) {
            if (AA[i] < md) {
                chk = false;
                break;
            }

            if (i + 1 < n) {
                lng d = AA[i] - md;
                AA[i] -= d;
                AA[i + 1] += d;
            }
        }

        if (chk)
            l = md;
        else
            r = md;
    }

    lng mn = l;

    vector<pair<lng, int>> V;
    for (int i = 0; i < n - 1; i++)
        if (A[i] > mn) 
            V.pb({A[i] - mn, i});

    for (int i = n - 1; i >= 0; i--) {
        if (!V.empty())
            if (V.back().se == i)
                V.pop_back();
        
        while (!V.empty()) {
            if (A[i] >= mn)
                break;

            lng to_add = min(V.back().fi, mn - A[i]);
            A[i] += to_add;
            A[V.back().se] -= to_add;
            V.back().fi -= to_add;
            if (V.back().fi == 0)
                V.pop_back();
        }
    }

    // minimize the maximum
    l = mn - 1, r = 1'000'000'000'001;
    while (r - l > 1) {
        lng md = (l + r) / 2;

        vector<lng> AA = A;
        vector<pair<lng, int>> VV;
        for (int i = 0; i < n - 1; i++)
            if (AA[i] > md)
                VV.pb({AA[i] - md, i});

        bool chk = true;
        for (int i = n - 1; i >= 0; i--) {
            if (AA[i] > md) {
                chk = false;
                break;
            }

            while (!VV.empty()) {
                if (AA[i] == md)
                    break;
                
                lng to_add = min(VV.back().fi, md - AA[i]);
                AA[i] += to_add;
                AA[VV.back().se] -= to_add;
                VV.back().fi -= to_add;
                if (VV.back().fi == 0)
                    VV.pop_back();
            }
        }

        if (!chk)
            l = md;
        else
            r = md;
    }

    lng mx = r;

    cout << mx - mn << endl;

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