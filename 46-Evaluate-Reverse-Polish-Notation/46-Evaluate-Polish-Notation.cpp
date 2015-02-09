/*Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
 idea: use a stack
 pitfalls: there would be negative numbers.
*/

class Solution {
private:
    enum InputType{NUMBER, OPERATOR};
    InputType checkStr(const string &s){
        if(s.size() == 1){
            switch(s[0]){
                case '+':
                case '-':
                case '*':
                case '/':
                    return OPERATOR;            
                    break;
                default:
                    return NUMBER;
            }
        }
        return NUMBER;     
    }
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> stk;
        
        for(int i = 0; i < tokens.size(); i++){
            string s = tokens[i];
            InputType t = checkStr(s);
            if(t == NUMBER){
                stk.push(s);
            }else if(t == OPERATOR){
                string b_s = stk.top();
                stk.pop();
                string a_s = stk.top();
                stk.pop();
                
                int b = atoi(b_s.c_str());
                int a = atoi(a_s.c_str());
                
                int c = 0;
                switch(s[0]){
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                        break;
                }
                string c_s = std::to_string(c);
                stk.push(c_s);
            }
        }
        string res = stk.top();
        stk.pop();
        return atoi(res.c_str());
    }
};