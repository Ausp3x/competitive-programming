// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct SegTree {
    int mn, mx;
    int l, r;
    SegTree *l_child, *r_child;
    
    SegTree(int l, int r) {
        if (l == r)
            this->mn = this->mx = 0;
        else {
            this->mn = -INF32;
            this->mx = INF32;
        }
        this->l = l;
        this->r = r;

        if (l == r) {
            this->l_child = this->r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            this->l_child = new SegTree(l, m);
            this->r_child = new SegTree(m + 1, r);
        }

        return;
    }

    void push() {
        if (l_child != nullptr && r_child != nullptr) {
            if (this->mn > l_child->mx)
                l_child->mn = l_child->mx = this->mn;
            else if (this->mx < l_child->mn)
                l_child->mn = l_child->mx = this->mx;
            else {
                l_child->mn = max(l_child->mn, this->mn);
                l_child->mx = min(l_child->mx, this->mx);
            }

            if (this->mn > r_child->mx)
                r_child->mn = r_child->mx = this->mn;
            else if (this->mx < r_child->mn)
                r_child->mn = r_child->mx = this->mx;
            else {
                r_child->mn = max(r_child->mn, this->mn);
                r_child->mx = min(r_child->mx, this->mx);
            }
        }
        this->mn = -INF32;
        this->mx = INF32;

        return;
    }

    void rangeMaximize(int L, int R, int h) {
        if (r < L || R < l)
            return;
        else if (L <= l && r <= R) {
            this->mn = max(this->mn, h);
            this->mx = max(this->mx, h);
        } else {
            push();
            l_child->rangeMaximize(L, R, h);
            r_child->rangeMaximize(L, R, h);
        }
    }

    void rangeMinimize(int L, int R, int h) {
        if (r < L || R < l)
            return;
        else if (L <= l && r <= R) {
            this->mn = min(this->mn, h);
            this->mx = min(this->mx, h);
        } else {
            push();
            l_child->rangeMinimize(L, R, h);
            r_child->rangeMinimize(L, R, h);
        }
    }

    int query(int M) {
        if (r < M || M < l)
            return -1;
        else if (l == M && r == M)
            return this->mn;
        else {
            push();
            int lq = l_child->query(M), rq = r_child->query(M);
            if (lq != -1)
                return lq;
            else if (rq != -1)
                return rq;
            else
                return -1;
        }
    }
};

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
    SegTree *root = new SegTree(0, n - 1);
    
    for (int i = 0; i < k; i++)
        if (op[i] == 1)
            root->rangeMaximize(left[i], right[i], height[i]);
        else if (op[i] == 2)
            root->rangeMinimize(left[i], right[i], height[i]);

    for (int i = 0; i < n; i++)
        finalHeight[i] = root->query(i);

    return;
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int op[k], left[k], right[k], height[k], finalHeight[n];
        for (int i = 0; i < k; i++)
            cin >> op[i] >> left[i] >> right[i] >> height[i];

        buildWall(n, k, op, left, right, height, finalHeight);

        for (int i = 0; i < n; i++)
            cout << finalHeight[i] << ' ';
        cout << endl;
    }

    return 0;
}
//*/