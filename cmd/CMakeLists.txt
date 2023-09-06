
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#> main lib
find_package(Threads REQUIRED)
link_libraries(ORBextractor)
link_libraries(ORBmatcher)

add_executable(ORBextractor-main main.cpp )

set_target_properties(ORBextractor-main PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(ORBextractor-main Threads::Threads)

