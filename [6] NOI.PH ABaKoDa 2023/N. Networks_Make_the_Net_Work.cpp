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
    int n, m;
    cin >> n >> m;
    vector<string> vertices;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        vertices.push_back(s);
    }
 
    map<string, vector<string>> adjl;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        
        adjl[s1].push_back(s2);
        adjl[s2].push_back(s1);
    }
 
    if (n < 5) {
        cout << "PRANKED" << endl;
        return;
    }
 
    int groups = 0;
    map<string, bool> vst;
    for (auto v : vertices) {
        if (vst[v]) {
            continue;
        }        
        groups++;
        vst[v] = true;
        
        queue<string> q;
        q.push(v);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            
            for (auto nxt : adjl[cur]) {
                if (vst[nxt]) {
                    continue;
                }
                vst[nxt] = true;
                
                q.push(nxt);
            }
        }
    }
 
    if (groups > 1) {
        cout << "PRANKED" << endl;
        return;
    }
 
    if (m > n + 1) {
        cout << "PRANKED" << endl;
        return;   
    }
 
    if (m == n - 1) {
        int con1 = 0;
        for (auto [k, v] : adjl) {
            if (v.size() == 2) {
                continue;
            }
 
            if (v.size() != 1) {
                cout << "PRANKED" << endl;
                return;
            }
 
            con1 += v.size() == 1;
        }
 
        if (con1 == 2) {
            cout << "Cindy" << endl;
        } else {
            cout << "PRANKED" << endl;
        }
        return;
    }
 
    if (m == n) {
        int con1 = 0, con3 = 0;
        for (auto [k, v] : adjl) {
            if (v.size() == 2) {
                continue;
            }
 
            if (v.size() != 1 && v.size() != 3) {
                cout << "PRANKED" << endl;
                return;
            }
 
            con1 += v.size() == 1;
            con3 += v.size() == 3;
        }
 
        if (con1 != 2 || con3 != 2) {
            cout << "PRANKED" << endl;
            return;   
        }
 
        for (auto [k, v] : adjl) {
            if (v.size() != 3) {
                continue;
            }
 
            map<string, bool> vst2;
            stack<pair<string, string>> s;
            s.push({k, k});
            while (!s.empty()) {
                auto [cur, prv] = s.top();
                s.pop();
 
                vst2[cur] = true;

                for (auto nxt : adjl[cur]) {
                    if (vst2[nxt]) {
                        if (nxt == prv) {
                            continue;
                        }

                        if (nxt != k) {
                            cout << "PRANKED" << endl;
                            return;
                        } else {
                            goto exit;
                        }
                    }

                    s.push({nxt, cur});
                }
            }
        exit:
            "for the sake of compilation";

            cout << endl;
        }
 
        cout << "Alice" << endl;
 
        return;
    }
 
    if (m == n + 1) {
        int con4 = 0;
        for (auto [k, v] : adjl) {
            if (v.size() == 2) {
                continue;
            }
 
            if (v.size() != 4) {
                cout << "PRANKED" << endl;
                return;
            }
 
            con4 += v.size() == 4;
        }
 
        if (con4 == 1) {
            cout << "Bob" << endl;
        } else {
            cout << "PRANKED" << endl;
        }
        return;
    }
    
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