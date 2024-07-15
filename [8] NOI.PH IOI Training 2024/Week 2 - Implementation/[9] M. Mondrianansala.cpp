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
    int m;
    cin >> m;

    if (m == 6) {
        cout << 12 << endl;
        cout << 
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "BBBBAAAABBBB\n"
        "BBBBAAAABBBB\n"
        "BBBBAAAABBBB\n"
        "BBBBAAAABBBB\n"
        "BBBBAAAABBBB\n"
        "BBBBAAAABBBB" 
        << endl;

        return;
    }

    if (m == 7) {
        cout << 12 << endl;
        cout << 
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "AAAABBBBAAAA\n"
        "MMMMMMMMMYYY\n"
        "MMMMMMMMMYYY\n"
        "MMMMMMMMMZZZ\n"
        "MMMMMMMMMZZZ\n"
        "MMMMMMMMMYYY\n"
        "MMMMMMMMMYYY" 
        << endl;

        return;
    }

    if (m == 8) {
        cout << 18 << endl;
        cout << 
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAIIIIII\n"
        "AAAAAAAAAAAAQQQQYY\n"
        "AAAAAAAAAAAAQQQQYY\n"
        "AAAAAAAAAAAAQQQQYY\n"
        "AAAAAAAAAAAAQQQQZZ\n"
        "AAAAAAAAAAAAQQQQZZ\n"
        "AAAAAAAAAAAAQQQQZZ\n"
        "AAAAAAAAAAAAYYZZYY\n"
        "AAAAAAAAAAAAYYZZYY\n"
        "AAAAAAAAAAAAYYZZYY"
        << endl;

        return;
    }

    int n;
    vector<vector<char>> grid;
    if (m % 3 == 0) { 
        n = 1536;
        grid.resize(n, vector<char>(n, 'A'));

        m -= 6;
        for (int i = 0; i < n / 2; i++)
            for (int j = n / 3; j < 2 * n / 3; j++)
                grid[i][j] = 'B';
        for (int i = n / 2; i < n; i++)
            for (int j = 0; j < n / 3; j++) {
                grid[i][j] = 'B';
            for (int j = 2 * n / 3; j < n; j++)
                grid[i][j] = 'B';
            }

        char c1 = 'A', c2 = 'B';
        int di = n / 2, dj = n / 3;
        while (m > 0) {
            c1 = 'A' + ((c1 - 'A') + 2) % 26;
            c2 = 'A' + ((c2 - 'A') + 2) % 26;
            
            for (int i = 0; i < n; i += di)
                for (int j = 0; j < n; j += dj) {
                    if (m == 0)
                        goto exit;
               
                    m -= 3;
                    for (int k = i; k < i + di / 2; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c1;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c2;
                    }
                    for (int k = i + di / 2; k < i + di; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c2;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c1;
                    }
                }

            di /= 2;
            dj /= 2;
        }
    } else if (m % 3 == 1) {
        n = 1536;
        grid.resize(n, vector<char>(n, 'A'));

        m -= 7;
        for (int i = 0; i < n / 2; i++)
            for (int j = n / 3; j < 2 * n / 3; j++)
                grid[i][j] = 'B';
        for (int i = n / 2; i < n; i++)
            for (int j = 0; j < 3 * n / 4; j++)
                grid[i][j] = 'X';
        for (int j = 3 * n / 4; j < n; j++) {
            for (int i = n / 2; i < 2 * n / 3; i++) 
                grid[i][j] = 'Y';
            for (int i = 2 * n / 3; i < 5 * n / 6; i++) 
                grid[i][j] = 'Z';
            for (int i = 5 * n / 6; i < n; i++) 
                grid[i][j] = 'Y';
        }

        char c1 = 'A', c2 = 'B';
        int di = n / 2, dj = n / 3;
        while (m > 0 && di % 2 == 0 && dj % 2 == 0) {
            c1 = 'A' + ((c1 - 'A') + 2) % 12;
            c2 = 'A' + ((c2 - 'A') + 2) % 12;
            
            for (int i = 0; i < n / 2; i += di)
                for (int j = 0; j < n; j += dj) {
                    if (m == 0)
                        goto exit;
               
                    m -= 3;
                    for (int k = i; k < i + di / 2; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c1;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c2;
                    }
                    for (int k = i + di / 2; k < i + di; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c2;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c1;
                    }
                }

            di /= 2;
            dj /= 2;
        }

        c1 = 'M', c2 = 'N';
        di = n / 2, dj = 3 * n / 4;
        while (m > 0 && di % 2 == 0 && dj % 2 == 0) {
            c1 = 'M' + ((c1 - 'M') + 2) % 12;
            c2 = 'M' + ((c2 - 'M') + 2) % 12;
            
            for (int i = n / 2; i < n; i += di)
                for (int j = 0; j < 3 * n / 4; j += dj) {
                    if (m == 0)
                        goto exit;
               
                    m -= 3;
                    for (int k = i; k < i + di / 2; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c1;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c2;
                    }
                    for (int k = i + di / 2; k < i + di; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c2;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c1;
                    }
                }

            di /= 2;
            dj /= 2;
        }
    } else if (m % 3 == 2) {
        n = 2304;
        grid.resize(n, vector<char>(n, 'A'));

        m -= 11;
        for (int i = 0; i < n / 2; i++)
            for (int j = 2 * n / 3; j < n; j++)
                grid[i][j] = 'I';
        for (int i = n / 2; i < 2 * n / 3; i++) {
            for (int j = 2 * n / 3; j < 7 * n / 9; j++)
                grid[i][j] = 'Q';
            for (int j = 7 * n / 9; j < 8 * n / 9; j++)
                grid[i][j] = 'R';
            for (int j = 8 * n / 9; j < n; j++)
                grid[i][j] = 'Q';
        }
        for (int i = 2 * n / 3; i < 5 * n / 6; i++) {
            for (int j = 2 * n / 3; j < 7 * n / 9; j++)
                grid[i][j] = 'R';
            for (int j = 7 * n / 9; j < 8 * n / 9; j++)
                grid[i][j] = 'Q';
            for (int j = 8 * n / 9; j < n; j++)
                grid[i][j] = 'R';
        }
        for (int i = 5 * n / 6; i < n; i++) {
            for (int j = 2 * n / 3; j < 7 * n / 9; j++)
                grid[i][j] = 'Q';
            for (int j = 7 * n / 9; j < 8 * n / 9; j++)
                grid[i][j] = 'R';
            for (int j = 8 * n / 9; j < n; j++)
                grid[i][j] = 'Q';
        }

        char c1 = 'A', c2 = 'B';
        int di = n, dj = 2 * n / 3;
        while (m > 0 && di % 2 == 0 && dj % 2 == 0) {
            c1 = 'A' + ((c1 - 'A') + 2) % 8;
            c2 = 'A' + ((c2 - 'A') + 2) % 8;
            
            for (int i = 0; i < n; i += di)
                for (int j = 0; j < 2 * n / 3; j += dj) {
                    if (m == 0)
                        goto exit;
               
                    m -= 3;
                    for (int k = i; k < i + di / 2; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c1;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c2;
                    }
                    for (int k = i + di / 2; k < i + di; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c2;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c1;
                    }
                }

            di /= 2;
            dj /= 2;
        }

        c1 = 'I', c2 = 'J';
        di = n / 2, dj = n / 3;
        while (m > 0 && di % 2 == 0 && dj % 2 == 0) {
            c1 = 'I' + ((c1 - 'I') + 2) % 8;
            c2 = 'I' + ((c2 - 'I') + 2) % 8;
            
            for (int i = 0; i < n / 2; i += di)
                for (int j = 2 * n / 3; j < n; j += dj) {
                    if (m == 0)
                        goto exit;
               
                    m -= 3;
                    for (int k = i; k < i + di / 2; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c1;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c2;
                    }
                    for (int k = i + di / 2; k < i + di; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c2;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c1;
                    }
                }

            di /= 2;
            dj /= 2;
        }

        c1 = 'Q', c2 = 'R';
        di = n / 6, dj = n / 9;
        while (m > 0 && di % 2 == 0 && dj % 2 == 0) {
            c1 = 'Q' + ((c1 - 'Q') + 2) % 10;
            c2 = 'Q' + ((c2 - 'Q') + 2) % 10;
            
            for (int i = n / 2; i < n; i += di)
                for (int j = 2 * n / 3; j < n; j += dj) {
                    if (m == 0)
                        goto exit;
               
                    m -= 3;
                    for (int k = i; k < i + di / 2; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c1;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c2;
                    }
                    for (int k = i + di / 2; k < i + di; k++) {
                        for (int l = j; l < j + dj / 2; l++)
                            grid[k][l] = c2;
                        for (int l = j + dj / 2; l < j + dj; l++)
                            grid[k][l] = c1;
                    }
                }

            di /= 2;
            dj /= 2;
        }
    }

exit:
    // cout << m << endl;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j];
        cout << endl;
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