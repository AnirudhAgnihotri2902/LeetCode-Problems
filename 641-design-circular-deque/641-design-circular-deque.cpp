struct Node {
     int val;
     Node *next;
     Node *prev; 
     Node() : val(0), next(nullptr), prev(nullptr) {}
     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 };
class MyCircularDeque {
public:
    Node *front = NULL, *rear = NULL;
    int  size, count = 0;
    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if(count == size)return false;
        Node *temp = new Node(value);
        if(count == 0){
            rear = temp;
            front  = temp;
            temp->next = rear;
            temp->prev = front;
            count++;
            return true;
        }
        rear->next = temp;
        temp->next = front;
        temp->prev = rear;
        front->prev = temp;
        front = temp;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(count == size)return false;
        Node *temp = new Node(value);
        if(count == 0){
            rear = temp;
            front  = temp;
            temp->next = rear;
            temp->prev = front;
            count++;
            return true;
        }
        temp->next = front;
        rear->next = temp;
        front->prev = temp;
        temp->prev = rear;
        rear = temp;
        count++;
        return true;
        
    }
    
    bool deleteFront() {
        if(!count)return false;
        if(count  == 1){
            front = NULL;
            rear = NULL;
            count--;
            return true;
        }
        Node* temp = front->next;
        temp->prev = rear;
        rear->next = temp;
        delete front;
        front = temp;
        count--;
        return true;
        
        
    }
    
    bool deleteLast() {
        if(!count)return false;
        if(count  == 1){
            front = NULL;
            rear = NULL;
            count--;
            return true;
        }
        Node * temp = rear->prev;
        temp->next = front;
        front->prev = temp;
        delete rear;
        rear = temp;
        count--;
        return true;
        
        
    }
    
    int getFront() {
        if(count == 0)return -1;
        return front->val;
    }
    
    int getRear() {
        if(count == 0)return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == size);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */