// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int giveNumber(string row) {
    vector<string> numbers {
        "#...###..#",
        ".##....#..",
        "#...#..#..",
        "#...#....#",
        "..##.#####",
        "#........#",
        "#....#...#",
        "....#..#..",
        "#...##...#",
        "#...#.####"
    };

    for (int i = 0; i <= 9; i++) 
        if (row == numbers[i])
            return i;

    return -1;
}

void solve() {
    int n;
    cin >> n;
    cout << "ASK ROW 2" << endl;
    string row1;
    cin >> row1;
    cout << "ASK ROW 5" << endl;
    string row2;
    cin >> row2;

    cout << "ANSWER ";
    for (int i = 0; i < 6 * n - 1; i += 6) {
        cout << giveNumber(row1.substr(i, 5) + row2.substr(i, 5));
    }
    cout << endl;
    
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