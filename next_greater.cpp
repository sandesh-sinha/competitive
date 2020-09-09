#include<bits/stdc++.h>
#define ll long long
#define print(ds) for(auto i:ds){cout<<i<<" ";} cout<<endl;
#define p2v(v) for(int i=0; i<v.size();i++){ for(int j=0; j<v[i].size();j++){ cout<<v[i][j]<<" ";} cout<<endl;}
#define pp pair <ll, ll>
#define mod 1000000007
#define large 1e6
using namespace std;
vector <int> next_greater(vector <int> &input){
    stack <int> temp;
    int n= input.size();
    vector <int> result(n,-1);
    for(int i=n-1; i>=0; i--){
        while(!temp.empty() && input[temp.top()]<input[i]){
            temp.pop();
        }
        if(temp.empty()) result[i] = -1;
        else {
            result [i] = temp.top();
        }
        temp.push(i);
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    } 
    vector <int> result = next_greater(v);
    print(result);
}