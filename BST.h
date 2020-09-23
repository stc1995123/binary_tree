#pragma once
#include<iostream>
using namespace std;
//#include"BST.cpp"
template<typename T>
class BSTNode {
public:
	T _key;
	BSTNode* _lchild;
	BSTNode* _rchild;
	BSTNode* _parent; // 双亲
	//BSTNode(T key, BSTNode* lchild, BSTNode* rchild, BSTNode* parent);
    BSTNode(T key, BSTNode* lchild, BSTNode* rchild, BSTNode* parent) :
        _key(key), _lchild(lchild), _rchild(rchild), _parent(parent) {};
};//
template<typename T>
class BSTree {
private:
    BSTNode<T> *_Root;  //根结点

public:
    BSTree() :_Root(nullptr) {};
    ~BSTree() {};


    void insert(T key);//二叉树的插入

    BSTNode<T>* search(T key);//二叉树的查找

    void preOrder();  //先序输出
    void inOrder();   //中序输出
    void postOrder(); //后序输出

    BSTNode<T>* minimumNode();//查找最小的节点
    BSTNode<T>* maximumNode();//查找最大的节点

    T minimumKey();//查找最小的键值
    T maximumKey();//查找最小的键值

    void print();//打印二叉树
    void remove(T key);

    BSTNode<T>* predecessor(BSTNode<T>* x);//查找某个结点的前驱
    BSTNode<T>* sucessor(BSTNode<T>* x); //查找某个结点的后继

    void destory();

    //内部使用函数，供外部接口调用
private:
    void insert(BSTNode<T> *& tree, BSTNode<T> * z);
    BSTNode<T>* search(BSTNode<T>*& tree, T key) const;
    void preOrder(BSTNode<T>*& tree) const;
    void inOrder(BSTNode<T>*& tree) const;
    void postOrder(BSTNode<T>*& tree) const;
    BSTNode<T>* minimumNode(BSTNode<T>*& tree);
    BSTNode<T>* maximumNode(BSTNode<T>*& tree);
    void print(BSTNode<T>*& tree);
    BSTNode<T>* remove(BSTNode<T>*& tree, BSTNode<T>* z);
    void destory(BSTNode<T>*& tree);
};


template<typename T>
void BSTree<T>::insert(BSTNode<T>*& tree, BSTNode<T>* z) {
    BSTNode<T>* parent = nullptr;
    BSTNode<T>* temp = tree;
    //寻找插入点
    while (temp != nullptr)
    {
        parent = temp;

        if (z->_key > temp->_key)
            temp = temp->_rchild;
        else
            temp = temp->_lchild;
    }
    z->_parent = parent;

    if (parent == nullptr) //如果树本来就是空树，则直接把z节点插入根节点
        tree = z;
    else if (z->_key > parent->_key) //如果z的值大于其双亲，则z为其双亲的右孩
        parent->_rchild = z;
    else
        parent->_lchild = z;

}
template <typename T>
void BSTree<T> ::insert(T key)
{
    //创建一个新的节点，使用构造函数初始化
    BSTNode<T>* z = new BSTNode<T>(key, nullptr, nullptr, nullptr);
    if (!z) //如果创建失败则返回
        return;
    //调用内部函数进行插入
    insert(_Root, z);
}

template<typename T>
inline void BSTree<T>::preOrder(BSTNode<T>*& tree) const
{
    if (!tree)return;
    cout << tree->_key << " ";
    preOrder(tree->_lchild);
    preOrder(tree->_rchild);
}

template <typename T>
void BSTree<T>::inOrder(BSTNode<T>*& tree) const
{
    if (tree)
    {
        inOrder(tree->_lchild);
        cout << tree->_key << " ";
        inOrder(tree->_rchild);
    }
}

template<typename T>
inline void BSTree<T>::preOrder()
{
    preOrder(_Root);
}

/*
*
*接口
*
*/
template<typename T>
void BSTree<T>::inOrder()
{
    inOrder(_Root);
}