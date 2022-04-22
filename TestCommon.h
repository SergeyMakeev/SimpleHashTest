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

