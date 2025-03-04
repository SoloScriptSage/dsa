/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        while(head != nullptr) {
            a.push_back(head->val);
            head = head->next;
        }

        int l=0;
        int r=a.size()-1;

        while(l<r && a[l]==a[r]) {
            l++;
            r--;
        }
        return l>=r;
    }
};
