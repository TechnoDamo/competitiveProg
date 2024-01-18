#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool starAt(int i, int j, int r, const vector<vector<char>> &sky) {
    if (i - r <= 0 || j - r <= 0 || i + r >= sky.size() || j + r >= sky[0].size()) { return false; }
    if (sky[i][j] == '*' && sky[i][j-r] == '*' && sky[i][j+r] == '*' && sky[i-r][j] == '*' && sky[i+r][j] == '*') { return true; }
    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<char> line(m+1, '.');
    vector<vector<char>> sky(n+1, line);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> sky[i][j];
        }
    }

    int r, x, y;
    int maxR = min(n, m);
    if (maxR % 2 == 0) { maxR /= 2; maxR--; }
    else {
        maxR /= 2;
    }

    for(r = 1; k>0 && r <= maxR; r++) {
        for(y = r; k>0 && y <= n-r; y++) {
            for(x = r; k>0 && x <= m-r; x++) {
                if(starAt(y,x,r, sky)) {
                    k--;
                }
            }
        }
    }

    y--;
    x--;
    r--;

    if(k == 0) {
        cout << y << " " << x << endl;
        cout << y - r << " " << x << endl;
        cout << y + r << " " << x << endl;
        cout << y << " " << x - r << endl;
        cout << y << " " << x + r << endl;
    }
    else {
        cout << -1;
    }



    return 0;
}
