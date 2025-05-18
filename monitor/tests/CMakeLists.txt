set(LIB_NAME tests)

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
# add_library(${LIB_NAME} STATIC
# ${HEADERS}
# ${SOURCES}
# )

# 添加可执行文件
add_executable(tests

    ${HEADER}
    ${SOURCES}
)

# 链接 Windows API 所需的库
target_link_libraries(${LIB_NAME} PRIVATE
    doctest
)

# 包含头文件目录
target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_compile_definitions(${LIB_NAME} PUBLIC

    # TOOLS_ENABLED
)
