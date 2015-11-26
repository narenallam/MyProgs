//
//  nstairs.hpp
//  MyProgs
//
//  Created by Narendra A on 10/10/15.
//  Copyright © 2015 Narendra A. All rights reserved.
//

#ifndef nstairs_hpp
#define nstairs_hpp
#include <vector>

class NStairs{
    std::vector<int> map;

public:
    NStairs(int size, int val):map(size,val){
    }
    int countWaysDP(int);
    static void Driver(void);
};

#endif /* nstairs_hpp */
