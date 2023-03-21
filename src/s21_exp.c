#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1.0;
  if (x == -S21_INF)
    res = 0;
  else if (x == S21_INF)
    res = S21_INF;
  else {
    long double prev_add = 1.0, add = 1.0;
    int positive = 1;
    if (x < 0) {
      positive = 0;
      x = -x;
    }
    for (int i = 1; i < 1000; i++) {
      add = prev_add * x / i;
      res += add;
      prev_add = add;
    }
    res = positive ? res : 1.0 / res;
  }
  return res;
}
