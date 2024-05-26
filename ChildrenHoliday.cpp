#include <bits/stdc++.h>
using namespace std;

struct at {
    int t, z, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<at> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].z >> a[i].y;
    }

    vector<int> p(n);
    auto isFeasible = [&](int mid) {
        vector<int> may(n);
        int remt = m;
        for (int i = 0; i < n; ++i) {
            int t = a[i].t;
            int z = a[i].z;
            int y = a[i].y;

            int tc = (t * z) + y;
            int fc = mid / tc;
            int rt = mid % tc;
            int ip = (fc * z) + min(z, (rt / t));

            ip = min(remt, ip);
            remt -= ip;
            may[i] = ip;
        }

        if (remt == 0) {
            for (int i = 0; i < n; i++) {
                p[i] = may[i];
            }
            return true;
        }
        return false;
    };

    int left = 0, right = 1e8, mid, ans;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (isFeasible(mid)) {
            ans = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
    for (auto val : p) {
        cout << val << " ";
    }
    cout << '\n';
}
