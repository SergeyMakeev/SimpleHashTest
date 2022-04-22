#include "ubench.h"

#include "ExcaliburHash.h"


#include "flat_hash_map.hpp"
#include "unordered_map.hpp"


#include "robin_map.h"

#include "Luau/DenseHash.h"

#define _PROFILEAPI_H_
#define FOLLY_NO_CONFIG
#include "folly/container/F14Map.h"
#include "folly/lang/SafeAssert.cpp"
#include "folly/lang/ToAscii.cpp"
#include "folly/ScopeGuard.cpp"
#include "folly/container/detail/F14Table.cpp"


#include "boost/unordered/unordered_map.hpp"


#include "absl/container/flat_hash_map.h"
#include "absl/container/internal/raw_hash_set.cc"
#include "absl/hash/internal/hash.cc"
#include "absl/hash/internal/city.cc"
#include "absl/hash/internal/low_level_hash.cc"




#include "llvm/ADT/DenseMap.h"
#include "Support/MemAlloc.cpp"


void test()
{
	Excalibur::HashTable<int, int> test01;
	test01.emplace(1, 2);

	ska::flat_hash_map<int, int> test02;
	test02.emplace(1, 2);

	ska::unordered_map<int, int> test03;
	test03.emplace(1, 2);

	tsl::robin_map<int, int> test04;
	test04.emplace(1, 2);

	Luau::DenseHashMap<int, int> test05(INT_MIN);
	test05[1] = 2;

	folly::F14ValueMap<int, int> test06;
	test06.emplace(1, 2);

	boost::unordered_map<int, int> test07;
	test07.emplace(1, 2);

	absl::flat_hash_map<int, int> test08;
	test08.emplace(1, 2);

	llvm::DenseMap<int, int> test09;
	test09.try_emplace(1, 2);
}


struct PreMain
{
	PreMain()
	{
		test();
	}
};

PreMain preMain;


UBENCH_MAIN()
