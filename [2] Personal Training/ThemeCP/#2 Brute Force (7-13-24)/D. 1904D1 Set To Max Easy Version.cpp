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

    vector<bool> same(n);
    for (int i = 1; i <= n; i++) {
        bool B_has_i = false;
        for (int j = 0; j < n; j++)
            if (B[j] == i) {
                B_has_i = true;
                break;
            }

        if (!B_has_i)
            continue;

        bool A_has_i = false;
        for (int j = 0; j < n; j++)
            if (A[j] == i) {
                A_has_i = true;
                break;
            }

        if (!A_has_i) {
            cout << "NO" << endl;
            return;
        }

        vector<bool> vst(n);
        for (int j = 0; j < n; j++) {
            if (A[j] != i || vst[j])
                continue;
            vst[j] = true;
            
            for (int k = j - 1; k >= 0; k--) {
                if (A[k] > A[j])
                    break;

                if (same[k])
                    break;

                if (vst[k])
                    break;
                vst[k] = true;
                
                A[k] = A[j];
            }

            for (int k = j + 1; k < n; k++) {
                if (A[k] > A[j])
                    break;

                if (same[k])
                    break;
                
                if (vst[k])
                    break;
                vst[k] = true;

                A[k] = A[j];
            }
        }

        for (int j = 0; j < n; j++) {
            if (B[j] != i)
                continue;

            if (A[j] != B[j]) {
                cout << "NO" << endl;
                return;
            }

            same[j] = true;
        }
    }

    cout << "YES" << endl;

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