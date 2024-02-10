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
    int r, c;
    cin >> r >> c;

    int r_cur = 1, c_cur = 1;
    string path, res;
    vector<vector<bool>> vst(r + 1, vector<bool>(c + 1));
    vst[1][1] = true;
    while (r_cur != r || c_cur != c) {
        if (r_cur > 1) {
            if (!vst[r_cur - 1][c_cur]) {
                cout << 'N' << endl;
                cin >> res;
                
                if (res == "SAFE") {
                    r_cur--;
                    path += 'N';
                    vst[r_cur][c_cur] = true;
                    continue;
                } else if (res == "TRAP") {
                    vst[r_cur - 1][c_cur] = true;
                    for (auto c : path) {
                        cout << c << endl;
                        cin >> res;
                    }
                } else if (res == "YAY") {
                    break;
                }
            }
        }

        if (r_cur < r) {
            if (!vst[r_cur + 1][c_cur]) { 
                cout << 'S' << endl;
                cin >> res;
                
                if (res == "SAFE") {
                    r_cur++;
                    path += 'S';
                    vst[r_cur][c_cur] = true;
                    continue;
                } else if (res == "TRAP") {
                    vst[r_cur + 1][c_cur] = true;
                    for (auto c : path) {
                        cout << c << endl;
                        cin >> res;
                    }
                } else if (res == "YAY") {
                    break;
                }
            }
        }
        
        if (c_cur < c) {
            if (!vst[r_cur][c_cur + 1]) {       
                cout << 'E' << endl;
                cin >> res;
                
                if (res == "SAFE") {
                    c_cur++;
                    path += 'E';
                    vst[r_cur][c_cur] = true;
                    continue;
                } else if (res == "TRAP") {
                    vst[r_cur][c_cur + 1] = true;
                    for (auto c : path) {
                        cout << c << endl;
                        cin >> res;
                    }
                } else if (res == "YAY") {
                    break;
                }
            }
        }

        if (c_cur > 1) {
            if (!vst[r_cur][c_cur - 1]) {    
                cout << 'W' << endl;
                cin >> res;
                
                if (res == "SAFE") {
                    c_cur--;
                    path += 'W';
                    vst[r_cur][c_cur] = true;
                    continue;
                } else if (res == "TRAP") {
                    vst[r_cur][c_cur - 1] = true;
                    for (auto c : path) {
                        cout << c << endl;
                        cin >> res;
                    }
                } else if (res == "YAY") {
                    break;
                }
            }
        }

        if (path.empty()) {
            cout << "RIGGED" << endl;
            break;
        } else {
            switch (path.back()) {
                case 'N':
                    cout << 'S' << endl;
                    cin >> res;
                    r_cur++;
                    break;
                case 'S':
                    cout << 'N' << endl;
                    cin >> res;
                    r_cur--;
                    break;
                case 'E':
                    cout << 'W' << endl;
                    cin >> res;
                    c_cur--;
                    break;
                case 'W':
                    cout << 'E' << endl;
                    cin >> res;
                    c_cur++;
                    break;
            }
            path.pop_back();
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