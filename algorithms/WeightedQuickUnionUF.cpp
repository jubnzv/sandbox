#include <vector>

class WeightedQuickUnionUF {
public:
  WeightedQuickUnionUF(int N)
      : Count(N), Sizes(std::vector<int>(N)), Ids(std::vector<int>(N)) {
    std::fill(Sizes.begin(), Sizes.end(), 0);
  }

  int size() const { return Count; }

  bool connected(int p, int q) const { return find(p) == find(q); }

  int find(int p) const {
    // Follow links to find a root
    while (p != Ids[p])
      p = Ids[p];
    return p;
  }

  void do_union(int p, int q) {
    int i = find(p);
    int j = find(q);
    if (i == j)
      return;

    // Make smaller point to larger one.
    if (Sizes[i] < Sizes[j]) {
      Ids[i] = j;
      Sizes[j] += Sizes[i];
    } else {
      Ids[j] = i;
      Sizes[i] += Sizes[j];
    }

    Count -= 1;
  }

private:
  int Count;
  std::vector<int> Sizes;
  std::vector<int> Ids;
};

