#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n; 
        int k;
        cin >> n >> k;
        
        vector<long long> mp(k);
        for (int i = 0; i < k; i++) {
            cin >> mp[i];
        }
        sort(mp.begin(), mp.end(), greater<long long>());

        int savedd = 0;
        long long cp = 0;

        for (int i = 0; i < k; i++) {
            if (mp[i] > cp) {
                savedd++;
                cp += (n - mp[i]);
            }
             else {
                break;
            }
        }

        cout << savedd << endl;
    }
}
