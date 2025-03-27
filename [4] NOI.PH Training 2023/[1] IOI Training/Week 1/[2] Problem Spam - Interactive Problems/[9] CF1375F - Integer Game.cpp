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
    lng a, b, c;
    cin >> a >> b >> c;

    cout << "First" << endl;

    int res;
    if (a == b && b == c) {    
        cout << 1 << endl;
        cin >> res;

        cout << 1 << endl;
        cin >> res;
        return;
    }

    if (a == b) {
        if (a < c) {
            cout << c - a << endl;
            cin >> res;

            cout << 2 * (c - a) << endl;
            cin >> res;
        } else {
            cout << a - c << endl;
            cin >> res;

            cout << a - c << endl;
            cin >> res;            
        }
        return;
    }

    if (a == c) {
        if (a < b) {
            cout << b - a << endl;
            cin >> res;

            cout << 2 * (b - a) << endl;
            cin >> res;
        } else {
            cout << a - b << endl;
            cin >> res;

            cout << a - b << endl;
            cin >> res;            
        }
        return;
    }

    if (b == c) {
        if (b < a) {
            cout << a - b << endl;
            cin >> res;

            cout << 2 * (a - b) << endl;
            cin >> res;
        } else {
            cout << b - a << endl;
            cin >> res;

            cout << b - a << endl;
            cin >> res;            
        }
        return;
    }
    
    while (true) {
        vector<lng> ints = {a, b, c};
        sort(ints.begin(), ints.end(), greater<lng>());

        lng y;
        if (ints[0] - ints[1] != ints[1] - ints[2]) {
            y = 2 * ints[0] - ints[1] - ints[2];
        } else {
            y = ints[0] - ints[1];
        }

        cout << y << endl;
        cin >> res;

        switch (res) {
            case 0:
                return;
            case 1:
                a += y;
                break;
            case 2:
                b += y;
                break;
            case 3:
                c += y;
                break;
        }
    }

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
    // cin >> t;
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