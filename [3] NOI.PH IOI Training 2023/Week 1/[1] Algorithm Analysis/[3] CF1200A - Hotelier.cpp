// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define ONLINE_JUDGE
// #define DEBUG

void solve() {
    int n;
    cin >> n;
    string events;
    cin >> events;
    
    string room_assignments(10, '0');
    for (char x : events) {
        if (x == 'L') {
            for (int i = 0; i < 10; i++) {
                if (room_assignments[i] == '0') {
                    room_assignments[i] = '1';
                    break;
                }
            }
        } else if (x == 'R') {
            for (int i = 9; i >= 0; i--) {
                if (room_assignments[i] == '0') {
                    room_assignments[i] = '1';
                    break;
                }
            }
        } else {
            room_assignments[x - '0'] = '0';
        }
    }

    cout << room_assignments << '\n';

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