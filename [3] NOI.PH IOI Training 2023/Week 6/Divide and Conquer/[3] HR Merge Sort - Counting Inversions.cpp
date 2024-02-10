// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

vector<int> fnwt;

void sub(int i, int x) {
    while (i < int(fnwt.size())) {
        fnwt[i] -= x;
        i += i & -i;
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += fnwt[i];
        i -= i & -i;
    }

    return s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> as(n);
    fnwt.clear();
    fnwt.resize(1e7 + 5);
    for (int &a : as) {
        cin >> a;
        fnwt[a]++;
    }

    for (int i = 1; i < int(fnwt.size()); i++) {
        int j = i + (i & -i);
        if (j < int(fnwt.size())) {
            fnwt[j] += fnwt[i];
        }
    }

    // number of a[j] < a[i] for each a[i] where 0 < i < j < n

    lng ans = 0;
    for (int i = 0; i < n; i++) {
        sub(as[i], 1);
        
        ans += sum(as[i] - 1);
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}