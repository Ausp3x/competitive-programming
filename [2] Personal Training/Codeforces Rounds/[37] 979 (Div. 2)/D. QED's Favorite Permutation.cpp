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
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    string s(n + 1, 'X');
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    vector<int> dif_arr(n + 1);
    for (int i = 1; i <= n; i++) {
        dif_arr[min(A[i], i)]++;
        dif_arr[max(A[i], i)]--;
    }
    for (int i = 2; i <= n; i++)
        dif_arr[i] += dif_arr[i - 1];

    set<int> problems;
    for (int i = 1; i < n; i++) 
        if (s[i] == 'L' && s[i + 1] == 'R' && dif_arr[i] > 0)
            problems.insert(i);

    while (q--) {
        int x;
        cin >> x;
        
        s[x] = (s[x] == 'L' ? 'R' : 'L');
        if (s[x - 1] == 'L' && s[x] == 'R' && dif_arr[x - 1] > 0)
            problems.insert(x - 1);
        else
            problems.erase(x - 1);
        if (s[x] == 'L' && s[x + 1] == 'R' && dif_arr[x] > 0)
            problems.insert(x);
        else
            problems.erase(x);

        cout << (problems.empty() ? "YES" : "NO") << endl;
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