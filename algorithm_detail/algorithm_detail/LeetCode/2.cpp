/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(-1), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(-1), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {

        ListNode* dummyHead = new ListNode(0); // ��� ���� ����Ʈ�� ���� ���
        ListNode* current = dummyHead; // ��� ���� ����Ʈ�� ���� ���
        int carry = 0; // �ڸ� �ø��� �����ϴ� ����

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // ���� �ڸ��� �հ踦 �����ϴ� ����

            if (l1 != nullptr) {
                sum += l1->val; // l1�� ���� ��� ���� �հ迡 �߰�
                l1 = l1->next; // l1�� ���� ���� �̵�
            }

            if (l2 != nullptr) {
                sum += l2->val; // l2�� ���� ��� ���� �հ迡 �߰�
                l2 = l2->next; // l2�� ���� ���� �̵�
            }

            carry = sum / 10; // �հ迡�� �ڸ� �ø��� ���
            current->next = new ListNode(sum % 10); // �հ��� ���� �ڸ��� ����Ͽ� �� ��� ����
            current = current->next; // ��� ����Ʈ���� ���� ��带 ���� ���� �̵�
        }

        ListNode* result = dummyHead->next; // ���� ��带 ������ ���� ��� ����Ʈ
        delete dummyHead; // ���� ��� �޸� ����
        return result; // ��� ����Ʈ ��ȯ
};


int main()
{

    return -1;
}