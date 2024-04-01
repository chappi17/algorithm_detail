
/*
링크드 리스트 순회하면서 중복 제거하기

current 만들어서 순회하면서 중복이면 다음 노드에 연결 하게하면  될듯

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
