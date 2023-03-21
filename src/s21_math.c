#include "s21_math.h"

struct_float128 longdouble_to_struct_float128(__float128 n) {
  struct_float128 float128;
  float128.sign = *((__uint128_t*)&n) >> 127;
  float128.power = (*((__uint128_t*)&n) << 1) >> 113;
  float128.fraction = (*((__uint128_t*)&n) << 16) >> 16;
  return float128;
}
