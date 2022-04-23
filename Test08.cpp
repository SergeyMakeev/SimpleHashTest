#include "TestCommon.h"




#define DO_TEST(THashMap) \
const std::vector<int>& randomNumbers = getUniquePositiveRandomNumbers(); \
THashMap<int, int> hashMap; \
for (const int& num : randomNumbers) \
{ \
	hashMap.emplace(num, num); \
} \
for(int i = 0; i < 10; i++) \
{ \
	for (const int& num : randomNumbers) \
	{ \
		hashMap.find(-num); \
	} \
} \


UBENCH(SearchNonExisting, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(SearchNonExisting, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(SearchNonExisting, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(SearchNonExisting, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(SearchNonExisting, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(SearchNonExisting, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(SearchNonExisting, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(SearchNonExisting, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(SearchNonExisting, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(SearchNonExisting, StdUnordered)
{
	DO_TEST(std::unordered_map);
}
