// {{{ FFT Generic
template<typename T>
struct FFTTrait {
  static T getRoot(int, bool) { assert(false); }
};

template<>
struct FFTTrait<complex<double>> {
  static complex<double> getRoot(int len, bool rev) {
    double ang = 2 * M_PI / len;
    return rev ? complex<double>{cos(ang), sin(ang)} : complex<double>{cos(-ang), sin(-ang)};
  }
};

template<typename T = complex<double>, typename Trait = FFTTrait<T>>
struct FFT {
  const static int MAXLEN = 1 << 20;
  static void reorder(vector<T> &data) {
    int n = SZ(data);
    assert(n > 0 && (n & (n - 1)) == 0);
    int bitCount = __builtin_ctz(n);
    for (int i = 0; i < n; i++) {
      int j = 0;
      for (int b = 0; b < bitCount; b++) {
        if (i & (1 << b)) {
          j |= 1 << (bitCount - 1 - b);
        }
      }
      if (i < j) {
        swap(data[i], data[j]);
      }
    }
  }
  static void fix(vector<T> &data) {
    int n = 1;
    while (n < SZ(data)) n *= 2;
    n *= 2;
    data.resize(n);
  }
  static void fft(vector<T> &data, bool rev) {
    reorder(data);
    int n = SZ(data);
    for (int len = 2; len <= n; len <<= 1) {
      static T roots[MAXLEN];
      int len2 = len >> 1;
      T w = Trait::getRoot(len, rev);
      roots[0] = T(1);
      for (int i = 1; i < len2; i++) {
        roots[i] = roots[i - 1] * w; // binary? can be precomputed
      }
      for (int i = 0; i < n; i += len) {
        for (int j = 0; j < len2; j++) {
          T p = data[i + j];
          T q = roots[j] * data[i + j + len2];
          data[i + j] = p + q;
          data[i + j + len2] = p - q;
        }
      }
    }
    if (rev) {
      for (int i = 0; i < n; i++) {
        data[i] /= n;
      }
    }
  }
};
// }}}
