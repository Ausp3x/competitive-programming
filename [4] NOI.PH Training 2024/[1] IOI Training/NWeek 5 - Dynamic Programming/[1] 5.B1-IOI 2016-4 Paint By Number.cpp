// 人外有人，天外有天
// author: Ausp3x
 
#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include "paint.h"
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define pb push_back
#define DEBUG
typedef long long    lng;
 
int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;
 
string solve_puzzle(string s, vector<int> clues) {
    int n = s.size(), k = clues.size();
    
    vector<int> last_white(n + 1);
    for (int i = 1; i <= n; i++) {
        last_white[i] = last_white[i - 1];
        if (s[i - 1] == '_')
            last_white[i] = i;
    }
    
    // ith cell, jth clue, end in black (0) or white (1)
    bool dp1[n + 1][k + 1][2];
    memset(dp1, 0, sizeof(dp1));
    dp1[0][0][1] = true;
    for (int i = 1; i <= n; i++) {	
        if (s[i - 1] != 'X')
            for (int j = 0; j <= k; j++)
                dp1[i][j][1] = dp1[i - 1][j][0] | dp1[i - 1][j][1];
                
        if (s[i - 1] != '_')
            for (int j = 1; j <= k; j++)	
                if (i - clues[j - 1] >= last_white[i])
                    dp1[i][j][0] = dp1[i - clues[j - 1]][j - 1][1];
    }
    
    int l = n + 1, r = n + 1;
    vector<bool> pos_black(n + 1), pos_white(n + 1);
    bool dp2[n + 1][k + 1][2];
    memset(dp2, 0, sizeof(dp2));
    dp2[n][k][0] = dp2[n][k][1] = true;
    for (int i = n; i > 0; i--) 
        for (int j = 0; j <= k; j++) {
            if (dp1[i][j][0] && dp2[i][j][0]) {
                if (i < l) {
                    l = r = i;
                    pos_black[i] = true;
                }
                
            if (j > 0)
                if (i - clues[j - 1] >= 0) {
                    while (i - clues[j - 1] + 1 < l) {
                        l--;
                        pos_black[l] = true;
                    }
                    
                    dp2[i - clues[j - 1]][j - 1][1] = 1;
                }		
            }
            
            if (dp1[i][j][1] && dp2[i][j][1]) {
                pos_white[i] = true;
                dp2[i - 1][j][0] = dp2[i - 1][j][1] = true;
            }
        }
        
    string t;
    for (int i = 1; i <= n; i++)
        if (pos_black[i] && pos_white[i])
            t += '?';
        else if (pos_black[i])
            t += 'X';
        else if (pos_white[i])
            t += '_';
        else
            t += '.';
            
    return t;
}
 
#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
    	string s;
    	int k;
    	cin >> s >> k;
    	vector<int> clues(k);
    	for (int &c : clues)
            cin >> c;
            	
        cout << solve_puzzle(s, clues) << endl;
    }
    
    return 0;
}
#endif