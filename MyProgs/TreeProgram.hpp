//
//  TreeProgram.hpp
//  MyProgs
//
//  Created by Narendra A on 10/10/15.
//  Copyright © 2015 Narendra A. All rights reserved.
//

#ifndef TreeProgram_hpp
#define TreeProgram_hpp

#include <memory>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace BSTree{
    struct Node{
        uint64_t data;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        uint64_t nodeCount;
        Node(uint64_t data){
            this->left = nullptr;
            this->right = nullptr;
            this->data = data;
            this->nodeCount = 0;
        }
    };
    
    class Tree {
    public:
        Tree(){
            this->root = nullptr;
            this->count = 0;
        }
        
        void insertNode(uint64_t data);
        void buildTree(vector<uint64_t> &a);
        void inOrder(shared_ptr<Node> &rt);
        void levelOrder(shared_ptr<Node> &rt);
        void preOrder(void);
        
        inline void printInOrder(){
            this->inOrder(this->root);
        }
        inline void printLevelOrder(){
            this->levelOrder(this->root);
        }
        inline void printPreOrder(){
            stack.push_back(this->root);
            this->preOrder();
        }
        static void Driver(void);
        auto& getRoot(){
            return this->root;
        }
        auto getCount(){
            return count;
        }
        uint64_t findDiameter(std::shared_ptr<Node>&, uint64_t&);
    private:
        uint64_t count;
        shared_ptr<Node> root;
        vector<shared_ptr<Node>> stack;
        
    };
}
#endif /* TreeProgram_hpp */
