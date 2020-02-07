#ifdef  _LinkedList_h
#define _LinkedList_h

class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    // int size;                // size是用來記錄Linked list的長度, 非必要
    ListNode *first;            // list的第一個node
public:
    LinkedList():first(0){};
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
};

#endif