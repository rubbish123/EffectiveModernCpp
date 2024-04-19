#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> pq;

int f(string &s,int k){
    int cnt=0;
    cout<<s.size()<<endl;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cnt++;
        }
        if(s[i]=='0'&&i!=0){
            cout<<cnt<<" ";
            pq.push(cnt);
            cnt=0;
        }
        if(s[i]=='1'&&i==s.size()-1){
            cout<<cnt<<" ";
            pq.push(cnt);
            cnt=0;
        }
    }
    while(k--){
        int tmp=pq.top();
        pq.pop();
        if(tmp==1){
            pq.push(0);
            continue;
        }
        pq.push(tmp/2);
        if(tmp%2==1){
            pq.push(tmp/2);
        }
        else{
            pq.push(tmp/2-1);
        }
    }
    cout<<endl;
    int res=pq.top();
    return res;
}

int main(){
    string s="10111011011111111101111111";
    int k=3;
    cout<<f(s,k)<<endl;
}