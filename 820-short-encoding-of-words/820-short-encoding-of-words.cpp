class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string>set;
        for(int i  = 0; i<words.size();i++){
            set.insert(words[i]);
        }
        for(int i = 0; i<words.size(); i++){
            string word = words[i];
            string temp = "";
            for(int j = word.size()-1; j>=0; j--){
                temp = word[j]+ temp;
                //cout<<temp<<endl;
                if(set.find(temp) !=set.end() && word !=temp ){
                    set.erase(temp);
                    //cout<<temp<<endl;
                }
            }
        }
        int ans = 0; 
        for(auto str: set){
            //cout<<str<<endl;
            ans+=str.size();
            ans+=1;
        }
        return ans;
    }
};