#include<bits/stdc++.h>
using namespace std;
bool cubes(long long x) {
    unordered_set<long long> c;
    long long limit = cbrt(x) + 1;
    for (long long i = 1; i <= limit; i++) {
        c.insert(i * i * i);
    }
    
    for (long long a = 1; a <= limit; a++) {
        long long a3 = a * a * a;
        if (c.count(x - a3)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        if (cubes(x)) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
}
