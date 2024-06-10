#include<bits/stdc++.h>
using namespace std;
bool Median(vector<int>&a,int n,int k,int t){
    long long op=0;
    for(int i=n/2;i<n;i++){
        if(a[i]<t){
            op+=(t-a[i]);
            if(op>k)
            return false;
        }
    }
    return op<=k;
}
int maxMedian(vector<int>&a,int n,int k){
    sort(a.begin(),a.end());
    int low=a[n/2],high=a[n/2]+k;
    int bstMedian=low;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(Median(a,n,k,mid)){
            bstMedian=mid;
            low=mid+1;
        } 
        else{
            high=mid-1;
        }
    }
    return bstMedian;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxMedian(a,n,k)<<endl;
}
