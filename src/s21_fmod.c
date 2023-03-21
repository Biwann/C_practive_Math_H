#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (s21_fabs(x) < s21_fabs(y)) {
    result = x;
  } else if (s21_fabs(x) <= EPS)
    result = x > 0 ? 0.0 : -0.0;
  else if (s21_fabs(x) == S21_INF || s21_fabs(y) <= EPS)
    result = S21_NAN;
  else if (s21_fabs(y) == S21_INF)
    result = x;
  else {
    __float128 a = x / y;
    struct_float128 float128 = longdouble_to_struct_float128(a);
    long double int_part;
    int power = float128.power - 16383;
    if (power < 0) {
      int_part = float128.sign ? -0.0 : 0.0;
    } else {
      __uint128_t bitsllu = (*((__uint128_t*)&a) >> (112 - power))
                            << (112 - power);
      int_part = *(__float128*)&bitsllu;
    }
    result = x - y * int_part;
  }
  return (result);
}
