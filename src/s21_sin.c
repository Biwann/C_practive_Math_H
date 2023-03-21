#include "s21_math.h"

long double s21_sin(double x) {
  long double s;
  if (s21_fabs(x) == S21_INF)
    s = S21_NAN;
  else {
    x = x - ((long long int)(x / 2 / PI)) * 2 * PI;
    s = x;
    double chislitel = x;
    double znamenatel = 1;
    int sign = -1;
    for (int i = 1; s21_fabs(chislitel / znamenatel) > EPS; i++) {
      chislitel = chislitel * x * x;
      znamenatel = znamenatel * (i * 2) * (i * 2 + 1);
      s = s + sign * chislitel / znamenatel;
      sign *= -1;
    }
  }
  return s;
}
