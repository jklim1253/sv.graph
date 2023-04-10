#ifndef __SV_GRAPH_HPP__
#define __SV_GRAPH_HPP__

#include <iostream>

namespace sv
{

template<class T, std::uint8_t Dimension>
struct vertex
{
  using element_type = T;
  static constexpr std::uint8_t dimension = Dimension;

  T pos[Dimension];
};

template<class T>
using vertex_1 = vertex<T, 1>;

using vertex_1i = vertex_1<int>;
using vertex_1p = vertex_1<float>;

template<std::uint8_t D>
using vertex_i = vertex<int, D>;

template<class T, std::uint8_t D>
std::ostream& operator << (std::ostream& os, vertex<T,D> const& o)
{
  os << '(';

  bool begin = true;
  for (auto const& e : o.pos)
  {
    if (begin)
    {
      begin = !begin;
    }
    else
    {
      os << ", ";
    }
    os << e;
  }

  os << ')';
  return os;
}

template<class T, std::uint8_t Dimension, class Vertex = vertex<T, Dimension>>
struct edge
{
  using vertex_type = Vertex;
  using element_type = typename vertex_type::element_type;
  static constexpr std::uint8_t dimension = Vertex::dimension;

  Vertex sv; // start vertex
  Vertex ev; // end vertex
};

template<class T>
using edge_1 = edge<T, 1>;

using edge_1i = edge_1<int>;
using edge_1p = edge_1<float>;

template<std::uint8_t D>
using edge_i = edge<int, D>;

template<class T, std::uint8_t D>
std::ostream& operator << (std::ostream& os, edge<T,D> const& o)
{
  os << '[';
  os << o.sv << '-';
  os << o.ev;
  os << ']';
  return os;
}

} // namespace sv

#endif // __SV_GRAPH_HPP__