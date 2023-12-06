// node.tpp

template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
