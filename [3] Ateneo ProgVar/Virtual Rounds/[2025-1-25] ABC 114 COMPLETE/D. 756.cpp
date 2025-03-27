// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,};

void solve() {
    // 74
    // 2 * 24 
    // 4 * 14
    // 2 * 4 * 4

    int n;
    cin >> n;
    vector<int> cnts(25);
    for (int i = 0; i < 25; i++) {
        if (primes[i] > n)
            continue;

        int cur = primes[i];
        while (cur <= n) {
            cnts[i] += n / cur;
            cur *= primes[i];
        }
    }

    int ans1 = 0;
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 25; j++) {
            if (i == j)
                continue;

            ans1 += (cnts[i] >= 2 && cnts[j] >= 24);
            ans1 += (cnts[i] >= 4 && cnts[j] >= 14);
        }

    int ans2 = 0;
    for (int i = 0; i < 25; i++) 
        for (int j = 0; j < 25; j++)
            for (int k = 0; k < 25; k++) {
                if (i == j || i == k || j == k)
                    continue;

                ans2 += (cnts[i] >= 2 && cnts[j] >= 4 && cnts[k] >= 4);
            }
            
    cout << (cnts[0] >= 74) + ans1 + ans2 / 2 << endl;

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