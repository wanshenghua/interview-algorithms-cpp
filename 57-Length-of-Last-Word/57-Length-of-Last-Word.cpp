/* Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 

tricky case: "a ", "a   b    ", i.e. ending with multiple spaces => keep track of last nonzero length
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!s){
            return 0;
        }
        
        int prev_nz_len = 0;
        int len = 0;
        while(*s){
            if(*s == ' '){
                if(len > 0){
                    prev_nz_len = len; //keep track of last nonzeor length
                }
                len = 0;
            }else{
                len++;
            }
            s++;
        }
        if(len){
            return len;
        }
        return prev_len;
    }
};