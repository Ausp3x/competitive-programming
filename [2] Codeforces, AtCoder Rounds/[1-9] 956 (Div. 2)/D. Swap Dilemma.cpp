// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve(int t) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    vector<int> B(n);
    for (int &b : B)
        cin >> b;

    vector<int> sA = A, sB = B;
    sort(sA.begin(), sA.end());
    sort(sB.begin(), sB.end());
    for (int i = 0; i < n; i++)
        if (sA[i] != sB[i]) {
            cout << "NO" << endl;
            return;
        }

    bool isEqual = true;
    for (int i = 0; i < n; i++)
        if (A[i] != B[i]) {
            isEqual = false;
            break;
        }

    if (isEqual || n == 1) {
        cout << "YES" << endl;
        return;
    }

    if (n == 2) {
        cout << "NO" << endl;
        return;
    }

    map<int, int> A_idxs;
    for (int i = 0; i < n; i++)
        A_idxs[A[i]] = i;

    lng ans = 0;
    tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> used;
    for (int i = n - 1; i >= 0; i--) {
        // cout << max<lng>(i - A_idxs[B[i]] + used.order_of_key(A_idxs[B[i]]), 0) << ' ';
        ans += max<lng>(i - A_idxs[B[i]] + used.order_of_key(A_idxs[B[i]]), 0);
        used.insert(A_idxs[B[i]]);
    }
    
    cout << (ans % 2 ? "NO" : "YES") << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}