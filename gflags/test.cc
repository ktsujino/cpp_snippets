#include <gflags/gflags.h>
#include <iostream>

namespace test {
DEFINE_bool(mybool, true, "boolean flagn");
DEFINE_string(mystring, "default string", "string flag");
DEFINE_int32(myint, 0, "int flag");
}

int main(int argc, char **argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::cout << test::FLAGS_myint << std::endl;
}
