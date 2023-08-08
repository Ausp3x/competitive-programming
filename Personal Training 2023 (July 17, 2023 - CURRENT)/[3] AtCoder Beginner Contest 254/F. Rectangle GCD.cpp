// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

struct SparseTable {
    int len, len_log2;
    vector<vector<int>> sptb;

    void init(int n, vector<int> arr) {
        len = n;
        len_log2 = log2(n);
        sptb.resize(len_log2 + 1, vector<int>(len));

        for (int j = 0; j < n; j++) {
            sptb[0][j] = arr[j];
        }

        for (int i = 1; i < len_log2 + 1; i++) {
            for (int j = 0; j + (1 << i) - 1 < n; j++) {
                sptb[i][j] = __gcd(sptb[i - 1][j], sptb[i - 1][j + (1 << (i - 1))]);
            }
        }
    
        return;
    }
    
    int query(int l, int r) {
        if (l > r) {
            return 0;
        }

        int i = log2(r - l + 1);

        return __gcd(sptb[i][l], sptb[i][r - (1 << i) + 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }
    vector<int> bs(n);
    for (int &b : bs) {
        cin >> b;
    }
    
    vector<int> a_minus(n), b_minus(n);
    for (int i = 1; i < n; i++) {
        a_minus[i] = abs(as[i] - as[i - 1]);
        b_minus[i] = abs(bs[i] - bs[i - 1]);
    }

    SparseTable a_sptb, b_sptb;
    a_sptb.init(n, a_minus);
    b_sptb.init(n, b_minus);

    while (q--) {
        int h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        h1--; h2--; w1--; w2--;

        int ans = as[h1] + bs[w1];
        ans = __gcd(ans, a_sptb.query(h1 + 1, h2));
        ans = __gcd(ans, b_sptb.query(w1 + 1, w2));

        cout << ans << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}