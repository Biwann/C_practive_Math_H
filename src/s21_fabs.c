#include "s21_math.h"

long double s21_fabs(double x) {
  long double res;
  if (x == S21_INF || x == -S21_INF)
    res = S21_INF;
  else
    res = x < 0 ? -x : x;
  return res;
}
