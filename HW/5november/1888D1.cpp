#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool check(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < a.size(); i++) {
        if (b[i] <= a[i]) { return false; }
    }
    return true;
}

int find(vector<int> v, int x) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i]==x){ return i;}
    }
    return -1;
}

void ins(vector<int> &v, int x) {
    int s;
    s = v.size();
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > x) { v.insert(v.begin() + i, x); return; }
    }
    if(s == v.size()) { v.push_back(x); }
    return;
}

int mxEl(vector<int> v) {
    int mx = v[0];
    for (int i = 0; i < v.size(); i++) {
        if(v[i] > mx){ mx = v[i]; }
    }
    return mx;
}

int minEl(vector<int> v) {
    int mn = v[0];
    for (int i = 0; i < v.size(); i++) {
        if(v[i] < mn){ mn = v[i]; }
    }
    return mn;
}

int k(vector<int> &a, vector<int> &b) {
    int k = 0;
    while (check(a, b) == 0) {
        a.pop_back();
        b.erase(b.begin());
        k++;
    }
    return k;
}

int main()
{
    vector<int> a;
    vector<int> b;
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        a.resize(n-1, 0);
        b.resize(n, 0);
        for (int j = 0; j < n-1; j++)
        {
            cin >> a[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }
        long long sm;
        long long K;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<long long> M(m, -1);
        ins(a, 1);
        K = (long long)k(a, b);
        sm = K;
        for (int j = 1; j < m; j++) {
            a[a.size()-1] = j+1;
            if(a[a.size()-1]>b[b.size()-1]) {a.pop_back(); b.erase(b.begin()); K++; }
            sm += K;
        }
        cout << sm << endl;
    }


    return 0;
}
