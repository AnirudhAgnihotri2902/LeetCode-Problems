class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank){
        if(start == end) return 0;
        unordered_set<string>myset(bank.begin(), bank.end());
        if(myset.find(end) ==  myset.end())return -1;
        queue<string>q;
        q.push(start);
        
        int depth = 0;
        vector<char>arr = {'A', 'C', 'G', 'T'};
        while(!q.empty()&& !myset.empty()){
            depth+=1;
            int lsize = q.size();
            while(lsize--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    // cout<<i<<endl;
                    for(char &c : arr){
                        temp[i] = c;
                        // cout<<temp<<endl;
                        if(curr.compare(temp)==0){
                            continue;
                        }
                        if(temp.compare(end)==0){
                            return depth;
                        }
                        if(myset.find(temp)!=myset.end()){
                            cout<<temp<<endl;
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};