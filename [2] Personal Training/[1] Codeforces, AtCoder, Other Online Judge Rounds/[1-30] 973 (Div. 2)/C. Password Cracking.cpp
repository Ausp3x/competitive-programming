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

void solve() {
    int n;
    cin >> n;
    
    cout << "? 0" << endl;

    int res0;
    cin >> res0;

    if (!res0) {
        cout << "! " << string(n, '1') << endl;
        return;
    }

    vector<string> ss = {"0", "1"};

    bool is_rev = false;
    string s = "0";
    for (int i = 1; i < n; i++) {
        bool has_true = false;
        for (int j = 0; j < 2; j++) {
            if (!is_rev)
                cout << "? " << s + ss[j] << endl;
            else 
                cout << "? " << ss[j] + s << endl;

            int res;
            cin >> res;

            if (res) {
                if (!is_rev)
                    s = s + ss[j];
                else
                    s = ss[j] + s;
                has_true = true;
                break;
            }
        }

        if (!has_true) {
            reverse(ss.begin(), ss.end());
            is_rev = true;
            i--;
        }
    }

    cout << "! " << s << endl;

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