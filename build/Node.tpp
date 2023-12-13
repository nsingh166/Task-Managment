// node.tpp

template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
void Node<T>::setNext(Node<T>* nextNode){
    next=nextNode;
}
template <typename T>
void Node<T>::setPrev(Node<T>* prevNode){
    prev=prevNode;
}