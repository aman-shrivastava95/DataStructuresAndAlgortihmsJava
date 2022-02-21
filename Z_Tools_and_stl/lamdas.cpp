#include<bits/stdc++.h>
using namespace std;

void pqWithLambdas(){
    cout<<"pq with lambdas: " ;
    auto cmp=[](const int &a, const int &b){
        return a > b ;
    } ;
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp) ;
    pq.push(6) ;
    pq.push(1) ;
    pq.push(2) ;
    while(!pq.empty()){
        cout<<pq.top()<<" " ;
        pq.pop() ;
    }
    cout<<endl ;
}
int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;


    //defning lambdas [] cpature clause.
    vector<int> V{1,2,3,4} ;
   
    for_each(V.begin(),V.end(),[](int x){
        if(x%2==0) cout<< x<< " is even"<<endl ;
        else cout<<x<< " is odd"<<endl ;
    }) ;

    pqWithLambdas() ;
    return 0;
}
