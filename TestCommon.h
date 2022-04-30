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

// google dense hash map
#include <sparsehash/dense_hash_map>


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

// adapter for google desne hash map
template<typename K, typename V>
struct GoogleDenseMap
{
	google::dense_hash_map<K, V> dmap;

	GoogleDenseMap()
	{
		dmap.set_empty_key(Excalibur::KeyInfo<K>::getEmpty());
		dmap.set_deleted_key(Excalibur::KeyInfo<K>::getTombstone());
	}

	inline void clear()
	{
		dmap.clear();
	}

	inline void erase(const K& key)
	{
		dmap.erase(key);
	}

	template <typename TK, class... Args> inline void emplace(TK&& key, Args&&... args)
	{
		V& val = dmap[key];
		val = V(std::forward<Args>(args)...);
	}

	inline V& operator[](const K& key)
	{
		return dmap[key];
	}

	inline typename google::dense_hash_map<K, V>::iterator find(const K& key)
	{
		return dmap.find(key);
	}

	inline typename google::dense_hash_map<K, V>::const_iterator find(const K& key) const
	{
		return dmap.find(key);
	}


};




// the resulting data set is unique
extern const std::vector<int>& getUniquePositiveRandomNumbers();

// 10% of the resulting data set is intersected
const std::vector<int>& getRandomNumbersWithIntersections10();

// 50% of the resulting data set is intersected
const std::vector<int>& getRandomNumbersWithIntersections50();
