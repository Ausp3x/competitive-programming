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
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1) {
        cout << 2 << endl;
        return;
    }

    if (n == 2) {
        if (s[0] != s[1]) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
        return;
    }
 
    bool chk = false;
    vector<string> patterns = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    for (int i = 0; i < n - 2; i++) {
        for (auto p : patterns) {
            if (s.substr(i, 3) == p) {
                chk = true;
                goto exit;
            }
        }
    }
exit:

    if (chk) {
        cout << 0 << endl;
    } else if (s[n - 2] != s[n - 1]) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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