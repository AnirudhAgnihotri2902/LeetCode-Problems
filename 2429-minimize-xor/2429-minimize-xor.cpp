class Solution {
public:
    int setbits = 0;
    string converttobits(int n){
        string str="";
        while(n){
            if(n&1){
                str+='1';
                setbits++;
            }
            else str+='0';
            n/=2;
        }
        while(str.size()<32)str+='0';
        return str;
    }
    int minimizeXor(int num1, int num2) {
        string n2 = converttobits(num2);
        int s2 = setbits;
        setbits = 0;
        string n1 = converttobits(num1);
        int s1 = setbits;
        // cout<<n1<<"\n"<<n2<<"\n";
        int set1 = 0;
        
        string str = "";
        for(int i = 31; i>=0; i--){
            if(set1<s2 && n1[i] == '1'){
                str+='1';
                set1++;
            }
            else{
                str+='0';
            }
        }
        reverse(str.begin(), str.end());
        for(int i = 0; i<32; i++){
            if(s2>set1 && str[i] == '0'){
                set1++;
                str[i] = '1';
            }
        }
        // cout<<str<<"\n";
        long mult = 1;
        int ans = 0;
        for(int i = 0; i<32; i++){
            if(str[i] == '1'){
                ans+=mult;
            }
            mult*=2;
        }
        return ans;
    }
};