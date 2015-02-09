/* Valid Number
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 

Key: regular expression, finite automata, state transition graph
Trivials: heading and trailing spaces
*/
#include <ctype>
class Solution {
public:
    bool isNumber(const char *s) {
		enum InputType {
			INVALID, //0
			SPACE, 	 //1
			SIGN,	 //2
			DIGIT,	 //3
			DOT, 	 //4
			EXP,	 //5
			NUM_INPUTS //6
			};
		static const int transition_table[][NUM_INPUTS] = {
			-1,  0,  3,  1,  2, -1,	//next state for state 0
			-1,  8, -1,  1,  4,  5,		//next state for state 1
			-1, -1, -1,  4, -1, -1, 	//next state for state 2
			-1, -1, -1,  1,  2, -1,		//next state for state 3
			-1,  8, -1,  4, -1,  5,		//next state for state 4
			-1, -1,  6,  7, -1, -1,	//next state for state 5
			-1, -1, -1,  7, -1, -1,	//next state for state 6
			-1,  8, -1,  7, -1, -1,	//next state for state 7		
			-1, 8, -1, -1,  -1, -1,	//next state for state 8			
		};
		
		int state = 0;
		while(*s){
			InputType inputType = INVALID;
			if(isspace(*s)){
				inputType = SPACE;
			}else if (*s == '+' || *s == '-'){
				inputType = SIGN;
			}else if(isdigit(*s)){
				inputType = DIGIT;
			}else if(*s == '.'){
				inputType = DOT;
			}else if(*s == 'e' || *s == 'E'){
				inputType = EXP;
			}
			//get next state
			state = transition_table[state][inputType];
			
			//when the state become invalid, it is not a number
			if(state == -1){
				return false;
			}			
			++s;
		}    
		return state == 1 || state == 4 || state == 7 || state == 8;
    }
};