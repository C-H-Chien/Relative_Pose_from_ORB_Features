#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
set ( control_sources
  
  ORBextractor.cpp
  ORBextractor.hpp

)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library( ORBextractor ${control_sources} )
target_link_libraries(ORBextractor 
        ${OpenCV_LIBS}
        #-L/gpfs/runtime/opt/magma-gpu/2.4.0/lib magma
        #-L${CUDAPATH}/lib cublas cudart cusparse
        #-L/gpfs/runtime/opt/openblas/0.3.7/lib openblas
        -L/usr/lib64 pthread
)

set_target_properties(ORBextractor PROPERTIES LINKER_LANGUAGE CXX)
