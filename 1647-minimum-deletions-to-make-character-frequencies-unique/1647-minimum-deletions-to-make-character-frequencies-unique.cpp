class Solution {
public:
    int minDeletions(string s) {
        vector<int>map(26,0);
        for(int i = 0; i<s.size(); i++){
            map[s[i]-'a']++;
        }
        vector<int>arr;
        unordered_map<int, int>mapp;
        for(int i = 0; i<26; i++){
            if(map[i]>0){
                arr.push_back(map[i]);
                mapp[map[i]]++;
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int ans = 0;
        for(int i = 0; i<arr.size(); i++){
            cout<<arr[i]<<" "<<mapp[arr[i]]<<endl;
            if(mapp[arr[i]]> 1){
                int now = arr[i];
                int temp = now;
                while(mapp.find(temp) != mapp.end()){
                    temp--;
                    ans++;
                }
                if(temp!=0){
                     mapp[temp]++;
                }
                mapp[now]--;
            }
        }
        return ans;
    }
};