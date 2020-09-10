#include<bits/stdc++.h>
#define ll long long 
#define print(ds) for(auto i:ds){cout<<i<<" ";} cout<<endl;
#define p2v(v) for(int i=0; i<v.size();i++){ for(int j=0; j<v[i].size();j++){ cout<<v[i][j]<<" ";} cout<<endl;}
#define pp pair <int, int>
#define mod 1000000007
#define large 1e6
#define debug cout<<"run"<<endl;
using namespace std;
struct treenode{
    int val=-1; 
    treenode * left = nullptr; 
    treenode * right=nullptr;
    treenode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
    treenode(int x, treenode * l, treenode *r){
        val = x;
        left = l;
        right = r;
    }
};
int first, second;
treenode * lca(treenode * root){
    if(root==nullptr) return nullptr;
    if(root->val==first || root->val == second){
        return root;
    }
    treenode * l =  lca(root->left);
    treenode * r = lca(root->right);
    if(l!=nullptr && r!=nullptr){
        return root;
    }
    else if(l==nullptr) return r;
    else return l;
}

int32_t main(){
    treenode * four = new treenode(4);
    treenode * five = new treenode(5);
    treenode * six = new treenode(6);
    treenode * seven = new treenode(7);
    treenode * two = new treenode(2, four, five);
    treenode * three = new treenode(3, six, seven);
    treenode * one = new treenode(1, two, three);
    first = 4;
    second = 6;
    cout<<lca(one)->val<<endl;
    return 0;
}