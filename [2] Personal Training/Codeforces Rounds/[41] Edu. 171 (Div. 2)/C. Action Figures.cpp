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
    string s(n + 1, 'X');
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    deque<int> free;
    priority_queue<int> pay;
    for (int i = n; i >= 1; i--)
        if (s[i] == '1' && free.size() <= n / 2)
            free.pb(i);
        else
            pay.push(i);

    lng ans = 1ll * n * (n + 1) / 2;
    while (!free.empty()) {
        while (!pay.empty())
            if (pay.top() > free.front())
                pay.pop();
            else
                break;

        if (pay.empty())
            if (free.size() > 1) {
                pay.push(free.back());
                free.pop_back();
            }

        if (!pay.empty()) {
            ans -= free.front();
            free.pop_front();
            pay.pop();
        } else 
            break;
    }

    cout << ans << endl;
    
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