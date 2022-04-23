#include "TestCommon.h"


#define DO_TEST(THashMap) \
THashMap<int, int> hashMap; \
for(int i = 0; i < 25; i++) \
{ \
	hashMap.clear(); \
	for(int j = 0; j < 599999; j++) \
	{ \
		hashMap.emplace(j, -j); \
	} \
} \


UBENCH(ClearAndInsertSeq, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(ClearAndInsertSeq, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(ClearAndInsertSeq, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(ClearAndInsertSeq, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(ClearAndInsertSeq, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(ClearAndInsertSeq, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(ClearAndInsertSeq, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(ClearAndInsertSeq, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(ClearAndInsertSeq, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(ClearAndInsertSeq, StdUnordered)
{
	DO_TEST(std::unordered_map);
}
