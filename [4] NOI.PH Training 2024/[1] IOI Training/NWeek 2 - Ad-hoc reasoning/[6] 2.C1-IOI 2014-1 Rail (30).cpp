// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "rail.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long         lng;
typedef pair<int, int>    pi;
typedef vector<int>       vi;
typedef pair<lng, lng>    pl;
typedef vector<lng>       vl;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void findLocation(int n, int first, int location[], int stype[]) {
    location[0] = first;
    stype[0] = 1;

    if (n == 1)
        return;

    int min_d = INF32, lm_up = -1;
    for (int i = 1; i < n; i++) {
        int d = getDistance(0, i);
        if (d < min_d) {
            min_d = d;
            lm_up = i;
        }
    }

    location[lm_up] = first + min_d;
    stype[lm_up] = 2;

    for (int i = 1; i < n; i++) {
        if (i == lm_up)
            continue;

        int d1 = getDistance(0, i);
        int d2 = getDistance(lm_up, i);
        if (d1 > d2) {
            location[i] = first - d2 + min_d;
            stype[i] = 1;
        } else {
            location[i] = first + d1;
            stype[i] = 2;
        }
    }
    
    return;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
    }

    return 0;
}
#endif