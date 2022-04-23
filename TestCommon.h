#include "ubench.h"

// excalibur hash
#include "ExcaliburHash.h"

// flat hash map
#include "flat_hash_map.hpp"
#include "unordered_map.hpp"

// robin map
#include "robin_map.h"

// luau
#include "Luau/DenseHash.h"

// folly
#ifndef _PROFILEAPI_H_
#define _PROFILEAPI_H_
#endif

#ifndef FOLLY_NO_CONFIG
#define FOLLY_NO_CONFIG
#endif
#include "folly/container/F14Map.h"

// boost
#include "boost/unordered/unordered_map.hpp"

// abseil
#include "absl/container/flat_hash_map.h"

// llvm
#include "llvm/ADT/DenseMap.h"



// adapter for luau dense hash map
template<typename K, typename V>
struct LuauDenseHashMap : public Luau::DenseHashMap<K, V>
{
	LuauDenseHashMap(const K& empty_key = Excalibur::KeyInfo<K>::getEmpty())
		: DenseHashMap(empty_key)
	{
	}

	template <typename TK, class... Args> inline void emplace(TK&& key, Args&&... args)
	{
		V& val = (*this)[key];
		val = V(std::forward<Args>(args)...);
	}
};



// adapter for llvm dense map
template<typename K, typename V>
struct LlvmDenseMap : public llvm::DenseMap<K, V>
{
public:

	explicit LlvmDenseMap(unsigned initialReserve = 0)
		: DenseMap(initialReserve)
	{
	}

	template <typename TK, class... Args> inline void emplace(TK&& key, Args&&... args)
	{
		try_emplace(key, std::forward<Args>(args)...);
	}

};


// the resulting data set is unique
extern const std::vector<int>& getUniquePositiveRandomNumbers();

// 10% of the resulting data set is intersected
const std::vector<int>& getRandomNumbersWithIntersections10();

// 50% of the resulting data set is intersected
const std::vector<int>& getRandomNumbersWithIntersections50();
