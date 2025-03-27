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

int M = 500'005; 

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    
    vector<bool> is_disrupt(n), vst(M);
    is_disrupt[0] = true;
    for (int i = n - 1; i >= 0; i--) {
        if (!vst[A[i]] && A[i] != A[0])
            is_disrupt[i] = true;
        vst[A[i]] = true;
    }
    
    if (A[0] == A[n - 1] || accumulate(vst.begin(), vst.end(), 0) == 1) {
        cout << 1 << endl;
        return;
    }

    int last = A[n - 1], i_last = n - 1;
    double a = 0; 
    vector<lng> cnts(M);
    vector<double> S(M);
    cnts[A[0]]++;
    S[A[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--) {
        cnts[A[i + 1]]++;
        if (A[i + 1] != last)
            a += S[A[i + 1]];
        
        if (!is_disrupt[i])
            continue;

        if (i_last == n - 1) 
            S[A[i]] = double(cnts[last]) / (n - i);
        else 
            S[A[i]] = ((cnts[last] + (n - i_last)) * S[last] + a) / (n - i);

        last = A[i];
        i_last = i;
        a = 0;
    }

    // for (auto &[k, v] : S)
    //     cout << k << ' ' << v << endl;

    cout << setprecision(10) << 1 - S[A[0]] << endl;
    
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