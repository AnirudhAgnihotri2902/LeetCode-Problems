class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans = INT_MIN;
        int temp;
        temp = special[0]-bottom;
        cout<<temp<<" ";
        ans = max(temp,ans);
        if(special.size() > 1){
            for(int i = 1; i<special.size();i++){
                temp = special[i]-special[i-1]-1;
                cout<<temp<<" ";
                ans = max(temp,ans);
            }
        }
        temp = top-special[special.size()-1];
        cout<<temp<<" ";
        ans = max(ans,temp);
        return ans;
    }
};