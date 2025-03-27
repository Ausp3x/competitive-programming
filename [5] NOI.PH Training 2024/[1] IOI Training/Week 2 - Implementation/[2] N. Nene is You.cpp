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
    int r, c;
    cin >> r >> c;
    map<char, bool> l_used;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            l_used[grid[i][j]] = true;
        }
    }
    int n;
    cin >> n;
    vector<pair<char, char>> path;
    while (n--) {
        char a, b;
        string s;
        cin >> a >> s >> b;
        
        if (a == b) {
            continue;
        }

        if (l_used[a] && l_used[b]) {
            cout << "NO" << endl;
            return;
        }
    
        if (l_used[a]) {
            path.push_back({b, a});
            l_used[a] = false;
            l_used[b] = true;
        }
    }
    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    for (auto &[a, b] : path) {
        cout << a << " is " << b << endl;
    }

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