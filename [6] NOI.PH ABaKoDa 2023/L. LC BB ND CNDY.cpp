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
    string s;
    getline(cin, s);
    lng idx;
    cin >> idx;

    map<char, bool> is_illegal_letter {
        {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
        {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true},
        {',', true}, {'.', true}, {'!', true}, {'?', true}, {' ', true}
    };
    
    string s_red;
    for (char c : s) {
        if (is_illegal_letter[c]) {
            continue;
        } 

        s_red += toupper(c);
    }

    int len = s_red.size();
    if (log2(idx) > len - 1) {
        cout << "out of bounds" << endl;
        return;
    }

    for (int i = 0; i < len - 1; i++) {
        cout << s_red[i];
        if (len - i - 2 > 59) {
            cout << ' ';
        } else if (!((idx - 1) & (1ll << (len - i - 2)))) {
            cout << ' ';
        }
    }
    cout << s_red.back() << endl;
    
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