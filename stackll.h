
template<typename T>
class stack;

template<typename T>
class node{
public:
    T data;
    node<T> *next;
    
    node(T d){
        data = d;
        next = NULL;
    }
};

template<typename T>
class stack{

    node<T> *head;
public:
    
    stack(){
        head = NULL;
    }
    
    void push(T data){
        node<T> * n = new node<T>(data);
        n->next = head;
        head = n;
    }
    
    bool empty(){
        return head==NULL;
    }
    
    T top(){
        return head->data;
    }
    
    void pop(){
        if(head!=NULL){
            node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

};