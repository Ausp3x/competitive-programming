// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "combo.h"
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

#ifdef DEBUG
string s = "BAAAXXXYYY";

int press(string p) {
    int res = 0, res_max = 0;
    for (char c : p) {
        if (res_max == s.size()) {
            cout << p << ' ' << res_max << endl;
            return res_max;
        }

        if (s[res] == c)
            res++;
        else
            res = s[0] == c;

        res_max = max(res_max, res);
    }

    cout << p << ' ' << res_max << endl;
    return res_max;
}
#endif

string guess_sequence(int N) {
    string chrs;
    if (press("AB") > 0)
        if (press("A") == 1) 
            chrs = "ABXY";
        else 
            chrs = "BAXY";
    else
        if (press("X") == 1)
            chrs = "XABY";
        else
            chrs = "YABX";

    if (N == 1)
        return chrs.substr(0, 1);

    string ans;
    ans += chrs[0];
    for (int _ = 1; _ < N - 1; _++) {
        string cur;
        cur += ans;
        cur += chrs[2];
        cur += ans;
        cur += chrs[3];
        cur += chrs[1];
        cur += ans;
        cur += chrs[3];
        cur += chrs[2];
        cur += ans;
        cur += chrs[3];
        cur += chrs[3];
        
        int res = press(cur);
        ans += chrs[res - ans.size() + 1]; 
    }

    string cur = ans;
    cur += chrs[1];
    if (press(cur) == ans.size() + 1) 
        return cur;

    cur = ans;
    cur += chrs[2];
    if (press(cur) == ans.size() + 1)
        return cur;

    ans += chrs[3];
    return ans;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << guess_sequence(s.size()) << endl;

    return 0;
}
#endif