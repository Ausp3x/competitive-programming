// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

#define ONLINE_JUDGE
// #define DEBUG

void solve() {
    int n;
    cin >> n;
    
    vector<int> responses(n);
    for (int i = 0; i < n; i++) {
        cout << "? " << i + 1 << ' ' << (i + 1) % n + 1 << ' ' << (i + 2) % n + 1 << endl;
        cin >> responses[i];
    }

    int a, b;
    for (int i = 0; i < n; i++) {
        if (responses[((i - 1) % n + n) % n] != responses[i]) {
            a = i + 1;
            b = (i + 1) % n + 1;
            break;
        }
    }

    int res, cnt = 0, c = -1, d = -1;
    vector<int> is_not_impostors(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b) {
            continue;
        }

        cout << "? " << a << ' ' << b << ' ' << i << endl;
        cin >> res;
        
        is_not_impostors[i] = res;
        cnt += res == 0;
        if (res == 0 && c == -1) {
            c = i;
        }
        if (res == 1 && d == -1) {
            d = i;
        }
    }

    cout << "? " << c << ' ' << d << ' ' << a << endl;
    cin >> res;
    
    is_not_impostors[a] = res;
    cnt += res == 0;

    cout << "? " << c << ' ' << d << ' ' << b << endl;
    cin >> res;
    
    is_not_impostors[b] = res;
    cnt += res == 0;

    cout << "! " << cnt << ' ';
    for (int i = 1; i <= n; i++) {
        if (is_not_impostors[i] == 0) {
            cout << i << ' ';
        }
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifdef DEBUG
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef DEBUG
    // testing code
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}