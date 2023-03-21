#include "s21_math.h"

long double s21_pow(double base, double exp) {
  double res;
  if (s21_fabs(exp) < EPS)
    res = 1;
  else if (s21_fabs(base - 1) < EPS)
    res = 1;
  else if (s21_fabs(base) < 1 && s21_fabs(exp) == S21_INF)
    res = exp == S21_INF ? 0 : S21_INF;
  else if (s21_fabs(base + 1) < EPS && s21_fabs(exp) == S21_INF)
    res = 1;
  else if (s21_fabs(base) > 1 && s21_fabs(exp) == S21_INF)
    res = exp == S21_INF ? S21_INF : 0;
  else if (base < 0 && s21_fabs(s21_fmod(exp, 1.0)) > EPS)
    res = S21_NAN;
  else if (s21_fabs(base) < EPS)
    res = 0;
  else if (base == S21_INF)
    res = exp > 0 ? S21_INF : 0.0;
  else if (base == -S21_INF && (long long int)exp == exp && exp < 0.0)
    res = s21_fmod(exp, 2) == 0 ? 0.0 : -0.0;
  else if (base == -S21_INF && (long long int)exp == exp && exp > 0.0)
    res = s21_fmod(exp, 2) == 0 ? S21_INF : -S21_INF;
  else {
    if (s21_fabs(s21_fmod(exp, 2.0)) < EPS) {
      res = s21_exp(exp * s21_log(s21_fabs(base)));
    } else if (s21_fabs(s21_fmod(exp, 1.0)) < EPS && base < 0) {
      res = -s21_exp(exp * s21_log(s21_fabs(base)));
    } else {
      res = s21_exp(exp * s21_log(base));
    }
  }
  return res;
}
