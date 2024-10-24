#include <cudaq.h>

__qpu__ void teleportation() {
  cudaq::qvector q(3);
  u3(3.14, 2.71, 6.62, q[0]);
  h(q[1]);
  cx(q[1], q[2]);
  cx(q[0], q[1]);
  h(q[0]);
  if (mz(q[0])) {
    z(q[2]);
  }
  if (mz(q[1])) {
    x(q[2]);
  }
  mz(q[2]);
}

int main() {
  auto test = []() __qpu__ {
    cudaq::qubit q;
    u3(3.14, 2.71, 6.62, q);
    mz(q);
  };
  cudaq::get_state(test).dump();
  cudaq::get_state(teleportation).dump();

  return EXIT_SUCCESS;
}