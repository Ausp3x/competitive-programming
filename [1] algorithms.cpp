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

lng dijkstra(int u, int v, int n, vector<vector<pair<int, int>>> &adjl) {
    vector<bool> is_processed(n + 1);
    vector<lng> dis(n + 1, INF64);
    priority_queue<pair<lng, int>, vector<pair<lng, int>>, greater<pair<lng, int>>> unprocessed;

    dis[u] = 0;
    unprocessed.push({dis[u], u});
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

    return dis[v];
}

lng kadane(vector<int> &arr) {
    lng max_sum = -INF64, cur_sum = -INF64;

    for (int a : arr) {
        cur_sum = max(cur_sum + a, lng(a));
        max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
}

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

struct UnionFind {
    int n;
    vector<int> link, size;

    UnionFind(int n): n(n), link(n + 1), size(n + 1, 1) {
        iota(link.begin(), link.end(), 0);
    }

    int findSet(int v) {
        if (v == link[v]) {
            return link[v];
        } else {
            return link[v] = findSet(link[v]);
        }
    }

    bool sameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

    void uniteSets(int a, int b) {
        if (sameSet(a, b)) {
            return;
        }

        a = findSet(a);
        b = findSet(b);
        
        if (size[a] < size[b]) {
            swap(a, b);
        }
        
        size[a] += size[b];
        link[b] = a;

        return;
    }
};