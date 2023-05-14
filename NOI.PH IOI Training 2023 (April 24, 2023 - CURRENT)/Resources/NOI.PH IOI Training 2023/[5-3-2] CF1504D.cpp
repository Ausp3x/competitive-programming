#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> Point;
/*
    Internally, treat colors as 0, 1, 2 (so that e.g. the parity checkerboard coloring is convenient)
    Remember to -1 colors read from input, and +1 colors before writing them to output
*/
int main() {
    int n; cin >> n;
    queue<Point> points[2]; // partition into checkerboard pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            points[(i + j) & 1].push({i, j});
        }
    } 

    while (!points[0].empty() && !points[1].empty()) {
        int banned; cin >> banned; banned--;
        int color = 0 != banned ? 0 : 1;

        Point pt = points[color].front();
        points[color].pop();
        cout << color+1 << " " << pt.first << " " << pt.second << endl;
    }

    int to_do = !points[0].empty() ? 0 : 1;
    while (!points[to_do].empty()) {
        int banned; cin >> banned; banned--;
        int color = to_do != banned ? to_do : 2;
        
        Point pt = points[to_do].front();
        points[to_do].pop();
        cout << color+1 << " " << pt.first << " " << pt.second << endl;
    }
    return 0;
}