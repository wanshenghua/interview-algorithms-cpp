/*
Reverse Words in a String
Total Accepted: 4794 Total Submissions: 34067

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

*/

class Solution {
public:
    void reverseWords(string &s) {
        string res;
        
        istringstream iss(s);
        string word;
        iss >> word;
        res = word;
        while(iss >> word){
            res = word + " " + res; //like a stack
        }
        s = res;
    }
};