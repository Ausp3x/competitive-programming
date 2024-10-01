// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void solve() {
    string s;
    cin >> s;

    bool ans = true;
    stack<char> cur_opens;
    for (char c : s) {
        if (c == ')') {
            if (!cur_opens.empty()) {
                if (cur_opens.top() == '(') {
                    cur_opens.pop();
                    
                    continue;
                } else {
                    ans = false;
                    
                    goto exit;
                }
            } else {
                ans = false;
                
                goto exit;
            }
        }

        if (c == '}') {
            if (!cur_opens.empty()) {
                if (cur_opens.top() == '{') {
                    cur_opens.pop();
                    
                    continue;
                } else {
                    ans = false;
                    
                    goto exit;
                }
            } else {
                ans = false;
                
                goto exit;
            }
        }

        if (c == ']') {
            if (!cur_opens.empty()) {
                if (cur_opens.top() == '[') {
                    cur_opens.pop();
                    
                    continue;
                } else {
                    ans = false;
                    
                    goto exit;
                }
            } else {
                ans = false;
                
                goto exit;
            }
        }

        cur_opens.push(c);
    }

exit:
    cout << (ans && cur_opens.empty() ? "YES" : "NO") << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}