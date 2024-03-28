/*
두 리스트를 병합하고 정렬시켜야 함

head 나 tail 더미로 만들고

2개 비교해서 tail->next에 계속 연결시키고

나머지까지 넣어주기

*/

#include <iostream>
#include <vector>
using namespace std;

// 연결 리스트 노드 정의
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

// 두 정렬된 리스트 병합 함수
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = (list1 != nullptr) ? list1 : list2;
    return dummy.next;
}

// 배열을 연결 리스트로 변환하는 함수
ListNode* vectorToList(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int val : v) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy.next;
}

// 연결 리스트를 순회하며 값을 출력하는 함수
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 입력 리스트
    vector<int> list1Vec = {1, 2, 4};
    vector<int> list2Vec = {1, 3, 4};

    // 배열을 연결 리스트로 변환
    ListNode* list1 = vectorToList(list1Vec);
    ListNode* list2 = vectorToList(list2Vec);

    // 두 리스트 병합
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // 결과 출력
    printList(mergedList);

    return 0;
}
