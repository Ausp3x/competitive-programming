// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int m;
    cin >> m;
    stack<int> A;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        A.push(a);
    }
    int n;
    cin >> n;
    stack<int> B;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        B.push(b);
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