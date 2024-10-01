// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "dreaming.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    vector<vector<pair<int, int>>> adjl(N);
    for (int i = 0; i < M; i++) {
        adjl[A[i]].pb({B[i], T[i]});
        adjl[B[i]].pb({A[i], T[i]});
    }

    lng max_diameter = 0;
    vector<int> vst(N);
    vector<lng> W;
    for (int i = 0; i < N; i++) {
        if (vst[i])
            continue;

        if (adjl[i].empty()) {
            W.pb(0);
            continue;
        }

        int end1 = i;
        lng max_dis = 0;
        queue<pair<int, lng>> bfs;
        bfs.push({i, 0});
        while (!bfs.empty()) {
            auto [cur, cur_d] = bfs.front();
            bfs.pop();

            if (vst[cur] > 0)
                continue;
            vst[cur]++;
            
            if (cur_d > max_dis) {
                end1 = cur;
                max_dis = cur_d;
            }

            for (auto [nxt, d] : adjl[cur]) {
                if (vst[nxt] == 0)
                    bfs.push({nxt, cur_d + d});
            } 
        }

        map<int, pair<lng, lng>> dis_from_diameter_ends;

        int end2 = end1; 
        max_dis = 0;
        bfs.push({end1, 0});
        while (!bfs.empty()) {
            auto [cur, cur_d] = bfs.front();
            bfs.pop();

            if (vst[cur] > 1)
                continue;
            vst[cur]++;
            
            if (cur_d > max_dis) {
                end2 = cur;
                max_dis = cur_d;
            }
            dis_from_diameter_ends[cur].fi = cur_d;

            for (auto [nxt, d] : adjl[cur]) {
                if (vst[nxt] == 1)
                    bfs.push({nxt, cur_d + d});
            }
        }

        max_diameter = max(max_diameter, max_dis);

        bfs.push({end2, 0});
        while (!bfs.empty()) {
            auto [cur, cur_d] = bfs.front();
            bfs.pop();

            if (vst[cur] > 2)
                continue;
            vst[cur]++;

            dis_from_diameter_ends[cur].se = cur_d;

            for (auto [nxt, d] : adjl[cur]) {
                if (vst[nxt] == 2)
                    bfs.push({nxt, cur_d + d});
            }
        }

        lng w = INF64;
        for (auto [k, v] : dis_from_diameter_ends) {
            // cout << v.fi << ' ' << v.se << endl;
            w = min(w, max(v.fi, v.se));
        }
        // cout << w << endl;

        W.pb(w);
    }

    sort(W.begin(), W.end(), greater<lng>());
    
    // for (int x : W)
    //     cout << x << ' ';
    // cout << endl;

    if (W.size() == 1) {
        return max(W[0], max_diameter);
    }

    if (W.size() == 2) {
        return max(W[0] + W[1] + L, max_diameter);
    }
    
    return max({W[0] + W[1] + L, W[1] + W[2] + 2 * L, max_diameter});
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int N, M, L;
        cin >> N >> M >> L;
        int A[M], B[M], T[M];
        for (int i = 0; i < M; i++)
            cin >> A[i] >> B[i] >> T[i];
        
        cout << travelTime(N, M, L, A, B, T) << endl;
    }

    return 0;
}
#endif