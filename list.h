#include<iostream>
using namespace std;

class List;

class Node{
    int data;
    
public:
    Node* next;
    
    Node(int d):data(d),next(NULL){}
    
    int get_data(){
        return data;
    }
    
    ~Node(){
        if(next!=NULL){
            delete next;
        }
        cout << "Deleting Node with data" << data << endl;
    }
    
    friend class List;
};

class List{
    Node* head;
    Node* tail;
    
    int searchHelper(Node* start, int key){
        //base case
        if (start==NULL){
            return -1;
        }
        //value matches
        if(start->data==key){
            return 0;
        }
        //remaining part of linked List
        int sub_idx = searchHelper(start->next,key);
        if(sub_idx==-1){
            return -1;
        }
        return sub_idx + 1;
        
    }
    
public:
    List():head(NULL), tail(NULL){}
    
    Node* begin(){
        return head;
    }
    
    //Insert element at the beginning
    void push_front(int data){
        if(head==NULL){
            Node* n = new Node(data);
            head = tail = n;
        }
        else{
            Node* n = new Node(data);
            n->next = head;
            head = n;
        }
    }
    
    //Insert element at the end
    void push_back(int data){
        if(head==NULL){
            Node* n = new Node(data);
            head = tail = n;
        }
        else{
            Node* n = new Node(data);
            tail->next = n;
            tail = n;
            
        }
    }
    
    //Insert element in the middle fo the list
    void insert(int data, int pos){
        if(pos==0){
            push_front(data);
            return;
        }
        //Otherwise
        Node* temp = head;
        
        for(int jump=1;jump<=pos-1;jump++){
            temp = temp->next;
        }
        
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
        
    }
    
    //Search function
    int search(Node* head, int key){
        Node* temp = head;
        int idx=0;
        
        while(temp!=NULL){
            if(temp->data == key){
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }
    
    //Recursive search function
    
    bool rec_search(Node* head, int key){
        if(head==NULL){
            return false;
        }
        
        if(head->data == key){
            return true;
        }
        else{
            return rec_search(head->next, key);
        }
        return -1;
    }
    
    //Recursive search returns index
    
    int recursive_search(int key){
        int idx = searchHelper(head, key);
        return idx;
    }
    
    //Function for removing node from head
    
    void pop_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    //Function for removing node from tail
    
    void pop_back(){
        Node* temp = head;
        
        while(temp->next!=tail){
            temp = temp->next;
        }
        
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    void remove_node(int pos){
        Node* temp = head;
        
        for(int idx=0; idx<pos-1; idx++){
            temp = temp->next; 
        }
        
        Node* n = temp->next;
        temp->next = n->next;
        n->next = NULL;
        delete n;
    }
    
    void reverse_list(){
        Node* C = head;
        Node* P = NULL;
        Node* N;
        
        while(C!=NULL){
            N = C->next;
            C->next = P;
            P = C;
            C = N;
        }
        
        head = P;
        return;
    }
    
    ~List(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }
    
};