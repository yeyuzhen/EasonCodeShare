#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::ostream;

// Provides a simple debug buffer. The client specifies the number
// of entries in the constructor and adds messages with the addEntry()
// method. Once the number of entries exceeds the number allowed, new
// entries overwrite the oldest entries in the buffer.
//
// The buffer also provides the option to print entries as they
// are added to the buffer. The client can specify an output stream
// in the constructor, and can reset it with the setOutput() method.
// 
// Finally, the buffer supports streaming to an output stream.
class RingBuffer
{
public:
	// Constructs a ring buffer with space for numEntries.
	// Entries are written to *ostr as they are queued.
	RingBuffer(size_t numEntries = kDefaultNumEntries, ostream* ostr = nullptr);
	virtual ~RingBuffer();

	// Adds the string to the ring buffer, possibly overwriting the
	// oldest string in the buffer (if the buffer is full).
	void addEntry(const string& entry);

	// Streams the buffer entries, separated by newlines, to ostr.
	friend ostream& operator<<(ostream& ostr, const RingBuffer& rb);

	// Sets the output stream to which entries are streamed as they are added.
	// Returns the old output stream.
	ostream* setOutput(ostream* newOstr);

protected:
	vector<string> mEntries;
	ostream* mOstr;

	size_t mNumEntries, mNext;
	bool mWrapped;

	static const size_t kDefaultNumEntries = 500;
};
