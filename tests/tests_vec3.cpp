#include "catch.hpp"
#include "../src/kiss_clang_3d.h"

TEST_CASE("vec3 is_null"){
    vec3 v1 {0.0, 0.0, 0.0};
    REQUIRE( vec3_is_null(&v1) );

    vec3 vi {1.0, 0.0, 0.0};
    REQUIRE( !vec3_is_null(&vi) );

    vec3 vj {0.0, 1.0, 0.0};
    REQUIRE( !vec3_is_null(&vj) );

    vec3 vk {0.0, 0.0, 1.0};
    REQUIRE( !vec3_is_null(&vk) );
}

TEST_CASE("vec3 equal"){
    vec3 v1 {1.0, 2.0, 3.0};
    vec3 v2 {1.0, 2.0, 3.0};
    REQUIRE( vec3_equal(&v1, &v2) );

    vec3 v3 {2.0, 2.0, 3.0};
    REQUIRE( !vec3_equal(&v1, &v3) );

    vec3 v4 {1.0, 3.0, 3.0};
    REQUIRE( !vec3_equal(&v1, &v4) );

    vec3 v5 {1.0, 2.0, 4.0};
    REQUIRE( !vec3_equal(&v1, &v5) );
}

TEST_CASE("vec3 norm_square"){
    vec3 vec_i {2.0, 0.0, 0.0};
    REQUIRE( vec3_norm_square(&vec_i) == Approx(4.0));

    vec3 vec_j {0.0, 3.0, 0.0};
    REQUIRE( vec3_norm_square(&vec_j) == Approx(9.0));

    vec3 vec_k {0.0, 0.0, 4.0};
    REQUIRE( vec3_norm_square(&vec_k) == Approx(16.0));

    vec3 vec_ijk {1.0, 2.0, 3.0};
    REQUIRE( vec3_norm_square(&vec_ijk) == Approx(14.0));
}

TEST_CASE("vec3 norm"){
    vec3 vec_i {2.0, 0.0, 0.0};
    REQUIRE( vec3_norm(&vec_i) == Approx(2.0));

    vec3 vec_j {0.0, 3.0, 0.0};
    REQUIRE( vec3_norm(&vec_j) == Approx(3.0));

    vec3 vec_k {0.0, 0.0, 4.0};
    REQUIRE( vec3_norm(&vec_k) == Approx(4.0));

    vec3 vec_ijk {1.0, 2.0, 3.0};
    REQUIRE( vec3_norm(&vec_ijk) == Approx(3.7416573867739413));
}

TEST_CASE("vec3 scale"){
    vec3 vec_init {1.0, 2.0, 3.0};
    F_TYPE scale {2.0};
    vec3_scale(&vec_init, scale);

    vec3 vec_final {2.0, 4.0, 6.0};

    REQUIRE( vec3_equal(&vec_init, &vec_final) );
}

TEST_CASE("vec3 add"){
    vec3 vec_acc {1.0, 10.0, 100.0};
    vec3 vec_add {2.0,  3.0,   4.0};
    vec3 vec_res {3.0, 13.0, 104.0};

    vec3_add(&vec_acc, &vec_add);

    REQUIRE( vec3_equal(&vec_acc, &vec_res) );
}

TEST_CASE("vec3 sub"){
    vec3 vec_acc {2.0, 10.0, 100.0};
    vec3 vec_sub {1.0,  3.0,   4.0};
    vec3 vec_res {1.0,  7.0,  96.0};

    vec3_sub(&vec_acc, &vec_sub);

    REQUIRE( vec3_equal(&vec_acc, &vec_res) );
}

TEST_CASE("vec3 scalar"){
    vec3 v1 {1.0, 10.0, 100.0};
    vec3 v2 {2.0,  3.0,   4.0};

    F_TYPE res {432.0};

    REQUIRE( vec3_scalar(&v1, &v2) == res );
}

TEST_CASE("vec3 cross"){
    vec3 vi {1.0, 0.0, 0.0};
    vec3 vj {0.0, 1.0, 0.0};
    vec3 vk {0.0, 0.0, 1.0};

    vec3 mvi {-1.0, 0.0, 0.0};
    vec3 mvj {0.0, -1.0, 0.0};
    vec3 mvk {0.0, 0.0, -1.0};

    vec3 zero {0.0, 0.0, 0.0};

    vec3 v_res;

    // ii, jj, kk 
    vec3_cross(&vi, &vi, &v_res);
    REQUIRE( vec3_equal(&v_res, &zero) );

    vec3_cross(&vj, &vj, &v_res);
    REQUIRE( vec3_equal(&v_res, &zero) );

    vec3_cross(&vk, &vk, &v_res);
    REQUIRE( vec3_equal(&v_res, &zero) );

    // i, j, k
    vec3_cross(&vi, &vj, &v_res);
    REQUIRE( vec3_equal(&v_res, &vk) );

    vec3_cross(&vj, &vi, &v_res);
    REQUIRE( vec3_equal(&v_res, &mvk) );

    // j, k, i
    vec3_cross(&vj, &vk, &v_res);
    REQUIRE( vec3_equal(&v_res, &vi) );

    vec3_cross(&vk, &vj, &v_res);
    REQUIRE( vec3_equal(&v_res, &mvi) );

    // k, i, j
    vec3_cross(&vk, &vi, &v_res);
    REQUIRE( vec3_equal(&v_res, &vj) );

    vec3_cross(&vi, &vk, &v_res);
    REQUIRE( vec3_equal(&v_res, &mvj) );
}

TEST_CASE("vec3 normalize"){
    vec3 v_null     {0.0, 0.0, 0.0};
    vec3 v_null_res {0.0, 0.0, 0.0};
    bool r_null = vec3_normalize(&v_null);
    REQUIRE( !r_null );
    REQUIRE( vec3_equal(&v_null, &v_null_res) );

    vec3 v1     {2.0, 0.0, 0.0};
    vec3 v1_res {1.0, 0.0, 0.0};
    bool r1 = vec3_normalize(&v1);
    REQUIRE( r1 );
    REQUIRE( vec3_equal(&v1, &v1_res) );

    vec3 v2     {0.0, 3.0, 0.0};
    vec3 v2_res {0.0, 1.0, 0.0};
    bool r2 = vec3_normalize(&v2);
    REQUIRE( r2 );
    REQUIRE( vec3_equal(&v2, &v2_res) );

    vec3 v3     {0.0, 0.0, 4.0};
    vec3 v3_res {0.0, 0.0, 1.0};
    bool r3 = vec3_normalize(&v3);
    REQUIRE( r3 );
    REQUIRE( vec3_equal(&v3, &v3_res) );

    vec3 v4     {1.0, 2.0, 3.0};
    vec3 v4_res {0.2672612419124244, 0.5345224838248488, 0.8017837257372732};
    bool r4 = vec3_normalize(&v4);
    REQUIRE( r3 );
    REQUIRE( vec3_equal(&v4, &v4_res) );
}

TEST_CASE("quat norm"){
    quat q {1.0, 2.0, 3.0, 4.0};
    REQUIRE( quat_norm(&q) == Approx(5.477225575051661) );
}

TEST_CASE("quat norm_square"){
    quat q {1.0, 2.0, 3.0, 4.0};
    REQUIRE( quat_norm_square(&q) == Approx(30.0) );
}

TEST_CASE("quat conj"){
    quat q        {1.0,  2.0,  3.0,  4.0};
    quat q_result {1.0, -2.0, -3.0, -4.0};

    quat_conj(&q);
    REQUIRE( quat_equal(&q, &q_result) );
}

TEST_CASE("quat is_unitary"){
    quat q_unit_1 {1.0, 0.0, 0.0, 0.0};
    REQUIRE( quat_is_unitary(&q_unit_1) );

    quat q_unit_2 {0.0, 1.0, 0.0, 0.0};
    REQUIRE( quat_is_unitary(&q_unit_2) );

    quat q_unit_3 {0.5, 0.5, 0.5, 0.5};
    REQUIRE( quat_is_unitary(&q_unit_3) );
}

TEST_CASE("quat prod"){
    quat const q_r {1.0, 0.0, 0.0, 0.0};
    quat const q_i {0.0, 1.0, 0.0, 0.0};
    quat const q_j {0.0, 0.0, 1.0, 0.0};
    quat const q_k {0.0, 0.0, 0.0, 1.0};

    quat const q_mr {-1.0, 0.0, 0.0, 0.0};
    quat const q_mi {0.0, -1.0, 0.0, 0.0};
    quat const q_mj {0.0, 0.0, -1.0, 0.0};
    quat const q_mk {0.0, 0.0, 0.0, -1.0};

    quat q_result {0.0, 0.0, 0.0, 0.0};

    // see the multiplication table for unit quaternions, for example on the
    // wikipedia page.

    quat_prod(&q_r, &q_r, &q_result);
    REQUIRE( quat_equal(&q_result, &q_r) );
    quat_prod(&q_r, &q_i, &q_result);
    REQUIRE( quat_equal(&q_result, &q_i) );
    quat_prod(&q_r, &q_j, &q_result);
    REQUIRE( quat_equal(&q_result, &q_j) );
    quat_prod(&q_r, &q_k, &q_result);
    REQUIRE( quat_equal(&q_result, &q_k) );

    quat_prod(&q_i, &q_r, &q_result);
    REQUIRE( quat_equal(&q_result, &q_i) );
    quat_prod(&q_i, &q_i, &q_result);
    REQUIRE( quat_equal(&q_result, &q_mr) );
    quat_prod(&q_i, &q_j, &q_result);
    REQUIRE( quat_equal(&q_result, &q_k) );
    quat_prod(&q_i, &q_k, &q_result);
    REQUIRE( quat_equal(&q_result, &q_mj) );

    quat_prod(&q_j, &q_r, &q_result);
    REQUIRE( quat_equal(&q_result, &q_j) );
    quat_prod(&q_j, &q_i, &q_result);
    REQUIRE( quat_equal(&q_result, &q_mk) );
    quat_prod(&q_j, &q_j, &q_result);
    REQUIRE( quat_equal(&q_result, &q_mr) );
    quat_prod(&q_j, &q_k, &q_result);
    REQUIRE( quat_equal(&q_result, &q_i) );

    quat_prod(&q_k, &q_r, &q_result);
    REQUIRE( quat_equal(&q_result, &q_k) );
    quat_prod(&q_k, &q_i, &q_result);
    REQUIRE( quat_equal(&q_result, &q_j) );
    quat_prod(&q_k, &q_j, &q_result);
    REQUIRE( quat_equal(&q_result, &q_mi) );
    quat_prod(&q_k, &q_k, &q_result);
    REQUIRE( quat_equal(&q_result, &q_mr) );
}
