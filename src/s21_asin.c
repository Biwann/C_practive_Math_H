#include "s21_math.h"

long double s21_asin(double x) {
  long double res = x, prev_add = x, add = 1;
  if (s21_fabs(x - 1) < EPS)
    res = PI / 2.0;
  else if (s21_fabs(x + 1) < EPS)
    res = -PI / 2.0;
  else if (s21_fabs(x) > 1) {
    res = S21_NAN;
  } else {
    for (int i = 1; s21_fabs(add) > EPS; i++) {
      add =
          prev_add * x * x * (2 * i - 1) * (2 * i - 1) / (2 * i * (2 * i + 1));
      res += add;
      prev_add = add;
    }
  }
  return res;
}
