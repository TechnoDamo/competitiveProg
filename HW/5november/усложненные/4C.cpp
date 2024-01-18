#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    string name;
    map<string, int> base;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        if (base.count(name) != 0) {
            name += to_string(base[name]++);
            cout << name << endl;
        }
        else {
            base[name] = 1;
            cout << "OK" << endl;
        }
    }

    return 0;
}
