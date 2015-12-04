//
//  TreeProgram.cpp
//  MyProgs
//
//  Created by Narendra A on 10/10/15.
//  Copyright © 2015 Narendra A. All rights reserved.
//

#include "TreeProgram.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
namespace BSTree {
    
    void Tree::insertNode(uint64_t data){
        shared_ptr<Node> temp = make_shared<Node(data);
        shared_ptr<Node> rt = nullptr;
        shared_ptr<Node> prev = nullptr;
        temp->nodeCount = 1;
        
        if (this->root == NULL) {
            this->root = temp;
            this->count++;
            return;
        }
        
        rt = this->root;
        while (rt != nullptr){
            rt->nodeCount++;
            prev = rt;
            
            if(rt->data == data){
                cout << "Duplicate found, data ignored!!" << endl;
                return;
            }
            
            if (temp->data < rt->data){
                rt = rt->left;  
            }
            else{
                rt = rt->right;
            }
        } 
        if (temp->data > prev->data){
            prev->right = temp;
        }
        else{
            prev->left = temp;
        }
        this->count++;
    }
    
    void Tree::buildTree(vector<uint64_t> &a){
        
        for (auto &x : a){
            this->insertNode(x);
        }
    }
    
    void Tree::inOrder(shared_ptr<Node> &rt){
        if (rt){
            this->inOrder(rt->left);
            cout << rt->data << " ";
            this->inOrder(rt->right);
        }
    }
    
    void Tree::levelOrder(shared_ptr<Node> &rt){
        vector<shared_ptr<Node>> v;
        v.reserve(100);
        v.push_back(rt);
        
        try{
            
            for (auto i = 0; i < v.size(); i++)
            {
                auto x = v[i];
                if (x->left != nullptr)	{
                    v.push_back(x->left);
                }
                if (x->right != nullptr){
                    v.push_back(x->right);
                }
                cout << x->data << " ";
            }
        }
        catch (exception e){
            cout << "Exception: " << e.what() << endl;
        }
    }
    
    void Tree::preOrder(void){
        while(!stack.empty()){
            
            shared_ptr<Node> tmp = stack.back();
            stack.pop_back();
            cout << tmp->data << " ";
            
            if(tmp->left) stack.push_back(tmp->left);
            if(tmp->right) stack.push_back(tmp->right);
            
        }
    }
    
    uint64_t findDiameter(std::shared_ptr<Node>& cur_node, uint64_t& height){
        
        uint64_t l_diameter, r_diameter;
        uint64_t l_height, r_height;
        
        if(cur_node == nullptr){
            height = 0;
            return 0;
        }
        
        l_diameter = findDiameter(cur_node->left, l_height);
        r_diameter = findDiameter(cur_node->right, r_height);
        
        height = std::max(l_height, r_height) + 1; // pass-by-reference
        
        return std::max(l_height + r_height + 1, std::max( l_diameter, r_diameter));
    }
    
    void Tree::Driver(void){
        vector<uint64_t> vTree{ 40, 20, 30, 13, 25, 42, 60 };
        
        Tree T;
        
        T.buildTree(vTree);
        cout << "Inorder order"<<endl;
        T.printInOrder();
        cout << endl;
        cout << "Level order"<<endl;
        T.printLevelOrder();
        cout << endl;
        cout << "Pre order"<<endl;
        T.printPreOrder();
        cout << endl;
        uint64_t h = 0;
        cout << "Tree diameter = " << T.findDiameter(T.getRoot(), h)  << "Depth = "<< h << endl;
        
    }
    
}