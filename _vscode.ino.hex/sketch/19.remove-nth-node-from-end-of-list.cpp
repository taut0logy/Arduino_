#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\19.remove-nth-node-from-end-of-list.cpp"
/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* p=head;
        while(p!=NULL)
        {
            cnt++;
            p=p->next;
        }
        if(cnt==n)
        {
            return head->next;
        }
        p=head;
        cnt=cnt-n-1;
        if (cnt<0) cnt=0;
        while(cnt--)
        {
            p=p->next;
        }
        ListNode* q=p->next;
        p->next=q->next;
        delete(q);
        return head;
    }
};
// @lc code=end

