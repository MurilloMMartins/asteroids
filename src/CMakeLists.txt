# GLOB isn't good practice, so this will be temporary for development
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(AsteroidsLib ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(AsteroidsLib PUBLIC ../include/)

target_link_libraries(AsteroidsLib PRIVATE sfml-graphics)

target_compile_features(AsteroidsLib PRIVATE cxx_std_17)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
