#include "s21_math.h"

#define SQRT3 1.73205080756887729357372529559455642811371944844722747802734375L
#define ATAN_EPS 1e-17

long double s21_atan(double x) {
  long double res;
  if (s21_fabs(x) == S21_INF)
    res = x == S21_INF ? PI / 2.0 : -PI / 2.0;
  else {
    long double y = s21_fabs(x);
    if (y > 1) y = 1 / y;
    int count = 0;
    while (y > 0.6) {
      y = (y * SQRT3 - 1) / (y + SQRT3);
      count++;
    }
    res = y;
    long double n = y;
    long double n_abs = n;
    int i = 1;
    while (n_abs > ATAN_EPS) {
      n = -n * y * y * (2 * i - 1) / (2 * i + 1);
      n_abs = n < 0 ? -n : n;
      res = res + n;
      i++;
    }
    res += count * PI / 6;
    if (s21_fabs(x) > 1) res = PI / 2.0 - res;
    if (x < 0) res = -res;
  }
  return res;
}
