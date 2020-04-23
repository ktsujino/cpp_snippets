#include <iostream>

#include <boost/type_index.hpp>

#include "type_name.h"

// template type inference

#define REPORT_TYPE_TEMPLATE(T) \
  std::cout << "Type of " << (#T) << " is " << boost::typeindex::type_id_with_cvr<T>().pretty_name();

#define REPORT_TYPE_AND_CALL(x, func) \
  std::cout << "\t"; REPORT_TYPE_RUNTIME(x); std::cout << "\t\t"; func(x);

template <class T>
void templateFuncWithRefArg(T& x) {
  std::cout << __func__ << "() inferred:\t";
  REPORT_TYPE_TEMPLATE(T);
  std::cout << std::endl;
}

template <class T>
void templateFuncWithConstRefArg(const T& x) {
  std::cout << __func__ << "() inferred:\t";
  REPORT_TYPE_TEMPLATE(T);
  std::cout << std::endl;
}

template <class T>
void templateFuncWithPtrArg(T* x) {
  std::cout << __func__ << "() inferred:\t";
  REPORT_TYPE_TEMPLATE(T);
  std::cout << std::endl;
}

template <class T>
void templateFuncWithConstPtrArg(const T* x) {
  std::cout << __func__ << "() inferred:\t";
  REPORT_TYPE_TEMPLATE(T);
  std::cout << std::endl;
}

template <class T>
void templateFuncWithValArg(const T x) {
  std::cout << __func__ << "() inferred:\t";
  REPORT_TYPE_TEMPLATE(T);
  std::cout << std::endl;
}

template <class T>
void templateFuncWithConstValArg(const T x) {
  std::cout << __func__ << "() inferred:\t";
  REPORT_TYPE_TEMPLATE(T);
  std::cout << std::endl;
}

template <class T>
void templateFuncWithFwdRefArg(T&& x) {
  std::cout << __func__ << "() inferred:\t";
  REPORT_TYPE_TEMPLATE(T);
  std::cout << std::endl;
}

void funcWithRValueRefArg(int && x) {
  std::cout << __func__ << "() arg type:\t";
  REPORT_TYPE_RUNTIME(x);
  std::cout << std::endl;
}

int main() {
  int x = 0;
  int* px = &x;
  int* const cpx = &x;
  int &rx = x;
  const int &crx = x;
  
  const int cx = 0;
  const int* pcx = &cx;
  const int* const cpcx = &cx;
  const int &crcx = cx;

  std::cout << std::endl << "When paramType has ref: " << std::endl;
  REPORT_TYPE_AND_CALL(x, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(px, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(cpx, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(rx, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(crx, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(cx, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(pcx, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(cpcx, templateFuncWithRefArg);
  REPORT_TYPE_AND_CALL(crcx, templateFuncWithRefArg);

  std::cout << std::endl << "When paramType has const ref: " << std::endl;  
  REPORT_TYPE_AND_CALL(x, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(px, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(cpx, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(rx, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(crx, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(cx, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(pcx, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(cpcx, templateFuncWithConstRefArg);
  REPORT_TYPE_AND_CALL(crcx, templateFuncWithConstRefArg);

  std::cout << std::endl << "When paramType has ptr: " << std::endl;
  // REPORT_TYPE_AND_CALL(x, templateFuncWithPtrArg);
  REPORT_TYPE_AND_CALL(px, templateFuncWithPtrArg);
  REPORT_TYPE_AND_CALL(cpx, templateFuncWithPtrArg);
  // REPORT_TYPE_AND_CALL(rx, templateFuncWithPtrArg);
  // REPORT_TYPE_AND_CALL(crx, templateFuncWithPtrArg);
  // REPORT_TYPE_AND_CALL(cx, templateFuncWithPtrArg);
  REPORT_TYPE_AND_CALL(pcx, templateFuncWithPtrArg);
  REPORT_TYPE_AND_CALL(cpcx, templateFuncWithPtrArg);
  // REPORT_TYPE_AND_CALL(crcx, templateFuncWithPtrArg);

  std::cout << std::endl << "When paramType has const ptr: " << std::endl;
  // REPORT_TYPE_AND_CALL(x, templateFuncWithConstPtrArg);
  REPORT_TYPE_AND_CALL(px, templateFuncWithConstPtrArg);
  REPORT_TYPE_AND_CALL(cpx, templateFuncWithConstPtrArg);
  // REPORT_TYPE_AND_CALL(rx, templateFuncWithConstPtrArg);
  // REPORT_TYPE_AND_CALL(crx, templateFuncWithConstPtrArg);
  // REPORT_TYPE_AND_CALL(cx, templateFuncWithConstPtrArg);
  REPORT_TYPE_AND_CALL(pcx, templateFuncWithConstPtrArg);
  REPORT_TYPE_AND_CALL(cpcx, templateFuncWithConstPtrArg);
  // REPORT_TYPE_AND_CALL(crcx, templateFuncWithConstPtrArg);

  std::cout << std::endl << "When paramType has val: " << std::endl;
  REPORT_TYPE_AND_CALL(x, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(px, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(cpx, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(rx, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(crx, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(cx, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(pcx, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(cpcx, templateFuncWithValArg);
  REPORT_TYPE_AND_CALL(crcx, templateFuncWithValArg);

  std::cout << std::endl << "When paramType has const val: " << std::endl;
  REPORT_TYPE_AND_CALL(x, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(px, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(cpx, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(rx, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(crx, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(cx, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(pcx, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(cpcx, templateFuncWithConstValArg);
  REPORT_TYPE_AND_CALL(crcx, templateFuncWithConstValArg);

  std::cout << std::endl << "When paramType has fwd ref: " << std::endl;
  REPORT_TYPE_AND_CALL(x, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(x), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(px, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(px), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(cpx, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(cpx), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(rx, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(rx), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(crx, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(crx), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(cx, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(cx), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(pcx, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(pcx), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(cpcx, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(cpcx), templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(crcx, templateFuncWithFwdRefArg);
  REPORT_TYPE_AND_CALL(std::move(crcx), templateFuncWithFwdRefArg);

  std::cout << std::endl << "When calling non-template func with rvalue ref: " << std::endl;
  // REPORT_TYPE_AND_CALL(x, funcWithRValueRefArg);
  REPORT_TYPE_AND_CALL(std::move(x), funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(px, funcWithRValueRefArg);
  //REPORT_TYPE_AND_CALL(std::move(px), funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(cpx, funcWithRValueRefArg);
  //REPORT_TYPE_AND_CALL(std::move(cpx), funcWithRValueRefArg);
  //REPORT_TYPE_AND_CALL(rx, funcWithRValueRefArg);
  REPORT_TYPE_AND_CALL(std::move(rx), funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(crx, funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(std::move(crx), funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(cx, funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(std::move(cx), funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(pcx, funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(std::move(pcx), funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(cpcx, funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(std::move(cpcx), funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(crcx, funcWithRValueRefArg);
  // REPORT_TYPE_AND_CALL(std::move(crcx), funcWithRValueRefArg);
}
