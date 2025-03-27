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

vector<double> P = {0, 0, double(1)/36, double(2)/36, double(3)/36, double(4)/36, double(5)/36, double(6)/36, double(5)/36, double(4)/36, double(3)/36, double(2)/36, double(1)/36};

int n;
vector<int> D;
vector<vector<double>> memo;

double dp(int hp) {
    memo.clear();
    memo.resize(n + 1, vector<double>(hp + 1));
    memo[0][hp] = 1;

    for (int i = 0; i < n; i++) 
        for (int j = 1; j <= hp; j++) {
            for (int jump = 2; jump <= 12; jump++) {
                int new_i = min(i + jump, n);
                int new_j = j - D[new_i];

                if (new_j <= 0)
                    continue;

                memo[new_i][new_j] += memo[i][j] * P[jump];
            }
        }

    double res = 0;
    for (int j = 1; j <= hp; j++)
        res += memo[n][j];

    return res;
}

void solve() {
    int a, b, c;
    cin >> n >> a >> b >> c;
    D.clear();
    D.resize(n + 1);
    for (int &d : D)
        cin >> d;

    double A = dp(a);
    double B = dp(b);
    double C = dp(c);

    cout << setprecision(15) << A * B * C << endl;

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