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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int N = 10'000'000;
vector<bool> is_prime(N + 1, true);
vector<int> primes;
vector<int> G(N + 1);

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        ans ^= G[a];
    }

    cout << (ans != 0 ? "Alice" : "Bob") << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (!is_prime[i]) 
            continue;

        primes.pb(i);
        for (lng j = 1ll * i * i; j <= N; j += i)
            is_prime[j] = false;
    }

    G[1] = 1;
    for (int i = 1; i < primes.size(); i++)
        for (int j = primes[i]; j <= N; j += 2 * primes[i])
            if (G[j] == 0)
                G[j] = i + 1;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}