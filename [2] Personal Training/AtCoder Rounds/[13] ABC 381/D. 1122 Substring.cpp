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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    vector<pair<int, int>> segs;
    segs.pb({A[0], 1});
    for (int i = 1; i < n; i++)
        if (segs.back().fi == A[i])
            segs.back().se++;
        else
            segs.pb({A[i], 1});

    int len = segs.size();    
    // for (int i = 0; i < len; i++)
    //     cout << i << ": " << segs[i].fi << ' ' << segs[i].se << endl;
    // cout << endl;

    int j = 0, chk = 0, cur = 0, ans = 0;
    vector<bool> vst(n + 1);
    chk += segs[0].se > 2;
    cur += (segs[0].se == 1 ? 0 : 2);
    vst[segs[0].fi] = true;
    for (int i = 0; i < len; i++) {
        assert(j >= i);
        if (segs[i].se == 1) {
            vst[segs[i].fi] = false;
            if (j == i) {
                j++;
                if (j < len) {
                    chk += segs[j].se > 2;
                    cur += (segs[j].se == 1 ? 0 : 2);
                    vst[segs[j].fi] = true;
                }
            }
            
            continue;
        }

        while (j + 1 < len) {
            if (chk - (segs[i].se > 2) >= 1 || vst[segs[j + 1].fi] || segs[j + 1].se == 1)
                break;

            j++;
            chk += segs[j].se > 2;
            cur += 2;
            vst[segs[j].fi] = true;
        }
        
        // cout << i << ' ' << cur << endl;
        // for (bool x : vst)
        //     cout << x << ' ';
        // cout << endl;

        ans = max(ans, cur);

        chk -= segs[i].se > 2;
        cur -= 2;
        vst[segs[i].fi] = false;
        if (j == i) {
            j++;
            if (j < len) {
                chk += segs[j].se > 2;
                cur += (segs[j].se == 1 ? 0 : 2);
                vst[segs[j].fi] = true;
            } 
        }
    }

    cout << ans << endl;
    
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