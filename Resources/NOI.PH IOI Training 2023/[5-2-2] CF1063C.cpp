#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;

    cout << "0 1" << endl;
    string root_color; cin >> root_color;

    int leftmost_other = 1e9;
    int x = 1 << (n - 2);
    for (int i = 2; i <= n; i++) {
        cout << x << " " << 1 << endl;
        string color; cin >> color;
        if (color == root_color) {
            x += 1 << (n - 1 - i);
        } else {
            leftmost_other = x;
            x -= 1 << (n - 1 - i);
        }
    }

    cout << leftmost_other << " " << 2 << " "  << leftmost_other-1 << " " << 0 << endl;

    return 0;
}