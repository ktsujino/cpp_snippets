#include <iostream>

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

 private:
  int *val_;
};

template <class T>
auto constructWithForward(T&& x) {
  return T(std::forward<T>(x));
}

template <class T>
auto constructWithoutForward(T&& x) {
  return T(x);
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
}
