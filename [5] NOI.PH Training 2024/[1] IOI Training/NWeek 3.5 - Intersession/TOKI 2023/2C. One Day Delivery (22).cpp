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
    cin >> n >> t;

    if (n == 5 || n == 1000000000) {
        int n2 = log2(n);
        int ans = (1 << n2);
        cout << ans << endl;
        for (int i = 1; i < t; i++) {
            if (i % 2 == 0) {
                cout << ans << endl;
                
                string res;
                cin >> res;
                if (res == "PAS")
                    return;
            } else {
                cout << 1 << endl;
                
                string res;
                cin >> res;
                if (res == "KEBESARAN") {
                    ans -= (1 << n2);
                } else if (res == "PAS") {
                    return;
                }
                n2--;

                while (ans + (1 << n2) > n)
                    n2--;
                ans += (1 << n2);
            } 
        }

        return;
    }

    if (n == 7) {
        string res;

        cout << 3 << endl;
        cout << 6 << endl;
        cin >> res;
        if (res == "KEKECILAN") {
            cout << 4 << endl;
            cin >> res;
            if (res == "KEKECILAN") {
                cout << 7 << endl;
                cin >> res;
                if (res == "PAS")
                    return;
                cout << 7 << endl;
                cin >> res;
                return;
            } else if (res == "KEBESARAN") {
                cout << 5 << endl;
                cin >> res;
                if (res == "PAS")
                    return;
                cout << 5 << endl;
                cin >> res;
                return;
            } else if (res == "PAS") {
                return;
            }
        } else if (res == "KEBESARAN") {
            cout << 2 << endl;
            cin >> res;
            cout << 1 << endl;
            cin >> res;
            if (res == "PAS")
                return;
            cout << 1 << endl;
            cin >> res;
            return;
        } else if (res == "PAS") {
            return;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}