class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if(s.length() == 0){
            return 0;
        }

        int lengthLastWord = 0;
        int firstNonSpaceCharPos = s.size() - 1;
        
        while(s[firstNonSpaceCharPos] == ' '){
            firstNonSpaceCharPos--;
        }

        for(int i = firstNonSpaceCharPos; (i >= 0 && s[i] != ' '); i--){
            lengthLastWord++;
        }
        
        return lengthLastWord; 
    }
};