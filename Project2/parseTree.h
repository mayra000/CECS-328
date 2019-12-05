//
//  parseTree.h
//  CECS328_Project2
//
//  Created by Mayra Sanchez on 11/25/19.
//  Copyright © 2019 Mayra Sanchez. All rights reserved.
//

#ifndef parseTree_h
#define parseTree_h

class parseTree {
    public:
        parseTree(Operator* op){ //operator pointer
            root = op;
            left = NULL;
            right = NULL;
        }
    
        int getPriority() {//returning itself and determines if current arithmetic sequence should take place. must follow PEMDAS
            return root->getPriority();
        }
        
        int evalOp() {
            if ((left != NULL) && (right != NULL)) {
                return root -> opFunc(left -> evalOp(), right -> evalOp());
            }
            return root -> opFunc(0,0);
            
        }
    /* Making pointers for the positions in the parseTree*/
        Operator *root; //null if not a valid integer
        parseTree *left;
        parseTree *right;
    
};

//void printTree(parseTree *op) {
//    if((op->root->getPriority()) != 0)
//        printTree(op->left);
//    op->root->print();
//    if((op->root->getPriority()) != 0)
//        printTree(op->right);
//}

/*
 inserting an element into the parse tree
 */
void insert(parseTree * tree, Operator* op1, Operator* num){
    /* If element being inserted is greater than current element, then
     shifting must take place*/
    if (op1->getPriority() >= tree->right->getPriority()) {
        parseTree* pt = new parseTree(op1);
        pt->right = new parseTree(num);
        pt->left = tree->right; //shifting occurring here
        tree->right = pt;
    }
    else
        insert(tree->right, op1, num);
}

/* Clearing element and moving connections it has to the other elements*/
void removePT(parseTree *arbol) {
    if (arbol != NULL) {
        removePT(arbol->left);
        removePT(arbol->right);
        delete arbol;
    }
}

void makePTree(Operator *opArray[] , int size){
    parseTree * mathTree = new parseTree(opArray[0]);
    
    for(int i = 1; i < size; i += 2) {
        if(mathTree->getPriority() <= opArray[i]->getPriority()) {
            parseTree* newPTree = new parseTree(opArray[i]);
            newPTree->left = mathTree;
            newPTree->right = new parseTree(opArray[i+1]);
            mathTree = newPTree;
        }
        else
            insert(mathTree, opArray[i], opArray[i+1]);
        
        //printTree(mathTree);
        
        cout << "= " << mathTree->evalOp() << endl;
        
        removePT(mathTree);
    }
}

#endif /* parseTree_h */
