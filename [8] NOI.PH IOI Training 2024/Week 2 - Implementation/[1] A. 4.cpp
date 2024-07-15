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
    string s;
    char on_1, on_2;
    cin >> s >> s >> on_1;
    cin >> s >> s >> on_2;
    cin >> s >> s >> s >> s;
    char off;
    cin >> s >> s >> off;
    cin >> s >> s >> s;
    int l1, l2;
    string tmp;
    cin >> s >> l1 >> s >> s;
    cin >> s >> l2 >> s >> tmp;

    string ans = "XXXX";
    if (tmp == "HOT") {
        if (on_1 == off) {
            ans[l1] = on_2;
            ans[l2] = on_1;
        } else if (on_2 == off) {
            ans[l1] = on_1;
            ans[l2] = on_2;
        }
        ans[l1 ^ l2] = char('@' + ((on_1 - '@') ^ (on_2 - '@')));
    } else if (tmp == "COOL") {
        if (on_1 == off) {
            ans[l1] = on_2;
            ans[l1 ^ l2] = on_1;
        } else if (on_2 == off) {
            ans[l1] = on_1;
            ans[l1 ^ l2] = on_2;
        }
        ans[l2] = char('@' + ((on_1 - '@') ^ (on_2 - '@')));
    }

    for (int i = 1; i <= 3; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
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