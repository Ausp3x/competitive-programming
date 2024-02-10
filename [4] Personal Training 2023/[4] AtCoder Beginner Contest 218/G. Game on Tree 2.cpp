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

void insertValue(int a, multiset<int> &left, multiset<int> &right) {
    if (left.empty()) {
        left.insert(a);
    } else if (a <= *left.rbegin()) {
        left.insert(a);
    } else {
        right.insert(a);
    }
    
    return;
}

void eraseValue(int a, multiset<int> &left, multiset<int> &right) {
    if (a <= *left.rbegin()) {
       left.erase(left.find(a));
    } else {
        right.erase(right.find(a));
    }

    return;
}

void adjustMultisets(multiset<int> &left, multiset<int> &right) {
    if (left.size() == right.size() + 2) {
        int x = *left.rbegin();
        left.erase(--left.end());
        right.insert(x);
    } else if (right.size() == left.size() + 1) {
        int x = *right.begin();
        right.erase(right.begin());
        left.insert(x);
    }

    return;
}

int getMedian(multiset<int> &left, multiset<int> &right) {
    if (left.size() > right.size()) {
        return *left.rbegin();
    } 
    
    if (left.size() == right.size()) {
        return (*left.rbegin() + *right.begin()) / 2;
    }

    return -1;
}

int findMedianAfterOptimalPlays(int turn, int cur, int prv, multiset<int> &left, multiset<int> &right, vector<int> &as, vector<vector<int>> &adjl) {
    insertValue(as[cur], left, right);
    adjustMultisets(left, right);

    if (adjl[cur].size() == 1 && cur != 0) {    
        int mdn = getMedian(left, right);

        eraseValue(as[cur], left, right);
        adjustMultisets(left, right);
        
        return mdn;
    }

    int mdn = (turn == 0 ? 0 : INF32);
    for (int nxt : adjl[cur]) {
        if (nxt == prv) {
            continue;
        }

        if (turn == 0) {
            mdn = max(mdn, findMedianAfterOptimalPlays(turn ^ 1, nxt, cur, left, right, as, adjl));
        } else {
            mdn = min(mdn, findMedianAfterOptimalPlays(turn ^ 1, nxt, cur, left, right, as, adjl));
        }
    }

    eraseValue(as[cur], left, right);
    adjustMultisets(left, right);

    return mdn;
}

void solve() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }
    vector<vector<int>> adjl(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    if (n == 1) {
        cout << as[0] << endl;
        return;
    }

    if (n == 2) {
        cout << (as[0] + as[1]) / 2 << endl;
        return;
    }

    multiset<int> left, right;

    cout << findMedianAfterOptimalPlays(0, 0, -1, left, right, as, adjl) << endl;

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