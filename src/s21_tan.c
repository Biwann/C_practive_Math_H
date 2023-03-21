#include "s21_math.h"

long double s21_tan(double x) {
  long double res;
  if (s21_fabs(x) == S21_INF)
    res = S21_NAN;
  else if (s21_fabs(x) == 0.0)
    res = x == 0 ? 0.0 : -0.0;
  else
    res = s21_sin(x) / s21_cos(x);
  return res;
}
