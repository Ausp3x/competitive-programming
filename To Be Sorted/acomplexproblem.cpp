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

/*
dotted arrow - is a subset of
solid arrow  - is a PROPER subset of

TERMS:
 * CG  - condensation graph
 * DAC - directed acyclic component
 * SCC - strongly connected compoenent

SOLUTION:
1) get the CG (combine all SCCs into one node)
2) max: number of nodes in the CG
3) min: maximum height among all solid DACs, where we ignore dotted arrows (Mirski's Theorem)
    - get all nodes with no outgoing edges (sinks)
    - set the weights of the dotted arrows to 0 and that of the solid arrows to 1
    - use recursion and dp starting with the sinks to obtain the height of each DAC
*/

struct Kosaraju {
    int n;
    vector<vector<int>> adjl, adjl_cond;

    Kosaraju() {}
}

void solve() {
    
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