cmake_minimum_required(VERSION 2.8.12)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(PROJ_NAME SimpleHashTest)
project(${PROJ_NAME})

set (CMAKE_CXX_STANDARD 17)


set(BENCH_SOURCES 
  main.cpp
)
set (EXE_NAME ${PROJ_NAME})
add_executable(${EXE_NAME} ${BENCH_SOURCES})

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

#add_subdirectory("${PROJECT_SOURCE_DIR}/extern/boost/functional")
#target_link_libraries(${EXE_NAME} boost_functional)



# Folly
target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/extern/folly")


