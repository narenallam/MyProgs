//
//  nstairs.cpp
//  MyProgs
//
//  Created by Narendra A on 10/10/15.
//  Copyright © 2015 Narendra A. All rights reserved.
//

#include "nstairs.hpp"

int NStairs::countWaysDP(int n) {
    
    if (n < 0) {
        return 0;
    }
    else if (n == 0) {
        return 1;
    } else if (map[n] > -1) {
        return map[n];
    }
    else {
        map[n] = countWaysDP(n - 1) +
                 countWaysDP(n - 2) +
                 countWaysDP(n - 3);
        
        return map[n];
    }
}
void NStairs::Driver(void){
    
}

