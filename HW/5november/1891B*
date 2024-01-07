#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// на 3 тесте превышение времени, не понимаю как забыстрить

int main() {
    int t;
    cin >> t;
    vector<int> a, x;
    int n, q;
    vector<int>two(31, 0);
    int nm = 1;
    for (int i = 0; i <= 30; i++) {
        two[i] = nm;
        nm *= 2;
    }
    for (int ti = 0; ti < t; ti++) {
        cin >> n >> q;
        a.resize(n, 0);
        x.resize(q, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < q; j++) {
            cin >> x[j];
        }
        int mn = 31;
        // обрабатываем массив x
        for (auto it = x.begin(); it != x.end();) {
            if (*it >= mn) {
                it = x.erase(it);
            } else {
                mn = *it;
                ++it;
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < q; i++) {
                if (a[j] % two[x[i]] == 0) {
                    a[j] += two[x[i]-1];
                }
            }
        }

        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
