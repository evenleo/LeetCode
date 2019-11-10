/*
* 题目：编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
*      不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
*      你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
*
* 示例 1：
*        输入: ["h","e","l","l","o"]
*        输出: ["o","l","l","e","h"]
*
* 示例 2：
*
*        输入: ["H","a","n","n","a","h"]
*        输出: ["h","a","n","n","a","H"]
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // begin:反转字符开始索引，end:反转字符串结束索引
    void reverse(string& s, int begin, int end) {
        while (begin <= end) {
            char tmp = s[begin];
            s[begin++] = s[end];
            s[end--] = tmp;
        }
    }
    string reverseWords(string s) {
        int begin = 0;
        int end = 0;
        while (end <= s.size()) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s, begin, end-1);
                begin = end + 1;
            }
            end++;
        }
        return s;
    }
};