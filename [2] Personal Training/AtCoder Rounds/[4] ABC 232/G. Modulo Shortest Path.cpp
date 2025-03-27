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

struct Dijkstras {
    int n;
    unordered_map<int, lng> dis;
    unordered_map<int, unordered_map<int, lng>> adjl; 

    Dijkstras(int n, unordered_map<int, lng> &dis, unordered_map<int, unordered_map<int, lng>> &adjl): n(n), dis(dis), adjl(adjl) {
    };

    unordered_map<int, bool> is_processed;
    priority_queue<pair<lng, int>, vector<pair<lng, int>>, greater<pair<lng, int>>> unprocessed;
    
    lng findShortestPath(int a, int b) {
        dis[a] = 0;
        unprocessed.push({0, a});

        while (!unprocessed.empty()) {
            int cur = unprocessed.top().second;
            unprocessed.pop();

            if (is_processed[cur]) {
                continue;
            }

            is_processed[cur] = true;

            for (auto &[nxt, w] : adjl[cur]) {
                if (dis[cur] + w < dis[nxt]) {
                    dis[nxt] = dis[cur] + w;
                    unprocessed.push({dis[nxt], nxt});
                }
            }
        }

        return dis[b];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }
    vector<int> bs(n);
    for (int &b : bs) {
        cin >> b;
    }

    unordered_map<int, lng> dis;    
    unordered_map<int, unordered_map<int, lng>> adjl;
    vector<int> used_rems;
    for (int i = 0; i < n; i++) {
        dis[i + 1] = INF64;
        dis[(as[i] - m) % m] = INF64;
        dis[-bs[i]] = INF64;

        adjl[i + 1][(as[i] - m) % m] = 0;
        adjl[-bs[i]][i + 1] = 0;
        
        used_rems.push_back((as[i] - m) % m);
        used_rems.push_back(-bs[i]);
    }
    
    sort(used_rems.begin(), used_rems.end(), greater<int>());

    int len = used_rems.size();
    for (int i = 0; i < len - 1; i++) {
        if (used_rems[i] == used_rems[i + 1]) {
            continue;
        }

        adjl[used_rems[i]][used_rems[i + 1]] = used_rems[i] - used_rems[i + 1];
    }
    if (used_rems[len - 1] != used_rems[0]) {
        adjl[used_rems[len - 1]][used_rems[0]] = used_rems[len - 1] + m - used_rems[0];
    }

    Dijkstras djk(n, dis, adjl);

    cout << djk.findShortestPath(1, n) << endl;
    
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