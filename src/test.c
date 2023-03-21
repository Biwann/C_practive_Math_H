#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_math.h"

// ----------------------------------ABS---------------------------------- //
START_TEST(s21_abs_0) {
  int x = -827382;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST
START_TEST(s21_abs_1) {
  int x = 0;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST
START_TEST(s21_abs_2) {
  int x = -2147483648;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST
START_TEST(s21_abs_3) {
  ck_assert_int_eq(abs((int)-2147483649), s21_abs((int)-2147483649));
}
END_TEST
START_TEST(s21_abs_4) {
  int x = 2147483647;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

// ----------------------------------SEIL---------------------------------- //
START_TEST(s21_ceil_0) {
  double x = 0;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_1) {
  double x = 7.2;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_2) {
  double x = -11.3;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_3) {
  double x = 156.484564846;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_4) {
  double x = S21_INF;
  ck_assert(s21_ceil(x) == ceil(x));
}
END_TEST
START_TEST(s21_ceil_5) {
  double x = -6651645168.651449;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_6) {
  double x = -0.6516515651449;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_7) {
  double x = -9849848.1;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_8) {
  double x = 0.000000000001;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST
START_TEST(s21_ceil_9) {
  double x = -0.0000000000001;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), 1e-6);
}
END_TEST

// ----------------------------------COS---------------------------------- //
START_TEST(s21_cos_0) {
  double x = 0;
  double res = fabs(cos(x) - (double)s21_cos(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_cos_1) {
  double x = 0.018484865654464885;
  double res = fabs(cos(x) - (double)s21_cos(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_cos_2) {
  double x = 5534534466.54465465;
  double res = fabs(cos(x) - (double)s21_cos(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_cos_3) {
  double x = PI;
  double res = fabs(cos(x) - (double)s21_cos(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_cos_4) {
  double x = S21_INF;
  ck_assert(isnan(s21_cos(x)));
}
END_TEST
START_TEST(s21_cos_5) {
  double x = -2.68789;
  double res = fabs(cos(x) - (double)s21_cos(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_cos_6) {
  double x = -PI / 2;
  double res = fabs(cos(x) - (double)s21_cos(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST

// ----------------------------------FABS---------------------------------- //
START_TEST(s21_fabs_0) {
  double x = -827382.65465;
  ck_assert_double_eq(fabs(x), s21_fabs(x));
}
END_TEST
START_TEST(s21_fabs_1) {
  double x = 0;
  ck_assert_double_eq(fabs(x), s21_fabs(x));
}
END_TEST
START_TEST(s21_fabs_2) {
  double x = -2147483648.57777;
  ck_assert_double_eq(fabs(x), s21_fabs(x));
}
END_TEST
START_TEST(s21_fabs_3) {
  double x = 2147483647;
  ck_assert_double_eq(fabs(x), s21_fabs(x));
}
END_TEST
START_TEST(s21_fabs_4) {
  double x = -S21_INF;
  ck_assert(isinf(s21_fabs(x)));
}
END_TEST
START_TEST(s21_fabs_5) {
  double x = S21_INF;
  ck_assert(isinf(s21_fabs(x)));
}
END_TEST

// ----------------------------------FLOOR---------------------------------- //
START_TEST(s21_floor_0) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_1) {
  double x = S21_INF;
  ck_assert(s21_floor(x) == floor(x));
}
END_TEST
START_TEST(s21_floor_2) {
  double x = -11.3;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_3) {
  double x = 156.484564846;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_4) {
  double x = -665168.651449;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_5) {
  double x = -6651645168.651449;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_6) {
  double x = -0.6516515651449;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_7) {
  double x = -9849848.1;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_8) {
  double x = 0.000000000001;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST
START_TEST(s21_floor_9) {
  double x = -0.0000000000001;
  ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), 1e-6);
}
END_TEST

// ----------------------------------FMOD---------------------------------- //
START_TEST(s21_fmod_0) {
  double x = 0.1;
  double y = 0.0;
  ck_assert(isnan(s21_fmod(x, y)));
}
END_TEST
START_TEST(s21_fmod_1) {
  double x = S21_INF;
  double y = S21_INF;
  ck_assert(isnan(s21_fmod(x, y)));
}
END_TEST
START_TEST(s21_fmod_2) {
  double x = 1568466688.156;
  double y = -68489.668;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-6);
}
END_TEST
START_TEST(s21_fmod_3) {
  double x = -684846855545.885;
  double y = 6884.5487;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-6);
}
END_TEST
START_TEST(s21_fmod_4) {
  double x = -88.8;
  double y = 11.1;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-6);
}
END_TEST
START_TEST(s21_fmod_5) {
  double x = -983;
  double y = S21_INF;
  ck_assert(fmod(x, y) == s21_fmod(x, y));
}
END_TEST
START_TEST(s21_fmod_6) {
  double x = -0.000000068;
  double y = 0.00000000005;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-6);
}
END_TEST
START_TEST(s21_fmod_7) {
  double x = -10000.11111;
  double y = 1.3;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), 1e-6);
}
END_TEST

// ----------------------------------SIN---------------------------------- //
START_TEST(s21_sin_0) {
  double x = 0;
  double res = fabs(sin(x) - (double)s21_sin(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_sin_1) {
  double x = 5534545655.54465465;
  double res = fabs(sin(x) - (double)s21_sin(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_sin_2) {
  double x = -4665145614.54465465;
  double res = fabs(sin(x) - (double)s21_sin(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_sin_3) {
  double x = PI;
  double res = fabs(sin(x) - (double)s21_sin(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_sin_4) {
  double x = S21_INF;
  ck_assert(isnan(s21_sin(x)));
}
END_TEST
START_TEST(s21_sin_5) {
  double x = -2.68789;
  double res = fabs(sin(x) - (double)s21_sin(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST
START_TEST(s21_sin_6) {
  double x = -PI / 2;
  double res = fabs(sin(x) - (double)s21_sin(x));
  ck_assert_ldouble_lt(fabs(res), 1e-6);
}
END_TEST

// ----------------------------------ATAN---------------------------------- //
START_TEST(s21_atan_0) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST
START_TEST(s21_atan_1) {
  double x = 0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST
START_TEST(s21_atan_2) {
  double x = -0.5;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST
START_TEST(s21_atan_3) {
  double x = S21_INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST
START_TEST(s21_atan_4) {
  double x = 3;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST
START_TEST(s21_atan_5) {
  double x = -16515;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST
START_TEST(s21_atan_6) {
  double x = -S21_INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

// ----------------------------------ASIN---------------------------------- //
START_TEST(s21_asin_0) {
  double x = -1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST
START_TEST(s21_asin_1) {
  double x = 0;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST
START_TEST(s21_asin_2) {
  double x = 1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST
START_TEST(s21_asin_3) {
  double x = -0.5;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST
START_TEST(s21_asin_4) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST
START_TEST(s21_asin_5) {
  double x = 0.123124;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST
START_TEST(s21_asin_6) {
  double x = -1230656.4864845;
  ck_assert(isnan(s21_asin(x)));
}
END_TEST
START_TEST(s21_asin_7) {
  double x = 2544.684;
  ck_assert(isnan(s21_asin(x)));
}
END_TEST
// ----------------------------------ACOS---------------------------------- //
START_TEST(s21_acos_0) {
  double x = -1;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST
START_TEST(s21_acos_1) {
  double x = 0;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST
START_TEST(s21_acos_2) {
  double x = 1;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST
START_TEST(s21_acos_3) {
  double x = -0.5;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST
START_TEST(s21_acos_4) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST
START_TEST(s21_acos_5) {
  double x = 0.123124;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST
START_TEST(s21_acos_6) {
  double x = 123064646.64845;
  ck_assert(isnan(s21_acos(x)));
}
END_TEST
START_TEST(s21_acos_7) {
  double x = -2;
  ck_assert(isnan(s21_acos(x)));
}
END_TEST
// ----------------------------------EXP---------------------------------- //
START_TEST(s21_exp_0) {
  double x = -23.2345;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST
START_TEST(s21_exp_1) {
  double x = 0;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST
START_TEST(s21_exp_2) {
  double x = 10;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST
START_TEST(s21_exp_3) {
  double x = -0.5;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST
START_TEST(s21_exp_4) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST
START_TEST(s21_exp_5) {
  double x = 24;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST
START_TEST(exp_various0) {
  char original[50];
  char fake[50];
  double x = 0;
  for (int i = -2000; i <= 2000; i++) {
    sprintf(fake, "%16.6Lf", s21_exp(x + i * 0.01));
    sprintf(original, "%16.6lf", exp(x + i * 0.01));
    ck_assert_str_eq(fake, original);
  }
}
END_TEST
// ----------------------------------LOG---------------------------------- //
START_TEST(s21_log_0) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST
START_TEST(s21_log_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST
START_TEST(s21_log_2) {
  double x = 2;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST
START_TEST(s21_log_3) {
  double x = 1236564.1236846545;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST
START_TEST(s21_log_4) {
  double x = -10;
  ck_assert(isnan(s21_log(x)));
}
END_TEST
START_TEST(s21_log_5) {
  double x = 0;
  ck_assert(isinf(s21_log(x)));
}
// ----------------------------------POW---------------------------------- //
START_TEST(s21_pow_0) {
  double x = -1;
  double y = S21_INF;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), 1e-6);
}
END_TEST
START_TEST(s21_pow_1) {
  double x = S21_INF;
  double y = -5;
  ck_assert_int_eq(s21_pow(x, y), pow(x, y));
}
END_TEST
START_TEST(s21_pow_2) {
  double x = -S21_INF;
  double y = -6;
  ck_assert_int_eq(s21_pow(x, y), pow(x, y));
}
END_TEST
START_TEST(s21_pow_3) {
  double x = -0.5;
  double y = 0;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), 1e-6);
}
END_TEST
START_TEST(s21_pow_4) {
  double x = 0;
  double y = 0;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), 1e-6);
}
END_TEST
START_TEST(s21_pow_5) {
  double x = 23.1234;
  double y = -17;
  ck_assert_ldouble_eq_tol(pow(x, y), s21_pow(x, y), 1e-6);
}
END_TEST
START_TEST(s21_pow_6) {
  double x = -12;
  double y = 12.32;
  ck_assert(isnan(s21_pow(x, y)));
}
END_TEST
START_TEST(s21_pow_7) {
  double x = -S21_INF;
  double y = -13;
  ck_assert_int_eq(s21_pow(x, y), pow(x, y));
}
END_TEST
START_TEST(s21_pow_8) {
  double x = -0.56;
  double y = S21_INF;
  ck_assert_int_eq(s21_pow(x, y), pow(x, y));
}
END_TEST
START_TEST(s21_pow_9) {
  double x = 59.5956;
  double y = S21_INF;
  ck_assert_int_eq(s21_pow(x, y), pow(x, y));
}
END_TEST
START_TEST(s21_pow_10) {
  double x = 0;
  double y = 8481686.8948;
  ck_assert_int_eq(s21_pow(x, y), pow(x, y));
}
END_TEST
// ----------------------------------TAN---------------------------------- //
START_TEST(s21_tan_0) {
  double x = -0.0;
  ck_assert_ldouble_eq(tan(x), s21_tan(x));
}
END_TEST
START_TEST(s21_tan_1) {
  double x = 55365.54465465;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST
START_TEST(s21_tan_2) {
  double x = -4665001230.54465465;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST
START_TEST(s21_tan_3) {
  double x = PI / 3;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST
START_TEST(s21_tan_4) {
  double x = 1;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST
START_TEST(s21_tan_5) {
  double x = -2.68789;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST
START_TEST(s21_tan_6) {
  double x = -PI / 4;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST
// ----------------------------------SQRT---------------------------------- //
START_TEST(s21_sqrt_0) {
  double x = -23.2345;
  ck_assert(isnan(s21_sqrt(x)));
}
END_TEST
START_TEST(s21_sqrt_1) {
  double x = 0;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST
START_TEST(s21_sqrt_2) {
  double x = 10;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST
START_TEST(s21_sqrt_3) {
  double x = -0.5;
  ck_assert(isnan(s21_sqrt(x)));
}
END_TEST
START_TEST(s21_sqrt_4) {
  double x = 0.5;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST
START_TEST(s21_sqrt_5) {
  double x = 2364448.1234;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST
// Функция создания набора тестов
Suite *example_suite_create(void) {
  Suite *suite = suite_create("Example");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("Core of example");

  // ----------------------------------ABS---------------------------------- //
  tcase_add_test(tcase_core, s21_abs_0);
  tcase_add_test(tcase_core, s21_abs_1);
  tcase_add_test(tcase_core, s21_abs_2);
  tcase_add_test(tcase_core, s21_abs_3);
  tcase_add_test(tcase_core, s21_abs_4);
  // ----------------------------------SEIL---------------------------------- //
  tcase_add_test(tcase_core, s21_ceil_0);
  tcase_add_test(tcase_core, s21_ceil_1);
  tcase_add_test(tcase_core, s21_ceil_2);
  tcase_add_test(tcase_core, s21_ceil_3);
  tcase_add_test(tcase_core, s21_ceil_4);
  tcase_add_test(tcase_core, s21_ceil_5);
  tcase_add_test(tcase_core, s21_ceil_6);
  tcase_add_test(tcase_core, s21_ceil_7);
  tcase_add_test(tcase_core, s21_ceil_8);
  tcase_add_test(tcase_core, s21_ceil_9);
  // ----------------------------------COS---------------------------------- //
  tcase_add_test(tcase_core, s21_cos_0);
  tcase_add_test(tcase_core, s21_cos_1);
  tcase_add_test(tcase_core, s21_cos_2);
  tcase_add_test(tcase_core, s21_cos_3);
  tcase_add_test(tcase_core, s21_cos_4);
  tcase_add_test(tcase_core, s21_cos_5);
  tcase_add_test(tcase_core, s21_cos_6);
  // ----------------------------------FABS---------------------------------- //
  tcase_add_test(tcase_core, s21_fabs_0);
  tcase_add_test(tcase_core, s21_fabs_1);
  tcase_add_test(tcase_core, s21_fabs_2);
  tcase_add_test(tcase_core, s21_fabs_3);
  tcase_add_test(tcase_core, s21_fabs_4);
  tcase_add_test(tcase_core, s21_fabs_5);
  // ----------------------------------FLOOR----------------------------------
  tcase_add_test(tcase_core, s21_floor_0);
  tcase_add_test(tcase_core, s21_floor_1);
  tcase_add_test(tcase_core, s21_floor_2);
  tcase_add_test(tcase_core, s21_floor_3);
  tcase_add_test(tcase_core, s21_floor_4);
  tcase_add_test(tcase_core, s21_floor_5);
  tcase_add_test(tcase_core, s21_floor_6);
  tcase_add_test(tcase_core, s21_floor_7);
  tcase_add_test(tcase_core, s21_floor_8);
  tcase_add_test(tcase_core, s21_floor_9);
  // ----------------------------------FMOD----------------------------------
  tcase_add_test(tcase_core, s21_fmod_0);
  tcase_add_test(tcase_core, s21_fmod_1);
  tcase_add_test(tcase_core, s21_fmod_2);
  tcase_add_test(tcase_core, s21_fmod_3);
  tcase_add_test(tcase_core, s21_fmod_4);
  tcase_add_test(tcase_core, s21_fmod_5);
  tcase_add_test(tcase_core, s21_fmod_6);
  tcase_add_test(tcase_core, s21_fmod_7);
  // ----------------------------------SIN---------------------------------- //
  tcase_add_test(tcase_core, s21_sin_0);
  tcase_add_test(tcase_core, s21_sin_1);
  tcase_add_test(tcase_core, s21_sin_2);
  tcase_add_test(tcase_core, s21_sin_3);
  tcase_add_test(tcase_core, s21_sin_4);
  tcase_add_test(tcase_core, s21_sin_5);
  tcase_add_test(tcase_core, s21_sin_6);
  // ----------------------------------ATAN---------------------------------- //
  tcase_add_test(tcase_core, s21_atan_0);
  tcase_add_test(tcase_core, s21_atan_1);
  tcase_add_test(tcase_core, s21_atan_2);
  tcase_add_test(tcase_core, s21_atan_3);
  tcase_add_test(tcase_core, s21_atan_4);
  tcase_add_test(tcase_core, s21_atan_5);
  tcase_add_test(tcase_core, s21_atan_6);
  // ----------------------------------ASIN---------------------------------- //
  tcase_add_test(tcase_core, s21_asin_0);
  tcase_add_test(tcase_core, s21_asin_1);
  tcase_add_test(tcase_core, s21_asin_2);
  tcase_add_test(tcase_core, s21_asin_3);
  tcase_add_test(tcase_core, s21_asin_4);
  tcase_add_test(tcase_core, s21_asin_5);
  tcase_add_test(tcase_core, s21_asin_6);
  tcase_add_test(tcase_core, s21_asin_7);
  // ----------------------------------ACOS---------------------------------- //
  tcase_add_test(tcase_core, s21_acos_0);
  tcase_add_test(tcase_core, s21_acos_1);
  tcase_add_test(tcase_core, s21_acos_2);
  tcase_add_test(tcase_core, s21_acos_3);
  tcase_add_test(tcase_core, s21_acos_4);
  tcase_add_test(tcase_core, s21_acos_5);
  tcase_add_test(tcase_core, s21_acos_6);
  tcase_add_test(tcase_core, s21_acos_7);
  // ----------------------------------EXP---------------------------------- //
  tcase_add_test(tcase_core, s21_exp_0);
  tcase_add_test(tcase_core, s21_exp_1);
  tcase_add_test(tcase_core, s21_exp_2);
  tcase_add_test(tcase_core, s21_exp_3);
  tcase_add_test(tcase_core, s21_exp_4);
  tcase_add_test(tcase_core, s21_exp_5);
  tcase_add_test(tcase_core, exp_various0);
  // ----------------------------------LOG---------------------------------- //
  tcase_add_test(tcase_core, s21_log_0);
  tcase_add_test(tcase_core, s21_log_1);
  tcase_add_test(tcase_core, s21_log_2);
  tcase_add_test(tcase_core, s21_log_3);
  tcase_add_test(tcase_core, s21_log_4);
  tcase_add_test(tcase_core, s21_log_5);
  // ----------------------------------POW---------------------------------- //
  tcase_add_test(tcase_core, s21_pow_0);
  tcase_add_test(tcase_core, s21_pow_1);
  tcase_add_test(tcase_core, s21_pow_2);
  tcase_add_test(tcase_core, s21_pow_3);
  tcase_add_test(tcase_core, s21_pow_4);
  tcase_add_test(tcase_core, s21_pow_5);
  tcase_add_test(tcase_core, s21_pow_6);
  tcase_add_test(tcase_core, s21_pow_7);
  tcase_add_test(tcase_core, s21_pow_8);
  tcase_add_test(tcase_core, s21_pow_9);
  tcase_add_test(tcase_core, s21_pow_10);
  // ----------------------------------TAN---------------------------------- //
  tcase_add_test(tcase_core, s21_tan_0);
  tcase_add_test(tcase_core, s21_tan_1);
  tcase_add_test(tcase_core, s21_tan_2);
  tcase_add_test(tcase_core, s21_tan_3);
  tcase_add_test(tcase_core, s21_tan_4);
  tcase_add_test(tcase_core, s21_tan_5);
  tcase_add_test(tcase_core, s21_tan_6);
  // ----------------------------------SQRT---------------------------------- //
  tcase_add_test(tcase_core, s21_sqrt_0);
  tcase_add_test(tcase_core, s21_sqrt_1);
  tcase_add_test(tcase_core, s21_sqrt_2);
  tcase_add_test(tcase_core, s21_sqrt_3);
  tcase_add_test(tcase_core, s21_sqrt_4);
  tcase_add_test(tcase_core, s21_sqrt_5);
  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = example_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов.
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
