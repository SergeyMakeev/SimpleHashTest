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


template<typename K, typename V>
struct LuauDenseHashMap : public Luau::DenseHashMap<K, V>
{
	LuauDenseHashMap(const K& empty_key = Excalibur::KeyInfo<K>::getEmpty())
		: DenseHashMap(empty_key)
	{
	}
};




#define TEST_CTOR_DTOR(name) \
for(int i = 0; i < 300000; i++) \
{ \
	name<int, HeavyWeightObject> hashMap; \
} \


UBENCH(CtorDtor, Excalibur)
{
	TEST_CTOR_DTOR(Excalibur::HashTable);
}

UBENCH(CtorDtor, SkaFlatMap)
{
	TEST_CTOR_DTOR(ska::flat_hash_map);
}

UBENCH(CtorDtor, SkaUnorderedMap)
{
	TEST_CTOR_DTOR(ska::unordered_map);
}

UBENCH(CtorDtor, TslRobin)
{
	TEST_CTOR_DTOR(tsl::robin_map);
}

UBENCH(CtorDtor, LuauDense)
{
	TEST_CTOR_DTOR(LuauDenseHashMap);
}

UBENCH(CtorDtor, FollyF14)
{
	TEST_CTOR_DTOR(folly::F14ValueMap);
}

UBENCH(CtorDtor, BoostUnordered)
{
	TEST_CTOR_DTOR(boost::unordered_map);
}

UBENCH(CtorDtor, AbslFlatMap)
{
	TEST_CTOR_DTOR(absl::flat_hash_map);
}

UBENCH(CtorDtor, LlvmDense)
{
	TEST_CTOR_DTOR(llvm::DenseMap);
}

UBENCH(CtorDtor, StdUnordered)
{
	TEST_CTOR_DTOR(std::unordered_map);
}
