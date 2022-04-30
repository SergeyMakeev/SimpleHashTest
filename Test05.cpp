#include "TestCommon.h"
#include <thread>



#define DO_TEST(THashMap) \
for(int i = 0; i < 300000; i++) \
{ \
	THashMap<int, int> hashMap; \
	hashMap.emplace(3, 3); \
} \


UBENCH(CtorSingleEmplaceDtor, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(CtorSingleEmplaceDtor, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(CtorSingleEmplaceDtor, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(CtorSingleEmplaceDtor, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(CtorSingleEmplaceDtor, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(CtorSingleEmplaceDtor, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(CtorSingleEmplaceDtor, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(CtorSingleEmplaceDtor, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(CtorSingleEmplaceDtor, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(CtorSingleEmplaceDtor, StdUnordered)
{
	DO_TEST(std::unordered_map);
}

UBENCH(CtorSingleEmplaceDtor, GoogleDense)
{
	DO_TEST(GoogleDenseMap);
}
