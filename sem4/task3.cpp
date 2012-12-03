#include <vector>
#include <iostream>

template<size_t n>
class Permutation {
  private:
    std::vector<size_t> perm_;

  public:
    Permutation() : perm_(n) {
      for (size_t i = 0; i < n; ++i) {
        perm_[i] = i;
      }
    }

    Permutation(const std::vector<size_t>& perm) : perm_(n) {
      std::copy(perm.begin(), perm.end(), perm_.begin());
    }

    Permutation& operator *= (const Permutation& other) {
      std::vector<size_t> result(n);
      for (size_t i = 0; i < n; ++i) {
        result[i] = perm_[other.perm_[i]];
      }
      perm_ = result;
      return *this;
    }

    Permutation operator * (const Permutation& other) const {
      Permutation result(*this);
      return result *= other;
    }

    Permutation inverse() const {
      Permutation result(*this);
      for (size_t i = 0; i < n; ++i) {
        result.perm_[perm_[i]] = i;
      }
      return result;
    }

    std::vector<std::vector<size_t> > independent_cycles() const {
      std::vector<std::vector<size_t> > result;
      std::vector<bool> seen(n, false);

      size_t count = 0;
      for (size_t i = 0; i < n; ++i) {
        if (seen[i]) {
          continue;
        }
        seen[i] = true;
        size_t begin = i, cur = i;
        result.push_back(std::vector<size_t>());
        while (1) {
          seen[cur] = true;
          result[count].push_back(perm_[cur]);
          cur = perm_[cur];
          if (cur == begin) {
            break;
          }
        }
        ++count;
      }

      return result;
    }

    template<size_t m>
    friend std::ostream& operator << (std::ostream& os, const Permutation<m>& perm);
};

template<size_t m>
std::ostream& operator << (std::ostream& os, const Permutation<m>& perm) {
  for (size_t i = 0; i < m; ++i) {
    os << perm.perm_[i] << ' ';
  }
  return os;
}

int main() {
  std::vector<size_t> p;
  p.push_back(2);
  p.push_back(0);
  p.push_back(1);

  Permutation<3> perm(p);

  std::cout << perm << '\n';
  std::cout << perm.inverse() << '\n';

  Permutation<3> pi = perm.inverse();

  std::cout << perm * pi << '\n';
  std::cout << pi * perm << '\n';

  std::vector<std::vector<size_t> > cycles;
  std::vector<size_t> pp;
  pp.push_back(1);
  pp.push_back(0);
  pp.push_back(3);
  pp.push_back(2);
  Permutation<4> perm1(pp);
  std::cout << "split\n";
  std::cout << perm1 << '\n';
  std::cout << "cycles\n";
  cycles = perm1.independent_cycles();
  for (size_t i = 0; i < cycles.size(); ++i) {
    for (size_t j = 0; j < cycles[i].size(); ++j) {
      std::cout << cycles[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
