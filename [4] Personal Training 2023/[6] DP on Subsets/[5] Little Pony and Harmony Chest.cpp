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

int prm_len = 16;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
map<int, vector<int>> same_prm_facs = {
    {stoi("0000000000000000", 0, 2), {1}},
    {stoi("0000000000000001", 0, 2), {2, 4, 8, 16, 32}},
    {stoi("0000000000000010", 0, 2), {3, 9, 27}},
    {stoi("0000000000000100", 0, 2), {5, 25}},
    {stoi("0000000000000011", 0, 2), {6, 12, 18, 24, 36, 48, 54}},
    {stoi("0000000000001000", 0, 2), {7, 49}},
    {stoi("0000000000000101", 0, 2), {10, 20, 40, 50}},
    {stoi("0000000000010000", 0, 2), {11}},
    {stoi("0000000000100000", 0, 2), {13}},
    {stoi("0000000000001001", 0, 2), {14, 28, 56}},
    {stoi("0000000000000110", 0, 2), {15, 45}},
    {stoi("0000000001000000", 0, 2), {17}},
    {stoi("0000000010000000", 0, 2), {19}},
    {stoi("0000000000001010", 0, 2), {21}},
    {stoi("0000000000010001", 0, 2), {22, 44}},
    {stoi("0000000100000000", 0, 2), {23}},
    {stoi("0000000000100001", 0, 2), {26, 52}},
    {stoi("0000001000000000", 0, 2), {29}},
    {stoi("0000000000000111", 0, 2), {30}},
    {stoi("0000010000000000", 0, 2), {31}},
    {stoi("0000000000010010", 0, 2), {33}},
    {stoi("0000000001000001", 0, 2), {34}},
    {stoi("0000000000001100", 0, 2), {35}},
    {stoi("0000100000000000", 0, 2), {37}},
    {stoi("0000000010000001", 0, 2), {38}},
    {stoi("0000000000100010", 0, 2), {39}},
    {stoi("0001000000000000", 0, 2), {41}},
    {stoi("0000000000001011", 0, 2), {42}},
    {stoi("0010000000000000", 0, 2), {43}},
    {stoi("0000000100000001", 0, 2), {46}},
    {stoi("0100000000000000", 0, 2), {47}},
    {stoi("0000000001000010", 0, 2), {51}},
    {stoi("1000000000000000", 0, 2), {53}},
    {stoi("0000000000010100", 0, 2), {55}},
    {stoi("0000000010000010", 0, 2), {57}},
    {stoi("0000001000000001", 0, 2), {58}} 
};

map<int, vector<pair<int, int>>> optimal_bs;

void solve() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }

    vector<vector<pair<int, vector<int>>>> dp(2, vector<pair<int, vector<int>>>(1 << prm_len, {INF32, {}}));
    for (auto &[j, bs] : same_prm_facs) {
        auto [b, d] = optimal_bs[j][as[0]];
        dp[0][j] = {d, {b}};
    }
    for (int i = 1; i < n; i++) {
        int i_red = i & 1;
        for (int j = 0; j < (1 << prm_len); j++) {
            int j_prv = 0, b_opt = 1;
            for (auto &[k, bs] : same_prm_facs) {
                if ((j & k) != k) {
                    continue;
                }

                auto [b, d] = optimal_bs[k][as[i]]; // (void)b; (void)d;
                if (dp[i_red ^ 1][j ^ k].first + d < dp[i_red][j].first) {
                    dp[i_red][j].first = dp[i_red ^ 1][j ^ k].first + d;
                    j_prv = j ^ k;
                    b_opt = b;
                }
            }

            dp[i_red][j].second = dp[i_red ^ 1][j_prv].second;
            dp[i_red][j].second.push_back(b_opt);
        }

        for (int j = 0; j < (1 << prm_len); j++) {
            dp[i_red ^ 1][j] = {INF32, {}};
        }
    }

    /*
    cout << "|||||||||||||||dp|||||||||||||||" << endl;
    for (int i = 0; i < 2; i++) {
        cout << i << ": ";
        for (int j = 0; j < 64; j++) {
            cout << dp[i][j].first << ' ';
        }
        cout << endl;
    }
    cout << "||||||||||||||||||||||||||||||||" << endl;
    //*/

    int min_dif_sum = INF32, j_opt = -1;
    for (int j = 0; j < (1 << prm_len); j++) {
        if (dp[(n - 1) & 1][j].first < min_dif_sum) {
            j_opt = j;
            
            min_dif_sum = dp[(n - 1) & 1][j].first;
        }
    }

    for (int b : dp[(n - 1) & 1][j_opt].second) {
        cout << b << ' ';
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (auto &[bitmsk, bs] : same_prm_facs) {
        optimal_bs[bitmsk].resize(31, {-1, -1});
        
        for (int a = 1; a <= 30; a++) {
            if (a <= bs[0]) {
                optimal_bs[bitmsk][a] = {bs[0], bs[0] - a};
            } else if (a >= bs.back()) {
                optimal_bs[bitmsk][a] = {bs.back(), a - bs.back()};
            } else {
                auto itr = upper_bound(bs.begin(), bs.end(), a);
                int b1 = *(itr - 1), b2 = *itr; 
                int d1 = a - b1, d2 = b2 - a;

                if (d1 <= d2) {
                    optimal_bs[bitmsk][a] = {b1, d1};
                } else {
                    optimal_bs[bitmsk][a] = {b2, d2};
                }
            }        
        }
    }

    /*
    cout << "|||||||||||||||optimal_bs|||||||||||||||" << endl;
    for (auto &[bitmsk, b_opts] : optimal_bs) {
        cout << bitset<16>(bitmsk) << endl;
        for (int a = 1; a <= 30; a++) {
            cout << a << ' ' << b_opts[a].first << endl;
        }
        cout << endl;
    }
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    //*/

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}