struct Node{
    Node *link[26];
    bool flag = false;
    int count = 0;
    
    bool containkey(char ch){
        return (link[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void increase(){
        count++;
    }
    int getcount(){
        return count;
    }
    void setend(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();
        
        for(auto word:words){
            Node* node = root;
            for(int i=0; i<word.size(); i++ ){
                if(!node->containkey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
                node->increase();
            }
            node->setend();
        }
        vector<int>ans;
        for(auto word: words){
            int cnt = 0;
            Node* node = root;
            for(int i = 0; i<word.size(); i++){
                node = node->get(word[i]);
                cnt+=node->getcount();
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};