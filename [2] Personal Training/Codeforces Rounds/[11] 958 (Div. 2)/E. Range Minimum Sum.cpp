// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct SegTree {    
    int l, r;
    lng sum = 0, upd = 0;
    SegTree *l_child, *r_child;

    SegTree(int l, int r, const vector<int> &arr) {
        this->l = l;
        this->r = r;
        upd = 0;

        if (l == r) {
            sum += arr[l];
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, arr);
            r_child = new SegTree(m + 1, r, arr);
            pull();
        }
    }

    // push updates down to children
    void push() {
        sum = getTotalSum();
        if (l_child != nullptr && r_child != nullptr) {
            l_child->upd += upd;
            r_child->upd += upd;
        }
        upd = 0;

        return;
    }

    // pull states up from children
    void pull() {
        assert(upd == 0);
        if (l_child != nullptr && r_child != nullptr) {
            sum = l_child->getTotalSum() + r_child->getTotalSum();
        }

        return;
    }

    void rangeSumUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            upd += x;
            return;
        }
        
        push();
        l_child->rangeSumUpdate(cur_l, cur_r, x);
        r_child->rangeSumUpdate(cur_l, cur_r, x);
        pull();
        return;
    }

    lng rangeSumQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return getTotalSum();
        } 
        
        push();
        return l_child->rangeSumQuery(cur_l, cur_r) + r_child->rangeSumQuery(cur_l, cur_r);
    }

    lng getTotalSum() {
        return sum + (r - l + 1) * upd;
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has sum " << sum << " and upd " << upd << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};

void solve(int t) {
    int n;
    cin >> n;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;

    // val, idx
    priority_queue<pair<int, int>> pq0, pq1;
    vector<vector<int>> pse(n, {-1, -1});
    for (int i = n - 1; i >= 0; i--) {
        while (!pq1.empty()) {
            if (A[i] >= pq1.top().fi)
                break;

            auto [a, b] = pq1.top();
            pq1.pop();

            pse[b][1] = i;
        }

        while (!pq0.empty()) {
            if (A[i] >= pq0.top().fi)
                break;
            
            auto [a, b] = pq0.top();
            pq0.pop();

            pse[b][0] = i;
            pq1.push({a, b});
        }

        pq0.push({A[i], i});
    }

    pq0 = priority_queue<pair<int, int>>();
    pq1 = priority_queue<pair<int, int>>();
    vector<vector<int>> nse(n, {n, n});
    for (int i = 0; i < n; i++) {
        while (!pq1.empty()) {
            if (A[i] >= pq1.top().fi)
                break;

            auto [a, b] = pq1.top();
            pq1.pop();

            nse[b][1] = i;
        }

        while (!pq0.empty()) {
            if (A[i] >= pq0.top().fi)
                break;
            
            auto [a, b] = pq0.top();
            pq0.pop();

            nse[b][0] = i;
            pq1.push({a, b});
        }

        pq0.push({A[i], i});
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++) {
            if (pse[i][j] == -1)
                pse[i][j] = -1;
            if (nse[i][j] == -1)
                nse[i][j] = n;
        }

    // for (int i = 0; i < n; i++)
    //     cout << (pse[i][1] == -1 ? 0 : A[pse[i][1]]) << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << (pse[i][0] == -1 ? 0 : A[pse[i][0]]) << ' ';
    // cout << endl;
    // for (int &a : A)
    //     cout << a << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << (nse[i][0] == -1 ? 0 : A[nse[i][0]]) << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << (nse[i][1] == -1 ? 0 : A[nse[i][1]]) << ' ';
    // cout << endl;
    // cout << endl;
    
    SegTree *root = new SegTree(0, n - 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        root->rangeSumUpdate(0, pse[i][0] - 1, A[i] * (i - pse[i][0]) * (nse[i][0] - i));
        root->rangeSumUpdate(pse[i][0], pse[i][0], A[i] * (i - pse[i][1] - 1) * (nse[i][0] - i));
        root->rangeSumUpdate(pse[i][0] + 1, i - 1, A[i] * (i - pse[i][0] - 1) * (nse[i][0] - i));
        root->rangeSumUpdate(i + 1, nse[i][0] - 1, A[i] * (i - pse[i][0]) * (nse[i][0] - i - 1));
        root->rangeSumUpdate(nse[i][0], nse[i][0], A[i] * (i - pse[i][0]) * (nse[i][1] - i - 1));
        root->rangeSumUpdate(nse[i][0] + 1, n - 1, A[i] * (i - pse[i][0]) * (nse[i][0] - i));
    }
    
    for (int i = 0; i < n; i++) {
        cout << root->rangeSumQuery(i, i) << ' ';
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}