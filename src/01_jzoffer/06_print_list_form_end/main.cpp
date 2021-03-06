//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"
#include "List.h"
#include <vector>
#include <memory>
#include <functional>

typedef std::unique_ptr<ListNode, std::function<void(ListNode *)>> ListNodePtr;
typedef std::vector<ListNodePtr> ListNodePtrVector;

ListNodePtr createListNodePtr(int val) {
    ListNodePtr ptr(new ListNode, [](ListNode *node) {
        printf("delete ListNode %d\n", node->m_nValue);
        delete node;
    });

    ptr->m_nValue = val;
    ptr->m_pNext = nullptr;
    return ptr;
}

void testPrintListFromEnd() {
    ListNodePtrVector listNodePtrVector;
    ListNode preHead, *endNode = &preHead;
    for (int i = 0; i < 10; i++) {
        ListNodePtr listNodePtr = createListNodePtr(i);
        listNodePtrVector.emplace_back(std::move(listNodePtr));
        endNode->m_pNext = listNodePtrVector[i].get();
        endNode = endNode->m_pNext;
    }
    PrintList(preHead.m_pNext);
    printListNodeFromEnd(preHead.m_pNext);

}

int main() {
    LOG(error, "main")
    testPrintListFromEnd();

    return 0;
}