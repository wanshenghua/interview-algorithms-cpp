/*

Plus One
Total Accepted: 8235 Total Submissions: 27388

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/



class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        if(!digits.size()){
            return res;
        }
        
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] + carry > 9){
                digits[i] = (digits[i] + carry) % 10;
                carry = 1;
            }else{
                digits[i] = digits[i] + carry;
                carry = 0;
            }
        }
        //process msd
        if(carry == 1){
            res.push_back(1);
            res.insert(res.end(), digits.begin(), digits.end());
        }else{
            res.insert(res.end(), digits.begin(), digits.end());
        }
        return res;
    }
};