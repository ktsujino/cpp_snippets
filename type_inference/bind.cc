#include <iostream>

#include "type_name.h"

void funcWithLValueRefArg(int &x) {
  std::cout << x << std::endl;
}

void funcWithConstLValueRefArg(const int &x) {
  std::cout << x << std::endl;
}

void funcWithRValueRefArg(int &&x) {
  std::cout << x << std::endl;
}

int main() {
  int x = 0;
  funcWithLValueRefArg(x);
  funcWithConstLValueRefArg(x);
  // funcWithRValueRefArg(x); // doesn't compile

  const int cx = 0;
  // funcWithLValueRefArg(cx); // doesn't compile
  funcWithConstLValueRefArg(cx);
  // funcWithRValueRefArg(cx); // doesn't compile

  // funcWithLValueRefArg(std::move(x)); // doesn't compile
  funcWithConstLValueRefArg(std::move(x)); // DOES COMPILE
  funcWithRValueRefArg(std::move(x));

  
  return 0;
}
