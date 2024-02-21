cmake_minimum_required(VERSION 3.18)

project("matio-playground")



add_library(zlib STATIC IMPORTED)

set_property(
  TARGET zlib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(zlib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${ZLIB_ROOT}/lib/libzlibstatic.a"
)
  
set_target_properties(zlib PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_include_directories(zlib INTERFACE "${ZLIB_ROOT}/include")

add_library(matio STATIC IMPORTED)


set_property(
  TARGET matio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(matio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${matio_ROOT}/lib/libmatio.a"
)

set_target_properties(matio PROPERTIES
#   INTERFACE_COMPILE_DEFINITIONS "LIBSSH_STATIC"
#   INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "${ZLIB_ROOT}/lib/libzlibstatic.a"
)
  
set_target_properties(matio PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_include_directories(matio INTERFACE "${matio_ROOT}/include")

add_executable(${PROJECT_NAME}
    "src/main.c"
)


target_link_libraries(${PROJECT_NAME}  matio)
target_link_options(${PROJECT_NAME} PRIVATE "-static")
