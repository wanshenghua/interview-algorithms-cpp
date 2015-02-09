/*Valid Palindrome 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if(len == 0){
            return true;
        }
        int left = 0;
        int right = len - 1;
        
        while(left < right){
            while(!isalnum(s[left]) && left < len){//ignore non alpha-numberic char, check boundary
                left++;
            }
            while(!isalnum(s[right]) && right >=0 ){//check boundary
                right--;
            }
            if(left >= right){
                break;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};