#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

lng kadane(vector<int> &arr) {
    lng max_sum = -INF64, cur_sum = -INF64;
    for (int a : arr) {
        cur_sum = max(cur_sum + a, lng(a));
        max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
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