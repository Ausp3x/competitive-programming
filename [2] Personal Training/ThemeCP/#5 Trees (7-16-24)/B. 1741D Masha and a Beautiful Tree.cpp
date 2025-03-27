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
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

vector<int> arr;
int calc(int l, int r) {
    int len = r - l + 1;
    if (len == 1)
        return (arr[l] == l ? 0 : -1);

    int res = 0;
    for (int i = l; i < l + len / 2; i++)
        if (arr[i] < l || arr[i] >= l + len / 2) {
            for (int j = l; j < l + len / 2; j++)
                swap(arr[j], arr[j + len / 2]);
            res++;
        }

    for (int i = l; i < l + len / 2; i++)
        if (arr[i] < l || arr[i] >= l + len / 2)
            return -1;

    int lft = calc(l, l + len / 2 - 1);
    int rht = calc(l + len / 2, r);
    
    if (lft == -1 || rht == -1)
        return -1;

    return res + lft + rht;
}

void solve(int t) {
    int m;
    cin >> m;
    arr.clear();
    arr.resize(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> arr[i];

    cout << calc(1, m) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}