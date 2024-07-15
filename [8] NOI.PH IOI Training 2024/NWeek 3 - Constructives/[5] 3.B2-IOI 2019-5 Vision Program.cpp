// 人外有人，天外有天
// author: Ausp3x
 
#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "vision.h"
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;
 
int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;
 
#ifdef DEBUG
vector<bool> arr;
void add_not(int N) {
    arr.pb(!arr[N]);
 
    return;
}
 
void add_and(vector<int> Ns) {
    bool res = 1;
    for (int N : Ns)
        res &= arr[N];
    arr.pb(res);
 
    return;
}
 
void add_or(vector<int> Ns) {
    bool res = 0;
    for (int N : Ns)
        res |= arr[N];
    arr.pb(res);
 
    return;
}
 
void add_xor(vector<int> Ns) {
    bool res = 0;
    for (int N : Ns)
        res ^= arr[N];
    arr.pb(res);
 
    return;
}
#endif
 
void construct_network(int H, int W, int K) {
    // H + W - 1 increasing diagonals, does it contain a black square?
    for (int io = 0; io < H; io++) {
        vector<int> id;
        for (int i = io, j = 0; i >= 0 && j < W; i--, j++)
            id.pb(i * W + j);
        
        add_or(id);
    }
    for (int jo = 1; jo < W; jo++) {
        vector<int> id;
        for (int i = H - 1, j = jo; i >= 0 && j < W; i--, j++)
            id.pb(i * W + j);

        add_or(id);
    }

    // H + W - 1 decreasing diagonals, does it contain a black square?
    for (int io = H - 1; io >= 0; io--) {
        vector<int> dd;
        for (int i = io, j = 0; i < H && j < W; i++, j++)
            dd.pb(i * W + j);
        
        add_or(dd);
    }
    for (int jo = 1; jo < W; jo++) {
        vector<int> dd;
        for (int i = 0, j = jo; i < H && j < W; i++, j++)
            dd.pb(i * W + j);

        add_or(dd);
    }

    int idb = H * W,   ide = idb + H + W - 2;
    int ddb = ide + 1, dde = ddb + H + W - 2;

    // for (int i = idb; i <= ide; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // for (int i = ddb; i <= dde; i++)
    //     cout << arr[i] << ' ';
    // cout << endl << endl;

    int idpb = dde + 1, idpe = dde + 1;
    
    // H + W - 1 increasing diagonals, prefix bool left to right
    add_and({idb});
    for (int i = idb + 1; i <= ide; i++) {
        add_xor({i, idpe});
        idpe++;
    }

    idpe++;

    // H + W - 1 increasing diagonals, prefix bool right to left
    add_and({ide});
    for (int i = ide - 1; i >= idb; i--) {
        add_xor({i, idpe});
        idpe++;
    }

    int ddpb = idpe + 1, ddpe = idpe + 1;

    // H + W - 1 decreasing diagonals, prefix bool left to right
    add_and({ddb});
    for (int i = ddb + 1; i <= dde; i++) {
        add_xor({i, ddpe});
        ddpe++;
    }

    ddpe++;

    // H + W - 1 decreasing diagonals, prefix bool right to left
    add_and({dde});
    for (int i = dde - 1; i >= ddb; i--) {
        add_xor({i, ddpe});
        ddpe++;
    }

    // for (int i = idpb; i <= idpe; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // for (int i = ddpb; i <= ddpe; i++)
    //     cout << arr[i] << ' ';
    // cout << endl << endl;

    // H + W - 1 increasing diagonals, is it in between diagonals containing black squares (inclusive)?
    for (int d = 0; d < H + W - 1; d++)
        add_or({idpb + d, idpe - d});

    // H + W - 1 decreasing diagonals, is it in between diagonals containing black squares (inclusive)?
    for (int d = 0; d < H + W - 1; d++)
        add_or({ddpb + d, ddpe - d});

    int idib = ddpe + 1, idie = idib + H + W - 2;
    int ddib = idie + 1, ddie = ddib + H + W - 2;

    // for (int i = idib; i <= idie; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // for (int i = ddib; i <= ddie; i++)
    //     cout << arr[i] << ' ';
    // cout << endl << endl;

    vector<int> q;
    for (int i = idb; i <= ide; i++)
        q.pb(i);
    add_xor({q}); // 1
    
    q.clear();
    for (int i = ddb; i <= dde; i++)
        q.pb(i);
    add_xor({q}); // 2

    add_not(ddie + 1); // 3
    add_not(ddie + 2); // 4

    // cout << arr[ddie + 1] << ' ' << arr[ddie + 2] << ' ' << arr[ddie + 3] << ' ' << arr[ddie + 4] << endl << endl; 

    for (int i = idib; i <= idie; i++)
        add_and({i, ddie + 3});

    for (int i = ddib; i <= ddie; i++)
        add_and({i, ddie + 4});

    int idjb = ddie + 5, idje = idjb + H + W - 2;
    int ddjb = idje + 1, ddje = ddjb + H + W - 2; 

    // for (int i = idjb; i <= idje; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // for (int i = ddjb; i <= ddje; i++)
    //     cout << arr[i] << ' ';
    // cout << endl << endl;

    for (int d = 0; d < H + W - 1; d++) 
        add_or({idb + d, idjb + d});

    for (int d = 0; d < H + W - 1; d++) 
        add_or({ddb + d, ddjb + d});

    int id2b = ddje + 1, id2e = id2b + H + W - 2;
    int dd2b = id2e + 1, dd2e = dd2b + H + W - 2;

    // for (int i = id2b; i <= id2e; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // for (int i = dd2b; i <= dd2e; i++)
    //     cout << arr[i] << ' ';
    // cout << endl << endl;

    // H + W - K - 1 pairs of inc. diagonals, are they both in between diagonals containing black squares (inclusive)?
    for (int i = id2b; i + K <= id2e; i++)
        add_and({i, i + K});

    // H + W - K - 1 pairs of dec. diagonals, are they both in between diagonals containing black squares (inclusive)?
    for (int i = dd2b; i + K <= dd2e; i++)
        add_and({i, i + K});

    int idkb = dd2e + 1, idke = idkb + H + W - K - 2;
    int ddkb = idke + 1, ddke = ddkb + H + W - K - 2;

    // for (int i = idkb; i <= idke; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // for (int i = ddkb; i <= ddke; i++)
    //     cout << arr[i] << ' ';
    // cout << endl << endl;

    if (H + W - K - 1 == 1) {
        add_or({idkb, ddkb});

        // cout << arr[ddke + 1] << endl << endl;

        return;
    }

    // H + W - K - 2 adjacent pairs of pairs of inc. diagonals
    for (int i = idkb; i + 1 <= idke; i++)
        add_and({i, i + 1});

    // H + W - K - 2 adjacent pairs of pairs of dec. diagonals
    for (int i = ddkb; i + 1 <= ddke; i++)
        add_and({i, i + 1});

    int idlb = ddke + 1, idle = idlb + H + W - K - 3;
    int ddlb = idle + 1, ddle = ddlb + H + W - K - 3;

    // for (int i = idlb; i <= idle; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // for (int i = ddlb; i <= ddle; i++)
    //     cout << arr[i] << ' ';
    // cout << endl << endl;

    vector<int> id_end;
    for (int i = idkb; i <= idke; i++)
        id_end.pb(i);
    add_or(id_end); // 1

    id_end.clear();
    for (int i = idlb; i <= idle; i++)
        id_end.pb(i);
    add_or(id_end); // 2

    vector<int> dd_end;
    for (int i = ddkb; i <= ddke; i++)
        dd_end.pb(i);
    add_or(dd_end); // 3

    dd_end.clear();
    for (int i = ddlb; i <= ddle; i++)
        dd_end.pb(i);
    add_or(dd_end); // 4

    // cout << arr[ddle + 1] << ' ' << arr[ddle + 2] << ' ' << arr[ddle + 3] << ' ' << arr[ddle + 4] << endl << endl; 

    add_xor({ddle + 1, ddle + 2});   // 5
    add_xor({ddle + 3, ddle + 4});   // 6
    add_and({ddle + 1, ddle + 2});   // 7
    add_and({ddle + 3, ddle + 4});   // 8
    add_or({ddle + 7, ddle + 8});    // 9

    // cout << arr[ddle + 5] << ' ' << arr[ddle + 6] << ' ' << arr[ddle + 7] << ' ' << arr[ddle + 8] << ' ' << arr[ddle + 9] << endl << endl; 

    add_or({ddle + 5, ddle + 6});    // 10
    add_not(ddle + 9);               // 11

    // cout << arr[ddle + 10] << ' ' << arr[ddle + 11] << endl << endl;

    add_and({ddle + 10, ddle + 11}); // 12

    // cout << arr[ddle + 12] << endl << endl;

    return;
}
 
#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t;
    while (t--) {
        int H, W, K;
        cin >> H >> W >> K;
        arr.clear();
        arr.resize(H * W);
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        arr[r1 * W + c1] = 1;
        arr[r2 * W + c2] = 1;
 
        construct_network(H, W, K);
 
        cout << arr.back() << endl;
    }
 
    return 0;
}
#endif