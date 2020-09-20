#include<bits/stdc++.h>
#define ll long long 
#define print(ds) for(auto i:ds){cout<<i<<" ";} cout<<endl;
#define printpair(pairs) cout<<pairs.first<<" "<<pairs.second<<endl;
#define p2v(v) for(int i=0; i<v.size();i++){ for(int j=0; j<v[i].size();j++){ cout<<v[i][j]<<" ";} cout<<endl;}
#define pp pair <ll, ll>
#define mod 1000000007
#define itr(structure) structure.begin(), structure.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define large 800005
#define endl "\n"
using namespace std;
struct segtree{
    int size;
    vector <ll> tree;
    void init(int n){
        size = 1;
        while(size<n) size*=2;
        tree.assign(2*size, 0LL);
    }
    void update(int node, int lx, int rx, int i, ll v){
        if((rx-lx)==1){
            tree[node] = v;
            return ;
        }
        int mid = (lx+rx)/2;
        if(i<mid) {
            update(2*node+1, lx, mid, i, v);
        }
        else {
            update(2*node+2, mid, rx, i, v);
        }
        tree[node] = tree[2*node+1] + tree[2*node+2];
        return ;
    }
    void update(int i, ll v){
        update(0,0, size, i, v);
    }
    ll query(int node, int lx, int rx, int l, int r){
        if(l>=rx || r<=lx) return 0;
        if(l<=lx && rx<=r) return tree[node];
        int mid = (lx+rx)/2;
        ll left = query(2*node+1, lx, mid, l, r);
        ll right = query(2*node+2, mid, rx, l, r);
        return left+right;
    }
    ll query(int l, int r){
        return query(0,0,size, l, r);
    }
    void build(vector <int> &arr, int node, int lx , int rx){
        if((rx-lx)==1){
            if(lx< int(arr.size())){
                tree[node] = arr[lx];
            }
            return ;
        }
        int mid = (lx+rx)/2;
        build(arr, 2*node+1, lx, mid);
        build(arr, 2*node+2, mid, rx);
        tree[node] = tree[2*node+1]+tree[2*node+2];
        return ;
    }
    void build(vector <int> &arr){
        build(arr, 0, 0, size);
        return ;
    }

};
int32_t main(){
    fastio;
    int n, m; cin>>n>>m;
    vector <int> a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    segtree seg;
    seg.init(n);
    seg.build(a);
    while(m--){
        int op; cin>>op;
        if(op==1){
            int index; ll value; cin>>index>>value;
            seg.update(index, value);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<seg.query(l, r)<<"\n";
        }
    }
}