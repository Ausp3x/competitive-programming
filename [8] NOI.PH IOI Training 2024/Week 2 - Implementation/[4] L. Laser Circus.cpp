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

int r, c;
vector<vector<char>> grid;

tuple<int, int, char> move(tuple<int, int, char> loc) {
    auto [i, j, d] = loc;
    if (grid[i][j] == '/') {
        if (d == 'N') {
            return {i, j - 1, 'E'};   
        } else if (d == 'S') {
            return {i, j + 1, 'W'};
        } else if (d == 'E') {
            return {i + 1, j, 'N'};
        } else if (d == 'W') {
            return {i - 1, j, 'S'};
        }
    } else if (grid[i][j] == '\\') {
        if (d == 'N') {
            return {i, j + 1, 'W'};   
        } else if (d == 'S') {
            return {i, j - 1, 'E'};
        } else if (d == 'E') {
            return {i - 1, j, 'S'};
        } else if (d == 'W') {
            return {i + 1, j, 'N'};
        }
    }
}

pair<char, int> translate(tuple<int, int, char> loc) {
    auto [i, j, d] = loc;
    if (i == 0) {
        return {'T', j};
    } else if (i == r + 1) {
        return {'B', j};
    } else if (j == 0) {
        return {'L', i};
    } else if (j == c + 1) {
        return {'R', i};
    } else {
        return {'X', -1};
    }
}

void solve() {
    cin >> r >> c;
    grid.resize(r + 2, vector<char>(c + 2));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
        }
    }

    map<pair<char, int>, pair<char, int>> in_out;
    
    for (int j = 1; j <= c; j++) {
        if (in_out.contains({'T', j})) {
            continue;
        }

        tuple<int, int, char> in = {1, j, 'N'}, out = in;
        while (true) {
            out = move(out);
            
            if (translate(out).first != 'X') {
                in = {0, j, 'N'};
                in_out[translate(in)] = translate(out);
                in_out[translate(out)] = translate(in);
                break;
            }
        }
    }

    for (int j = 1; j <= c; j++) {
        if (in_out.contains({'B', j})) {
            continue;
        }

        tuple<int, int, char> in = {r, j, 'S'}, out = in;
        while (true) {
            out = move(out);
            
            if (translate(out).first != 'X') {
                in = {r + 1, j, 'S'};
                in_out[translate(in)] = translate(out);
                in_out[translate(out)] = translate(in);
                break;
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        if (in_out.contains({'L', i})) {
            continue;
        }

        tuple<int, int, char> in = {i, 1, 'W'}, out = in;
        while (true) {
            out = move(out);
            
            if (translate(out).first != 'X') {
                in = {i, 0, 'W'};
                in_out[translate(in)] = translate(out);
                in_out[translate(out)] = translate(in);
                break;
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        if (in_out.contains({'R', i})) {
            continue;
        }

        tuple<int, int, char> in = {i, c, 'E'}, out = in;
        while (true) {
            out = move(out);
            
            if (translate(out).first != 'X') {
                in = {i, c + 1, 'E'};
                in_out[translate(in)] = translate(out);
                in_out[translate(out)] = translate(in);
                break;
            }
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        // cout << c << ' ' << x << endl;
        cout << in_out[{c, x}].first << ' ' << in_out[{c, x}].second << endl;
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