#ifndef WEB_H
#define WEB_H

#include "Node.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Make a size function for each direction

template <typename T>
class Web {
  public:
    Web();
    ~Web();
    void addNode(T);			// adds a node to the web
    void displayContents();		// displays the elements in web
    void deleteNode(T);			// deletes a node at a given key
    int  getPos(int);  			// returns the key of a node
    int  getSize();				// returns size of web
  
  private:
    Node<T> *head;
    Node<T> *up; 	// last element up
    Node<T> *down;	// last element down
    Node<T> *left;	// last element left
    Node<T> *right;	// last element right
    int ctr;        // ctr keeps track of keys
    int size;		// the size of the web
    
};

template <typename T>
Web<T>::Web(){
  head = 0;
  ctr = 0;
  size = 0;
}

template <typename T>
Web<T>::~Web(){
}

/* Adds a new node to the web
   to the specific brach depending
   on key value. Treats each 
   branch as a stack. Ie: adds
   at the front but keeps track 
   of the last element in each
   branch for quick access */
template <typename T>
void Web<T>::addNode(T data){
  Node<T> *node = new Node<T>(data);
  Node<T> *curr, *prev;

  int var = 0;
  curr = head;
  if(head == 0){
    head = node;
    head -> key = size;
    size++;
  } else {
    int num = node -> getData();
    num = num%2;
    if(num == 0) {
      num = (data/2)%2;
      if(num == 1){
        if(curr -> left != 0){
          curr -> left -> right = node;
          node -> left = curr -> left;
          curr -> left = node;
          node -> right = curr;
        } else {
          curr -> left = node;
          node -> right = curr;
          left = node;
        }
        node -> key = size;
        //cout << node -> key << "~" << node -> getData() << "left|";
      } else {
        if(curr -> right != 0){
          curr -> right -> left = node;
          node -> right = curr -> right;
          curr -> right = node;
          node -> left = curr;
        } else {
          curr -> right = node;
          node -> left = curr;
          right = node;
        }
        node -> key = size;
        //cout << node -> key << "~" << node -> getData() << "right|";
      }
    } else if(num == 1) {
      num = ((data-3)/2)%2;
      if(num == 0){
        if(curr -> up != 0){
          curr -> up -> down = node;
          node -> up = curr -> up;
          curr -> up = node;
          node -> down = curr;
        } else {
          curr -> up = node;
          node -> down = curr;
          up = node;
        }
        node -> key = size;
        //cout << node -> key << "~" << node -> getData() << "up|";
      } else {
        if(curr -> down != 0){
          curr -> down -> up = node;
          node -> down = curr -> down;
          curr -> down = node;
          node -> up = curr;
        } else {
          curr -> down = node;
          node -> up = curr;
          down = node;
        }
        node -> key = size;
        //cout << node -> key << "~" << node -> getData() << "down|";
      }
    }
    size++;
  }
}

template <typename T>
void Web<T>::displayContents(){
  Node<T> *curr;
  curr = head;
  int hd = head -> getData();
  int hdk = head -> key;
  int count = 0;
  if(head == 0){
    cout << "-----Empty Web-----" << endl;
  } else {
    Node<T> *left = new Node<T>();
    Node<T> *right = new Node<T>();
    Node<T> *up = new Node<T>();
    Node<T> *down = new Node<T>();
    Node<T> *tmp = new Node<T>();
    cout << std::left;
    cout << setw(75) 
    << "-------------------------- Web Contents --------------------------" << endl;
    cout 
    << setw(15) << "Head"
    << setw(15) << "Left" 
    << setw(15) << "Right"
    << setw(15) << "Up" 
    << setw(15) << "Down"
    << endl;
    
    if(curr -> left != 0){
      left = curr -> left;
    }
    if(curr -> right != 0){
      right = curr -> right;
    } 
    if(curr -> up != 0){
      up = curr -> up;
    } 
    if(curr -> down != 0){
      down = curr -> down;
    }
    
    while(count < size) {      
      cout << std::left ;
      cout
      << setw(15)
      << (hdk == -1 ? "" : ("[" + to_string(hdk) + ":" + to_string(hd)+"]"))
      << setw(15)
      << ((left -> getData() == -1) ? "" : ("[" + to_string(left->key) + ":" + to_string(left -> getData())+"]")) 
      << setw(15)
      << ((right -> getData() == -1) ? "" : ("[" + to_string(right->key) + ":" + to_string(right -> getData())+"]"))
      << setw(15)
      << ((up -> getData() == -1) ? "" : ("[" + to_string(up->key) + ":" + to_string(up -> getData())+"]"))
      << setw(15)
      << ((down -> getData() == -1) ? "" : ("[" + to_string(down->key) + ":" + to_string(down -> getData())+"]"))
      << endl;
      if(left -> left == 0 && right -> right == 0 && up -> up == 0 && down -> down == 0){
        break;
      }
      if(left -> left != 0){
        left -> setData(left -> left -> getData(), left -> left -> key);
      } else {
        left -> setData(-1,0);
      }
      
      if(right -> right != 0){
        right -> setData(right -> right -> getData(), right -> right -> key);
      } else {
        right -> setData(-1,0);
      }
      
      if(up -> up != 0){
        up -> setData(up -> up -> getData(), up -> up -> key);
      } else {
        up -> setData(-1,0);
      }
      
      if(down -> down != 0){
        down -> setData(down -> down -> getData(), down -> down -> key);
      } else {
        down -> setData(-1,0);
      }
      
      if(left -> left != 0){
        left = left -> left;
      }
      if(right -> right != 0){
        right = right -> right;
      }
      if(up -> up != 0){
        up = up -> up;
      }
      if(down -> down != 0){
        down = down -> down;
      }
      hdk = -1;
      count ++;
    }
  }
}

template <typename T>
int Web<T>::getPos(int val){
  if(head == 0){
    cout << "-----Web is Empty-----" << endl;
  } else {
    int ctr = 0;
    Node<T> *tmp;
    Node<T> *curr = head;
      int num = val;
      num = num%2;
      if(num == 0) {
        num = (val/2)%2;
        tmp = curr;
        if(num == 1){
          while(tmp != 0) {
            if(tmp -> getData() == val){
              //cout << "[" << tmp -> key <<  "]--" << endl;
              break;
            }
            tmp = tmp -> left;
          }
        } else {
          while(tmp != 0) {
            if(tmp -> getData() == val){
              //cout << "--[" << tmp -> key <<  "]" << endl;
              break;
            }
            tmp = tmp -> right;
          }
        }
      } else if(num == 1) {
        num = ((val-3)/2)%2;
        tmp = curr;
        if(num == 0){
          while(tmp != 0) {
            if(tmp -> getData() == val){
              //cout << "[" << tmp -> key <<  "]" << endl;
              //cout << " | " << endl;
              break;
            }
            tmp = tmp -> up;
          }
        } else {
          while(tmp != 0) {
            if(tmp -> getData() == val){
              //cout << " | " << endl;
              //cout << "[" << tmp -> key <<  "]" << endl;
              break;
            }
            tmp = tmp -> down;
          }
        }
      }
    if(tmp != 0){
      return tmp -> key;
    }
  }
  return -1;
}

template <typename T>
void Web<T>::deleteNode(T){
}

template <typename T>
int Web<T>::getSize(){
  return size;
}

#endif