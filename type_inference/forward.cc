#include <iostream>

#include "type_name.h"

class VerboseInt {
 public:
  VerboseInt(const int val) {
    val_ = new int(val);
  };

  VerboseInt(const VerboseInt &x) {
    std::cout << "Copying " << &x << std::endl;
    val_ = new int(x.val());
  };

  VerboseInt(const VerboseInt &&x) {
    std::cout << "Moving " << &x << std::endl;
    val_ = x.val_;
  };

  int val() const {
    return *val_;
  }

  int *val_;
};

template <class T>
auto constructWithForward(T&& x) {
  REPORT_TYPE_RUNTIME(x);
  std::cout << "\t";
  return T(std::forward<T>(x));
}

template <class T>
auto constructWithoutForward(T&& x) {
  REPORT_TYPE_RUNTIME(x);
  std::cout << "\t";
  return T(x);
}

template <class T>
decltype(auto) getReference(T&& x) {
  REPORT_TYPE_RUNTIME(x);
  std::cout << std::endl;
  return *(std::forward<T>(x).val_); // returns reference because of decltype(auto)
}

decltype(auto) foo() {
  static int x = 0;
  return (x); // returns reference because of decltype(auto) and () around x
}

int main() {
  VerboseInt x(0);
  VerboseInt &rx = x;
  VerboseInt copied_with_fwd_x = constructWithForward(x);
  VerboseInt moved_with_fwd_x = constructWithForward(std::move(x));
  VerboseInt copied_with_fwd_rx = constructWithForward(rx);
  VerboseInt moved_with_fwd_rx = constructWithForward(std::move(rx));

  VerboseInt copied_without_fwd_x = constructWithoutForward(x);
  VerboseInt moved_without_fwd_x = constructWithoutForward(std::move(x));
  VerboseInt copied_without_fwd_rx = constructWithoutForward(rx);
  VerboseInt moved_without_fwd_rx = constructWithoutForward(std::move(rx));

  getReference(x) = 1;
  REPORT_TYPE_RUNTIME(getReference(x));
  std::cout << copied_with_fwd_x.val() << std::endl;
  std::cout << moved_with_fwd_x.val() << std::endl;
  std::cout << foo() << std::endl;
  foo() = 1;
  std::cout << foo() << std::endl;
}
