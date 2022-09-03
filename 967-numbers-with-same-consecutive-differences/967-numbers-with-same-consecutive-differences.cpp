#include<bits/stdc++.h>
class Solution {
public:
    vector<int>arr;
    unordered_set<int>set;
    void solve(int i, int k,int n ,string s){
        if(s.size()==n){
            //cout<<s<<endl;
            int temp = stoi(s);
            set.insert(temp);
            return;
        }
        if(i+k<10){
            char ch = '0'+ (i+k);
            solve(i+k, k, n, s+ch);
        }
        if(i-k>=0){
            char ch = '0'+ (i-k);
            solve(i-k, k, n, s+ch);
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string str;
        for(int i = 1; i<10; i++){
            char ch= '0'+ i;
            solve(i, k, n, str+ch);
        }
        for(auto i: set){
            arr.push_back(i);
        }
        return arr;
    }
};