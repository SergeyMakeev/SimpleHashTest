#include "TestCommon.h"


bool testFailed = false;


#define EXPECT_FALSE(val) \
if ((val) != false) \
{ \
    testFailed = true; \
} \


struct ComplexValue
{
    ComplexValue(const ComplexValue& other)
        : isMoved(other.isMoved)
        , isDeleted(other.isDeleted)
    {
        EXPECT_FALSE(other.isMoved);
        EXPECT_FALSE(other.isDeleted);
    }

    ComplexValue& operator=(const ComplexValue& other) noexcept
    {
        EXPECT_FALSE(other.isMoved);
        EXPECT_FALSE(other.isDeleted);
        isMoved = other.isMoved;
        isDeleted = other.isDeleted;
        return *this;
    }

    ComplexValue() noexcept
        : isMoved(false)
        , isDeleted(false)
    {
    }

    ComplexValue(ComplexValue&& other) noexcept
        : isMoved(other.isMoved)
        , isDeleted(other.isDeleted)
    {
        EXPECT_FALSE(other.isDeleted);
        other.isMoved = true;
    }

    ~ComplexValue() noexcept { isDeleted = true; }

    ComplexValue& operator=(ComplexValue&& other) noexcept
    {
        isDeleted = other.isDeleted;
        isMoved = other.isMoved;
        other.isMoved = true;
        return *this;
    }

    bool isMoved;
    bool isDeleted;
};



#define DO_TEST(THashMap) \
{ \
    testFailed = false; \
    printf(#THashMap); \
    for (int i = 1; i <= 1000; i++) \
    { \
        THashMap<int, ComplexValue> ht; \
        for (int j = 0; j < i; j++) \
        { \
            ht.emplace(j, ComplexValue{}); \
        } \
        auto it = ht.find(0); \
        ht.emplace(-1, it->second); \
    } \
    if (testFailed) \
    { \
        printf(" - failed\n"); \
    } \
    else \
    { \
        printf(" - passed\n"); \
    } \
} \

#define DO_TEST2(THashMap) \
{ \
    testFailed = false; \
    printf("Testing: "); \
    printf(#THashMap); \
    for (int i = 1; i <= 1000; i++) \
    { \
        THashMap<int, ComplexValue> ht; \
        for (int j = 0; j < i; j++) \
        { \
            ht.emplace(j, ComplexValue{}); \
        } \
        auto it = ht.find(0); \
        ht.emplace(-1, *it); \
    } \
    if (testFailed) \
    { \
        printf(" - failed\n"); \
    } \
    else \
    { \
        printf(" - passed\n"); \
    } \
} \


void aliasingTest()
{
    printf("Hash table 'aliasing' test.\n");
    printf("===========================\n");
    DO_TEST(Excalibur::HashTable);
    DO_TEST(ska::flat_hash_map);
    DO_TEST(ska::unordered_map);
    DO_TEST(tsl::robin_map);
    DO_TEST2(LuauDenseHashMap);
    DO_TEST(folly::F14ValueMap);
    DO_TEST(boost::unordered_map);
    DO_TEST(absl::flat_hash_map);
    DO_TEST(LlvmDenseMap);
    DO_TEST(std::unordered_map);
    DO_TEST(GoogleDenseMap);
    printf("===========================\n");
}