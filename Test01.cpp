#include "TestCommon.h"
#include <thread>

struct HeavyWeightObject
{
	uint32_t val;
	HeavyWeightObject()
	{
		// Simulate heavy ctor workload with a sleep
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		val = rand();
	}
};


#define DO_TEST(THashMap) \
for(int i = 0; i < 300000; i++) \
{ \
	THashMap<int, HeavyWeightObject> hashMap; \
} \


UBENCH(CtorDtor, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(CtorDtor, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(CtorDtor, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(CtorDtor, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(CtorDtor, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(CtorDtor, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(CtorDtor, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(CtorDtor, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(CtorDtor, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(CtorDtor, StdUnordered)
{
	DO_TEST(std::unordered_map);
}
