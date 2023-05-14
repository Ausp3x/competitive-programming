#include <iostream>
#include <vector>
using namespace std;
vector<int> ask(int L, int R) {
    cout << "? " << L << " " << R << endl;
    vector<int> ans(R-L+1);
    for (int& x : ans) {
        cin >> x;
    }
    return ans;
}
int count_in_range(vector<int> arr, int L, int R) {
    int ans = 0;
    for (int& x : arr) {
        if (L <= x && x <= R) {
            ans++;
        }
    }
    return ans;
}
bool is_good(int m) {
    return count_in_range(ask(1, m), 1, m) % 2 == 1;
}
int bs(int n) { // return first m such that is_good(m) is true
    int L = 1;
    int R = n;
    while (R > L) {
        int M = (L+R)/2;
        if (is_good(M)) {
            R = M;
        } else {
            L = M+1;
        }
    }
    return L;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = bs(n);
        cout << "! " << ans << endl;
    }
    return 0;
}