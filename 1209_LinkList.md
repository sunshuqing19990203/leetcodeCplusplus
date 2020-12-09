# LinkedList

### 1.C++定义

链表的基本构造

```c++
// 单链表
struct ListNode{
    int val;// 节点上存储的元素
    ListNode* next;// 指向下一个节点的指针
    ListNode(int x): val(x), next(NULL){}	// 节点的构造函数，可以不定义
}
```

