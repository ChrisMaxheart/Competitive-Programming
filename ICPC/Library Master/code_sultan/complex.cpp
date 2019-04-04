// add : a + b
// scalar multi : r * a
// dot product : (conj(a) * b).x
// cross product : (conj(a) * b).y
// squared distance : norm(a - b)
// euclidean distance : abs(a - b)
// angle of elevation : arg(b - a)
// slope of line (a, b) : tan(arg(b - a))
// polar to cartesian : polar(r, theta)
// rotation about the origin : a * polar(1.0, theta)
// rotation about pivot p : (a - p) * polar(1.0, theta) + p
// angle ABC: abs(remainder(arg(a - b) - arg(c - b), 2.0 * M_PI)) distance: [-PI, PI]
// project p onto vector v : v * dot(p, v) / norm(v)
// project p onto line(a, b) : a + (b - a) * dot(p - a, b - a) / norm(b - a)
// reflect p across line (a, b) : a + conj((p - a) / (b - a)) * (b - a)
// relect p across line (a, b) : a + conj((p - a) / (b - a)) * (b - a)
// intersection of line(a, b) and (p, q) :
point intersection(point a, point b, point c) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); //undefined if parallel
}
// read:
template<class T>
istream &operator>>(istream &is, complex<T> &p) {
  T value;
  is >> value;
  p.real(value);
  is >> value;
  p.imag(value);
  return is;
}
