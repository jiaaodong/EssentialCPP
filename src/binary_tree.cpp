/* Implement a binary tree, in order to learn how to program with template*/
#include<iostream>
#include<algorithm>

template <typename valType>
class BTnode
{
    friend class BinaryTree<valTYpe>; 
private:
    /* data */
    valType _val;
    int _cnt;
    BTnode* _lchild;
    BTnode* _rchild;

public:
    BTnode(/* args */);
    ~BTnode();
};

template <typename elemTYpe>
class BinaryTree{
    public: 
    //
    BinaryTree(); // default constructor
    BinaryTree(const BinaryTree&); // copy constructor
    ~BinaryTree(); 
    BinaryTree& operator=(const BinaryTree&);

    bool empty();
    void clear();
    private:
    BTnode<elemTYpe> *_root;
    void copy(BTnode<elemTYpe> * tar, BTnode<elemTYpe> * src); 
};

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree():_root(0){}

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs){
    copy(_root, rhs._root);
}

template<typename elemType>
inline BinaryTree<elemType>::~BinaryTree(){
    clear();
}


template<typename elemType>
inline bool BinaryTree<elemType>::empty(){
    //
}


template<typename elemType>
inline void BinaryTree<elemType>::copy(BTnode<elemType>* tar, BTnode<elemType>* src){
    //
}

template<typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::operator=(const BinaryTree &rhs){
    if(this!= &rhs){
        clear(); copy(_root, rhs._root);
        return *this;
    }
}

template<typename elemType>
inline void BinaryTree<elemType>::clear(){
    //
}



