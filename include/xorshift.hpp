#pragma once
#include <cstdint>
#include <tl/generator.hpp>

namespace cppcon {
	tl::generator<std::uint64_t> xorshift(std::uint64_t seed) {
		while (true) {
			seed ^= seed << 13;
			seed ^= seed >> 7;
			seed ^= seed << 17;
			co_yield seed;
		}
	}
}