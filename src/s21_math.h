#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <string.h>

#define EPS 1e-50
#define PI 3.1415926535897932384626433832795
#define S21_EXP 2.718281828459045235360287471352662497
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0

typedef union {
  double f;
  long long i;
} u_X;

typedef struct {
  unsigned int sign;
  unsigned int power;
  __uint128_t fraction;
} struct_float128;

int s21_abs(int x);
long double s21_acos(double x);                // working
long double s21_asin(double x);                // working
long double s21_atan(double x);                // working
long double s21_ceil(double x);                // -- test ready
long double s21_cos(double x);                 // working
long double s21_exp(double x);                 // -- timeout ready
long double s21_fabs(double x);                // working
long double s21_floor(double x);               // -- test ready
long double s21_fmod(double x, double y);      // working
long double s21_log(double x);                 // -- test ready
long double s21_pow(double base, double exp);  // -- timeout ready
long double s21_sin(double x);                 // working
long double s21_sqrt(double x);                // working
long double s21_tan(double x);                 // working

struct_float128 longdouble_to_struct_float128(__float128 n);
#endif  //  SRC_S21_MATH_H_
