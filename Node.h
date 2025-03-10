#ifndef NODE_H
#define NODE_H
template <typename T>

class Node{
    private:
        T data;
        Node<T>* next;
    public:
        Node(T data);
        void setData(T data);
        T getData();
        void setNext(Node<T>* next);
        Node<T>* getNext();
};
template <typename T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr;
}
template <typename T>
void Node<T>::setData(T data){
    this->data = data;
}
template <typename T>
T Node<T>::getData(){
    return data;
}
template <typename T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}
template <typename T>
Node<T>* Node<T>::getNext(){
    return next;
}
#endif 
