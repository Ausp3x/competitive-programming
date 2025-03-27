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

int N, T;
double P;

bool test_students(vector<bool> &msk) {
    assert(msk.size() == N);

    string msk_str = "Q ";
    for (int i = 0; i < N; i++)
        msk_str += msk[i] ? '1' : '0';

    cout << msk_str << endl;

    char res;
    cin >> res;
    return res == 'P';
}

/* bible generator (it lied)
Es = [1, 5, 12, 29, 40, 69, 105, 159, 200]

S = '{'
for E in Es:
    S += '\n{'
    S += f'{E}'
    S += ', {'
    for i in range(0, 1001):
        if i <= E:
            S += '0, '
            continue
            
        cnt = 0  
        cur_prob = 1  
        prob_N = (1 - E / i)
        while cur_prob * prob_N >= 0.5:
            cnt += 1
            cur_prob *= prob_N
        
        S += f'{cnt}, '
    
    S = S[:-2]        
    S += '}}, '
              
S = S[:-2]
S += '\n}'

print(S)
//*/

vector<bool> msk, ans;
vector<int> to_test;

void binarySearch(int l, int r) {
    if (l > r)
        return;
    
    // cout << l << ' ' << r << endl;

    if (l == r) {
        ans[to_test[l]] = true;
        return;
    }

    int md = (l + r) / 2;

    for (int i = l; i <= md; i++) 
        msk[to_test[i]] = true;
    bool l_res = test_students(msk);
    for (int i = l; i <= md; i++) 
        msk[to_test[i]] = false;

    if (!l_res) {
        binarySearch(md + 1, r);
        return;  
    }

    for (int i = md + 1; i <= r; i++)
        msk[to_test[i]] = true;
    bool r_res = test_students(msk);
    for (int i = md + 1; i <= r; i++)
        msk[to_test[i]] = false;
    
    binarySearch(l, md);
    if (r_res)
        binarySearch(md + 1, r);

    return;
}

vector<bool> find_positive() {
    if (T == 1) {
        msk.clear();
        msk.resize(N);
        ans.clear();
        ans.resize(N);
        for (int i = 0; i < N; i++) {
            msk[i] = true;
            ans[i] = test_students(msk);
            msk[i] = false;
        }
        
        return ans;
    }

    double err = 1e-9;
    int R = 0;
    if (abs(P - 0.001) <= err) {
        R = 1000;
    } else if (abs(P - 0.005256) <= err) {
        R = 160;
    } else if (abs(P - 0.011546) <= err) {
        R = 84;
    } else if (abs(P - 0.028545) <= err) {
        R = 32; 
    } else if (abs(P - 0.039856) <= err) {
        R = 24;
    } else if (abs(P - 0.068648) <= err) {
        R = 12;
    } else if (abs(P - 0.104571) <= err) {
        R = 8;
    } else if (abs(P - 0.158765) <= err) {
        R = 6;
    } else if (abs(P - 0.2) <= err) {
        R = 4;
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    msk.clear();
    msk.resize(N);
    ans.clear();
    ans.resize(N);
    to_test.clear();
    to_test.resize(N);
    iota(to_test.begin(), to_test.end(), 0);
    shuffle(to_test.begin(), to_test.end(), rng);
    
    for (int i = 0; i < N; i += R) {
        int l = i, r = min(i + R - 1, N - 1);
        
        for (int i = l; i <= r; i++)
            msk[to_test[i]] = true;
        bool res = test_students(msk);
        for (int i = l; i <= r; i++) 
            msk[to_test[i]] = false;

        if (!res)
            continue;

        binarySearch(i, min(i + R - 1, N - 1));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P >> T;
    for (int _ = 0; _ < T; _++) {
        vector<bool> ans = find_positive();

        assert(ans.size() == N);

        string ans_str = "A ";
        for (int i = 0; i < N; i++)
            ans_str += ans[i] ? '1' : '0';

        cout << ans_str << endl;

        char res;
        cin >> res;
        if (res == 'W')
            return 0;
    }

    return 0;
}