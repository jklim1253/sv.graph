#include <iostream>
#include "sv/graph.hpp"

int main(int argc, const char** argv)
{
  sv::edge_i<2> sample;
  sample.sv = {1, 114};
  sample.ev = {23, 12531};

  std::cout << sample << std::endl;
  return 0;
}
