// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define ONLINE_JUDGE
// #define DEBUG

int n;
vector<vector<char>> grid;

void init_grid() {
    grid.clear();
    grid.resize(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++) {
        grid[i][i] = '\\';
    }

    return;
}

void print_grid() {
    cout << "YES" << endl;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
    #ifdef DEBUG
        string s = to_string(i);
        s.append(3 - s.size(), ' ');
        cout << s << ' ';
    #endif

    #ifdef DEBUG
        int cnt = 0;
    #endif
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
    #ifdef DEBUG
            cnt += grid[i][j] == 'L';
    #endif
        }

    #ifdef DEBUG
        cout << ' ' << cnt;
    #endif
        cout << endl;
    }

    return;
}

int no_of_L_required(int i, int L_cnt) {
    for (int j = 0; j < n; j++) {
        L_cnt -= grid[i][j] == 'L';
    }

    return L_cnt;
}

void solve() {
    int a, b;
    cin >> a >> b;
    
    if (a > b) {
        swap(a, b);
    }

    if (a == b) {
        n = 2 * a + 1;
        init_grid();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= i + a; j++) {
                grid[i][j % n] = 'L';
            }
        }
        
        print_grid();
        return;
    }

    if (a * b == 0) {
        n = 2 * b;
        init_grid();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < i + b; j++) {
                grid[i][j % (n - 1)] = 'L';
            }
            grid[i][n - 1] = 'L';
        }
        
        print_grid();
        return;
    }
    
    if (a * b <= b) {
        if (b == 2) {
            cout << "YES" << endl;
            cout << 4 << endl;
            cout << "\\LL."<< endl;
            cout << ".\\LL"<< endl;
            cout << "..\\L"<< endl;
            cout << "L..\\"<< endl;
            return;
        }

        n = 2 * b - 2;
        init_grid();

        grid[0][n - 2] = 'L';
        for (int i = 1; i < n - 2; i++) {
            grid[i][0] = 'L';
            grid[i][n - 2] = 'L';
            grid[i][n - 1] = 'L';
        }
        grid[n - 2][n - 1] = 'L';
        grid[n - 1][0] = 'L';

        for (int i = 1; i < n - 2; i++) {
            for (int j = i + 1; j <= i + b - 3; j++) {
                grid[i][(j - 1) % (n - 3) + 1] = 'L';
            }
        }

        print_grid();
        return;
    }

    if (a == 2 && b == 3) {
        cout << "YES" << endl;
        cout << 6 << endl;
        cout << "\\LL..." << endl;
        cout << ".\\LL.." << endl;
        cout << "..\\LL." << endl;
        cout << "L..\\LL" << endl;
        cout << "LL..\\L" << endl;
        cout << "LLL..\\" << endl;
        return;    
    }

    if (b > 2 * a) {
        n = 2 * (b - a); 
        init_grid();

        int c = 2 * a + 1;
        for (int i = 0; i < c; i++) {
            for (int j = i + 1; j <= i + a; j++) {
                grid[i][j % c] = 'L';
            }
        }

        int d = 2 * (b - c) + 1;
        for (int i = c; i < n; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = 'L';
            }
        
            for (int j = i + 1; j <= i + b - c; j++) {
                grid[i][(j - c) % d + c] = 'L';
            }
        }

        print_grid();
        return;
    }

    for (int i = 2 * a + 2; i < 2 * b + 1; i++) {
        if (i % (2 * (b - a)) != 0) {
            continue;
        }

        n = i;
        break;
    }
    init_grid();

    int x = (n * (2 * b - n + 1)) / (2 * (b - a)), y = n - x;

#ifdef DEBUG
    cout << n << ' ' << x << ' ' << y << endl;
#endif

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            grid[i][j] = 'L';
        }
    }

    vector<int> L_reqs(n);
    for (int i = 0; i < n; i++) {
        L_reqs[i] = no_of_L_required(i, i < x ? a : b);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (L_reqs[i] >= 0) {
            continue;
        }

        for (int j = i - 1; j >= 0 && L_reqs[i] < 0; j--) {
            if (L_reqs[j] <= 0) {
                continue;
            }

            grid[i][j] = '.';
            grid[j][i] = 'L';
            L_reqs[i]++;
            L_reqs[j]--;
        }

        for (int j = i - 1; j >= 0 && L_reqs[i] < 0; j--) {
            if (grid[j][i] == 'L' || L_reqs[j] <= -j) {
                continue;
            }

            grid[i][j] = '.';
            grid[j][i] = 'L';
            L_reqs[i]++;
            L_reqs[j]--;
        }
    }
    
    print_grid();

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifdef DEBUG
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef DEBUG
    // testing code
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}