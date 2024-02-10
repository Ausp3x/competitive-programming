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
    map<char, char> complements = {
        {'A', 'T'},
        {'T', 'A'},
        {'C', 'G'},
        {'G', 'C'}
    };
    
    int n;
    cin >> n;
    map<string, bool> is_in_list;
    vector<string> reversed_dnas;
    for (int i = 0; i < n; i++) {
        int l;
        string dna;
        cin >> l >> dna;
        is_in_list[dna] = true;
        
        for (char& c : dna) {
            c = complements[c];
        }
        reverse(dna.begin(), dna.end());
        reversed_dnas.push_back(dna);
    }

    vector<int> ans;
    for (int i = 0; i < reversed_dnas.size(); i++) {
        if (is_in_list[reversed_dnas[i]]) {
            ans.push_back(i + 1);
        }        
    }
    
    if (ans.empty()) {
        cout << "RACOON ROLL" << endl;
        return;
    }
    
    for (int a : ans) {
        cout << a << ' ';
    }
    cout << endl;

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