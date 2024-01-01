#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
// на 5 тесте превышение времени, уж и не знаю как рационализировать
void ins(vector<long long> &v, long long x) {
    long long a = 0;
    long long b;
    b = v.size() - 1;
    while (a <= b) {
        long long k = (a+b)/2;
        if (v[k] == x) {
            v.insert(v.begin() + k, x); return;
        }
        if (v[k] > x) b = k-1;
        else { a = k+1; }
    }
    if (b < 0) v.insert(v.begin(), x);
    else if (a >= v.size()) { v.push_back(x); }
    else { v.insert(v.begin() + a, x); }
}

bool f(vector<long long> a, vector<long long> b) {
    for (long long i = 0; i < a.size(); i++) {
        if (a[i] >= b[i]) { return false; }
    }
    return true;
}

long long k(vector<long long> a, vector<long long> b) {
    long long k = 0;
    while (!f(a, b)) {
        a.pop_back();
        b.erase(b.begin());
        k++;
    }
    return k;
}

long long resInd(vector<long long> a, vector<long long> b, long long i) {
    ins(a, i);
    return k(a, b);
}

long long findX(const vector<long long>& a, const vector<long long>& b, long long m, long long origRes) {
    long long mBeg = 1, mEnd = m;
    while (mBeg <= mEnd) {
        long long k = (mBeg + mEnd) / 2;
        if (origRes < resInd(a, b, k)) { mEnd = k-1; }
        else { mBeg = k+1; }
    }
    long long x = mEnd;
    while (resInd(a, b, x) <= origRes && x <= m) {
        x++;
    }
    //cout << "x: " << x << endl;
    return x;
}

int main() {
    long long t;
    cin >> t;
    long long n, m, res, orig;
    for (long long i = 0; i < t; i++) {
        cin >> n >> m;
        vector<long long> a(n-1, 0), b(n, 0);


        // input of a
        for (long long i = 0; i < n-1; i++) {
            cin >> a[i];
        }
        // input of b
        for (long long i = 0; i < n; i++) {
            cin >> b[i];
        }

        //sorting values
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        orig = resInd(a, b, 1);

        // computing res
        long long x = findX(a, b, m, orig) - 1;
        res = orig*(x) + (orig+1)*(m-x);

        cout << res << endl;

    }
    return 0;
}
