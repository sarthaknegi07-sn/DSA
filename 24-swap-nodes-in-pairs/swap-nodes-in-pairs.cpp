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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp=head;
        ListNode *front=NULL;
        ListNode *new1=NULL;
        ListNode *curr=NULL;
        ListNode *prev=NULL;
        if(head == NULL || head->next == NULL)
            return head;

        head=head->next;
        while(temp!=NULL && temp->next!=NULL){
            curr=temp;
            front=temp->next;
            new1=front->next;
            front->next=curr;
            curr->next=new1;
            if(prev != NULL)
                prev->next = front;

            prev = curr;
            temp = new1;
        }
        return head;
    }
};