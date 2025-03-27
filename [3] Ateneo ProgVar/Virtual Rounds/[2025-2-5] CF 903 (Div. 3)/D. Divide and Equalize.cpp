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

int N = 1'005;
vector<bool> is_prime(N, true);
vector<int> primes;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    map<int, int> cnts;
    for (int a : A) {
        for (int p : primes) {
            if (p * p > a)
                break;
            
            while (a % p == 0) {
                cnts[p]++;
                a /= p;
            }
        }
        if (a > 1)
            cnts[a]++;
    }

    for (auto &[k, v] : cnts) {
        if (v % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) 
        if (is_prime[i]) {
            primes.pb(i);
            if (lng(i * i) < N) 
                for (int j = i * i; j < N; j += i)
                    is_prime[j] = false;
        }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}