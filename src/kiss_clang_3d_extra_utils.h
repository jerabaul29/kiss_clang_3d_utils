#ifndef CPP_PRINTING_UTILS_H
#define CPP_PRINTING_UTILS_H

#include "./kiss_clang_3d.h"
#include <iostream>

void print_vec3(Vec3 const * v){
    std::cout << "v_i: " << v->i;
    std::cout << " | v_j: " << v->j;
    std::cout << " | v_k: " << v->k;
    std::cout << std::endl;
}

void print_quat(Quat const * q){
    std::cout << "q_r: " << q->r;
    std::cout << " | q_i: " << q->i;
    std::cout << " | q_j: " << q->j;
    std::cout << " | q_k: " << q->k;
    std::cout << std::endl;
}

#endif
