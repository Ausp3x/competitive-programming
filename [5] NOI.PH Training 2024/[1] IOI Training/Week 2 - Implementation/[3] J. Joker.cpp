// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    vector<char> itoc = {'X', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T'};
    map<char, int> ctoi = {
        {'A', 1},  {'2', 2},  {'3', 3}, {'4', 4}, {'5', 5}, 
        {'6', 6},  {'7', 7},  {'8', 8}, {'9', 9}, {'T', 10},
        {'J', 10}, {'Q', 10}, {'K', 10}  
    };

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int jokers = 0, sum = 0;
    for (char c : s) {
        if (c == '*') {
            jokers++;
        } else {
            sum += ctoi[c];
        }
    }

    if (m < sum + jokers || m > sum + 10 * jokers) {
        cout << "NO" << endl;
        return;
    }

    sum = m - sum - jokers;
    for (char &c : s) {
        if (c == '*') {
            c = itoc[min(sum, 9) + 1];
            sum -= min(sum, 9);
        }
    }

    cout << "YES" << endl;
    cout << s << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}