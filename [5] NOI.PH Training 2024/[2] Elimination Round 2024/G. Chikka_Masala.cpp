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
    map<string, bool> is_num = {
        {"0", true},
        {"1", true},
        {"2", true},
        {"3", true},
        {"4", true},
        {"5", true},
        {"6", true},
        {"7", true},
        {"8", true},
        {"9", true}
    };
    
    int a, r, c, q;
    cin >> a >> r >> c >> q;
    map<string, char> adj_to_char;
    map<char, int> chr_to_pow2;
    for (int i = 0; i < a; i++) {
        char c;
        string adj;
        cin >> c >> adj;

        adj_to_char[adj] = c;
        chr_to_pow2[c] = i;
    }
    vector<vector<string>> grid(r + 2, vector<string>(c + 2));
    vector<vector<int>> has_char(r + 2, vector<int>(c + 2));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
            
            if (is_num[grid[i][j]]) {
                continue;
            }

            for (char x : grid[i][j]) {
                has_char[i][j] |= 1 << chr_to_pow2[x];
            }

            // cout << grid[i][j] << ' ';
        }
        // cout << endl;
    }

    //*
    vector<vector<int>> qualities(r + 2, vector<int>(c + 2));
    for (auto [k, v] : chr_to_pow2) {
        int color = 1;
        vector<vector<int>> is_visited(r + 2, vector<int>(c + 2));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (is_visited[i][j] || (has_char[i][j] & (1 << chr_to_pow2[k]))) {
                    continue;
                }
                is_visited[i][j] = color;
                
                bool is_inside_curve = true;
                queue<pair<int, int>> bfs;
                bfs.push({i, j});
                while (!bfs.empty()) {
                    auto [i_cur, j_cur] = bfs.front();
                    bfs.pop();
                    
                    if (i_cur == 1 || i_cur == r || j_cur == 1 || j_cur == c) {
                        is_inside_curve = false;
                    }

                    for (auto [di, dj] : vector<pair<int, int>>({{-1, 0}, {0, -1}, {0, 1}, {1, 0}})) {
                        if (i_cur + di == 0 || i_cur + di == r + 1) {
                            continue;
                        }

                        if (j_cur + dj == 0 || j_cur + dj == c + 1) {
                            continue;
                        }
                        
                        if (!is_visited[i_cur + di][j_cur + dj] && !(has_char[i_cur + di][j_cur + dj] & (1 << chr_to_pow2[k]))) {
                            is_visited[i_cur + di][j_cur + dj] = color;
                            bfs.push({i_cur + di, j_cur + dj});
                        }
                    }
                }

                if (!is_inside_curve) {
                    color++;
                    continue;
                }

                for (int i = 1; i <= r; i++) {
                    for (int j = 1; j <= c; j++) {
                        if (is_num[grid[i][j]] && is_visited[i][j] == color) {
                            qualities[i][j] |= 1 << v;
                        }
                    }
                }

                break;
            }
        } 
    }

    // for (int i = 1; i <= r; i++) {
    //     for (int j = 1; j <= c; j++) {
    //         cout << bitset<6>(qualities[i][j]) << ' ';
    //     }
    //     cout << endl;
    // }

    map<int, int> qual_cnts;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!is_num[grid[i][j]]) {
                continue;
            }

            qual_cnts[qualities[i][j]] += grid[i][j][0] - '0';
        }
    }

    // for (auto [k, v] : qual_cnts) {
    //     cout << bitset<6>(k) << ' ' << v << endl;
    // }

    //*
    cin.ignore();
    while (q--) {
        string story;
        getline(cin, story);
        stringstream story_stream(story);

        // cout << q << ' ' << story << endl;

        string token;
        vector<string> ss;
        while (getline(story_stream, token, ' ')) {
            ss.push_back(token);
        }

        vector<vector<int>> binary_conditions;
        stack<string> operators;
        for (auto s : ss) {
            if (s == "not" || s == "but" || s == "OR") {
                operators.push(s);
                continue;
            }

            bool is_in_bin_cond = false; 
            int cur = chr_to_pow2[adj_to_char[s]];

            while (!operators.empty()) {
                auto op = operators.top();
                operators.pop();
            
                if (op == "not") {
                    cur = -cur - 1;
                } else if (op == "but") {
                    binary_conditions.back().push_back(cur);
                    is_in_bin_cond = true;
                } else if(op == "OR") {
                    binary_conditions.push_back({cur});
                    is_in_bin_cond = true;
                }
            }

            if (!is_in_bin_cond) {
                binary_conditions.push_back({cur});
            }
        } 

        set<int> distinct_included;
        for (auto x : binary_conditions) {
            for (auto [k, v] : qual_cnts) {
                bool is_included = true;
                for (int y : x) {
                    if (y >= 0) {
                        if (!(k & (1 << y))) {
                            is_included = false;
                            break;
                        }
                    } else {
                        if (k & (1 << (-y - 1))) {
                            is_included = false;
                            break;
                        }
                    }
                }

                if (is_included) {
                    distinct_included.insert(k);
                }
            }
        }

        int ans = 0;
        for (int x : distinct_included) {
            // cout << x << ' ';
            ans += qual_cnts[x];
        }
        // cout << endl;

        cout << ans << endl;
    }
    //*/

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