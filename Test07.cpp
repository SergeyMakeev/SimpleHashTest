#include "TestCommon.h"


struct Value
{
	int val = 0;
};


#define DO_TEST(THashMap) \
const std::vector<int>& randomNumbers = getRandomNumbersWithIntersections50(); \
for(int i = 0; i < 8; i++) \
{ \
	THashMap<int, Value> hashMap; \
	for (const int& num : randomNumbers) \
	{ \
		hashMap[num].val++; \
	} \
} \


UBENCH(InsertAccessWithProbability50, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(InsertAccessWithProbability50, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(InsertAccessWithProbability50, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(InsertAccessWithProbability50, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(InsertAccessWithProbability50, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(InsertAccessWithProbability50, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(InsertAccessWithProbability50, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(InsertAccessWithProbability50, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(InsertAccessWithProbability50, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(InsertAccessWithProbability50, StdUnordered)
{
	DO_TEST(std::unordered_map);
}

UBENCH(InsertAccessWithProbability50, GoogleDense)
{
	DO_TEST(GoogleDenseMap);
}

UBENCH(InsertAccessWithProbability50, BoostUnorderedFlat)
{
	DO_TEST(boost::unordered_flat_map);
}

UBENCH(InsertAccessWithProbability50, ParallelHashmap)
{
	DO_TEST(phmap::flat_hash_map);
}
