#include <iostream>

#include "type_name.h"

int main() {
  int a = 0;
  REPORT_TYPE_RUNTIME(a);
  std::cout << a << std::endl;
  auto b = a;
  b = 1;
  REPORT_TYPE_RUNTIME(b);
  std::cout << a << std::endl;
  decltype(a) c = a;
  c = 2;
  REPORT_TYPE_RUNTIME(c);
  std::cout << a << std::endl;
  decltype((a)) d = a;
  d = 3;
  REPORT_TYPE_RUNTIME(d);
  std::cout << a << std::endl;
  decltype(auto) e = a;
  e = 4;
  REPORT_TYPE_RUNTIME(e);
  std::cout << a << std::endl;
  decltype(auto) f = (a);
  f = 5;
  REPORT_TYPE_RUNTIME(f);
  std::cout << f << std::endl;
}
