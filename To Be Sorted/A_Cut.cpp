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
typedef long long             lng;
typedef pair<int, int>        pi;
typedef vector<int>           vi;
typedef pair<lng, lng>        pl;
typedef vector<lng, lng>      vl;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve(int t) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A)
        cin >> a;

    for (int i = N - K; i < N; i++)
        cout << A[i] << ' ';
    for (int i = 0; i < N - K; i++)
        cout << A[i] << ' ';
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);     

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}