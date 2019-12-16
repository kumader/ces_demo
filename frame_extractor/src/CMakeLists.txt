if (NOT TARGET adtf_file)
    find_package(adtf_file PATHS ${CMAKE_SOURCE_DIR}/lib/cmake/adtf_file REQUIRED)
endif()

find_package(Qt5 COMPONENTS Gui REQUIRED)
find_package(PCL 1.9 REQUIRED)
find_package(OpenCV REQUIRED)

set(EXAMPLE frame_extractor) #to not exceed 260 chars on path under windows...

add_executable(${EXAMPLE} src/frame_extractor.cpp) 
target_link_libraries(${EXAMPLE} adtf_file Qt5::Gui ${PCL_LIBRARIES} ${OpenCV_LIBS})
set_target_properties(${EXAMPLE} PROPERTIES FOLDER examples)

include_directories(./headers ${PCL_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set_target_properties(${EXAMPLE} PROPERTIES
    DEBUG_POSTFIX "d"
)

install(TARGETS ${EXAMPLE}
    DESTINATION bin
)

