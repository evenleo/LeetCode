/*
* 题目：判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*
* 示例 1：
*        输入: 121
*        输出: true
*
* 示例 2：
*
*        输入: -121
*        输出: false
*        解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
* 示例 3：
*        输入: 10
*        输出: false
*        解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        long reverse_val = 0;   //用long型是为了防止int溢出
        int val = x;
        while (val) {
            reverse_val = reverse_val * 10 + val % 10;
            val /= 10;
        }
        
        return reverse_val == x ? true : false;
    }
};