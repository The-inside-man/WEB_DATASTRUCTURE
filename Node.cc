#ifndef NODE_H
#define NODE_H

template <typename T>
class Web;

template <typename T>
class Node {
  friend class Web<T>;
  
  public:
    Node();
    T *getData();
    
  private:
    T *data;
    int Key;
    Node *up;
    Node *down;
    Node *left;
    Node *right;
};

template <typename T>
Node<T>::Node(){
}

template <typename T>
Node<T>::getData(){
  return data;
}

#endif