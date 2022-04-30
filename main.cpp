#include "TestCommon.h"

// folly
#include "folly/lang/SafeAssert.cpp"
#include "folly/lang/ToAscii.cpp"
#include "folly/ScopeGuard.cpp"
#include "folly/container/detail/F14Table.cpp"

// abseil
#include "absl/container/internal/raw_hash_set.cc"
#include "absl/hash/internal/hash.cc"
#include "absl/hash/internal/city.cc"
#include "absl/hash/internal/low_level_hash.cc"

// llvm
#include "Support/MemAlloc.cpp"

#include <unordered_set>
#include <random>
#include <algorithm>

const std::vector<int>& getUniquePositiveRandomNumbers()
{
	const size_t kNumberOfItems = 1000000;
	static std::vector<int> data;
	if (data.empty())
	{
		std::random_device randDev;
		std::mt19937 generator(randDev());
		std::uniform_int_distribution<int> distr(1, std::numeric_limits<int>::max() - 1);

		std::set<int> uniques;
		while (uniques.size() < kNumberOfItems)
		{
			uniques.insert(distr(generator));
		}

		data.resize(kNumberOfItems);
		std::copy(uniques.begin(), uniques.end(), data.begin());
	}
	return data;
}

// 10% of the resulting data set is intersected
const std::vector<int>& getRandomNumbersWithIntersections10()
{
	static std::vector<int> data;
	if (data.empty())
	{
		data = getUniquePositiveRandomNumbers();
		size_t cutoff = (data.size() / 10);
		size_t j = cutoff;
		for (size_t i = 0; i < cutoff; i++, j++)
		{
			data[i] = data[j];
		}
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(data.begin(), data.end(), g);
	}
	return data;
}

// 50% of the resulting data set is intersected
const std::vector<int>& getRandomNumbersWithIntersections50()
{
	static std::vector<int> data;
	if (data.empty())
	{
		data = getUniquePositiveRandomNumbers();
		size_t cutoff = (data.size() / 2);
		size_t j = 0;
		for (size_t i = cutoff; i < data.size(); i++, j++)
		{
			data[i] = data[j];
		}
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(data.begin(), data.end(), g);
	}
	return data;
}



struct PreMain
{
	PreMain() {
		getUniquePositiveRandomNumbers();
		getRandomNumbersWithIntersections10();
		getRandomNumbersWithIntersections50();
	}
};

PreMain preMain;




/*
void test()
{
	Excalibur::HashTable<int, int> test01;
	test01.emplace(1, 2);

	ska::flat_hash_map<int, int> test02;
	test02.emplace(1, 2);

	ska::unordered_map<int, int> test03;
	test03.emplace(1, 2);

	tsl::robin_map<int, int> test04;
	test04.emplace(1, 2);

	Luau::DenseHashMap<int, int> test05(INT_MIN);
	test05[1] = 2;

	folly::F14ValueMap<int, int> test06;
	test06.emplace(1, 2);

	boost::unordered_map<int, int> test07;
	test07.emplace(1, 2);

	absl::flat_hash_map<int, int> test08;
	test08.emplace(1, 2);

	llvm::DenseMap<int, int> test09;
	test09.try_emplace(1, 2);

	std::unordered_map<int, int> test10;
	test10.emplace(1, 2);
}

struct PreMain
{
	PreMain()
	{
		test();
	}
};

PreMain preMain;
*/

UBENCH_MAIN()
