#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    int k = x % 2;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x % 2 != k) {
            if (i == 1) {
                cin >> x;
                if (x % 2 == k) {
                    cout << 2;
                    break;
                } else {
                    cout << 1;
                    break;
                }
            }
            cout << i+1; break;
        }
    }

    return 0;
}
