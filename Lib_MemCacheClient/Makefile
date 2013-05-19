CC=g++
AR=ar
ARFLAGS=-rcs
INC=./include
SRC=./src
CPPFLAGS=-I$(INC) -I$(MEMCACHECLIENT_ROOT) -I$(BOOST_ROOT)/include -Wall
LDFLAGS=-L$(BOOST_ROOT)/lib -L$(MEMCACHECLIENT_ROOT)/lib
LIBS=-lboost_thread-mt -lMemCacheClient -lrt

LIB_OBJS=MemcacheProtocolClient.o MemcachedClient.o

OBJS=Sample.o MemcacheProtocolClient.o MemcachedClient.o

all: $(OBJS)
	$(CC) -o Sample $(OBJS) $(LDFLAGS) $(LIBS)
	$(AR) $(ARFLAGS) libmemcacheclient.a $(LIB_OBJS)
	mkdir lib
	mv libmemcacheclient.a lib 

clean:
	rm -rf core *.o lib Sample

Sample.o : $(SRC)/Sample.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/Sample.cpp

MemcacheProtocolClient.o : $(SRC)/MemcacheProtocolClient.cpp $(INC)/MemcacheProtocolClient.h
	$(CC) $(CPPFLAGS) -c $(SRC)/MemcacheProtocolClient.cpp

MemcachedClient.o : $(SRC)/MemcachedClient.cpp $(INC)/MemcachedClient.h
	$(CC) $(CPPFLAGS) -c $(SRC)/MemcachedClient.cpp
