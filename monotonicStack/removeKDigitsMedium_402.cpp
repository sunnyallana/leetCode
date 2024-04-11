class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> monotonicStack;
        string result;
        for(char c :num){
            while(k>0 && !monotonicStack.empty() && monotonicStack.back()>c){
                monotonicStack.pop_back();
                k--;
            }
            monotonicStack.push_back(c);
        }
        while(k>0){
            monotonicStack.pop_back();
            k--;
        }
        for(char c : monotonicStack){
            if(result.empty() && c=='0') continue;
            result.push_back(c);
        }
        return result.empty()?"0":result;
    }
};