class Solution {
public:
    string pushDominoes(string s) {
        string ans;
        int right = -1, left;
        string vis;
        // string ans;
        for(int i = 0; i<s.size(); i++){
            //cout<<i<<" "<<ans<<endl;
            ans+=s[i];
            vis+='f';
            if(s[i] == '.'){
                continue;
            }
            if(s[i] == 'R'){
                if(right!=-1){
                    while(right<i){
                        vis[right] = 't';
                        ans[right++] = 'R'; 
                    }
                }
                right = i;
            }
            if(s[i] == 'L'){
                left = i;
                if(right!=-1){
                    while(right<left && vis[right] == 'f' && vis[left]=='f'){
                        vis[right] = 't';
                        vis[left] = 't';
                        ans[right++] = 'R';
                        ans[left--] = 'L';
                    }
                    vis[right]='t';
                    right = -1;
                }
                else{
                    while(left>=0 && vis[left]=='f'){
                        vis[left] = 't';
                        ans[left--] = 'L';
                    }   
                }
            }
        }
        if(right!=-1){
            while(right<ans.size()){
                ans[right++] = 'R';
            }
        }
        return ans;
    }
};