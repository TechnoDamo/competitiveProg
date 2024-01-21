#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[i] = x;
    }

    int i = 1;
    int f = 0;
    int k = 0;
    vector<int> ans;
    while (i != n + 1) {
        if (a[i] == 1) {
            f = 1;
            break;
        }
        i++;
    }

    if (f == 0) {
        cout << 0;
        return 0;
    }

    if (i == n) {
        cout << 1 << endl;
        cout << 2000+i;
        return 0;
    }
    ans.push_back(i);
    k++;
    i++;
    int prevA = 1;
    for (; i <= n; i++) {
        if (a[i] - prevA == 1) {
            ans.push_back(i);
            prevA = a[i];
            k++;
        }
    }

    cout << k << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << 2000+ans[i] << " ";
    }
    return 0;
}
