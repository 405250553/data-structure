// C++ code
#include <iostream>

struct QueueNode{
    int data;
    QueueNode *next;
    QueueNode():data(0),next(0){};
    QueueNode(int x):data(x),next(0){};
};

class QueueList{ // linked list 的指向為front -> back
private:
    QueueNode *front;
    QueueNode *back;
    int size;
public:
    QueueList():front(0),back(0),size(0){};
    void Push(int x); // 此範例將新增的 data 從後面開始放
    void Pop(); //此範例將欲離開queue的 data 從前面開始拿
    bool IsEmpty(); // 確認Queue裡是否有資料。
    int getFront(); // 回傳front所指向的資料。
    int getBack(); // 傳back所指向的資料。
    int getSize(); // 回傳Queue裡的資料個數。
    void PrintList(); // 印出queue的所有資料 (由左至右是 front到back)
};

void QueueList::Push(int x){

    if (IsEmpty()) { //代表此queue只有新增的點這一個點
        front = new QueueNode(x);
        back = front;
        size++;
        return;
    }

    QueueNode *newNode = new QueueNode(x);
    back->next = newNode;   // 讓back會指向自己
    back = newNode;         // update back pointer
    size++;
}

void QueueList::Pop(){

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    QueueNode *deletenode = front; //要刪除的會是front
    front = front->next;    // update front pointer
    delete deletenode;
    deletenode = 0;
    size--;
}

int QueueList::getFront(){

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return front->data;
}

int QueueList::getBack(){

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return back->data;
}

bool QueueList::IsEmpty(){

//    return (size == 0);
    return ((front && back) == 0);
}

int QueueList::getSize(){

    return size;
}

void QueueList::PrintList(){

    if (front == 0) {                      // 如果first node指向NULL, 表示list沒有資料
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "\ntotal data in queue:\n";
    QueueNode *current = front;             // 用pointer *current在list中移動
    while (current != 0) {                 // Traversal (逐一尋訪)
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout <<std::endl;
}

int main(){

    QueueList q;
    if (q.IsEmpty()) {
        std::cout << "Queue is empty.\n";
    }
    q.Push(24);
    std::cout<< "\nAfter push 24: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(8);
    std::cout<< "\nAfter push 8: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(23);
    std::cout<< "\nAfter push 23: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(13);
    std::cout<< "\nAfter push 13: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Push(35);
    std::cout<< "\nAfter push 35: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    
    q.PrintList();

    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout<< "\nAfter pop the front element: \n";
    q.Pop();

    system("pause");
    return 0;
}