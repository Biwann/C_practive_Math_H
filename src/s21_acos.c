#include "s21_math.h"

long double s21_acos(double x) {
  double res;
  if (x < 0)
    res = PI - s21_asin(s21_sqrt(1 - x * x));
  else
    res = s21_asin(s21_sqrt(1 - x * x));
  return res;
}
