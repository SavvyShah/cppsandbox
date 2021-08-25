#include <vector>
#include <string>

#include <benchmark/benchmark.h>

#include "solution.h"

/* Limits for benchmarking code
 * If you don't know the big O of code then run upto 1<<5
 * If at most O(n^2) run upto 1 << 10
 * If at most O(nlgn) run upto 1 << 15
 * If at most O(n) run upto 1 << 20
 * You can increase the limit if the RMS error % is larger.
 */

static void BM_RadixSort(benchmark::State& state) {
  Solution s;
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> v;
    for(int i{0}; i < state.range(0); i++)
    {
      int random = rand();
      v.push_back(random);
    }
    state.ResumeTiming();
    s.solution(v);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_RadixSort)
    ->RangeMultiplier(2)->Range(1<<5, 1<<15)->Complexity();


static void BM_StdSort(benchmark::State& state) {
  Solution s;
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> v;
    for(int i{0}; i < state.range(0); i++)
    {
      int random = rand();
      v.push_back(random);
    }
    state.ResumeTiming();
    std::sort(v.begin(), v.end());
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_StdSort)
    ->RangeMultiplier(2)->Range(1<<5, 1<<15)->Complexity();


//Define main function by replacing the below line
BENCHMARK_MAIN();


