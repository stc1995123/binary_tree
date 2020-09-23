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
	BSTNode* _parent; // ˫��
	//BSTNode(T key, BSTNode* lchild, BSTNode* rchild, BSTNode* parent);
    BSTNode(T key, BSTNode* lchild, BSTNode* rchild, BSTNode* parent) :
        _key(key), _lchild(lchild), _rchild(rchild), _parent(parent) {};
};//
template<typename T>
class BSTree {
private:
    BSTNode<T> *_Root;  //�����

public:
    BSTree() :_Root(nullptr) {};
    ~BSTree() {};


    void insert(T key);//�������Ĳ���

    BSTNode<T>* search(T key);//�������Ĳ���

    void preOrder();  //�������
    void inOrder();   //�������
    void postOrder(); //�������

    BSTNode<T>* minimumNode();//������С�Ľڵ�
    BSTNode<T>* maximumNode();//�������Ľڵ�

    T minimumKey();//������С�ļ�ֵ
    T maximumKey();//������С�ļ�ֵ

    void print();//��ӡ������
    void remove(T key);

    BSTNode<T>* predecessor(BSTNode<T>* x);//����ĳ������ǰ��
    BSTNode<T>* sucessor(BSTNode<T>* x); //����ĳ�����ĺ��

    void destory();

    //�ڲ�ʹ�ú��������ⲿ�ӿڵ���
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
    //Ѱ�Ҳ����
    while (temp != nullptr)
    {
        parent = temp;

        if (z->_key > temp->_key)
            temp = temp->_rchild;
        else
            temp = temp->_lchild;
    }
    z->_parent = parent;

    if (parent == nullptr) //������������ǿ�������ֱ�Ӱ�z�ڵ������ڵ�
        tree = z;
    else if (z->_key > parent->_key) //���z��ֵ������˫�ף���zΪ��˫�׵��Һ�
        parent->_rchild = z;
    else
        parent->_lchild = z;

}
template <typename T>
void BSTree<T> ::insert(T key)
{
    //����һ���µĽڵ㣬ʹ�ù��캯����ʼ��
    BSTNode<T>* z = new BSTNode<T>(key, nullptr, nullptr, nullptr);
    if (!z) //�������ʧ���򷵻�
        return;
    //�����ڲ��������в���
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
*�ӿ�
*
*/
template<typename T>
void BSTree<T>::inOrder()
{
    inOrder(_Root);
}