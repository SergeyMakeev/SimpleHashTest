#include "ubench.h"

#include "ExcaliburHash.h"


#include "flat_hash_map.hpp"
#include "unordered_map.hpp"


#include "robin_map.h"

#include "Luau/DenseHash.h"

#define FOLLY_NO_CONFIG
#include "folly/container/F14Map.h"


#include "boost/unordered/unordered_map.hpp"


void test()
{
	Excalibur::HashTable<int, int> test01;
	ska::flat_hash_map<int, int> test02;
	ska::unordered_map<int, int> test03;
	tsl::robin_map<int, int> test04;
	Luau::DenseHashMap<int, int> test05(INT_MIN);
	folly::F14ValueMap<int, int> test06;
}



UBENCH_MAIN()
