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
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    
    bool hasA = false, isAllA = true;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'A')
                hasA = true;
            
            if (grid[i][j] == 'P')
                isAllA = false;
        }

    if (!hasA) {
        cout << "MORTAL" << endl;
        return;
    }
    if (isAllA) {
        cout << 0 << endl;
        return;
    }

    // 0 - N, 1 - S, 2 - W, 3 - E
    vector<bool> hasEdgeLine(4, true);
    vector<bool> hasEdgeCell(4);
    for (int j = 0; j < c; j++) {
        if (grid[0][j] == 'P')
            hasEdgeLine[0] = false;
        if (grid[r - 1][j] == 'P')
            hasEdgeLine[1] = false;
        if (grid[0][j] == 'A')
            hasEdgeCell[0] = true;
        if (grid[r - 1][j] == 'A')
            hasEdgeCell[1] = true;
    }
    for (int i = 0; i < r; i++) {
        if (grid[i][0] == 'P')
            hasEdgeLine[2] = false;
        if (grid[i][c - 1] == 'P')
            hasEdgeLine[3] = false;
        if (grid[i][0] == 'A')
            hasEdgeCell[2] = true;
        if (grid[i][c - 1] == 'A')
            hasEdgeCell[3] = true;
    }

    for (int i = 0; i < 4; i++)
        if (hasEdgeLine[i]) {
            cout << 1 << endl;
            return;
        }

    if (grid[0][0] == 'A' || grid[0][c - 1] == 'A' || grid[r - 1][0] == 'A' || grid[r - 1][c - 1] == 'A') {
        cout << 2 << endl;
        return;
    }
    for (int i = 1; i < r - 1; i++) {
        bool hasMidLine = true;
        for (int j = 0; j < c; j++)
            if (grid[i][j] == 'P')
                hasMidLine = false;

        if (hasMidLine) {
            cout << 2 << endl;
            return;
        }
    }
    for (int j = 1; j < c - 1; j++) {
        bool hasMidLine = true;
        for (int i = 0; i < r; i++)
            if (grid[i][j] == 'P')
                hasMidLine = false;

        if (hasMidLine) {
            cout << 2 << endl;
            return;
        }
    }

    for (int i = 0; i < 4; i++)
        if (hasEdgeCell[i]) {
            cout << 3 << endl;
            return;
        }

    cout << 4 << endl;
    
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