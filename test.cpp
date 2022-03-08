#include <vector>

#include "include/ts/builder.h"
#include "include/ts/ts.h"

int main() {
  using Data = std::uint64_t;

  // generate sequential dataset. Others appear to have the same issue
  std::vector<Data> dataset;
  dataset.reserve(1000);
  for (size_t i = 0; i < dataset.capacity(); i++) dataset.push_back(i + 20000);

  const Data min = *std::min_element(dataset.begin(), dataset.end());
  const Data max = *std::max_element(dataset.begin(), dataset.end());
  const auto max_error = 16;

  // build trie spline
  ts::Builder<Data> tsb(min, max, max_error);
  for (const auto& key : dataset) tsb.AddKey(key);
  const auto ts = tsb.Finalize();
}
