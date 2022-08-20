class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int count = 0;
        while(true){
            bool flag = false;
            for(int i = 1; i<s.size(); i++){
                string temp = s.substr(i-1, 2);
                //cout<<s[i-1]<<s[i]<<" "<<temp<<endl;
                if( temp == "01"){
                    flag = true;
                    s[i-1] = '1';
                    s[i] = '0';
                    i++;
                }
            }
            if(!flag)return count;
            count++;
        }
        return count;
    }
};