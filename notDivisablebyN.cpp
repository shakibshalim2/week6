#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long q=k/(n-1);
        long long rem=k%(n-1);
        if(rem==0){
            cout<<q*n-1<<endl;
        } 
        else{
            cout<<q*n+rem<<endl;
        }
    }
    
}
