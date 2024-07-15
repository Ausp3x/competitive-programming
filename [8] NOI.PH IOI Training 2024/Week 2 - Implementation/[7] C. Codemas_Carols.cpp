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
    int n, Q;
    cin >> n >> Q;

    while (Q--) {
        lng q;
        cin >> q;
        
        if (q == 1) {
            cout << "On the 1st day of Codemas, my computer gave to me," << endl;
            continue;
        }

        if (q == 2) {
            cout << "A syntax error on line three!" << endl;
            continue;
        }

        lng i = (-3 + sqrtl(9 + 8 * q - 1)) / 2 + 1;
        // cout << i << endl;

        if (i > n) {
            cout << "Codemas is already over!" << endl;
            continue;
        }
    
        if (q == i * (i + 1) / 2) {
            if (i % 100 == 11 || i % 100 == 12 || i % 100 == 13)
                cout << "On the " << i << "th day of Codemas, my computer gave to me," << endl;
            else if (i % 10 == 1)
                cout << "On the " << i << "st day of Codemas, my computer gave to me," << endl;
            else if (i % 10 == 2)
                cout << "On the " << i << "nd day of Codemas, my computer gave to me," << endl;
            else if (i % 10 == 3)
                cout << "On the " << i << "rd day of Codemas, my computer gave to me," << endl;
            else 
                cout << "On the " << i << "th day of Codemas, my computer gave to me," << endl;

            continue;
        }

        if (q == (i + 1) * (i + 2) / 2 - 1) {
            cout << "And a syntax error on line three!" << endl;
            continue;
        }

        if (i >= 5) 
            if (q == (i + 1) * (i + 2) / 2 - 5) {
                cout << "FIVE! COMPILER! WARNINGS!!!" << endl;
                continue;
            }

        cout << (i + 1) * (i + 2) / 2 - q << " compiler warnings," << endl;
    }
    
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