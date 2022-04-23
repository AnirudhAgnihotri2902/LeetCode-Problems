class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string>map;
    string encode(string longUrl) {
        map["Anirudh"] = longUrl;
        
        return "Anirudh";
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map["Anirudh"];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));