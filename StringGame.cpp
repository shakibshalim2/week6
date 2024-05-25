#include<bits/stdc++.h>
using namespace std;

bool v(long long n, long long x, long long y, long long t) {
    return (t / x + t / y) >= n;
}

int main() {
    long long n, x, y;
    cin >> n >> x >> y;

    if (x > y) 
    swap(x, y);

    long long left = 0, right = n * x;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (v(n, x, y, mid)) {
            right = mid;
        } 
        else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}
