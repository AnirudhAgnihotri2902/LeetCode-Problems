class Solution {
public:
    string intToRoman(int num) {
        vector<string>thousand = {"","M","MM","MMM"};
        vector<string>hundred = {"","C","CC","CCC","CD", "D","DC", "DCC", "DCCC", "CM"};
        vector<string>tens = {"","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string>ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string str = "";
        if(num>=1000){
            int tem = num/1000;
            str+= thousand[tem];
            num %=1000; 
        }
        if(num>=100){
            int tem = num/100;
            str+= hundred[tem];
            num %=100; 
        }
        if(num>=10){
            int tem = num/10;
            str+= tens[tem];
            num %=10; 
        }
        if(num>=1){
            int tem = num;
            str+= ones[tem]; 
        }
        return str;
        
     }
};