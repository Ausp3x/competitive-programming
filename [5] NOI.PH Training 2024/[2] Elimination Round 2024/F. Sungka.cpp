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

vector<vector<lng>> sungka(2, vector<lng>(9));

bool isDone() {
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 8; j++) {
            if (sungka[i][j] > 0) {
                return false;
            }
        }
    }

    return true;
}

int findNextHouse(int i) {
    int idx = -1;
    lng val = INF64;
    if (i == 0) {
        for (int j = 7; j > 0; j--) {
            if (sungka[i][j] == 0) {
                continue;
            }

            if (sungka[i][j] < val) {
                idx = j;
                val = sungka[i][j];
            }    
        }
    } else if (i == 1) {
        for (int j = 1; j < 8; j++) {
            if (sungka[i][j] == 0) {
                continue;
            }

            if (sungka[i][j] < val) {
                idx = j;
                val = sungka[i][j];
            } 
        }
    }

    return idx;
}

void move(int &i, int &j, int turn) {
    if (turn == 0) {
        if (i == 0) {
            if (j < 8) {
                j++;
            } else {
                i++;
                j--;
            }
        } else if (i == 1) {
            if (j > 1) {
                j--;
            } else {
                i--;
            }
        }
    } else if (turn == 1) {
        if (i == 0) {
            if (j < 7) {
                j++;
            } else {
                i++;
            }
        } else if (i == 1) {
            if (j > 0) {
                j--;
            } else {
                i--;
                j++;
            }
        }
    }

    return;
}

void solve() {  
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 8; j++) {
            cin >> sungka[i][j];
        }
    }

    // for (int a = 0; a < 2; a++) {
    //     for (int b = 0; b < 9; b++) {
    //         cout << sungka[a][b] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int turn = 0;
    while (!isDone()) {
        int i = turn, j = findNextHouse(turn);
        while (j != -1) {
            lng cur = sungka[i][j];
            sungka[i][j] = 0;

            int i_cur = i, j_cur = j;            
            lng q = cur / 15, r = cur % 15;
            for (int _ = 0; _ < 15; _++) {
                if (r == 0) {
                    i = i_cur, j = j_cur;
                }

                move(i_cur, j_cur, turn);
                sungka[i_cur][j_cur] += q;
                if (r > 0) {
                    sungka[i_cur][j_cur]++;
                }
                r--;
            }

            if (i == turn && j == 4 + int(pow(-1, turn)) * 4) {
                j = findNextHouse(turn);
            } else if (sungka[i][j] == 1) {
                if (i == turn && sungka[i ^ 1][j] > 0) {
                    sungka[turn][4 + int(pow(-1, turn)) * 4] += sungka[i][j] + sungka[i ^ 1][j];
                    sungka[i][j] = 0;
                    sungka[i ^ 1][j] = 0;
                }
                break;
            }
        }

        // cout << turn << endl;
        // for (int a = 0; a < 2; a++) {
        //     for (int b = 0; b < 9; b++) {
        //         cout << sungka[a][b] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        turn ^= 1;
    }

    cout << sungka[0][8] << ' ' << sungka[1][0] << endl; 

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