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
    lng idx, k_1, k_2;
    cin >> idx >> k_1 >> k_2;

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
    if (s.size() <= 16) {
        int cnt = 0;
        for (int bitmsk = 0; bitmsk < (1 << (len - 1)); bitmsk++) {
            string ans;
            vector<int> token_lengths;
            token_lengths.push_back(0);
            for (int i = 0; i < len - 1; i++) {
                ans += s_red[i];
                token_lengths.back()++;
                if (!(bitmsk & (1 << (len - 2 - i)))) {
                    ans += ' ';
                    token_lengths.push_back(0);
                }
            }
            ans += s_red[len - 1];
            token_lengths.back()++;

            bool is_valid = true;
            for (int i = 0; i < token_lengths.size(); i++) {
                if (token_lengths[i] > k_1) {
                    is_valid = false;
                    break;
                }
            }

            if (!is_valid) {
                continue;
            }

            for (int i = 1; i < token_lengths.size(); i++) {
                if (token_lengths[i] <= k_2 && token_lengths[i - 1] <= k_2) {
                    is_valid = false;
                    break;
                }
            }

            if (!is_valid) {
                continue;
            }

            cnt++;
            if (cnt != idx) {
                continue;
            }

            cout << ans << endl;
            return;
        }

        cout << "out of bounds" << endl; 
        return;
    }

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