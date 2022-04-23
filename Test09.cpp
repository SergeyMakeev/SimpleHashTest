#include "TestCommon.h"


template<typename T>
struct TAdder
{
	uint64_t val = 0;

	void step(const T& hashMap, int search)
	{
		const auto it = hashMap.find(search);
		const int& v = it->second;
		val += v;
	}
};

template<>
struct TAdder<LuauDenseHashMap<int, int>>
{
	uint64_t val = 0;

	void step(const LuauDenseHashMap<int, int>& hashMap, int search)
	{
		const int* v = hashMap.find(search);
		val += *v;
	}
};


#define DO_TEST(THashMap) \
const std::vector<int>& randomNumbers = getUniquePositiveRandomNumbers(); \
THashMap<int, int> hashMap; \
for (const int& num : randomNumbers) \
{ \
	hashMap.emplace(num, num); \
} \
for(int i = 0; i < 10; i++) \
{ \
	TAdder<THashMap<int, int>> sum; \
	for (const int& num : randomNumbers) \
	{ \
		sum.step(hashMap, num); \
	} \
	UBENCH_DO_NOTHING(&sum.val); \
} \


UBENCH(SearchExisting, Excalibur)
{
	DO_TEST(Excalibur::HashTable);
}

UBENCH(SearchExisting, SkaFlatMap)
{
	DO_TEST(ska::flat_hash_map);
}

UBENCH(SearchExisting, SkaUnorderedMap)
{
	DO_TEST(ska::unordered_map);
}

UBENCH(SearchExisting, TslRobin)
{
	DO_TEST(tsl::robin_map);
}

UBENCH(SearchExisting, LuauDense)
{
	DO_TEST(LuauDenseHashMap);
}

UBENCH(SearchExisting, FollyF14)
{
	DO_TEST(folly::F14ValueMap);
}

UBENCH(SearchExisting, BoostUnordered)
{
	DO_TEST(boost::unordered_map);
}

UBENCH(SearchExisting, AbslFlatMap)
{
	DO_TEST(absl::flat_hash_map);
}

UBENCH(SearchExisting, LlvmDense)
{
	DO_TEST(LlvmDenseMap);
}

UBENCH(SearchExisting, StdUnordered)
{
	DO_TEST(std::unordered_map);
}

