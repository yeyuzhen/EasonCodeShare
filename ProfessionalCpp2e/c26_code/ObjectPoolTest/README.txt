To compile and run this example, you will need to download, build,
and install cppunit. Please see the top-level README file and the
cppunit documentation for additional details.

As an example, after cppunit is installed, the example can be built
as follows on Linux with GCC 4.6:

> export LD_LIBRARY_PATH=/usr/local/lib
> g++ -I/usr/local/include/cppunit -L/usr/local/lib -lcppunit -ldl -std=c++0x *.cpp
