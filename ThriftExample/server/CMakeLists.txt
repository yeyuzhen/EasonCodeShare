ADD_EXECUTABLE(Server CppServer.cpp)
TARGET_LINK_LIBRARIES(Server tutorialgencpp
                             thrift thriftnb
                             boost_thread-mt
                             event)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/server)