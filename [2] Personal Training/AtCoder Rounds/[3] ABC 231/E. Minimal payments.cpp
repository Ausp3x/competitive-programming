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

map<lng, map<int, lng>> min_steps;
vector<lng> as;
lng steps(lng x, int i) {
    if (x == 0) {
        return 0;
    }

    if (min_steps[x].count(i)) {
        return min_steps[x][i];
    }

    auto itr = min_steps[x].find(i);
    if (itr != min_steps[x].begin()) {
        min_steps[x][i] = (--itr)->second;
    } else {
        min_steps[x][i] = INF64;
    }

    if (x % as[i] == 0) {
        min_steps[x][i] = min(min_steps[x][i], x / as[i]);

        return min_steps[x][i];
    }

    min_steps[x][i] = min({min_steps[x][i], 
                           x / as[i] + steps(x % as[i], i - 1), 
                           x / as[i] + 1 + steps(as[i] - x % as[i], i - 1)});

    return min_steps[x][i];
}


void solve() {
    int n;
    lng x;
    cin >> n >> x;
    as.resize(n);
    for (lng &a : as) {
        cin >> a;
    }

    for (int i = 0; i < n; i++) {
        steps(x, i);
    }

    cout << min_steps[x][n - 1] << endl;

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