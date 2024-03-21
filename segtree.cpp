#include<bits/stdc++.h>
using namespace std;
 
class SGT_tree{
   
    public:
     vector<int>seg;
    SGT_tree(int n){
      seg.resize(4*n+1);
    }
void build(int ind,int low,int high,int arr[]){
    if(low==high) {
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
   seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r){
    //no overlap
    if(l>high || r<low) return INT_MAX;
    //complete overlap
    if(low>=l && high<=r) return seg[ind];
    int mid=(low+high)>>1;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return min(left,right);
}
void update(int ind,int low,int high,int i,int val){
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid) update(2*ind+1,low,mid,i,val);
    else update(2*ind+2,mid+1,high,i,val);
    seg[ind]= min(seg[2*ind+1],seg[2*ind+2]);

}
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
   SGT_tree sg(n);
    sg.build(0,0,n-1,arr);
    cout<<sg.seg[0]<<endl;
    int q;
    cin>>q;
    // while(q--){
    //     int l,r;
    //     cin>>l>>r;
    //     cout<<query(0,0,n-1,l,r,seg)<<endl;
        
    // }
    while(q--){
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<sg.query(0,0,n-1,l,r)<<endl;

        }
        else{
            int i,val;
            cin>>i>>val;
            sg.update(0,0,n-1,i,val);
          arr[i]=val;
          for(int i=0;i<n;i++ ) cout<<arr[i]<<" ";
          cout<<endl;
        }
    }

}
