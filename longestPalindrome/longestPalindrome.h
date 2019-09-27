/*
* 题目：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*
* 示例 1：
*        输入: "babad"
*        输出: "bab"
*        注意: "aba" 也是一个有效答案。
*
* 示例 2：
*
*        输入: "cbbd"
*        输出: "bb"
*/
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len < 2)
            return s;
        
        int leftMost = 0;
        int rightMost = 0;
        int i = 0;
        int start, end;
        while(i < len)
        {
            int start = i;
            i++;
            while(i < len && s[start] == s[i])
                i++;
            
            end = i - 1;
            while(start - 1 >= 0 && end + 1 < len && s[start-1] == s[end+1])
            {
                start--;
                end++;
            }
            
            if(end - start > rightMost - leftMost)
            {
                leftMost = start;
                rightMost = end;
            }  
        }
        return s.substr(leftMost, rightMost - leftMost + 1);
    }
};