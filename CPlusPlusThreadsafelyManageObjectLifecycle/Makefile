# Makefile

CXX = g++
CXXFLAGS = -O2 -g -Wall

LIBS = -L$(BOOST_ROOT)/lib -lboost_system-mt -lboost_thread-mt

TARGET = CPlusPlusThreadsafelyManageObjectLifecycle

INCLUDE = -I$(BOOST_ROOT)/include

$(TARGET): SessionDB.o main.o
	$(CXX) $(LIBS) -o $(TARGET) SessionDB.o main.o

main.o: Session.h SessionDB.h main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o main.o main.cpp

SessionDB.o: Session.h SessionDB.h SessionDB.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o SessionDB.o SessionDB.cpp

all: $(TARGET)

clean:
	rm -f $(TARGET) *.o
