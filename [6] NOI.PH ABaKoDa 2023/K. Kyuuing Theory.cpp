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
    lng t;
    cin >> n >> t;
    lng a_max = 0;
    vector<lng> as(n);
    for (lng &a : as) {
        cin >> a;
        a_max = max(a_max, a);
    }
    
    if (a_max > t) {
        cout << "NO" << endl;
        return;
    }


    int l = 1, r = n;
    while (l <= r) {
        int md = (l + r) / 2;
        
        bool chk = true;
        priority_queue<lng, vector<lng>, greater<lng>> pq;
        for (int i = 0; i < md; i++) {
            pq.push(0);
        }
        for (lng a : as) {
            if (pq.top() + a <= t) {
                pq.push(pq.top() + a);
                pq.pop();
            } else {
                chk = false;
                break;
            }
        }

        if (chk) {
            r = md - 1;
        } else {
            l = md + 1;
        }
    }
    
    cout << "YES" << endl;
    cout << l << endl;

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