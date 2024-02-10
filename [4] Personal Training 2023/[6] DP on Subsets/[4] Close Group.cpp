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

void getVertices(vector<int> &vertices, int bitmsk, int n) {
    for (int i = 0; i < n; i++) {
        if (bitmsk & 1) {
            vertices.push_back(i);
        }

        bitmsk >>= 1;
    }
    
    return;
}

bool isCompleteGraph(int bitmsk, int n, vector<vector<bool>> &adjm) {
    if (__builtin_popcount(bitmsk) <= 1) {
        return true;
    }

    vector<int> vertices;
    getVertices(vertices, bitmsk, n);

    /*
    cout << "|||||||||||||||vertices|||||||||||||||" << endl;
    for (int &u : vertices) {
        cout << u << ' ';
    }
    cout << endl;
    cout << "||||||||||||||||||||||||||||||||||||||" << endl;
    //*/

    for (int &u : vertices) {
        for (int &v : vertices) {
            if (u == v) {
                continue;
            }

            if (!adjm[u][v]) {
                return false;
            }
        }
    }
    
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> adjm(n, vector<bool>(n));
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjm[u][v] = true;
        adjm[v][u] = true;
    }

    /*
    cout << "|||||||||||||||adjm|||||||||||||||" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjm[i][j];
        }
        cout << endl;
    }
    cout << "||||||||||||||||||||||||||||||||||" << endl;
    //*/

    vector<bool> is_complete_graph(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        is_complete_graph[i] = isCompleteGraph(i, n, adjm);
    } 

    /*
    cout << "|||||||||||||||is_complete_graph|||||||||||||||" << endl;
    for (int i = 0; i < (1 << n); i++) {
        cout << bitset<18>(i) << ": " << is_complete_graph[i] << endl;
    }
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    //*/
    
    vector<int> dp(1 << n, INF32);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        if (is_complete_graph[i]) {
            dp[i] = 1;
            continue;
        }

        /*
        cout << "|||||||||||||||vertices|||||||||||||||" << endl;
        for (int &u : vertices) {
            cout << u << ' ';
        }
        cout << endl;
        cout << "||||||||||||||||||||||||||||||||||||||" << endl;
        //*/       

        for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
            dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
        }
    }

    /*
    cout << "|||||||||||||||dp|||||||||||||||" << endl;
    for (int i = 0; i < (1 << n); i++) {
        cout << bitset<18>(i) << ": " << dp[i] << endl;
    }
    cout << "||||||||||||||||||||||||||||||||" << endl;
    //*/

    cout << dp[(1 << n) - 1] << endl;

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