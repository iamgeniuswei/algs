//
// Created by developer on 19-10-15.
//

#ifndef ALGS_BSTNODE_H
#define ALGS_BSTNODE_H

#include <algorithm>

/**
 * 二叉树的节点定义
 * 假定只有一个节点时，该节点为根节点，不为叶节点
 * */
class BSTNode {
    friend class BinarySearchTree;
private:
    BSTNode *left_ = nullptr;
    BSTNode *right_ = nullptr;
    BSTNode *parent_ = nullptr;
    int data_ = 0;
    int height_ = 0;
public:
    void setHeight(int height)
    {
        height_ = height;
    }

    static int stature(BSTNode *node = nullptr)
    {
        return node != nullptr ? node->getHeight() : -1;
    }

    virtual int updateHeight()
    {
        return height_ = 1 + std::max(stature(left_), stature(right_));
    }

public:
    int getHeight() const
    {
        return height_;
    }

public:
    BSTNode(){}
    BSTNode(int data,
            BSTNode *parent = nullptr,
            BSTNode *lc = nullptr,
            BSTNode *rc = nullptr)
            :data_(data), parent_(parent),
            left_(lc), right_(rc)
            {}

    BSTNode *getLeft() const
    {
        return left_;
    }

    void setLeft(BSTNode *left)
    {
        left_ = left;
    }

    BSTNode *getRight() const
    {
        return right_;
    }

    void setRight(BSTNode *right)
    {
        right_ = right;
    }

    BSTNode *getParent() const
    {
        return parent_;
    }

    void setParent(BSTNode *parent)
    {
        parent_ = parent;
    }

    int getData() const
    {
        return data_;
    }

    void setData(int data)
    {
        data_ = data;
    }

public:
    bool isRoot(){
        return parent_ == nullptr;
    }
    bool isLChild(){
        return (!isRoot() && (this == parent_->left_));
    }
    bool isRChild(){
        return (!isRoot() && (this == parent_->right_));
    }
    bool hasParent(){
        return !isRoot();
    }
    bool hasLChild(){
        return left_ != nullptr;
    }
    bool hasRChild(){
        return right_ != nullptr;
    }
    bool hasChild(){
        return hasLChild() || hasRChild();
    }
    bool hasBothChild(){
        return hasLChild() && hasRChild();
    }
    bool isLeaf(){
        return !hasChild() && !isRoot();
    }
    BSTNode* sibling()
    {
        if(parent_)
            return isLChild() ? parent_->right_ : parent_->left_;
        else
            return nullptr;
    }

    BSTNode* uncle()
    {
        if(parent_)
        {
            if(parent_->isRoot())
                return nullptr;
            return parent_->isLChild() ? parent_->parent_->right_ : parent_->parent_->left_;
        } else
            return nullptr;
    }

    BSTNode* insertAsLC(int data)
    {
        BSTNode* node = new BSTNode(data, this);
        return left_ = node;
    }

    BSTNode*insertAsRC(int data)
    {
        BSTNode* node = new BSTNode(data, this);
        return right_ = node;
    }

    /**
     * 节点的中序遍历后继节点查找
     * 情况一：若该节点有右孩子，则后继节点必在右子树中：
     * 1）若右子树无左孩子，则该右子树根节点即为该节点后继节点
     * 2）若右子树有左孩子，则最靠左的左孩子即为该节点的后继节点
     *     X
     *      \
     *       X
     *      /
     *    SUCC
     * 情况二：若该节点无右孩子，则后继节点必为将该节点包含在其左子树中的最低祖先
     * 则判断该节点是否为右孩子，若是则沿父链而上，直到其为左孩子
     *      SUCC
     *       /
     *      X
     *      \
     *       X
     *        \
     *         X
     * */
    BSTNode* succOfInOrder()
    {
        BSTNode *succ = this;
        if(right_)
        {
            succ = right_;
            if(succ->left_)
                succ = succ->left_;
        } else
        {
            if(succ->isRChild())
                succ = succ->parent_;
            succ = succ->parent_;
        }
        return succ;
    }

};


#endif //ALGS_BSTNODE_H
