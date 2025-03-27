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

int solve(int N, int M, vector<int> F, vector<vector<int>> S) {
    vector<int> idx_cnts(N); 
    for (int i = 0; i < M; i++) {
        vector<int> chd_cnts(N + 1);
        for (int j = 1; j < N; j++)
            chd_cnts[F[j]]++;

        map<int, int> rem;
        for (int j = 0; j < N - 1; j++) {
            chd_cnts[F[S[i][j]]]--;
            if (rem.find(F[S[i][j]]) != rem.end()) {
                rem[F[S[i][j]]]--;
                if (rem[F[S[i][j]]] == 0)
                    rem.erase(F[S[i][j]]);
            }

            if (chd_cnts[S[i][j]] > 0)
                rem[S[i][j]] = chd_cnts[S[i][j]];

            if (rem.empty())
                idx_cnts[j]++;
        }
    }
    
    int ans = 0, prv = -1;
    map<int, int> rec_cnts;
    for (int i = 0; i < N - 1; i++) {
        if (idx_cnts[i] < M)
            continue;

        for (int j = 0; j < M; j++)
            for (int k = prv + 1; k <= i; k++) {
                if (rec_cnts.find(S[j][k]) == rec_cnts.end())
                    rec_cnts[S[j][k]] = M;

                rec_cnts[S[j][k]]--;
                
                if (rec_cnts[S[j][k]] == 0)
                    rec_cnts.erase(S[j][k]);
            }

        ans += rec_cnts.empty();

        prv = i;
    }

    return ans;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cout << solve(3, 1, {-1, 0, 0}, {{1, 2}}) << endl;
//     cout << solve(5, 2, {-1, 0, 0, 1, 1}, {{1, 2, 3, 4}, {4, 1, 2, 3}}) << endl;

//     return 0;
// }