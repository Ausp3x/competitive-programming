// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include "doll.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

#ifdef DEBUG
void answer(vector<int> C, vector<int> X, vector<int> Y) {
    
    return;
}
#endif

void create_circuit(int M, vector<int> A) {
    int N = A.size();

}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int M, N;
        cin >> M >> N;
        vector<int> A(N);
        for (int &a : A)
            cin >> a;
        
        create_circuit(M, A);
    }

    return 0;
}
#endif