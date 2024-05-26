#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--) {
        long long n, pw, left = 1;
        long long right = 2e9;
        cin >> n >> pw;

        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long ans = 0;

        while (left <= right) {
            long long mh = left + (right - left) / 2;
            long long tw = 0;

            for (long long i = 0; i < n; i++) {
                if (a[i] < mh) {
                    tw += (mh - a[i]);
                }
            }

            if (tw <= pw) {
                ans = mh;
                left = mh + 1;
            } 
            else {
                right = mh - 1;
            }
        }

        cout << ans << '\n';
    }
}
