#include "TestCommon.h"
#include "slot_map.h"

#define COMMA ,

struct DodSlotMap
{
	dod::slot_map<int> slotMap;

	uint64_t emplace(int val)
	{
		dod::slot_map_key<int> key = slotMap.emplace(val);
		return key;
	}

};


namespace Excalibur
{
	template <> struct KeyInfo<uint64_t>
	{
		static inline bool isValid(const uint64_t& key) noexcept { return key < 0xfffffffffffffffeL; }
		static inline uint64_t getTombstone() noexcept { return 0xffffffffffffffffL; }
		static inline uint64_t getEmpty() noexcept { return 0xfffffffffffffffeL; }
		static inline uint64_t hash(const uint64_t& key) noexcept { return key; }
		static inline bool isEqual(const uint64_t& lhs, const uint64_t& rhs) noexcept { return lhs == rhs; }
	};

}

template<typename THashMap>
struct SlotMapAdapter
{
	uint64_t id = 0;
	THashMap hashMap;

	uint64_t emplace(int val)
	{
		uint64_t r = id;
		hashMap.emplace(id, val);
		id++;
		return r;
	}
};


#define DO_TEST(TSlotMap) \
const std::vector<int>& randomNumbers = getUniquePositiveRandomNumbers(); \
for(int i = 0; i < 25; i++) \
{ \
	TSlotMap slotMap; \
	for (const int& num : randomNumbers) \
	{ \
		slotMap.emplace(num); \
	} \
} \




UBENCH(SlotMap, DodSlotMap)
{
	DO_TEST(DodSlotMap);
}

UBENCH(SlotMap, Excalibur)
{
	DO_TEST(SlotMapAdapter<Excalibur::HashTable<uint64_t COMMA int>>);
}

UBENCH(SlotMap, SkaFlatMap)
{
	DO_TEST(SlotMapAdapter < ska::flat_hash_map<uint64_t COMMA int>>);
}

UBENCH(SlotMap, SkaUnorderedMap)
{
	DO_TEST(SlotMapAdapter < ska::unordered_map<uint64_t COMMA int>>);
}

UBENCH(SlotMap, TslRobin)
{
	DO_TEST(SlotMapAdapter < tsl::robin_map<uint64_t COMMA int>>);
}

UBENCH(SlotMap, LuauDense)
{
	DO_TEST(SlotMapAdapter < LuauDenseHashMap<uint64_t COMMA int>>);
}

UBENCH(SlotMap, FollyF14)
{
	DO_TEST(SlotMapAdapter < folly::F14ValueMap<uint64_t COMMA int>>);
}

UBENCH(SlotMap, BoostUnordered)
{
	DO_TEST(SlotMapAdapter < boost::unordered_map<uint64_t COMMA int>>);
}

UBENCH(SlotMap, AbslFlatMap)
{
	DO_TEST(SlotMapAdapter < absl::flat_hash_map<uint64_t COMMA int>>);
}

UBENCH(SlotMap, LlvmDense)
{
	DO_TEST(SlotMapAdapter < LlvmDenseMap<uint64_t COMMA int>>);
}

UBENCH(SlotMap, StdUnordered)
{
	DO_TEST(SlotMapAdapter < std::unordered_map<uint64_t COMMA int>>);
}

UBENCH(SlotMap, GoogleDense)
{
	DO_TEST(SlotMapAdapter < GoogleDenseMap<uint64_t COMMA int>>);
}
