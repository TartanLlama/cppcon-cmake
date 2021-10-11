#define _HAS_ITERATOR_DEBUGGING 0
#define _ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
#include <iostream>
#include <tl/generator.hpp>
#include <ranges>
#include <vector>
#include "xorshift.hpp"


int main()
{
    auto random_numbers = cppcon::xorshift(4)
        | std::views::take(4)
        | std::views::transform([](auto i) { return i % 100; });
    
    for (auto i : random_numbers) {
        std::cout << i << '\n';
    }
}
