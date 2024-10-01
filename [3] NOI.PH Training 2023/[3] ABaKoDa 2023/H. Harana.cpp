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
    vector<int> ss(n);
    for (int &s : ss) {
        cin >> s;
    }
    vector<int> bs(n);
    for (int &b : bs) {
        cin >> b;
    }
    vector<lng> difs(n);
    for (lng i = 0; i < n; i++) {
        difs[i] = bs[i] - ss[i];
    }

    priority_queue<lng> less_than_median;
    priority_queue<lng, vector<lng>, greater<lng>> greater_than_median;

    lng prv_median = difs[0];    
    vector<lng> ans1(n);
    less_than_median.push(difs[0]);
    for (int i = 2; i < n; i++) {
        ans1[i] = ans1[i - 1];

        int llen = less_than_median.size(), glen = greater_than_median.size();

        if (difs[i - 1] <= less_than_median.top()) {
            less_than_median.push(difs[i - 1]);
        } else {
            greater_than_median.push(difs[i - 1]);
        }

        int type = 0;
        lng moved = -1;

        if (less_than_median.size() > greater_than_median.size() + 1) {
            greater_than_median.push(less_than_median.top());
            type = -1;
            moved = less_than_median.top();

            less_than_median.pop();
        }

        if (greater_than_median.size() > less_than_median.size()) {
            less_than_median.push(greater_than_median.top());
            type = 1;
            moved = greater_than_median.top();
            
            greater_than_median.pop();
        }

        lng cur_median = less_than_median.top();
        ans1[i] += abs(cur_median - difs[i - 1]);
        if (type == -1 && moved != difs[i - 1]) {
            ans1[i] -= abs(prv_median - moved);
            ans1[i] += abs(cur_median - moved);
            ans1[i] += abs(cur_median - prv_median) * abs(llen - 1 - glen);
        } else if (type == 1 && moved != difs[i - 1]) {
            ans1[i] -= abs(prv_median - moved);
            ans1[i] += abs(cur_median - moved);
            ans1[i] += abs(cur_median - prv_median) * abs(llen - glen + 1);
        } else {
            ans1[i] += abs(cur_median - prv_median) * abs(llen - glen);
        }

        prv_median = cur_median;
    }

    reverse(difs.begin(), difs.end());

    while (!less_than_median.empty()) {
        less_than_median.pop();
    }
    while (!greater_than_median.empty()) {
        greater_than_median.pop();
    }

    prv_median = difs[0];    
    vector<lng> ans2(n);
    less_than_median.push(difs[0]);
    for (int i = 2; i < n; i++) {
        ans2[i] = ans2[i - 1];

        int llen = less_than_median.size(), glen = greater_than_median.size();

        if (difs[i - 1] <= less_than_median.top()) {
            less_than_median.push(difs[i - 1]);
        } else {
            greater_than_median.push(difs[i - 1]);
        }

        int type = 0;
        lng moved = -1;

        if (less_than_median.size() > greater_than_median.size() + 1) {
            greater_than_median.push(less_than_median.top());
            type = -1;
            moved = less_than_median.top();

            less_than_median.pop();
        }

        if (greater_than_median.size() > less_than_median.size()) {
            less_than_median.push(greater_than_median.top());
            type = 1;
            moved = greater_than_median.top();
            
            greater_than_median.pop();
        }

        lng cur_median = less_than_median.top();
        ans2[i] += abs(cur_median - difs[i - 1]);
        if (type == -1 && moved != difs[i - 1]) {
            ans2[i] -= abs(prv_median - moved);
            ans2[i] += abs(cur_median - moved);
            ans2[i] += abs(cur_median - prv_median) * abs(llen - 1 - glen);
        } else if (type == 1 && moved != difs[i - 1]) {
            ans2[i] -= abs(prv_median - moved);
            ans2[i] += abs(cur_median - moved);
            ans2[i] += abs(cur_median - prv_median) * abs(llen - glen + 1);
        } else {
            ans2[i] += abs(cur_median - prv_median) * abs(llen - glen);
        }

        prv_median = cur_median;
    }

    for (int i = 1; i < n; i++) {
        cout << ans1[i] + ans2[n - i] << ' ';
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