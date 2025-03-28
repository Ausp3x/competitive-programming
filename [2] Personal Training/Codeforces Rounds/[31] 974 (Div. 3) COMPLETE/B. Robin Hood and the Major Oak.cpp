// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

vector<string> evn_start = {"YES", "YES", "NO", "NO"};
vector<string> odd_start = {"YES", "NO", "NO", "YES"};


void solve() {
    int n, k;
    cin >> n >> k;

    int bgn = max(n - k + 1, 1);
    int len = min(n, k);
    if (bgn % 2 == 0) {
        cout << evn_start[len % 4] << endl;
    } else {
        cout << odd_start[len % 4] << endl;
    }
    
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