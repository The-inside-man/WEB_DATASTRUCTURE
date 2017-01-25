#ifndef NODE_H
#define NODE_H

template <typename T>
class Web;

template <typename T>
class Node {
  friend class Web<T>;
  
  public:
    Node(T);
    Node();
    T getData();
    void setData(T,int);
    int key;
    
  private:
    T data;
    Node *up;
    Node *down;
    Node *left;
    Node *right;
};

template <typename T>
Node<T>::Node(){
  data = -1;
  up = 0;
  down = 0;
  left = 0;
  right = 0;
  key = 0;
}

template <typename T>
Node<T>::Node(T dat){
  data = dat;
  up = 0;
  down = 0;
  left = 0;
  right = 0;
}

template <typename T>
T Node<T>::getData(){
  return data;
}

template <typename T>
void Node<T>::setData(T dat,int k){
  data = dat;
  key = k;
}

#endif