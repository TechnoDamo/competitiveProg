#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    for (int ti = 1; ti < t+1; ti++) {
        cin >> n;
        vector<int> a(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long x = 0, i = 1, j = n;
        long long k = 0;
        while (i < j) {
            if (x + a[i] == a[j]) {
                k += a[i];
                i++;
                j--;
                k++;
                x = 0;
            }
            else if (x + a[i] > a[j]) {
                k += a[j] - x;
                a[i] -= a[j] - x;
                k++;
                j--;
                x = 0;
            }
            else {
                x += a[i];
                k += a[i];
                i++;
            }
        }

        if (i > j) { cout << k << endl; continue;}

        else {
            if (a[i] == 1) { k++; }
            else {
                k += (a[i] - x) / 2;
                k++;
                k += (a[i] - x) % 2;
            }
        }


        cout << k << endl;
        k = 0;

    }


    return 0;
}
