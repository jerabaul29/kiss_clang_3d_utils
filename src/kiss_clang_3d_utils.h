#ifndef KISS_CLANG_3D_UTILS_H
#define KISS_CLANG_3D_UTILS_H

// ------------------------------------------------------------
// our fundamental type
#define F_TYPE float

// --------------------------------------------------
// the main structs

// 3D vector, components i, j, k
struct vector_3 {
    F_TYPE v_i;
    F_TYPE v_j;
    F_TYPE v_k;
};

// quaternion
struct quat {
    F_TYPE q_real;
    F_TYPE q_i;
    F_TYPE q_j;
    F_TYPE q_k;
};

// --------------------------------------------------
// the functions on these structs

#endif
