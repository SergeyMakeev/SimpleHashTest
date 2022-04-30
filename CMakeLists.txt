cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(PROJ_NAME SimpleHashTest)
project(${PROJ_NAME})

set (CMAKE_CXX_STANDARD 17)


set(BENCH_SOURCES 
  TestCommon.h
  main.cpp
  Test01.cpp
  Test02.cpp
  Test03.cpp
  Test04.cpp
  Test05.cpp
  Test06.cpp
  Test07.cpp
  Test08.cpp
  Test09.cpp
  Test10.cpp
)
set (EXE_NAME ${PROJ_NAME})
add_executable(${EXE_NAME} ${BENCH_SOURCES})

if(MSVC)
  target_compile_options(${EXE_NAME} PRIVATE "$<$<CONFIG:Release>:/Zi>")
  target_link_options(${EXE_NAME} PRIVATE "$<$<CONFIG:Release>:/DEBUG>")
  target_link_options(${EXE_NAME} PRIVATE "$<$<CONFIG:Release>:/OPT:REF>")
  target_link_options(${EXE_NAME} PRIVATE "$<$<CONFIG:Release>:/OPT:ICF>")
endif()


target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/ubench")


# add Excalibur Hash
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/ExcaliburHash/ExcaliburHash")
target_link_libraries(${EXE_NAME} ExcaliburHash)

# flat_hash_map
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/flat_hash_map")

# robin-map
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/robin-map/include/tsl")

# Luau Desnse Hash
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/luau/Ast/include")

# Boost
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/preprocessor")
target_link_libraries(${EXE_NAME} boost_preprocessor)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/unordered")
target_link_libraries(${EXE_NAME} boost_unordered)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/config")
target_link_libraries(${EXE_NAME} boost_config)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/core")
target_link_libraries(${EXE_NAME} boost_core)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/container_hash")
target_link_libraries(${EXE_NAME} boost_container_hash)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/integer")
target_link_libraries(${EXE_NAME} boost_integer)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/assert")
target_link_libraries(${EXE_NAME} boost_assert)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/type_traits")
target_link_libraries(${EXE_NAME} boost_type_traits)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/detail")
target_link_libraries(${EXE_NAME} boost_detail)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/static_assert")
target_link_libraries(${EXE_NAME} boost_static_assert)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/move")
target_link_libraries(${EXE_NAME} boost_move)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/throw_exception")
target_link_libraries(${EXE_NAME} boost_throw_exception)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/tuple")
target_link_libraries(${EXE_NAME} boost_tuple)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/predef")
target_link_libraries(${EXE_NAME} boost_predef)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/container")
target_link_libraries(${EXE_NAME} boost_container)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/intrusive")
target_link_libraries(${EXE_NAME} boost_intrusive)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/winapi")
target_link_libraries(${EXE_NAME} boost_winapi)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/smart_ptr")
target_link_libraries(${EXE_NAME} boost_smart_ptr)

# Folly
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/folly")

# Abseil
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/abseil-cpp")

# LLVM
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/include")
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/lib")

configure_file(
  ${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/include/llvm/Config/abi-breaking.h.cmake
  ${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/include/llvm/Config/abi-breaking.h)
configure_file(
  ${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/include/llvm/Config/llvm-config.h.cmake
  ${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/include/llvm/Config/llvm-config.h)
configure_file(
  ${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/include/llvm/Config/abi-breaking.h.cmake
  ${PROJECT_SOURCE_DIR}/extern/llvm-project/llvm/include/llvm/Config/abi-breaking.h)

# Google Dense Hash
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/sparsehash/src")

configure_file(
  ${PROJECT_SOURCE_DIR}/extern/sparsehash/src/windows/sparsehash/internal/sparseconfig.h
  ${PROJECT_SOURCE_DIR}/extern/sparsehash/src/sparsehash/internal/sparseconfig.h COPYONLY)



