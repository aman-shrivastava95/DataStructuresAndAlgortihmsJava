#include<bits/stdc++.h>
using namespace std;

//COMPARATOR function
//if this returns true, chnage does not happen,,i.e they are at right place.
bool compare(int a, int b){
    return a > b  ;
}

//COMPARATOR CLASS
//overloading function call operator
class Compare{
    public:
        bool operator()(const int &a, const int &b){
            return a > b ;
        }
};

class comp{
    public:
        bool operator()(const int &a, const int &b){
            return a > b ;
        }
};

void vectors(){
    cout<<"working with vectors: " ;
    vector<int> v{1,2,3,4} ;
    sort(v.begin(),v.end(),compare) ;//using comparator function here.
    for(auto it:v){
        cout<< it<<" " ;
    }
    cout<<endl ;
}

void sets(){
    cout<<"working with sets: " ;
    set<int,Compare> st ;
    st.insert(2) ;
    st.insert(1) ;
    st.insert(3) ;
    for(auto it:st){
        cout<<it<<" " ;
    }
    cout<<endl;
}

void priorityQueues(){
    cout<<"working with priortiyQueues: "<<endl ;
    cout<<"max heap: " ;
    priority_queue<int> pq ;
    pq.push(1) ;
    pq.push(2) ;
    pq.push(6) ;
    while(!pq.empty()){
        cout<<pq.top()<<" " ;
        pq.pop() ;
    }
    cout<<endl ;
    cout<<"min heap: " ;
    priority_queue<int, vector<int>, comp> p ;
    p.push(1) ;
    p.push(2) ;
    p.push(6) ;
    while(!p.empty()){
        cout<<p.top()<<" " ;
        p.pop() ;
    }

    //can also be declared like this
    priority_queue<int, vector<int> ,greater<int>> pqq ;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    vectors() ;
    sets() ;
    priorityQueues() ;
   
    
    
    //associative containers comparators,, where we need class/structures.
    
    
    return 0;
}
