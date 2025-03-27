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

void decrement(int x, map<int, int> &M) {
    if (!M.contains(x))
        return;

    M[x]--;
    if (M[x] == 0)
        M.erase(x);

    return;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    if (n == 1) {
        int q;
        cin >> q;
        while (q--) {
            int i, x;
            cin >> i >> x;

            cout << x << ' ';
        }
        cout << endl;
        
        return;
    }

    map<int, int> cnts;
    indexed_set<int> S;
    for (int a : A) {
        cnts[a]++;
        S.insert(a);
    }

    int len = S.size(); 
    map<int, int> d_cnts;
    for (auto &[k, v] : cnts)
        if (v > 1)
            d_cnts[0] += v - 1;
    for (int i = 0; i < len - 1; i++) {
        int d = *S.find_by_order(i + 1) - *S.find_by_order(i);
        d_cnts[d]++;
    }

    S.insert(0);
    S.insert(INF32);

    int q;
    cin >> q;
    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        
        if (!cnts.contains(A[i])) 
            return;

        if (cnts[A[i]] > 1) {
            cnts[A[i]]--;
            decrement(0, d_cnts);
            
            if (cnts.contains(x)) {
                A[i] = x;
                cnts[x]++;
                d_cnts[0]++;

                len = S.size();
                cout << *S.find_by_order(len - 2) + d_cnts.rbegin()->fi << ' ';
            } else {
                A[i] = x;
                cnts[x]++;
                int l = *S.find_by_order(S.order_of_key(x) - 1);
                int r = *S.find_by_order(S.order_of_key(x));
                S.insert(x);
                
                if (r != INF32 && l != 0)
                    decrement(r - l, d_cnts);
                if (r != INF32) 
                    d_cnts[r - x]++;
                if (l != 0)
                    d_cnts[x - l]++;

                len = S.size();
                cout << *S.find_by_order(len - 2) + d_cnts.rbegin()->fi << ' ';
            }
        } else {
            cnts.erase(A[i]);
            int L = *S.find_by_order(S.order_of_key(A[i]) - 1);
            int R = *S.find_by_order(S.order_of_key(A[i]) + 1);
            S.erase(A[i]);
            
            if (R != INF32 && L != 0)
                d_cnts[R - L]++;
            if (R != INF32) 
                decrement(R - A[i], d_cnts);
            if (L != 0) 
                decrement(A[i] - L, d_cnts);

            if (cnts.contains(x)) {
                A[i] = x;
                cnts[x]++;
                d_cnts[0]++;
                
                len = S.size();
                cout << *S.find_by_order(len - 2) + d_cnts.rbegin()->fi << ' ';
            } else {
                A[i] = x;
                cnts[x]++;
                int l = *S.find_by_order(S.order_of_key(x) - 1);
                int r = *S.find_by_order(S.order_of_key(x));
                S.insert(x);
                
                if (r != INF32 && l != 0)
                    decrement(r - l, d_cnts);
                if (r != INF32) 
                    d_cnts[r - x]++;
                if (l != 0)
                    d_cnts[x - l]++;

                len = S.size();
                cout << *S.find_by_order(len - 2) + d_cnts.rbegin()->fi << ' ';
            }
        }
    }
    cout << endl;

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