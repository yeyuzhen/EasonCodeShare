#include <string>
using std::string;

class ArticleCitations
{
public:
	ArticleCitations(const string& fileName);
	virtual ~ArticleCitations();
	ArticleCitations(const ArticleCitations& src);
	ArticleCitations& operator=(const ArticleCitations& rhs);

	string getArticle() const { return mArticle; }
	size_t getNumCitations() const { return mNumCitations; }
	string getCitation(size_t i) const { return mCitations[i]; }

protected:
	void readFile(const string& fileName);

	string mArticle;
	string* mCitations;
	size_t mNumCitations;
};
