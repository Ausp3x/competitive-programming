// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "robots.h"
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng fastPow(lng x, lng y) {
    if (y == 0)
        return 1;
    
    lng res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
        }
 
        y >>= 1;
        x *= x;
    }
 
    return res;
}
int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    if (T == 2 && A + B == 2) {
        vector<pair<int, int>> robots;
        for (int i = 0; i < A; i++)
            robots.push_back({X[i], 2 * INF32});
        for (int i = 0; i < B; i++)
            robots.push_back({2 * INF32, Y[i]});

        int ans = -1, l = robots.size();
        for (int i = 0; i < fastPow(l, T); i++) {
            int ii = i;
            vector<int> cnts(l);
            for (int j = 0; j < T; j++) {
                if (W[j] < robots[ii % l].first && S[j] < robots[ii % l].second)
                    cnts[ii % l]++;
            
                ii /= l;
            }

            if (accumulate(cnts.begin(), cnts.end(), 0) < T)
                continue;

            int max_cnt = 0;
            for (int j = 0; j < T; j++)
                max_cnt = max(max_cnt, cnts[j]);

            ans = (ans == -1 ? max_cnt : min(ans, max_cnt));
        }

        return ans;
    }

    if (B == 0) {
        sort(X, X + A);
        
        vector<int> reqs;
        for (int i = 0; i < T; i++)
            reqs.push_back(upper_bound(X, X + A, W[i]) - X);
    
        sort(reqs.begin(), reqs.end(), greater<int>());

        if (reqs[0] == A)
            return -1;

        int ans = -1, l = 0, r = T;
        while (l <= r) {
            int md = (l + r) / 2;

            bool chk = true;
            int j = A - 1;
            vector<int> cnts(A);
            for (int i = 0; i < T; i++) {
                while (cnts[j] == md) {
                    if (j == 0) {
                        chk = false;
                        exit;
                    }
            
                    j--;
                }

                if (j < reqs[i]) {
                    chk = false;
                    break;
                }

                cnts[j]++;
            }

        exit:
            if (chk) {
                ans = md;
                r = md - 1;
            } else
                l = md + 1;
        }

        return ans;
    }

    sort(X, X + A);
    sort(Y, Y + B, greater<int>());

    vector<pair<int, int>> toys;
    for (int i = 0; i < T; i++)
        toys.push_back({W[i], S[i]});

    sort(toys.begin(), toys.end());    

    int ans = -1, l = 0, r = T;
    while (l <= r) {
        int md = (l + r) / 2;

        int j = 0;
        priority_queue<int> pq;
        for (int i = 0; i < A; i++) {
            while (toys[j].first < X[i] && j < T) {
                pq.push(toys[j].second);
                j++;
            }

            int cnt = 0;
            while (!pq.empty() && cnt < md) {
                pq.pop();
                cnt++;
            }
        }

        while (j < T) {
            pq.push(toys[j].second);
            j++;
        }

        for (int i = 0; i < B; i++) {
            if (pq.top() >= Y[i])
                break;

            int cnt = 0;
            while (!pq.empty() && cnt < md) {
                pq.pop();
                cnt++;
            }
        }

        if (pq.empty()) {
            ans = md;
            r = md - 1;
        } else 
            l = md + 1;
    }

    return ans;
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int A, B, T;
        cin >> A >> B >> T;
        int X[A];
        for (int i = 0; i < A; i++)
            cin >> X[i];
        int Y[B];
        for (int i = 0; i < B; i++)
            cin >> Y[i];
        int W[T], S[T];
        for (int i = 0; i < T; i++)
            cin >> W[i] >> S[i];

        cout << putaway(A, B, T, X, Y, W, S) << endl;
    }

    return 0;
}
//*/