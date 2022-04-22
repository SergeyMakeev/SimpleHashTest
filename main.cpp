#include "ubench.h"

#include "ExcaliburHash.h"


#include "flat_hash_map.hpp"
#include "unordered_map.hpp"


#include "robin_map.h"

#include "Luau/DenseHash.h"

#define FOLLY_NO_CONFIG
#include "folly/container/F14Map.h"
#include "folly/lang/SafeAssert.h"

namespace folly
{
	namespace detail
	{
		template <>
		void safe_assert_terminate<0>(safe_assert_arg const* arg, ...) noexcept {
			__debugbreak();
		}

		template <>
		void safe_assert_terminate<1>(safe_assert_arg const* arg, ...) noexcept {
			__debugbreak();
		}
	}

	namespace f14 {
		namespace detail {
			EmptyTagVectorType kEmptyTagVector = {};
		}
	}

}

#include "boost/unordered/unordered_map.hpp"


#include "absl/container/flat_hash_map.h"

namespace absl {
	namespace container_internal {
		// A single block of empty control bytes for tables without any slots allocated.
		// This enables removing a branch in the hot path of find().
		alignas(16) ABSL_CONST_INIT ABSL_DLL const ctrl_t kEmptyGroup[16] = {
			ctrl_t::kSentinel, ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty,
			ctrl_t::kEmpty,    ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty,
			ctrl_t::kEmpty,    ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty,
			ctrl_t::kEmpty,    ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty };
	}
}


#include "llvm/ADT/DenseMap.h"

#include "llvm/Support/MemAlloc.h"
#include <new>

// These are out of line to have __cpp_aligned_new not affect ABI.

LLVM_ATTRIBUTE_RETURNS_NONNULL LLVM_ATTRIBUTE_RETURNS_NOALIAS void*
llvm::allocate_buffer(size_t Size, size_t Alignment) {
	return ::operator new(Size
#ifdef __cpp_aligned_new
		,
		std::align_val_t(Alignment)
#endif
		);
}

void llvm::deallocate_buffer(void* Ptr, size_t Size, size_t Alignment) {
	::operator delete(Ptr
#ifdef __cpp_sized_deallocation
		,
		Size
#endif
#ifdef __cpp_aligned_new
		,
		std::align_val_t(Alignment)
#endif
		);
}


void test()
{
	Excalibur::HashTable<int, int> test01;
	ska::flat_hash_map<int, int> test02;
	ska::unordered_map<int, int> test03;
	tsl::robin_map<int, int> test04;
	Luau::DenseHashMap<int, int> test05(INT_MIN);
	folly::F14ValueMap<int, int> test06;
	boost::unordered_map<int, int> test07;
	absl::flat_hash_map<int, int> test08;
	llvm::DenseMap<int, int> test09;
}



UBENCH_MAIN()
