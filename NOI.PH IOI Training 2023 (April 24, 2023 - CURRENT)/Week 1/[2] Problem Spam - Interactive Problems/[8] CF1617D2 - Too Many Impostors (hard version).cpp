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

    int a = -1, b = -1, c = -1, d = -1, e = -1, f = -1;
    vector<int> majorities(n + 1); 
    for (int i = 1; i < n; i += 3) {
        cout << "? " << i << ' ' << i + 1 << ' ' << i + 2 << endl;
        cin >> majorities[i];

        if (majorities[i] == 0 && a == -1) {
            a = i;
            b = i + 1;
            c = i + 2;
        } else if (majorities[i] == 1 && d == -1) {
            d = i;
            e = i + 1;
            f = i + 2;
        }
    }

    cout << "? " << a << ' ' << b << ' ' << d << endl;
    int r1;
    cin >> r1; 

    cout << "? " << a << ' ' << b << ' ' << e << endl;
    int r2;
    cin >> r2; 

    int imp, crw;
    if (r1 + r2 > 0) {
        imp = c;

        if (r1 == 1) {
            crw = d;
        } else if (r2 == 1) {
            crw = e;
        }      
    } else {
        imp = a;

        cout << "? " << imp << ' ' << d << ' ' << e << endl;
        cin >> r1;

        cout << "? " << imp << ' ' << d << ' ' << f << endl;
        cin >> r2;

        if (r1 == 1 || r2 == 1) {
            crw = d;
        } else {
            crw = e;
        }
    }

    vector<int> imps, crws, to_be_checked;
    for (int i = 1; i <= n; i += 3) {
        if ((i <= imp && imp <= i + 2) && (i <= crw && crw <= i + 2)) {
            imps.push_back(imp);
            crws.push_back(crw);
            if (majorities[i] == 0) {
                imps.push_back(3 * i + 3 - imp - crw);
            } else if (majorities[i] == 1) {
                crws.push_back(3 * i + 3 - imp - crw);
            }
            continue;
        }
    
        if ((i <= imp && imp <= i + 2) && majorities[i] == 1) {
            imps.push_back(imp);
            for (int j = i; j <= i + 2; j++) {
                if (j == imp) {
                    continue;
                }
                crws.push_back(j);
            }
            continue;
        }

        if ((i <= crw && crw <= i + 2) && majorities[i] == 0) {
            crws.push_back(crw);
            for (int j = i; j <= i + 2; j++) {
                if (j == crw) {
                    continue;
                }
                imps.push_back(j);
            }
            continue;
        }

        if (majorities[i] == 0) {
            cout << "? " << crw << ' ' << i << ' ' << i + 1 << endl;
            cin >> r1;

            cout << "? " << crw << ' ' << i << ' ' << i + 2 << endl;
            cin >> r2;

            if (r1 == 0 && r2 == 0) {
                imps.push_back(i);
                imps.push_back(i + 1);
                imps.push_back(i + 2);
            } else if (r1 == 0 && r2 == 1) {
                imps.push_back(i);
                imps.push_back(i + 1);
                crws.push_back(i + 2);
            } else if (r1 == 1 && r2 == 0) {
                imps.push_back(i);
                crws.push_back(i + 1);
                imps.push_back(i + 2);
            } else if (r1 == 1 && r2 == 1) {
                crws.push_back(i);
                imps.push_back(i + 1);
                imps.push_back(i + 2);
            }
        } else if (majorities[i] == 1) {
            cout << "? " << imp << ' ' << i << ' ' << i + 1 << endl;
            cin >> r1;

            cout << "? " << imp << ' ' << i << ' ' << i + 2 << endl;
            cin >> r2;

            if (r1 == 0 && r2 == 0) {
                imps.push_back(i);
                crws.push_back(i + 1);
                crws.push_back(i + 2);
            } else if (r1 == 0 && r2 == 1) {
                crws.push_back(i);
                imps.push_back(i + 1);
                crws.push_back(i + 2);
            } else if (r1 == 1 && r2 == 0) {
                crws.push_back(i);
                crws.push_back(i + 1);
                imps.push_back(i + 2);
            } else if (r1 == 1 && r2 == 1) {
                crws.push_back(i);
                crws.push_back(i + 1);
                crws.push_back(i + 2);
            }
        }
    }

    cout << "! " << imps.size() << ' ';
    for (int x : imps) {
        cout << x << ' ';
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