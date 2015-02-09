/*Valid Parentheses Total 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Have you been asked this question in an interview

key: use a stack
*/
class Solution {
public:
    bool isValid(string s) {
        map<char, char> table;
		table.insert(make_pair('}', '{'));
		table.insert(make_pair(']', '['));
        table.insert(make_pair(')', '('));

		stack<pair<char, int> > pair_stk;
        int top = 0;
        
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
            case '(':
            case '[':
            case '{':
                if(pair_stk.size() == 0){
                    pair_stk.push(make_pair(s[i], 1));
                }else{
					if(pair_stk.top().first == s[i]){
                        pair_stk.top().second++;
                    }else{
                      pair_stk.push(make_pair(s[i], 1));
                    }
                }
              
                break;
            case ')':
            case ']':
            case '}':
                if(pair_stk.size() == 0){
                    return false;
                }else{//check top of the stack whether it is '('
                    if(pair_stk.top().first == table[s[i]]){
                        pair_stk.top().second--;  
                        if(pair_stk.top().second == 0){//pop
							pair_stk.pop();
                        }
                    }else{
                        return false;
                    }
                }
                
                break;
            default:
                return false;
            }
        }
        
        if(pair_stk.size() > 0){
            return false;
        }
        
        return true;
    }
};