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
import math

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]

numer = 1
denom = 1
L1, L2 = [], []
for p in primes:
    numer *= p - 1
    denom *= p
    
    g = math.gcd(denom - numer, denom)
    
    L1.append(denom)
    L2.append(f'{(denom - numer) // g}/{denom // g}')
    
L1 = L1[::-1]
L2 = L2[::-1]    

print(L1)
print(L2)
*/

vector<lll> bounds = {32589158477190044730, 614889782588491410, 13082761331670030, 304250263527210, 7420738134810, 200560490130, 6469693230, 223092870, 9699690, 510510, 30030, 2310, 210, 30, 6, 2};
vector<string> ans = {"40762420985117/47183480978717", "9968041656757/11573306655157", "4860900544813/5663533044013", "112599773191/131710070791", "2734683311/3212440751", "73551683/86822723", "2358365/2800733", "565447/676039", "268027/323323", "13945/17017", "809/1001", "61/77", "27/35", "11/15", "2/3", "1/2"};

void solve() {
    lng n;
    cin >> n;

    for (int i = 0; i < bounds.size(); i++) 
        if (n >= bounds[i]) {
            cout << ans[i] << endl;
            break;
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