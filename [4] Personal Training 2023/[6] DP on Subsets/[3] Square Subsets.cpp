// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

int const MOD = 1e9 + 7;

int modPow(lng x, int y, int MOD) {
    lng res = 1;

    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= MOD;
        }

        y >>= 1;
        x *= x;
        x %= MOD;
    }

    return (res + MOD) % MOD;
}

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int getPrimeFacExpParities(int x) {
    int bitmsk = 0;

    for (int i = 0; i < 19; i++) {
        int cnt = 0;

        while (x % primes[i] == 0) {
            x /= primes[i];
            cnt++;
        }

        bitmsk |= (cnt & 1) << i;
    }

    return bitmsk;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a_cnts(71);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
    
        a_cnts[a]++;
    }

    vector<int> a_bitmsks(71), a_subset_cnts(71);
    for (int a = 1; a <= 70; a++) {
        a_bitmsks[a] = getPrimeFacExpParities(a);
        
        if (a_cnts[a] == 0) {
            continue;
        }

        a_subset_cnts[a] = modPow(2, a_cnts[a] - 1, MOD);
    }

    /*
    cout << "|||||||||||||||a_bitmsks|||||||||||||||" << endl;
    for (int i = 1; i <= 70; i++) {
        cout << i << ' ' << bitset<19>(a_bitmsks[i]) << endl;
    }
    cout << "|||||||||||||||||||||||||||||||||||||||" << endl;
    //*/

    /*
    cout << "|||||||||||||||a_subset_cnts|||||||||||||||" << endl;
    for (int i = 1; i <= 70; i++) {
        cout << i << ' ' << a_subset_cnts[i] << endl;
    }
    cout << "|||||||||||||||||||||||||||||||||||||||||||" << endl;
    //*/

    vector<vector<lng>> dp(2, vector<lng>(1 << 20));
    dp[0][0] = 1;
    for (int a = 1; a <= 70; a++) {
        int i = a & 1;
        for (int j = 0; j < (1 << 20); j++) {
            dp[i][j] += dp[i ^ 1][j ^ a_bitmsks[a]] * a_subset_cnts[a];
            dp[i][j] += dp[i ^ 1][j] * (a_subset_cnts[a] == 0 ? 1 : a_subset_cnts[a]);
            dp[i][j] %= MOD;
        }
        for (int j = 0; j < (1 << 20); j++) {
            dp[i ^ 1][j] = 0;
        }
    }

    cout << dp[0][0] - 1 << endl;
    
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