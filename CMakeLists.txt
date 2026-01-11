cmake_minimum_required(VERSION 3.10)
project(SimArm)

set(CMAKE_CXX_STANDARD 17)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# Вместо одного общего поиска, ищем файлы только в корне и нужных подпапках
file(GLOB CORE_SOURCES "*.cpp" "*.h")
file(GLOB ENTITIES_SOURCES "entities/*.cpp" "entities/*.h")
file(GLOB UTILS_SOURCES "utils/*.cpp" "utils/*.h")

# Объединяем списки
set(SOURCES ${CORE_SOURCES} ${ENTITIES_SOURCES} ${UTILS_SOURCES})

add_executable(SimArm ${SOURCES})
target_include_directories(SimArm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
