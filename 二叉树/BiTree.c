//
//  BiTree.c
//  二叉树
//
//  Created by 李庚达 on 2016/11/11.
//  Copyright © 2016年 李庚达. All rights reserved.
//

#include "BiTree.h"

void preOrder(BiTree T) {
    if (T) {
        printf("%c\t", T -> data);
        preOrder(T -> lChild);
        preOrder(T -> rChild);
    }
}

void inOrder(BiTree T) {
    if (T) {
        inOrder(T -> lChild);
        printf("%c\t", T -> data);
        inOrder(T -> rChild);
    }
}

void postOrder(BiTree T) {
    if (T) {
        postOrder(T -> lChild);
        postOrder(T -> rChild);
        printf("%c\t", T -> data);
    }
}

void push(sqStack *S, BiTree T) {
    if (S->top == SIZE) {
        printf("栈满\n");
    }else {
        S->top++;
        S->data[S->top] = T;
    }
}

BiTree pop(sqStack *S) {
    if (S->top == -1) {
        return NULL;
    }else {
        S->top++;
        return S->data[S->top+1];
    }
}

void preOrderDev(BiTree T) {
    sqStack S;
    //因为top在这里表示了数组中的位置，所以空为-1
    S.top = -1;
    if (!T) {
        printf("ERROR\n");
    }else {
        while (S.top != -1 || T) {
            while (T) {
                //只要结点不为空就应该入栈保存，与其左右结点无关
                printf("%c\n", T -> data);
                push(&S, T);
                T = T -> lChild;
            }
            T = pop(&S);
            T = T -> rChild;
        }
    }
}

void inOrderDev(BiTree T) {
    sqStack S;
    BiTree p = T;
    S.top = -1;
    if (!p) {
        printf("ERROR\n");
    }else {
        while (S.top != -1 || p) {
            if (p != NULL) {
                //根指针进栈，遍历左子树
                push(&S, p);
                p = p -> lChild;
            }else {
                //根指针出栈，访问根节点，遍历右子树
                pop(&S);
                printf("%c", p -> data);
                p = p ->rChild;
            }
        }
    }
}

void NRInorderDev(BiTree T) {
    //没有头结点
    BiTree stack[SIZE], p;
    int top = 0;
    p = T;
    if (T == NULL) {
        return;
    }
    while (!(p == NULL && top == 0)) {
        while (p != NULL) {
            if (top < SIZE - 1) {
                stack[top++] = p;
            }else {
                printf("溢出\n");
                return;
            }
            p = p -> lChild;
        }
        if (top < 0) {
            //栈空时结束
            return;
        }else {
            //从栈中推出栈顶元素
            p = stack[top--];
            //访问结点的数据域
            printf("%c\n", p -> data);
            p = p -> rChild;
        }
    }
}

void postOrderDev(BiTree T) {
    sqStack S;
    S.top = -1;
    BiTree p;
    p = T;
    if (!T) {
        printf("tree is empty\n");
        return;
    }else {
        while (S.top != -1 || p) {
            //栈空了的同时t也为空
            while (p) {
                push(&S, p);
                //设置访问标记，0为第一次访问，1为第二次访问
                S.tag[S.top] = 0;
                p = p -> lChild;
            }
            if (S.tag[S.top] == 0) {
                //第一次访问时，转向同层右孩子
                //左走到底时t是为空的，必须有这步
                p = S.data[S.top];
                S.tag[S.top] = 1;
                p = p -> rChild;
            }else {
                while (S.tag[S.top] == 1) {
                    //找到栈中下一个第一次访问的结点，退出循环时并没有pop所以为其左子结点
                    p = pop(&S);
                    printf("%c\n", p -> data);
                }
                //必须将t置空。跳过向左走，直接向右走
                p = NULL;
            }
        }
    }
}

void enterSqQueue(sqQueue *Q, BiTree T) {
    if (Q -> rear == MAX) {
        printf("queue is full\n");
        return;
    }else {
        Q -> data[Q -> rear] = T;
        Q -> rear++;
    }
}

BiTree delSqQueue(sqQueue *Q) {
    if (Q -> front == Q -> rear) {
        printf("queue is empty\n");
        return NULL;
    }else {
        Q -> front++;
        return Q -> data[Q -> front - 1];
    }
}

void levelOrder(BiTree T) {
    sqQueue Q;
    BiTree p;
    p = T;
    Q.front = 0;
    Q.rear = 0;
    if (!T) {
        printf("tree is empty\n");
        return;
    }else {
        enterSqQueue(&Q, p);
        while (Q.rear != Q.front) {
            p = delSqQueue(&Q);
            printf("%c\n", p -> data);
            if (p -> lChild) {
                enterSqQueue(&Q, p -> lChild);
            }
            if (p -> rChild) {
                enterSqQueue(&Q, p -> rChild);
            }
        }
    }
}

void createTreePreOrder(BiTree *T) {
    //递归调用，不存点，想的时候只关注于一个点，因为还会回来的，不要跟踪程序运行，否则容易多加循环
    elemType e;
    if ((e = getchar()) == '#') {
        *T = NULL;
    }else {
        T = (BiTree)malloc(sizeof(BiTNode));
        (*T) -> data = e;
        createTreePreOrder(&(*T) -> lChild);
        createTreePreOrder(&(*T) -> rChild);
    }
}

void createTreeInOrder(BiTree *T) {
    //递归调用，不存点，想的时候只关注于一个点，因为还会回来的，不要跟踪程序运行，否则容易多加循环
    elemType e;
    if ((e = getchar()) == '#') {
        *T = NULL;
    }else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        createTreeInOrder(&(*T) -> lChild);
        (*T) -> data = e;
        createTreeInOrder(&(*T) -> rChild);
    }
}

void createTreePostOrder(BiTree *T) {
    //递归调用，不存点，想的时候只关注于一个点，因为还会回来的，不要跟踪程序运行，否则容易多加循环
    elemType e;
    if ((e = getchar()) == '#') {
        *T = NULL;
    }else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        createTreePostOrder(&(*T) -> lChild);
        createTreePostOrder(&(*T) -> rChild);
        (*T) -> data = e;
    }
}

BiTree searchTree(BiTree T, elemType e) {
    BiTree p;
    p = T;
    if (!T) {
        printf("tree is empty\n");
        return NULL;
    }
    if (p -> data == e) {
        return p;
    }else {
        if (!searchTree(p -> lChild, e)) {
            searchTree(p -> rChild, e);
        }
        return p;
    }
}

int countOfBiTree(BiTree T) {
    BiTree p;
    p = T;
    if (!T) {
        printf("tree is empty\n");
        return -1;
    }else {
        return (countOfBiTree(p -> lChild) + countOfBiTree(p -> rChild));
    }
    return 0;
}

int judgeOfTwoBiTrees(BiTree T1, BiTree T2) {
    BiTree p1, p2;
    p1 = T1;
    p2 = T2;
    if (!T1 && !T2) {
        //两树都为空时，相等
        return 1;
    }
    if (p1 && p2 && (p1 -> data == p2 -> data)) {
        //有一个为空或者数据不等，就不相等
        if (judgeOfTwoBiTrees(p1 -> lChild, p2 -> lChild)) {
            if (judgeOfTwoBiTrees(p1 -> rChild, p2 -> rChild)) {
                return 1;
            }
        }
    }
    return 0;
}

int depthOfBiTree(BiTree T) {
    int depth, leftDepth, rightDepth;
    BiTree p;
    p = T;
    if (!T) {
        printf("tree is empty\n");
        return 0;
    }
    leftDepth = depthOfBiTree(p -> lChild);
    rightDepth = depthOfBiTree(p -> rChild);
    //取左右子树中较大的值再+1(根节点)
    depth = (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    return depth;
}
