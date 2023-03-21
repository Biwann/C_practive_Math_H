#include "s21_math.h"

long double s21_floor(double x) {
  if (s21_fabs(x) == S21_INF)
    x = x > 0 ? S21_INF : -S21_INF;
  else if (s21_fabs(x) < EPS)
    x = x > 0 ? 0.0 : -0.0;
  else {
    unsigned long entry;
    memcpy(&entry, &x, 8);
    int power = ((entry >> 52) & 0x7ff) - 1023;
    if (power >= 0) {
      int frac_bits = 52 - power;
      if (frac_bits > 0) {
        unsigned long int_mask = 0xffffffffffffffff << frac_bits;
        unsigned long exit = entry & int_mask;
        memcpy(&x, &exit, 8);
        if (x < 0 && exit != entry) x -= 1.0;
      }
    } else {
      x = x < 0 ? -1 : 0;
    }
  }
  return (long double)x;
}
