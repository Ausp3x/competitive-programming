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
    int n;
    cin >> n;
    
    vector<string> ans;
    while (n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "cd") {
            string dir;
            cin >> dir;
            
            string block;
            stringstream dir_processing(dir);
            vector<string> dir_blocks;
            while (getline(dir_processing, block, '/')) {
                if (!block.empty()) {
                    dir_blocks.push_back(block);
                }
            }

            if (dir[0] == '/') {
                ans.clear();
            }
            
            for (auto &block : dir_blocks) {
                if (block == "..") {
                    ans.pop_back();
                } else {
                    ans.push_back(block);
                }
            }
        } else if (cmd == "pwd") {
            if (ans.empty()) {
                cout << '/' << endl;
            } else {
                for (auto &x : ans) {
                    cout << '/' << x;
                }
                cout << '/' << endl;
            }
        }
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