struct Node{
    Node *link[26];
    bool flag = false;
    
    bool containkey(char ch){
        return (link[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void setend(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++ ){
            if(!node->containkey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }
    bool search(Node* node, int i, string word){
        if(i == word.size()){
            return node->isend();
        }
        if(word[i]!='.' && node->containkey(word[i])){
            return search(node->get(word[i]), i+1, word);
        }
        if(word[i]!='.' && (!node->containkey(word[i]))){
            return false;
        }
        for(int itr = 0; itr<26; itr++){
            if(node->containkey('a'+itr)){
                if(search(node->get('a'+itr), i+1, word))return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        Node *node = root;
        return search(node, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */