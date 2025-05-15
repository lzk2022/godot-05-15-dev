set(LIB_NAME core)

project(${LIB_NAME})

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")

# 要排除的目录
set(EXCLUDE_DIRS
)

# 要排除的文件列表
set(EXCLUDE_FILES
)

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
utils_filter_sources_and_headers_by_dirs(SOURCES HEADERS "${EXCLUDE_DIRS}")
utils_filter_sources_and_headers_by_files(SOURCES HEADERS "${EXCLUDE_FILES}")
utils_create_source_groups(SOURCES HEADERS)

# 添加库源文件
add_library(${LIB_NAME} STATIC
    ${HEADERS}
    ${SOURCES}
)

# 链接 Windows API 所需的库
target_link_libraries(${LIB_NAME} PRIVATE

    # clipper2
    # brotli
    # minizip
    # zlib
    # zstd
    # misc
)

# 包含头文件目录
target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/

    # ${CMAKE_SOURCE_DIR}/thirdparty
    # ${CMAKE_SOURCE_DIR}/thirdparty/thirdparty/mbedtls/include
)

target_compile_definitions(${LIB_NAME} PUBLIC

    # TOOLS_ENABLED
    # DEBUG_METHODS_ENABLED
    # TYPED_METHOD_BIND
    # DEBUG_ENABLED
    # THREADS_ENABLED
    # MINIZIP_ENABLED
    # VERSION_PATCH
    # MBEDTLS_CONFIG_FILE="thirdparty/mbedtls/include/godot_module_mbedtls_config.h"
)
