#include<bits/stdc++.h>
using namespace std;
bool ProduceTime(vector<long long>&m, long long time, long long t) {
    long long product = 0;
    for (long long k : m) {
        product += time / k;
        if (product >= t) 
        return true;
    }
    return product >= t;
}

long long produceProducts(int n, long long t, vector<long long>&m) {
    long long l = 1;
    long long h = *min_element(m.begin(), m.end()) * t;
    long long ans = h;
    
    while (l <= h) {
        long long mid = l + (h - l) / 2;
        if (ProduceTime(m, mid, t)) {
            ans = mid;
            h = mid - 1;
        } 
        else {
            l = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    int n;
    long long t;
    cin >> n >> t;
    vector<long long> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    cout << produceProducts(n, t, m) << endl;
}
