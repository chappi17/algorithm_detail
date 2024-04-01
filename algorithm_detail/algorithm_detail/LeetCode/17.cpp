
/*
��ũ�� ����Ʈ ��ȸ�ϸ鼭 �ߺ� �����ϱ�

current ���� ��ȸ�ϸ鼭 �ߺ��̸� ���� ��忡 ���� �ϰ��ϸ�  �ɵ�

*/
#include <iostream>
#include <vector>

using namespace std;


  //Definition for singly-linked list.
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* current = head;

        while (current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution a;
    ListNode* _head = new ListNode(1);
    _head->next = new ListNode(1);
    _head->next->next = new ListNode(2);
    a.deleteDuplicates(_head);
}
