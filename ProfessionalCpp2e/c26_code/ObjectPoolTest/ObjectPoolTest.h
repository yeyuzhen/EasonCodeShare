#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>

class ObjectPoolTest : public CppUnit::TestFixture
{
public:
	void setUp();
	void tearDown();

	void testCreation();
	void testInvalidChunkSize();
	void testAcquire();
	void testExclusivity();
	void testRelease();
	void testSimple();  // Our first test!

	static CppUnit::Test* suite();
};
