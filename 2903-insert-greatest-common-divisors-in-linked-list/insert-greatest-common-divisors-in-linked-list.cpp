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
    int gcd(int a,int b){
    while(b!=0) {
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * temp=head;
        while(temp->next!=NULL){
            ListNode *sec=temp->next;
            ListNode *fresh=new ListNode(gcd(temp->val,temp->next->val));
            temp->next=fresh;
            fresh->next=sec;
            temp=temp->next->next;
        }
        return head;
    }
};