//
//  TreeDiameter.cpp
//  MyProgs
//
//  Created by Narendra A on 13/10/15.
//  Copyright © 2015 Narendra A. All rights reserved.
//

#include "TreeDiameter.hpp"
struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

/* returns maximum of two integers */
int max(int a, int b)
{
    return (a >= b)? a: b;
}
/*The second parameter is to store the height of tree.
 Initially, we need to pass a pointer to a location with value
 as 0. So, function should be used as follows:
 
 int height = 0;
 struct node *root = SomeFunctionToMakeTree();
 int diameter = diameterOpt(root, &height); */

int diameterOpt(struct node *root, int* height)
{
    /* lh --> Height of left subtree
     rh --> Height of right subtree */
    int lh = 0, rh = 0;
    
    /* ldiameter  --> diameter of left subtree
     rdiameter  --> Diameter of right subtree */
    int ldiameter = 0, rdiameter = 0;
    
    if(root == NULL)
    {
        *height = 0;
        return 0; /* diameter is also 0 */
    }
    
    /* Get the heights of left and right subtrees in lh and rh
     And store the returned values in ldiameter and ldiameter */
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);
    
    /* Height of current node is max of heights of left and
     right subtrees plus 1*/
    *height = max(lh, rh) + 1;
    
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}