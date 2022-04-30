#include "TestCommon.h"


#define DO_TEST(THashMap) \
const std::vector<int>& randomNumbers = getUniquePositiveRandomNumbers(); \
for(int i = 0; i < 25; i++) \
{ \
	THashMap<int, int> hashMap; \
	for (const int& num : randomNumbers) \
	{ \
		hashMap.emplace(num, -num); \
	} \
} \


UBENCH(ClearAndInsertRnd, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(ClearAndInsertRnd, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(ClearAndInsertRnd, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(ClearAndInsertRnd, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(ClearAndInsertRnd, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(ClearAndInsertRnd, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(ClearAndInsertRnd, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(ClearAndInsertRnd, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(ClearAndInsertRnd, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(ClearAndInsertRnd, StdUnordered)
{
	DO_TEST(std::unordered_map);
}

UBENCH(ClearAndInsertRnd, GoogleDense)
{
	DO_TEST(GoogleDenseMap);
}
