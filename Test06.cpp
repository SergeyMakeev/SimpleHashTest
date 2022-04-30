#include "TestCommon.h"


struct Value
{
	int val = 0;
};


#define DO_TEST(THashMap) \
const std::vector<int>& randomNumbers = getRandomNumbersWithIntersections10(); \
for(int i = 0; i < 8; i++) \
{ \
	THashMap<int, Value> hashMap; \
	for (const int& num : randomNumbers) \
	{ \
		hashMap[num].val++; \
	} \
} \


UBENCH(InsertAccessWithProbability10, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(InsertAccessWithProbability10, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(InsertAccessWithProbability10, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(InsertAccessWithProbability10, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(InsertAccessWithProbability10, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(InsertAccessWithProbability10, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(InsertAccessWithProbability10, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(InsertAccessWithProbability10, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(InsertAccessWithProbability10, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(InsertAccessWithProbability10, StdUnordered)
{
	DO_TEST(std::unordered_map);
}

UBENCH(InsertAccessWithProbability10, GoogleDense)
{
	DO_TEST(GoogleDenseMap);
}
