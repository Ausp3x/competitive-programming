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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> idxs;
    for (int i = 0; i < m; i++) {
        int ind;
        cin >> ind;
        idxs.insert(ind);
    }
    string c;
    cin >> c;
    
    sort(c.begin(), c.end());
    // cout << c << ' ';
    
    int i = 0;
    for (int ind : idxs) {
        s[ind - 1] = c[i];  
        i++; 
    }

    cout << s << endl;

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