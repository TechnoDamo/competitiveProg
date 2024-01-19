#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;


void swap(int ind1, int ind2, vector<int> &v) {
    int t = v[ind2];
    v[ind2] = v[ind1];
    v[ind1] = t;
}

int main() {
    int n;
    cin >> n;
    vector<int>games(n+1, 0);
    vector<int>p(n+1, 0);
    int x, y;
    for (int i = 1; i < n*(n-1)/2; i++) {
        cin >> x >> y;
        games[x]++;
        games[y]++;
        p[x]++;
    }

    vector<int> a;
    int i = 1;
    while (a.size() != 2) {
        if (games[i] != n - 1) {
            a.push_back(i);
        }
        i++;
    }

    if (p[a[0]] > p[a[1]]) {
        cout << a[0] << " " << a[1];
    }
    else {
        cout << a[1] << " " << a[0];
    }
    return 0;
}
