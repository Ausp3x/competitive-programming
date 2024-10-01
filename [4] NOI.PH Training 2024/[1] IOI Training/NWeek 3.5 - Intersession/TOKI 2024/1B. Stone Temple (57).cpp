// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "temple.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng min_weight(int N, int M, int K, vector<int> U, vector<int> V, vector<int> W, vector<int> P) {
    bool subtask_1_chk = (M == N - 1) && (K == 1) && (P[0] == N - 1);
    for (int i = 0; i < M; i++)
        subtask_1_chk &= (U[i] == i) & (V[i] == i + 1);

    if (subtask_1_chk) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < M; i++) {
            while (!pq.empty())
                if (pq.top() <= W[i])
                    pq.pop();
                else
                    break;
            pq.push(W[i]);
        }
        
        lng ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }

    set<int> S;
    vector<vector<pair<int, int>>> adjl(N);
    for (int i = 0; i < M; i++) {
        S.insert(W[i]);
        adjl[U[i]].pb({V[i], W[i]});
        adjl[V[i]].pb({U[i], W[i]});
    }

    if (N <= 1000 && M <= 2000 && S.size() <= 10) {
        int N2 = S.size();
        vector<int> idx_val;
        for (int x : S)
            idx_val.pb(x);
        map<int, int> val_idx;
        for (int i = 0; i < N2; i++)
            val_idx[idx_val[i]] = i;

        queue<pair<int, int>> q;
        vector<vector<bool>> vst(N, vector<bool>(1 << N2));
        q.push({0, 0});
        while (!q.empty()) {
            auto [cur, w_cur] = q.front();
            q.pop();

            if (vst[cur][w_cur])
                continue;
            vst[cur][w_cur] = true;

            for (auto [nxt, w] : adjl[cur]) {
                int w_nxt = w_cur;
                w_nxt |= (1 << (val_idx[w] + 1)) - 1;
                for (int i = 0; i < val_idx[w]; i++)
                    w_nxt ^= 1 << i;

                q.push({nxt, w_nxt});
            }
        }

        lng ans = INF64;
        for (int p : P)
            for (int i = 0; i < (1 << N2); i++) {
                if (!vst[p][i])
                    continue;
                
                lng cur = 0;
                for (int j = 0; j < N2; j++)
                    if (i & (1 << j))
                        cur += idx_val[j];

                ans = min(ans, cur);
            }

        return ans;      
    }

    if (N <= 1000 && M <= 2000) {
        int N2 = S.size();
        vector<int> idx_val = {0};
        for (int x : S)
            idx_val.pb(x);
        map<int, int> val_idx;
        for (int i = 1; i <= N2; i++)
            val_idx[idx_val[i]] = i;

        vector<vector<bool>> is_proc(N, vector<bool>(N2 + 1));
        vector<vector<lng>> dis(N, vector<lng>(N2 + 1, INF64));
        priority_queue<tuple<lng, int, int>, vector<tuple<lng, int, int>>, greater<tuple<lng, int, int>>> unproc;
        for (int p : P) {
            dis[p][0] = 0;
            unproc.push({dis[p][0], p, 0});
        }
        while (!unproc.empty()) {
            auto [d, cur, cur_w] = unproc.top();
            unproc.pop();

            if (is_proc[cur][cur_w]) {
                continue;
            }
            is_proc[cur][cur_w] = true;

            for (auto &[nxt, w] : adjl[cur]) {
                if (w <= idx_val[cur_w])
                    w = 0;

                int nxt_w = max(cur_w, val_idx[w]);
                if (dis[cur][cur_w] + w < dis[nxt][nxt_w]) {
                    dis[nxt][nxt_w] = dis[cur][cur_w] + w;
                    unproc.push({dis[nxt][nxt_w], nxt, nxt_w});
                }
            }
        }

        lng ans = INF64; 
        for (int i = 0; i <= N2; i++)
            ans = min(ans, dis[0][i]);

        return ans;
    }

    return -1;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> U(M), V(M), W(M);
        for (int &u : U)
            cin >> u;
        for (int &v : V)
            cin >> v;
        for (int &w : W)
            cin >> w;
        vector<int> P(K);
        for (int &p : P)
            cin >> p;

        cout << min_weight(N, M, K, U, V, W, P) << endl;
    }

    return 0;
}
#endif