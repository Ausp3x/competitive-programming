// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void solve() {
    int n;
    cin >> n;

    int ans = 0, to_be_removed = 1;
    priority_queue<int, vector<int>, greater<int>> sorted;
    stack<int> unsorted;
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;

        if (s == "add") {
            int x;
            cin >> x;

            unsorted.push(x);
        } else if (s == "remove") {
            if (unsorted.empty()) {
                sorted.pop();
                to_be_removed++;
    
                continue;
            }

            if (unsorted.top() == to_be_removed) {
                unsorted.pop();
                to_be_removed++;

                continue;
            }

            ans++;

            while (!unsorted.empty()) {
                sorted.push(unsorted.top());
                unsorted.pop();
            }

            sorted.pop();
            to_be_removed++;
        }
    }

    cout << ans << endl;
    
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