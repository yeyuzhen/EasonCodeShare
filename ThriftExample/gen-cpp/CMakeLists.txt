SET(LIBGENCPP_SRC Calculator.cpp /
                  Calculator.h /
                  SharedService.cpp /
                  SharedService.h /
                  shared_constants.cpp /
                  shared_constants.h /
                  shared_types.cpp /
                  shared_types.h /
                  tutorial_constants.cpp /
                  tutorial_constants.h /
                  tutorial_types.cpp /
                  tutorial_types.h)
ADD_LIBRARY(tutorialgencpp STATIC ${LIBGENCPP_SRC})

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/gen-cpp)