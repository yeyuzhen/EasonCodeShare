AUX_SOURCE_DIRECTORY(. CGS_SRC)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/libgreeting/include /
                    ${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

ADD_EXECUTABLE(CMakeGcovSupport ${CGS_SRC})
TARGET_LINK_LIBRARIES(CMakeGcovSupport greeting)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
