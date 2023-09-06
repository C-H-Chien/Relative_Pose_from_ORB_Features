#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
set ( orb_matcher_control_sources
  
  #> Add your script files here ...
  ORBmatcher.hpp

)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library( ORBmatcher ${orb_matcher_control_sources} )
target_link_libraries(ORBmatcher 
        ${OpenCV_LIBS}
        -L/usr/lib64 pthread
)

set_target_properties(ORBmatcher PROPERTIES LINKER_LANGUAGE CXX)
