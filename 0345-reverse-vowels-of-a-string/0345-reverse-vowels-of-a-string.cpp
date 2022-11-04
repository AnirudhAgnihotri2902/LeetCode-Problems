class Solution {
public:
    string reverseVowels(string arr) {
        vector<char>a;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]== 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
                a.push_back(arr[i]);
            }
            if(arr[i]== 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U'){
                a.push_back(arr[i]);
            }
        }
        reverse(a.begin(), a.end());
        int ind = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]== 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
                arr[i]=(a[ind++]);
            }
            else if(arr[i]== 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U'){
                arr[i] = (a[ind++]);
            }
        }
        return arr;
    }
};