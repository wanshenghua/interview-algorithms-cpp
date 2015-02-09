/* Implement strStr()

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 

Idea:
1. naive algorithm
2. KMP 
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len_s = strlen(haystack);
        int len_t = strlen(needle);

        for(int i = 0; i < len_s - len_t + 1; i++){
            int j = 0;
            for(; j < len_t; j++){
                if(haystack[i + j] != needle[j]){
                    break;
                }
            }
            if(needle[j] == '\0'){
                return haystack + i;
            }
        }
        return NULL;
    }
};