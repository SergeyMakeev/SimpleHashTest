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



namespace my_stdext
{
	using _STD basic_string;
	using _STD less;
	using _STD size_t;

	template <class _Kty>
	_NODISCARD size_t hash_value(const _Kty& _Keyval) noexcept {
		if constexpr (_STD is_pointer_v<_Kty> || _STD is_null_pointer_v<_Kty>) {
			return reinterpret_cast<size_t>(_Keyval) ^ 0xdeadbeefu;
		}
		else {
			return static_cast<size_t>(_Keyval) ^ 0xdeadbeefu;
		}
	}

	template <class _Elem, class _Traits, class _Alloc>
	_NODISCARD size_t hash_value(const basic_string<_Elem, _Traits, _Alloc>& _Str) noexcept {
		return _STD _Hash_array_representation(_Str.c_str(), _Str.size());
	}

	_NODISCARD inline size_t hash_value(_In_z_ const char* _Str) noexcept {
		return _STD _Hash_array_representation(_Str, _CSTD strlen(_Str));
	}

	_NODISCARD inline size_t hash_value(_In_z_ const wchar_t* _Str) noexcept {
		return _STD _Hash_array_representation(_Str, _CSTD wcslen(_Str));
	}

	template <class _Kty, class _Pr = less<_Kty>>
	class hash_compare { // traits class for hash containers
	public:
		enum { // parameters for hash table
			bucket_size = 1 // 0 < bucket_size
		};

		hash_compare() = default;
		hash_compare(const _Pr& _Pred) noexcept(_STD is_nothrow_copy_constructible_v<_Pr>) : comp(_Pred) {}

		_NODISCARD size_t operator()(const _Kty& _Keyval) const noexcept(noexcept(hash_value(_Keyval))) {
			long _Quot = static_cast<long>(hash_value(_Keyval) & LONG_MAX); // TRANSITION, ADL?
			ldiv_t _Qrem = _CSTD ldiv(_Quot, 127773);

			_Qrem.rem = 16807 * _Qrem.rem - 2836 * _Qrem.quot;
			if (_Qrem.rem < 0) {
				_Qrem.rem += LONG_MAX;
			}

			return static_cast<size_t>(_Qrem.rem);
		}

		_NODISCARD bool operator()(const _Kty& _Keyval1, const _Kty& _Keyval2) const
			noexcept(noexcept(comp(_Keyval1, _Keyval2))) {
			// test if _Keyval1 ordered before _Keyval2
			return comp(_Keyval1, _Keyval2);
		}

		_Pr comp{}; // the comparator object
	};

}

// adapter for google desne hash map
template<typename K, typename V,
	class HashFcn = my_stdext::hash_compare<K>,   // defined in sparseconfig.h
	class EqualKey = std::equal_to<K>,
	class Alloc = google::libc_allocator_with_realloc<std::pair<const K, V> > >
	struct GoogleDenseMap
{
	google::dense_hash_map<K, V, HashFcn, EqualKey, Alloc> dmap;

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

	inline typename google::dense_hash_map<K, V, HashFcn, EqualKey, Alloc>::iterator find(const K& key)
	{
		return dmap.find(key);
	}

	inline typename google::dense_hash_map<K, V, HashFcn, EqualKey, Alloc>::const_iterator find(const K& key) const
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
