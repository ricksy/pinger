#include<iostream>
#include <sys/utsname.h>
#include <csignal>
#include <chrono>
#include <thread>

namespace {
    volatile std::sig_atomic_t gSignalStatus;
}

void my_handler(int signal) {
  gSignalStatus = signal;
  std::cout << "Caught signal" << gSignalStatus << "\n";
  exit(1);
}

using namespace std::chrono_literals;

int main() {
  std::signal(SIGINT, my_handler);
  utsname u;
  if (uname(&u) != 0)
    return 1;
  std::cout << "Hello Docker from " << u.nodename << "!!!\n";
  unsigned int i{10};
  while (--i) {
    int x = system("ping -c1 -s1 8.8.8.8  > /dev/null 2>&1");
    if (x == 0) {
      std::cout << "internet is available" << "\n" << std::flush;;
    } else {
      std::cout << "no internet conneciton" << "\n" << std::flush;;
    }
    std::this_thread::sleep_for(1s);
  }
  return 0;
}
