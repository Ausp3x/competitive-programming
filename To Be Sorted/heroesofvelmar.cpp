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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

map<string, int> card_power = {
    {"Seraphina", 1},
    {"Frostwhisper", 2},
    {"Ironwood", 3},
    {"Vexia", 3},
    {"Voidclaw", 3},
    {"Ranger", 4},
    {"Zenith", 4},
    {"Gale", 5},
    {"Shadow", 6},
    {"Thunderheart", 6},
    {"Anvil", 7},
    {"Guardian", 8}
};

void solve() {
    int p1 = 0, p2 = 0;
    int ttl_pow_p1 = 0, ttl_pow_p2 = 0;
    for (int i = 0; i < 3; i++) {
        int n1;
        cin >> n1;
        int pow_p1 = 0;
        for (int j = 0; j < n1; j++) {
            string card;
            cin >> card;

            pow_p1 += card_power[card];
            if (card == "Seraphina") {
                pow_p1 += n1 - 1;
            } else if (card == "Zenith") {
                if (i == 1)
                    pow_p1 += 5;
            } else if (card == "Thunderheart") {
                if (n1 == 4)
                    pow_p1 += card_power[card];  
            }
        }
        ttl_pow_p1 += pow_p1;

        int n2;
        cin >> n2;
        int pow_p2 = 0;
        for (int j = 0; j < n2; j++) {
            string card;
            cin >> card;

            pow_p2 += card_power[card];
            if (card == "Seraphina") {
                pow_p2 += n2 - 1;
            } else if (card == "Zenith") {
                if (i == 1)
                    pow_p2 += 5;
            } else if (card == "Thunderheart") {
                if (n2 == 4)
                    pow_p2 += card_power[card];  
            }
        }
        ttl_pow_p2 += pow_p2;

        // cout << pow_p1 << ' ' << pow_p2 << endl;

        if (pow_p1 > pow_p2)
            p1++;
        else if (pow_p2 > pow_p1)
            p2++;
    }

    if (p1 > p2) {
        cout << "Player 1" << endl;
    } else if (p1 == p2) {
        if (ttl_pow_p1 > ttl_pow_p2) {
            cout << "Player 1" << endl;
        } else if (ttl_pow_p1 == ttl_pow_p2) {
            cout << "Tie" << endl;
        } else if (ttl_pow_p2 > ttl_pow_p1) {
            cout << "Player 2" << endl;
        }
    } else if (p2 > p1) {
        cout << "Player 2" << endl;
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