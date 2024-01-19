#include "TestCommon.h"

struct HeavyWeightObject
{
	int64_t val;
	HeavyWeightObject()
	{
		for (int i = 0; i < 400; i++)
		{
			val ^= rand();
		}
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

UBENCH(CtorDtor, GoogleDense)
{
	DO_TEST(GoogleDenseMap);
}

UBENCH(CtorDtor, BoostUnorderedFlat)
{
	DO_TEST(boost::unordered_flat_map);
}

UBENCH(CtorDtor, ParallelHashmap)
{
	DO_TEST(phmap::flat_hash_map);
}

