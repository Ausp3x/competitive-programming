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

double snuke(lng n) { 
    int sum = 0;
    lng nn = n;
    while (nn > 0) {
        sum += nn % 10;
        nn /= 10;
    }

    return double(n) / sum;
}

void solve() {
    int k;
    cin >> k;

    lng ans = 0, base = 1;
    while (k--) {
        while (snuke(ans + base) > snuke(ans + base * 10)) {
            base *= 10;
        }

        ans += base;
        
        cout << ans << endl;
    }
    
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
    // cin >> t;
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