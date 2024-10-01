// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "friend.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>> adjl;

vector<bool> st4_vst;
// including cur, excluding cur
vector<pair<lng, lng>> st4_dp;

lng st4(int cur, int confidence[]) {
    if (st4_dp[cur].fi != 0 || st4_dp[cur].se != 0)
        return max(st4_dp[cur].fi, st4_dp[cur].se);

    st4_vst[cur] = true;

    st4_dp[cur].fi += confidence[cur];
    for (int nxt : adjl[cur]) {
        if (st4_vst[nxt])
            continue;

        st4(nxt, confidence);

        st4_dp[cur].fi += st4_dp[nxt].se;
        st4_dp[cur].se += max(st4_dp[nxt].fi, st4_dp[nxt].se);
    }

    return max(st4_dp[cur].fi, st4_dp[cur].se);
}

vector<int> st5_parent;
vector<vector<int>> st5_resm;

bool st5_isReachable(int n, int s, int t) {
    queue<int> q;
    vector<bool> vst(n);
    q.push(s);
    vst[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) 
            if (st5_resm[u][v] > 0 && !vst[v]) {
                st5_parent[v] = u;
                
                if (v == t) 
                    return true;
                
                q.push(v);
                vst[v] = true;
            }
    }

    return false;
}

int findSample(int n, int confidence[], int host[], int protocol[]) {
    if (n <= 1000) {
        adjl.clear();
        adjl.resize(n);
        for (int i = 1; i < n; i++) {
            switch (protocol[i]) {
                case 0: // IAmYourFriend
                    adjl[host[i]].pb(i);
                    adjl[i].pb(host[i]);
                    break;
                case 1: // MyFriendsAreYourFriends
                    for (int j : adjl[host[i]]) {
                        adjl[j].pb(i);
                        adjl[i].pb(j);
                    }        
                    break;
                case 2: // WeAreYourFriends
                    for (int j : adjl[host[i]]) {
                        adjl[j].pb(i);
                        adjl[i].pb(j);
                    }
                    adjl[host[i]].pb(i);
                    adjl[i].pb(host[i]);
                    break;
                default:
                    return -1;
            }
        }
    }

    if (n <= 10) {
        lng ans = 0;
        for (int msk = 0; msk < (1 << n); msk++) {
            vector<bool> vst(n);
            for (int i = 0; i < n; i++)
                vst[i] = msk & (1 << i);
            
            lng cur = 0;
            for (int i = 0; i < n; i++) {
                if (!vst[i])
                    continue;

                cur += confidence[i];

                for (int j : adjl[i])
                    if (vst[j])
                        goto exit;
            }

            ans = max(ans, cur);
        exit:;
        }

#ifdef DEBUG
        cout << ans << endl;
#endif
#ifndef DEBUG
        return ans;
#endif 
    }

    bool isAll0 = true, isAll1 = true, isAll2 = true;
    bool has2 = false;
    for (int i = 1; i < n; i++) {
        isAll0 &= protocol[i] == 0;
        isAll1 &= protocol[i] == 1;
        isAll2 &= protocol[i] == 2;
        has2 |= protocol[i] == 2;
    }

    if (isAll1) {
        lng ans = 0;
        for (int i = 0; i < n; i++)
            ans += confidence[i];
        
        return ans;
    }

    if (isAll2) {
        lng ans = 0;
        for (int i = 0; i < n; i++)
            ans = max<lng>(ans, confidence[i]);
        
        return ans;
    }

    if (isAll0) {
        st4_vst.clear();
        st4_vst.resize(n);
        st4_dp.clear();
        st4_dp.resize(n, {0, 0});

        return st4(0, confidence);
    }

    // Ford-Fulkerson
    if (!has2) {
        st5_resm.clear();
        st5_resm.resize(n + 2, vector<int>(n + 2));
        vector<bool> vst(n);
        for (int i = 0; i < n; i++) {
            if (vst[i])
                continue;
            
            queue<pair<int, int>> q;
            q.push({i, 0});
            vst[i] = true;
            while (!q.empty()) {
                auto [cur, cclr] = q.front();
                q.pop();

                if (cclr == 0) {
                    st5_resm[0][cur + 1] = 1;
                } else if (cclr == 1) {
                    st5_resm[cur + 1][n + 1] = 1;
                }

                int nclr = cclr ^ 1;
                for (int nxt : adjl[cur]) {
                    if (cclr == 0)
                        st5_resm[cur + 1][nxt + 1] = 1;
                    
                    if (vst[nxt])
                        continue;
                    
                    q.push({nxt, nclr});
                    vst[nxt] = true;
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << i + 1 << ": ";
        //     for (int j : adjl[i])
        //         cout << j + 1 << ' ';
        //     cout << endl;
        // }

        // for (int i = 0; i <= n + 1; i++) {
        //     for (int j = 0; j <= n + 1; j++)
        //         cout << st5_resm[i][j] << ' ';
        //     cout << endl;
        // }    
    
        int max_flow = 0;
        st5_parent.clear();
        st5_parent.resize(n + 2);
        while (st5_isReachable(n + 2, 0, n + 1)) {
            int cur_flow = INF32;
            for (int v = n + 1; v != 0; v = st5_parent[v]) {
                int u = st5_parent[v];
                cur_flow = min(cur_flow, st5_resm[u][v]);
            }

            for (int v = n + 1; v != 0; v = st5_parent[v]) {
                int u = st5_parent[v];
                st5_resm[u][v] -= cur_flow;
                st5_resm[v][u] += cur_flow;
            }

            max_flow += cur_flow;
        }

        return n - max_flow;
    }

    vector<lng> choose(n), not_choose(n);
    for (int i = 0; i < n; i++)
        choose[i] = confidence[i];

    for (int i = n - 1; i >= 1; i--) {
        switch (protocol[i]) {
            case 0:
                choose[host[i]] += not_choose[i];
                not_choose[host[i]] += max(choose[i], not_choose[i]);
                break;
            case 1:
                choose[host[i]] = max({choose[host[i]] + choose[i], choose[host[i]] + not_choose[i], not_choose[host[i]] + choose[i]});
                not_choose[host[i]] += not_choose[i];
                break;
            case 2:
                choose[host[i]] = max(choose[host[i]] + not_choose[i], not_choose[host[i]] + choose[i]);
                not_choose[host[i]] += not_choose[i];
                break;
            default:
                cout << "No!" << endl;
        }
    }
    
    return max(choose[0], not_choose[0]);
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int confidence[n];
        for (int i = 0; i < n; i++)
            cin >> confidence[i];
        int host[n], protocol[n];
        for (int i = 1; i < n; i++)
            cin >> host[i] >> protocol[i];
    
        cout << findSample(n, confidence, host, protocol) << endl;
    }

    return 0;
}
#endif