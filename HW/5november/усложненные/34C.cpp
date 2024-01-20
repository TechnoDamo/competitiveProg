#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << s; return 0;
    }
    set<int> a;
    int nm;
    string nmS;
    for (int i = 0; i < s.size(); i++) {
        nmS.push_back(s[i]);
        if (s[i] == ',') {
            nmS.pop_back();
            a.insert(stoi(nmS));
            nmS = "";
        }
;   }
    a.insert(stoi(nmS));
    set<int>::iterator it = a.begin();
    int k = 0;
    vector<pair<int, int>> v;
    for(; it != a.end(); it++) {
        int baseN = *it;
        int baseInd = k;
        pair<int, int> p;
        while (*it - baseN == k - baseInd) {
            it++;
            k++;
        }
        k = 0;
        it--;
        p = {baseN, *it};
        v.push_back(p);
    }

    string ans = "";
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == v[i].second) {
            ans += to_string(v[i].first) + ",";
        } else {
            ans += (to_string(v[i].first) + "-" + to_string(v[i].second) + ",");
        }
    }
    ans.pop_back();
    cout << ans;
    return 0;
}
