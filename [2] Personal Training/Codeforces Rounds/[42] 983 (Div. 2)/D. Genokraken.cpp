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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;

    int cur = 2;
    set<int> to_query;
    vector<int> P(n, -1);
    P[0] = 0;
    P[1] = 0;
    for ( ; cur < n; cur++) {
        cout << "? " << 1 << ' ' << cur << endl;
    
        int res;
        cin >> res;
        
        if (!res) {
            P[cur] = 1;
            to_query.insert(cur++);

            break;
        } else {
            P[cur] = 0;
            to_query.insert(cur);
        }
    }

    for ( ; cur < n; cur++) {
        if (to_query.size() == 1) {
            P[cur] = *to_query.begin();
            to_query.clear();
            to_query.insert(cur);
            
            continue;
        }
        
        set<int> to_query2 = to_query;
        
        // for (int x : to_query2)
        //     cout << x << ' ';
        // cout << endl;

        for (int x : to_query2) {
            if (x == *to_query2.rbegin()) {
                P[cur] = x;
                if (to_query.find(x) != to_query.end())
                    to_query.erase(x);
                to_query.insert(cur);

                break;
            }

            cout << "? " << x << ' ' << cur << endl;

            int res;
            cin >> res;

            if (!res) {
                P[cur] = x;
                if (to_query.find(x) != to_query.end())
                    to_query.erase(x);
                to_query.insert(cur);

                break;
            } else {
                to_query.erase(x);
            }
        }
    }

    cout << "! ";
    for (int i = 1; i < n; i++)
        cout << P[i] << ' ';
    cout << endl;

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