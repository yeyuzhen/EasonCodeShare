#include <string>
#include <iostream>

using namespace std;

class Paragraph
{
public:
	Paragraph(const string& inInitialText) : mText(inInitialText) {}
	virtual string getHTML() const { return mText; }

protected:
	string mText;        
}; 

class BoldParagraph : public Paragraph
{
public:
	BoldParagraph(const Paragraph& inParagraph) :
	  Paragraph(""), mWrapped(inParagraph) {}

	  virtual string getHTML() const {
		  return "<B>" + mWrapped.getHTML() + "</B>";
	  }

protected:
	const Paragraph& mWrapped;
};

class ItalicParagraph : public Paragraph
{
public:
	ItalicParagraph(const Paragraph& inParagraph) :
	  Paragraph(""), mWrapped(inParagraph) {}

	  virtual string getHTML() const {
		  return "<I>" + mWrapped.getHTML() + "</I>";
	  }

protected:
	const Paragraph& mWrapped;
};



int main()
{
	Paragraph p("A party? For me? Thanks!");

	// Bold
	cout << BoldParagraph(p).getHTML() << endl;

	// Bold and Italic
	cout << ItalicParagraph(BoldParagraph(p)).getHTML() << endl;

	// Bold and Bold
	cout << BoldParagraph(BoldParagraph(p)).getHTML() << endl;

	return 0;
} 
