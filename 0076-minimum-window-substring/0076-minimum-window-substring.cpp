class Solution {
public:
    bool check(vector<int>&a, vector<int>&b){
        for(int i = 0; i<256; i++){
            // cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
            if(b[i]!=0)
            if(a[i]<b[i]){
                // cout<<endl;
                return false;
            }
        }
        // cout<<endl;
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>arr(256, 0);
        vector<int>mapt(256, 0);
        for(int i = 0; i<t.size(); i++){
            mapt[(int)(t[i])]++;
        }
        string ans = "";
        int mini = INT_MAX;
        int start = 0;
        int ind = 0;
        int end = s.size();
        while(start<end){
            // cout<<start<<"\n";
            arr[(int)(s[start])]++;
            int dist = start-ind+1;
            // cout<<flag<<"\n";
            while(check(arr, mapt)){
                if(dist<mini)
                ans = s.substr(ind, dist);
                // cout<<dist<<" "<<start<<" "<<ans<<endl;
                arr[(int)(s[ind])]--;
                ind++;
                mini = min(mini, dist);
                dist = start-ind+1;
            }
            start++;
        }
        return ans;
        
    }
};