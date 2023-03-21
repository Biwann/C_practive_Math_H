#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0, prev_add, add;
  if (s21_fabs(x - 1) < EPS)
    res = 0;
  else if (s21_fabs(x) < EPS)
    res = -S21_INF;
  else if (x < 0)
    res = S21_NAN;
  else {
    long double k = 0;

    int sign = 1;
    if (x < 1.0) {
      sign = -1;
      x = 1.0 / x;
    }
    while (x > S21_EXP) {
      x /= S21_EXP;
      k++;
    }

    prev_add = 0, add = 0;
    for (int i = 0; i < 1000; i++) {
      add = prev_add + 2.0 * (x - s21_exp(prev_add)) / (x + s21_exp(prev_add));
      prev_add = add;
    }
    res = add + k;
    res *= sign;
  }
  return res;
}
