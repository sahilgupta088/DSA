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
    int pairSum(ListNode* head) {
        vector<int> temp;
        ListNode* node = head;
        while (node) {
            temp.push_back(node->val);
            node = node->next;
        }
        int n = temp.size();
        node = head;
        int res = INT_MIN;
        for (int i = 0; i < n / 2; i++) {
            res = max(res, node->val + temp.back());
            temp.pop_back();
            node = node->next;
        }
        return res;
    }
};