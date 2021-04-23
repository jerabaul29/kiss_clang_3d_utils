#ifndef KISS_CLANG_3D_UTILS_H
#define KISS_CLANG_3D_UTILS_H

#include <cmath>

// ------------------------------------------------------------
// MACROS
// ------------------------------------------------------------

// our fundamental type; this will be the type used for all
// members of vectors, quaternions, DCM matrices, etc.
#define F_TYPE float

// the default tolerance for performing floating point comparisons
#define DEFAULT_TOL (1.0e-12)


// ------------------------------------------------------------
// STRUCTS
// ------------------------------------------------------------

// --------------------------------------------------
// 3D vector, components i, j, k
struct vec3 {
    F_TYPE i;
    F_TYPE j;
    F_TYPE k;
};

// --------------------------------------------------
// quaternion, with real part (r), and components (i, i, k)
struct quat {
    F_TYPE r;
    F_TYPE i;
    F_TYPE j;
    F_TYPE k;
};


// ------------------------------------------------------------
// FUNCTIONS DECLARATIONS
// ------------------------------------------------------------

// ---------------------------------------------
// VEC3 functions
// ---------------------------------------------

/*
Check if a vector is the null vector, up to a tolerance
*/
bool vec3_is_null(vec3 const * v1, F_TYPE tolerance=DEFAULT_TOL);

/*
Check if 2 vectors are equal, at a tolerance precision
*/
bool vec3_equal(vec3 const * v1, vec3 const * v2, F_TYPE tolerance=DEFAULT_TOL);

/*
Compute the square norm of a vector
*/
F_TYPE vec3_norm_square(vec3 const * v);

/*
Compute the norm of a vector
*/
F_TYPE vec3_norm(vec3 const * v);

/*
Scale a vector in place
*/
void vec3_scale(vec3 * v, F_TYPE scale);

/*
Add a vector v_add to an already existing vector v_acc
*/
void vec3_add(vec3 * v_acc, vec3 const * v_add);

/*
Subtract a vector v_subs to an already existing vector v_acc
*/
void vec3_sub(vec3 * v_acc, vec3 const * v_sub);

/*
Take the scalar product of 2 vectors
*/
F_TYPE vec3_scalar(vec3 const * v1, vec3 const * v2);

/*
Take the cross product of 2 vectors v1 and v2 and put the result in v_res
*/
void vec3_cross(vec3 const * v1, vec3 const * v2, vec3 * v_res);

/*
Normalize a vector in place; of course this does not work for the null vector, so also
return a bool if was able to normalize or not
*/
bool vec3_normalize(vec3 * v);

// ------------------------------------------------------------
// DEFINITIONS
// ------------------------------------------------------------

bool vec3_is_null(vec3 const * v1, F_TYPE tolerance){
    return(
        abs(v1->i) < tolerance &&
        abs(v1->j) < tolerance &&
        abs(v1->k) < tolerance
    );
}

bool vec3_equal(vec3 const * v1, vec3 const * v2, F_TYPE tolerance){
    return(
        abs(v1->i - v2->i) < tolerance &&
        abs(v1->j - v2->j) < tolerance &&
        abs(v1->k - v2->k) < tolerance
    );
}

F_TYPE vec3_norm_square(vec3 const * v){
    return (
            (v->i * v->i) + (v->j * v->j) + (v->k * v->k)
    );
}

F_TYPE vec3_norm(vec3 const * v){
    return (
        sqrt(
                (v->i * v->i) + (v->j * v->j) + (v->k * v->k)
        )
    );
}

void vec3_scale(vec3 * v, F_TYPE scale){
    v->i *= scale;
    v->j *= scale;
    v->k *= scale;
}

void vec3_add(vec3 * v_acc, vec3 const * v_add){
    v_acc->i += v_add->i;
    v_acc->j += v_add->j;
    v_acc->k += v_add->k;
}

void vec3_sub(vec3 * v_acc, vec3 const * v_sub){
    v_acc->i -= v_sub->i;
    v_acc->j -= v_sub->j;
    v_acc->k -= v_sub->k;
}

F_TYPE vec3_scalar(vec3 const * v1, vec3 const * v2){
    return(
        v1->i * v2->i +
        v1->j * v2->j +
        v1->k * v2->k
    );
}

void vec3_cross(vec3 const * v1, vec3 const * v2, vec3 * v_res){
    v_res->i =  v1->j * v2->k - v1->k * v2->j;
    v_res->j = -v1->i * v2->k + v1->k * v2->i;
    v_res->k =  v1->i * v2->j - v1->j * v2->i;
}

bool vec3_normalize(vec3 * v){
    if (vec3_is_null(v)){
        return false;
    }
    else{
        F_TYPE norm = vec3_norm(v);
        vec3_scale(v, 1.0 / norm);
        return true;
    }
}

#endif
