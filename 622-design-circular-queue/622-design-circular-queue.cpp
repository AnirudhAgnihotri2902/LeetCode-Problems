struct Node {
     int val;
     Node *next;
     Node *prev; 
     Node() : val(0), next(nullptr), prev(nullptr) {}
     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 };
class MyCircularQueue {
public:
    Node *front = NULL, *rear = NULL;
    int size , count;
    MyCircularQueue(int k) {
        size = k;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(size == count)return false;
        Node *temp = new Node(value);
        if(count == 0){
             rear = temp;
            front  = temp;
            count++;
            return true;
        }
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count==0)return false;
        if(count  == 1){
            front = NULL;
            rear = NULL;
            count--;
            return true;
        }
        front = front->next;
        front->prev = NULL;
        count--;
        return true;
        
        
    }
    
    int Front() {
        if(!front)return -1;
        return front->val;
    }
    
    int Rear() {
        if(!rear)return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return (count==0);
    }
    
    bool isFull() {
        return (count==size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */