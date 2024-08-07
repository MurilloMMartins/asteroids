add_executable(Asteroids main.cpp)

target_compile_features(Asteroids PRIVATE cxx_std_17)
target_link_libraries(Asteroids PRIVATE AsteroidsLib)

