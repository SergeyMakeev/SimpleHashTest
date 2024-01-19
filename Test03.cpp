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
	hashMap.clear(); \
	for (const int& num : randomNumbers) \
	{ \
		hashMap.emplace(num, -num); \
	} \
} \


UBENCH(InsertRndClearAndReInsert, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(InsertRndClearAndReInsert, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(InsertRndClearAndReInsert, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(InsertRndClearAndReInsert, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(InsertRndClearAndReInsert, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(InsertRndClearAndReInsert, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(InsertRndClearAndReInsert, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(InsertRndClearAndReInsert, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(InsertRndClearAndReInsert, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(InsertRndClearAndReInsert, StdUnordered)
{
	DO_TEST(std::unordered_map);
}

UBENCH(InsertRndClearAndReInsert, GoogleDense)
{
	DO_TEST(GoogleDenseMap);
}

UBENCH(InsertRndClearAndReInsert, BoostUnorderedFlat)
{
	DO_TEST(boost::unordered_flat_map);
}

UBENCH(InsertRndClearAndReInsert, ParallelHashmap)
{
	DO_TEST(phmap::flat_hash_map);
}
