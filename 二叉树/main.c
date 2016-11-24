//
//  main.c
//  二叉树
//
//  Created by 李庚达 on 2016/11/11.
//  Copyright © 2016年 李庚达. All rights reserved.
//

#include "BiTree.h"

void create(BiTree T) {
    char ch;
    scanf("%c",&ch);
    if (ch == '.') T = NULL;
    else {
        T = (BiTree)malloc(sizeof(BiTNode));
        (*T).data = ch;
        create((*T).lChild);
        create((*T).rChild);
    }
}


int main1(int argc, const char * argv[]) {
    // insert code here...
    BiTree *T;
    create(*T);
    //createTreePreOrder(&T);
    inOrderDev(*T);
    return 0;
}

