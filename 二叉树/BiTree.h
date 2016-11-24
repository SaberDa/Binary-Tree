//
//  BiTree.h
//  二叉树
//
//  Created by 李庚达 on 2016/11/11.
//  Copyright © 2016年 李庚达. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h

#include <stdio.h>

#define SIZE 128
#define MAX 1024

typedef char elemType;

//递归树定义
typedef struct BiTNode{
    elemType data;
    struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;

//顺序栈定义
typedef struct sqStack{
    BiTree data[SIZE];
    //为后序遍历准备
    int tag[SIZE];
    //数组下标
    int top;
}sqStack;

//队列的定义
typedef struct sqQueue{
    BiTree data[MAX];
    int front;
    int rear;
}sqQueue;

/**  递归先序遍历
 *
 * @param T BiTree
 *
 */
void preOrder(BiTree T);

/**  递归中序遍历
 *
 * @param T BiTree
 *
 */
void inOrder(BiTree T);

/**  递归后序遍历
 *
 * @param T BiTree
 *
 */
void postOrder(BiTree T);

/**  入栈
 *
 * @param S sqStack
 * @param T BiTree
 *
 */
void push(sqStack *S, BiTree T);

/**  出栈
 *
 * @param S sqStack
 *
 * @return BiTree BiTree
 *
 */
BiTree pop(sqStack *S);

/**  非递归前序遍历
 *
 * @param T BiTree
 *
 */
void preOrderDev(BiTree T);

/**  非递归中序遍历
 *   前者为带头结点，后者为无头结点
 *
 * @param T BiTree
 *
 */
void inOrderDev(BiTree T);
void NRInorderDev(BiTree T);

/**  非递归后序遍历
 *
 * @param T BiTree
 *
 */
void postOrderDev(BiTree T);

/**  进队
 *
 * @param Q sqQueue
 * @param T BiTree
 *
 */
void enterSqQueue(sqQueue *Q, BiTree T);

/**  出队
 *
 * @param Q sqQueue
 *
 * @return BiTree BiTree
 *
 */
BiTree delSqQueue(sqQueue *Q);

/**  层次遍历
 *
 * @param T BiTree
 *
 */
void levelOrder(BiTree T);

/**  按前序遍历的结果建树
 *
 * @param T BiTree
 *
 */
void createTreePreOrder(BiTree *T);

/**  按中序遍历的结果建树
 *
 * @param T BiTree
 *
 */
void createTreeInOrder(BiTree *T);

/**  按后序遍历的结果建树
 *
 * @param T BiTree
 *
 */
void createTreePostOrder(BiTree *T);

/**  二叉树的查找
 *
 * @param T BiTree
 * @param e elemType
 *
 * @return BiTree BiTree
 *
 */
BiTree searchTree(BiTree T, elemType e);

/**  统计结点个数
 *
 * @param T BiTree
 *
 * @return int int
 *
 */
int countOfBiTree(BiTree T);

/**  对两棵树进行比较
 *
 * @param T1 BiTree
 * @param T2 BiTree
 * 
 * @return int int
 *
 */
int judgeOfTwoBiTrees(BiTree T1, BiTree T2);

/**  求二叉树深度
 *
 * @param T BiTree
 *
 * @return int int
 *
 */
int depthOfBiTree(BiTree T);
#endif /* BiTree_h */
