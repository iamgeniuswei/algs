//
// Created by developer on 2019/9/9.
//

#ifndef ALGS_BINARYSEARCHTREE_H
#define ALGS_BINARYSEARCHTREE_H

#include "BSTNode.h"
#include <stack>
#include <vector>
using namespace std;
typedef void (*visit)(int data, vector<int> &v);


class BinarySearchTree {
private:
    int _size= 0;
    BSTNode* _root = nullptr;
public:
    int getSize() const
    {
        return _size;
    }

    BSTNode *getRoot() const
    {
        return _root;
    }



    void updateHeightAbove(BSTNode *node)
    {
        while (node)
        {
            node->updateHeight();
            node = node->getParent();
        }
    }

    BSTNode* insertAsRoot(int data)
    {
        _size = 1;
        return _root = new BSTNode(data);
    }

    BSTNode* insertAsLC(BSTNode *x, int data)
    {
        if(x)
        {
            x->insertAsLC(data);
            _size++;
            updateHeightAbove(x);
            return x->left_;
        }
        return nullptr;
    }

    BSTNode* insertAsRC(BSTNode *x, int data)
    {
        if(x)
        {
            x->insertAsRC(data);
            _size++;
            updateHeightAbove(x);
            return x->right_;
        }
        return nullptr;
    }

    /**
     * 树的先序遍历算法1：
     * 1）将根节点压入栈
     * 2）如果栈不空，弹出栈顶节点，访问之
     * 3）如果栈顶节点有右孩子，压入栈；如果有左孩子，压入栈；
     * 4）重复步骤2）
     * */
    void traversePre_I1(BSTNode *x, vector<int> &v)
    {
        stack<BSTNode*> s;
        if(x == nullptr)
            return;
        s.push(x);
        while (!s.empty())
        {
            BSTNode *top = s.top();
            s.pop();
            v.push_back(top->data_);
            if(top->right_)
                s.push(top->right_);
            if(top->left_)
                s.push(top->left_);
        }
    }
    /**
     * 树的中序遍历算法1：
     * 1）开始循环
     * 2）如果起始节点不为空，将起始节点压入栈，更新起始节点为其左孩子；
     * 3）起始节点为空，如果栈为空，退出；
     * 4）起始节点为空，如果栈非空，弹出栈顶节点，访问之，更新起始节点为栈顶节点右孩子；
     * 5）重复步骤2）
     * */
    void traverseIn_I1(BSTNode *x, vector<int> &v)
    {
        stack<BSTNode*> s;
        while (true)
        {
            if(x)
            {
                s.push(x);
                x=x->left_;
            } else if(s.empty())
            {
                break;
            } else
            {
                BSTNode *top = s.top();
                s.pop();
                v.push_back(top->data_);
                x = top->right_;
            }
        }
    }

    /**
     * 树的中序遍历算法2：
     * 1)进入循环
     * 2）当回溯标识为假，且当前节点有左孩子，将当前节点更新为其左孩子；
     * 3）否则，访问当前节点，
     * 4）若当前节点有右孩子，将当前节点更新为其右孩子，设置回溯为假，重复步骤2）；
     * 4）若没有右孩子，寻找当前节点的后继节点，
     * 5）若后继节点为空，跳出循环，结束
     * 6）若后继节点不为空，设置回溯标识为真，重复步骤2）
     * */
    void traverseIn_I2(BSTNode *x, vector<int> &v)
    {
        bool backTrace = false;
        while (true)
        {
            if(!backTrace && x->left_ != nullptr)
            {
                x = x->left_;
            } else
            {
                v.push_back(x->data_);
                if(x->right_ != nullptr)
                {
                    x = x->right_;
                    backTrace = false;
                }
                else
                {
                    x = x->succOfInOrder();
                    if(x == nullptr)
                        break;
                    else
                        backTrace = true;
                }
            }
        }
    }


    /**
     * 后序遍历迭代算法
     * 1）创建辅助栈，将起始节点入栈
     * 2）若栈不空，执行3）
     * 3）检查栈顶节点，若为空，弹出栈顶节点，执行4），否则：
     * 3.1）若有左孩子，检查是否有右孩子，若有，先将右孩子入栈，再将左孩子入栈，
     * 3.2）若无，将左孩子入栈；
     * 3.3）若无左孩子，若将右孩子入栈；
     * 4）访问栈顶节点，
     * 5）重复执行2）。
     * */
    void traversePost_I1(BSTNode *x, vector<int> &v)
    {
        stack<BSTNode*> s;
        s.push(x);
        while (!s.empty())
        {
            [&]()
            {
                while(true)
                {
                    BSTNode *top = s.top();
                    if(top == nullptr)
                    {
                        s.pop();
                        break;
                    }
                    if(top->left_)
                    {
                        if(top->right_)
                            s.push(top->right_);
                        s.push(top->left_);
                    } else
                    {
                        s.push(top->right_);
                    }
                }
            };
            BSTNode *top = s.top();
            v.push_back(top->data_);
            s.pop();
        }

    }




};


#endif //ALGS_BINARYSEARCHTREE_H
