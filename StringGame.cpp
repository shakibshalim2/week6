#include <bits/stdc++.h>
using namespace std;

bool canFormSubsequence(const string& s, const string& t, const vector<int>& a, int mid) {
    vector<bool> bad(s.size() + 1, false);
    for (int i = 0; i < mid; i++) {
        bad[a[i]] = true;
    }

    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[j] && !bad[i + 1]) {
            ++j;
        }
        if (j == t.size()) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0, right = n, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFormSubsequence(s, t, a, mid)) {
            ans = mid;
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
}
