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

int getLargestOddFactor(int n) {
    if (n == 0) {
        return 0;
    }

    while (n % 2 == 0) {
        n /= 2;
    }

    return n;
}

void solve() {
    int n;
    cin >> n;
    priority_queue<pair<int, pair<int, int>>> as, a_tmp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        as.push({getLargestOddFactor(a), {a, 0}});
        a_tmp.push({getLargestOddFactor(a), {a, 0}});
    }
    priority_queue<pair<int, int>> bs, b_tmp;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;

        bs.push({getLargestOddFactor(b), b});
        b_tmp.push({getLargestOddFactor(b), b});
    }

    /*
    cout << "|||||||||||||||as|||||||||||||||" << endl;
    while (!a_tmp.empty()) {
        cout << a_tmp.top().first << ' ' << a_tmp.top().second.first << ' ' << a_tmp.top().second.second << endl;
        a_tmp.pop();
    }
    cout << "||||||||||||||||||||||||||||||||" << endl;
    //*/

    /*
    cout << "|||||||||||||||bs|||||||||||||||" << endl;
    while (!b_tmp.empty()) {
        cout << b_tmp.top().first << ' ' << b_tmp.top().second << endl;
        b_tmp.pop();
    }
    cout << "||||||||||||||||||||||||||||||||" << endl;
    //*/

    int ans = 0;
    while (!as.empty()) {
        while (as.top().first > bs.top().first) {
            int a_odd = as.top().first;
            auto [a, cnt] = as.top().second;
            as.pop();

            while (a != a_odd / 2) {
                a /= 2;
                cnt++;
            }

            as.push({getLargestOddFactor(a_odd / 2), {a_odd / 2, cnt}});
        }

        if (as.top().first < bs.top().first) {
            cout << -1 << endl;
            return;
        }

        auto [a, cnt] = as.top().second;
        as.pop();
        int b = bs.top().second;
        bs.pop();

        if (a == 0) {
            ans += cnt;
        } else if (a >= b) {
            ans += int(log2(a / b)) + cnt;
        } else {
            ans += int(log2(b / a)) + cnt;
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