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

void solve() {
    int n;
    cin >> n;
    deque<int> A(n);
    for (int &a : A)
        cin >> a;
    deque<int> B(n);
    for (int &b : B)
        cin >> b;

    for (int i = 0; i < n - 1; i++) {
        if ((A[0] != B[0] && A[0] != B.back()) || (A.back() != B[0] && A.back() != B.back())) {
            cout << "Alice" << endl;
            return;
        }

        if (A[0] == B[0]) {
            A.pop_front();
            B.pop_front();
        } else if (A[0] == B.back()) {
            A.pop_front();
            B.pop_back();    
        } else if (A.back() == B[0]) {
            A.pop_back();
            B.pop_front();    
        } else if (A.back() == B.back()) {
            A.pop_back();
            B.pop_back(); 
        }
    }

    cout << "Bob" << endl;

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