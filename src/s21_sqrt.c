#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res;
  if (x == -0.0)
    res = -0.0;
  else if (x < 0)
    res = S21_NAN;
  else
    res = s21_pow(x, 0.5);
  return res;
}
