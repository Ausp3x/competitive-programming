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

void solve() {
    map<char, char> nLtr_oLtrs, oLtr_nLtrs;
    for (char i = 'a'; i <= 'z'; i++) {
        char x;
        cin >> x;

        nLtr_oLtrs[x] = i;
        oLtr_nLtrs[i] = x;
    }
    int n;
    cin >> n;
    vector<string> ss(n);
    for (auto &s : ss) {
        cin >> s;
        
        for (char &x : s) {
            x = nLtr_oLtrs[x];
        }
    }

    sort(ss.begin(), ss.end());

    for (auto &s : ss) {
        for (char &x : s) {
            x = oLtr_nLtrs[x];
        }

        cout << s << endl;
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