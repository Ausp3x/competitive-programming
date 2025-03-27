// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "secret.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int NN;
vector<bool> can_pass;
vector<lng> dis_to_next;

void init(int N, int M, vector<int> A) {
    NN = N;
    can_pass.resize(M, true);
    dis_to_next.clear();
    dis_to_next.resize(N);
    for (int i = 1; i < N; i++) {
        dis_to_next[i] += dis_to_next[i - 1];
        dis_to_next[i] += min(abs(A[i] - A[i - 1]), M - abs(A[i] - A[i - 1]));
    }

    return;
}

void toggle(int R) {
    can_pass[R] = can_pass[R] ^ 1;
    if (NN <= 2000) {
        return;
    }

    return;
}

lng query(int S, int T) {
    return dis_to_next[T] - dis_to_next[S];
}


#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> A(N);
        for (int &a : A)
            cin >> a;        

        init(N, M, A);

        while (Q--) {
            int event;
            cin >> event;
            if (event == 0) {
                int R;
                cin >> R;

                toggle(R);
            } else if (event == 1) {
                int S, T;
                cin >> S >> T;
                
                cout << query(S, T) << endl;
            }
        }
    }

    return 0;
}
#endif