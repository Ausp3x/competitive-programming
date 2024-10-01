// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "zebra.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

#ifdef DEBUG
int R, CNT;
// -1 - not visited, 0 - white, 1 - black
vector<int> colors;
int is_zebra(vector<int> E) {
    CNT++;

    int clr = colors[E[0]];
    for (int i = 1; i < E.size(); i++)
        if (colors[E[i]] != clr)
            return 1;

    return 0;
}
#endif

int find_root(int N, vector<int> U, vector<int> V) {
    map<pair<int, int>, int> edg_idxs;
    vector<vector<int>> adjl(N);
    for (int i = 0; i < N - 1; i++) {
        edg_idxs[{U[i], V[i] }] = i;
        edg_idxs[{V[i], U[i]}] = i;
        adjl[U[i]].pb(V[i]);
        adjl[V[i]].pb(U[i]);
    }

    bool subtask_1_chk = true;
    for (int i = 0; i < N - 1; i++) 
        if (U[i] != 0 || V[i] != i + 1) {
            subtask_1_chk = false;
            break;
        }

    // cout << subtask_1_chk << endl;

    if (subtask_1_chk && N > 20) {
        vector<int> E;
        for (int nxt : adjl[0])
            E.pb(edg_idxs[{0, nxt}]);

        int res = is_zebra(E);
        if (res == 0)
            return 0;

        int N2 = 1 << int(log2(N - 2));
        int l = 0, r = N - 2;
        while (r - l > 1) {
            while (N2 > 1 && l + N2 - 1 >= r)
                N2 >>= 1;

            int m = l + N2 - 1;
            E.clear();
            for (int i = l; i <= m; i++)
                E.pb(i);

            res = is_zebra(E);
            if (res == 0)
                l = m + 1;
            else
                r = m;
        }

        if (l == r)
            return l + 1;

        res = is_zebra({r, (r + 1) % (N - 1)});
        if (res == 0)
            return l + 1; 
        else 
            return r + 1;

        return -1;
    }

    bool subtask_2_chk = true;
    for (int i = 0; i < N - 2; i++) 
        if (U[i] != i || V[i] != i + 1) {
            subtask_2_chk = false;
            break;
        }
    subtask_2_chk &= U[N - 2] == N - 3 && V[N - 2] == N - 1;

    // cout << subtask_2_chk << endl;

    if (subtask_2_chk && N > 20) {
        int res = is_zebra({N - 2, N - 3, N - 4});
        if (res == 0)
            return N - 3;

        res = is_zebra({N - 2, N - 4});
        if (res == 0)
            return N - 2;

        res = is_zebra({N - 3, N - 4});
        if (res == 0)
            return N - 1;

        vector<int> Eternamax;
        for (int i = 0; i < N - 2; i += 2) {
            Eternamax.pb(i);
        }

        res = is_zebra(Eternamax);
        if (res == 0)
            return 0;

        int l = 0, r = Eternamax.size() - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;

            vector<int> E;
            for (int i = 0; i <= m; i++)
                E.pb(Eternamax[i]);

            int res = is_zebra(E);
            if (res == 0)
                l = m;
            else
                r = m;
        }

        res = is_zebra({Eternamax[l], Eternamax[l] + 1});
        if (res == 0)
            return Eternamax[l] + 1;
        else
            return Eternamax[l] + 2;

        return -1;
    }

    // handles non-leaf nodes
    for (int i = 0; i < N; i++) {
        if (adjl[i].size() == 1)
            continue;

        vector<int> E;
        for (int nxt : adjl[i])
            E.pb(edg_idxs[{i, nxt}]);
    
        int res = is_zebra(E);
        if (res == 0)
            return i;
    }

    // handles leaf nodes
    for (int i = 0; i < N; i++) {
        if (adjl[i].size() > 1)
            continue;

        int cur = i;
        vector<bool> vst(N - 1);
        while (true) {
            vector<int> E;
            for (int nxt : adjl[cur])
                if (!vst[edg_idxs[{cur, nxt}]]) {
                    vst[edg_idxs[{cur, nxt}]] = true;
                    E.pb(edg_idxs[{cur, nxt}]);
                }

            if (E.size() == 1) {
                cur = (cur == U[E[0]] ? V[E[0]] : U[E[0]]);
                continue;
            }

            int res = is_zebra(E);
            if (res == 0)
                return i;
            
            break;
        }
    }

    return -1;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) { 
        int N;
        cin >> N;
        vector<int> U(N - 1);
        for (int &u : U)
            cin >> u;
        vector<int> V(N - 1);
        for (int &v : V)
            cin >> v;
        
        map<pair<int, int>, int> edg_idxs;
        vector<vector<int>> adjl(N);
        for (int i = 0; i < N - 1; i++) {
            edg_idxs[{U[i], V[i]}] = i;
            edg_idxs[{V[i], U[i]}] = i;
            adjl[U[i]].pb(V[i]);
            adjl[V[i]].pb(U[i]);
        }

        for (int R = 0; R < N; R++) {  
            CNT = 0;
            colors.clear();
            colors.resize(N - 1, -1);        
            queue<pair<int, int>> q;
            q.push({R, 1});
            while (!q.empty()) {
                auto [cur, clr] = q.front();
                q.pop();
            
                for (int nxt : adjl[cur])
                    if (colors[edg_idxs[{cur, nxt}]] == -1) {
                        // cout << cur << ' ' << nxt << ' ' << edg_idxs[{cur, nxt}] << endl;
                        colors[edg_idxs[{cur, nxt}]] = clr;
                        q.push({nxt, clr ^ 1});
                    }
            }

            // cout << R << endl;
            // for (int x : colors)
            //     cout << x << ' ';
            // cout << endl;

            int ans = find_root(N, U, V);
            cout << R << ": " << ans << ' ' << (R == find_root(N, U, V) && CNT <= 20 ? "PASS" : "FAIL") << endl;
        }
    }

    return 0;
}
#endif