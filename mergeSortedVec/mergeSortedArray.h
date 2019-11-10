/*
* 题目：给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
* 说明:
*
*     初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
*     你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*
*
* 示例 1：
*        输入: nums1 = [1,2,3,0,0,0], m = 3
*              nums2 = [2,5,6],       n = 3
*        输出: [1,2,2,3,5,6]
*/

class Solution {
public:
    // 这里主要思想是从后面从大到小合并不担心覆盖前面的元素
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        int a = m-1;
        int b = n-1;
        while (a >= 0 && b >= 0) {
            nums1[idx--] = nums1[a] > nums2[b] ? nums1[a--] : nums2[b--];
        }
        while (a >= 0) {
            nums1[idx--] = nums1[a--];
        }
        while (b >= 0) {
            nums1[idx--] = nums2[b--];
        }
    }
};