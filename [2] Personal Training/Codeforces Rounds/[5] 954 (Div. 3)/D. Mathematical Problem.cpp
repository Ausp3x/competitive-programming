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

    if (s.size() == 2) {
        cout << stoi(s) << endl;

        return;
    }

    int ans = INF32;
    for (int i = 0; i < n - 1; i++) {
        vector<int> segments;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                segments.push_back(stoi(s.substr(j, 2)));
                j++;

                if (segments.back() == 0) {
                    cout << 0 << endl;
                    return;
                }

                if (segments.back() == 1) 
                    segments.pop_back();

                continue;
            }
            
            segments.push_back(s[j] - '0');

            if (segments.back() == 0) {
                cout << 0 << endl;
                return;
            }

            if (segments.back() == 1)
                segments.pop_back();
        }

        if (segments.empty()) {
            ans = min(ans, 1);
            continue;
        }

        ans = min(ans, accumulate(segments.begin(), segments.end(), 0));
    }

    cout << ans << endl;

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