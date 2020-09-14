#include<bits/stdc++.h>
#define ll long long 
#define printv(ds) for(auto i:ds){cout<<i<<" ";} cout<<endl;
#define pprint(pairs) cout<<pairs.first<<" "<<pairs.second<<endl;
#define print(a) cout<<a<<endl;
#define p2v(v) for(int i=0; i<v.size();i++){ for(int j=0; j<v[i].size();j++){ cout<<v[i][j]<<" ";} cout<<endl;}
#define pp pair <ll, ll>
#define mod 1000000007
#define large 1e6
using namespace std;

void count_sort(vector <int> & p, vector <int> & classes){
    int n = p.size();
    vector <int> count(n);
    for(int i=0; i<n;i++){
        count[classes[i]]++;
    }
    vector <int> pos(n);
    pos[0] = 0;
    for(int i=1; i<n;i++){
        pos[i] = pos[i-1]+count[i-1];
    }
    vector <int> p_new(n);


    for(auto x:p){
        int i = classes[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}
int32_t main(){
    string s;
    cin>>s;
    s += '$';
    int n = s.size();
    vector <pair <char, int> > c(n);
    vector <int> p(n);
    for(int i=0; i<n;i++){
        c[i] = {s[i],i};
    }
    sort(c.begin(), c.end());
    for(int i=0; i<n;i++){
        p[i] = c[i].second;
    }
    vector <int> classes(n);
    classes[c[0].second] = 0;
    for(int i=1; i<n;i++){
        if(c[i].first==c[i-1].first){
            classes[c[i].second] = classes[c[i-1].second];
        }
        else{
            classes[c[i].second] = classes[c[i-1].second]+1;
        }
    }
    int k = 0;
    while((1<<k)<n){
        for(int i=0; i<n;i++){
            p[i] = (p[i]-(1<<k)+n)%n;
        }
        count_sort(p, classes);   
        vector <int> new_classes(n);
        new_classes[p[0]] = 0;
        for(int i=1; i<n;i++){
            pair <int,int> now = {classes[p[i]], classes[(p[i]+ (1<<k))%n]};
            pair <int,int> last = { classes[p[i-1]], classes[(p[i-1]+(1<<k))%n]};
            if(now==last){
                new_classes[p[i]] = new_classes[p[i-1]];
            }
            else{
                new_classes[p[i]] = new_classes[p[i-1]]+1;
            }
        }
        classes = new_classes;
        k++;
    }  
    int q;
    cin>>q;
    while(q--){
        string sub;
        cin>>sub;   
    }
    return 0;
}