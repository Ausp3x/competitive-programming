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
    int n, k;
    cin >> n >> k;
    map<int, int> a_is, i_as;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        a_is[a] = i;
        i_as[i] = a;
    }

    int team = 1;
    string ans(n, '0');
    while (!a_is.empty()) {
        auto [a, i] = *a_is.rbegin();
        
        ans[i] = '0' + team;

        vector<int> as, is;
        as.push_back(a);
        is.push_back(i);

        int kk = k;
        auto itr = i_as.find(i);
        while (kk > 0 && itr != i_as.begin()) {
            itr--;
            kk--;

            ans[itr->first] = '0' + team;
        
            as.push_back(itr->second);
            is.push_back(itr->first);
        }

        kk = k;
        itr = i_as.find(i);
        while (kk > 0 && itr != prev(i_as.end())) {
            itr++;
            kk--;

            ans[itr->first] = '0' + team;

            as.push_back(itr->second);
            is.push_back(itr->first);
        }

        int len = as.size();
        for (int i = 0; i < len; i++) {
            a_is.erase(as[i]);
            i_as.erase(is[i]);
        }

        team ^= 3;
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