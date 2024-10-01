// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

unordered_map<int, array<int, 3>> cards;
set<pair<int, int>> R, G, B;

int getUniqueness(int id) {
    auto R_ptr = R.find({cards[id][0], id});
    auto G_ptr = G.find({cards[id][1], id});
    auto B_ptr = B.find({cards[id][2], id});

    assert(R_ptr != R.end() && G_ptr != G.end() && B_ptr != B.end());
    
    int res = 0;

    int Rl = (*R_ptr == *R.begin()  ? R.rbegin()->fi : prev(R_ptr)->fi);
    int Rr = (*R_ptr == *R.rbegin() ? R.begin()->fi  : next(R_ptr)->fi);
    if (Rr < Rl)
        Rr += 360;

    if (Rl != R_ptr->fi && Rr != R_ptr->fi)
        res += Rr - Rl;
        
    int Gl = (*G_ptr == *G.begin()  ? G.rbegin()->fi : prev(G_ptr)->fi);
    int Gr = (*G_ptr == *G.rbegin() ? G.begin()->fi  : next(G_ptr)->fi);
    if (Gr < Gl)
        Gr += 360;

    if (Gl != G_ptr->fi && Gr != G_ptr->fi)
        res += Gr - Gl;

    int Bl = (*B_ptr == *B.begin()  ? B.rbegin()->fi : prev(B_ptr)->fi);
    int Br = (*B_ptr == *B.rbegin() ? B.begin()->fi  : next(B_ptr)->fi);
    if (Br < Bl)
        Br += 360;

    if (Bl != B_ptr->fi && Br != B_ptr->fi)
        res += Br - Bl;

    return res;
}


void solve() {
    int n;
    cin >> n;
    cards.clear();
    R.clear();
    G.clear();
    B.clear();
    for (int i = 0; i < n; i++) {
        int r, g, b, id;
        cin >> r >> g >> b >> id;

        cards[id] = {r, g, b};
        R.insert({r, id});
        G.insert({g, id});
        B.insert({b, id});        
    }
    
    unordered_map<int, int> vers;
    // uniqueness, id (negative), version
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (auto &[id, clrs] : cards) {
        vers[id] = 1;
        int unq = getUniqueness(id);
    
        // cout << id << ' ' << unq << endl;

        pq.push({unq, -id, vers[id]});
    }

    for (int i = 0; i < n; i++) {
        while (!pq.empty()) {
            auto [unq, id, ver] = pq.top();
            pq.pop();

            id = abs(id);
            if (ver != vers[id])
                continue;

            cout << id << endl;

            auto R_ptr = R.find({cards[id][0], id});
            auto G_ptr = G.find({cards[id][1], id});
            auto B_ptr = B.find({cards[id][2], id});

            int Rl = (*R_ptr == *R.begin()  ? R.rbegin()->se : prev(R_ptr)->se);
            int Rr = (*R_ptr == *R.rbegin() ? R.begin()->se  : next(R_ptr)->se);
            int Gl = (*G_ptr == *G.begin()  ? G.rbegin()->se : prev(G_ptr)->se);
            int Gr = (*G_ptr == *G.rbegin() ? G.begin()->se  : next(G_ptr)->se);
            int Bl = (*B_ptr == *B.begin()  ? B.rbegin()->se : prev(B_ptr)->se);
            int Br = (*B_ptr == *B.rbegin() ? B.begin()->se  : next(B_ptr)->se);

            R.erase(R_ptr);
            G.erase(G_ptr);
            B.erase(B_ptr);

            if (i < n - 1) {
                unordered_set<int> S = {Rl, Rr, Gl, Gr, Bl, Br};
                // cout << i << ' ';
                for (int new_id : S) {
                    // cout << new_id << ' ';

                    vers[new_id]++;
                    int new_unq = getUniqueness(new_id);

                    pq.push({new_unq, -new_id, vers[new_id]});
                }
                // cout << endl;
            }

            break;
        }
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