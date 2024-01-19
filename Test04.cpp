#include "TestCommon.h"



#define DO_TEST(THashMap) \
const std::vector<int>& randomNumbers = getUniquePositiveRandomNumbers(); \
for(int i = 0; i < 10; i++) \
{ \
	THashMap<int, int> hashMap; \
	for (const int& num : randomNumbers) \
	{ \
		hashMap.emplace(num, -num); \
	} \
	for (const int& num : randomNumbers) \
	{ \
		hashMap.erase(num); \
	} \
} \


UBENCH(InsertRndAndRemove, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(InsertRndAndRemove, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(InsertRndAndRemove, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(InsertRndAndRemove, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

/* luau doesn't support erase
UBENCH(InsertRndAndRemove, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}
*/

UBENCH(InsertRndAndRemove, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(InsertRndAndRemove, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(InsertRndAndRemove, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(InsertRndAndRemove, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(InsertRndAndRemove, StdUnordered)
{
	DO_TEST(std::unordered_map);
}

UBENCH(InsertRndAndRemove, GoogleDense)
{
	DO_TEST(GoogleDenseMap);
}

UBENCH(InsertRndAndRemove, BoostUnorderedFlat)
{
	DO_TEST(boost::unordered_flat_map);
}

UBENCH(InsertRndAndRemove, ParallelHashmap)
{
	DO_TEST(phmap::flat_hash_map);
}

