// 人外有人，天外有天
// author: Ausp3x
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "horses.h"
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;
 
int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;
 
int const MOD = 1000000007;
 
int N;
vector<int> X, Y;
 
lng modPow(lng x, lng y) {
    lng res = 1;
 
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= MOD;
        }
 
        y >>= 1;
        x *= x;
        x %= MOD;
    }
 
    return (res + MOD) % MOD;
}
 
lng almostAllHorses = 1;
int getMaxValue(int opt) {
    if (opt == 1) {
        lng horses = 1;
        for (int i = 0; i < N; i++) {
            (horses *= X[i]) %= MOD;
            
            bool chk = true;
            lng cur = 1; 
            for (int j = i + 1; j < N; j++) {
                if (cur == INF32 || cur * X[j] > INF32) {
                    chk = false;
                    break;
                }
                cur *= X[j];
 
                if (cur * Y[j] > Y[i]) {
                    chk = false;
                    break;
                }
            }
                
            if (chk) {
                return horses * Y[i] % MOD;
            }
        }
    } else if (opt == 2) {
        lng horses = almostAllHorses;
        for (int i = max(N - 64, 0); i < N; i++) {
            (horses *= X[i]) %= MOD;
            
            bool chk = true;
            lng cur = 1; 
            for (int j = i + 1; j < N; j++) {
                if (cur == INF32 || cur * X[j] > INF32) {
                    chk = false;
                    break;
                }
                cur *= X[j];
 
                if (cur * Y[j] > Y[i]) {
                    chk = false;
                    break;
                }
            }
                
            if (chk) {
                return horses * Y[i] % MOD;
            }
        }
    }
 
    return -1;
}
 
bool allXG1 = true;
int init(int n, int x[], int y[]) {
    N = n;
    X.clear();
    X.resize(n);
    Y.clear();
    Y.resize(n);
    for (int i = 0; i < N; i++) {
        if (i < N - 64)
            (almostAllHorses *= x[i]) %= MOD;
        
        if (x[i] < 2)
            allXG1 = false;
 
        X[i] = x[i];
        Y[i] = y[i];
    }
 
	return (allXG1 ? getMaxValue(2) : getMaxValue(1));
}
 
bool allValG1 = true;
int updateX(int pos, int val) {
    if (pos < N - 64) {
        (almostAllHorses *= modPow(X[pos], MOD - 2)) %= MOD;
        (almostAllHorses *= val) %= MOD;
    }
 
    if (val < 2)
        allValG1 = false;
    
    X[pos] = val;
 
	return (allXG1 && allValG1 ? getMaxValue(2) : getMaxValue(1));
}
 
int updateY(int pos, int val) {    
    Y[pos] = val;
 
	return (allXG1 && allValG1 ? getMaxValue(2) : getMaxValue(1));
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        int y[n];
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }

        cout << init(n, x, y) << endl;

        int m;
        cin >> m;
        while (m--) {
            int opt, pos, val;
            cin >> opt >> pos >> val;
            if (opt == 1) {
                cout << opt << ' ' << pos << ' ' << val << ' ';
                cout << updateX(pos, val) << endl;
            } else if (opt == 2) {
                cout << opt << ' ' << pos << ' ' << val << ' ';
                cout << updateY(pos, val) << endl;
            }
        }
    }

    return 0;
}
//*/