#include "s21_math.h"

static const double COS_EXP = 1e-61;
long double s21_cos(double x) {
  long double s;
  if (s21_fabs(x) == S21_INF)
    s = S21_NAN;
  else {
    x = x - ((long long int)(x / 2 / PI)) * 2 * PI;
    double chislitel = 1;
    double znamenatel = 1;
    s = 1;
    int sign = -1;
    for (int i = 1; s21_fabs(chislitel / znamenatel) > COS_EXP; i++) {
      chislitel = chislitel * x * x;
      znamenatel = znamenatel * (i * 2 - 1) * (i * 2);
      s = s + sign * chislitel / znamenatel;
      sign *= -1;
    }
  }
  return s;
}
