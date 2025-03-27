// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "buffet.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng min_leftover(int N, vector<int> A) {
    if (A[0] == 0 && A[N - 1] == 0)
        return accumulate(A.begin(), A.end(), 0ll);

    if (A[N - 1] == 0) {        
        vector<int> A_min(N);
        A_min[0] = A[0];
        for (int i = 1; i < N; i++)
            A_min[i] = min(A_min[i - 1], A[i]);

        return accumulate(A.begin(), A.end(), 0ll) - accumulate(A_min.begin(), A_min.end(), 0ll);
    }

    int inc_peak = 0;
    for (int i = 0; i < N - 1; i++)
        if (A[i + 1] >= A[i])
            inc_peak = i + 1;
        else
            break;

    int dec_peak = N - 1;
    for (int i = N - 1; i > 0; i--) {
        if (A[i - 1] >= A[i])
            dec_peak = i - 1;
        else
            break;
    }

    if (inc_peak >= dec_peak) {
        int d = A[0] + A[N - 1];
        lng ans = 0;
        for (int i = 0; i < N; i++) {
            ans += max(A[i] - d, 0);
        }

        return ans;
    }

    bool subtask_5_chk = true;
    for (int i = 1; i < N - 1; i++)
        if (A[i] < A[0]) {
            subtask_5_chk = false;
            break;
        }

    if (A[0] == A[N - 1] && subtask_5_chk) {
        int a = A[0];
        for (int i = 0; i < N; i++)
            A[i] -= a;

        // for (int x : A)
        //     cout << x << ' ';
        // cout << endl;

        int l = -1, r = -1;
        // size, l, r
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < N; i++)
            if (A[i] > 0) {
                if (l == -1)
                    l = i;
                r = i;
            } else {
                if (l != -1)
                    pq.push({r - l + 1, l, r});
                l = -1;
                r = -1;
            }

        while (a > 0 && !pq.empty()) {
            auto [len, cur_l, cur_r] = pq.top();
            pq.pop();

            // cout << len << ' ' << cur_l << ' ' << cur_r << endl;

            int A_min = a;
            for (int i = cur_l; i <= cur_r; i++)
                A_min = min(A_min, A[i]);

            for (int i = cur_l; i <= cur_r; i++)
                A[i] -= A_min;
            a -= A_min;

            int l = -1, r = -1;
            for (int i = cur_l; i <= cur_r; i++) {
                if (A[i] > 0) {
                    if (l == -1)
                        l = i;
                    r = i;
                } else {
                    if (l != -1)
                        pq.push({r - l + 1, l, r});
                    l = -1;
                    r = -1;
                }
            }
            if (l != -1)
                pq.push({r - l + 1, l, r});

            // for (int x : A)
            //     cout << x << ' ';
            // cout << endl;
        }
    
        return accumulate(A.begin(), A.end(), 0ll);
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
        vector<int> A(N);
        for (int &a : A)
            cin >> a;

        cout << min_leftover(N, A) << endl; 
    }

    return 0;
}
#endif