README for source code distribution of examples in "Professional C++, Second
Edition" by Marc Gregoire, Nicholas A. Solter, and Scott J. Kleper.

Unless otherwise noted, examples adhere to the C++ standard, so they should
run with any standards-conforming compiler on any platform.

Allmost all examples except those that use third-party libraries have been
tested with g++ (GCC) 4.6 on Fedora 13, and Microsoft Visual C++ 2010 on
Windows 7. Examples using third-party libraries or tools have been tested on
a subset of the above platforms.

The following C++11 features were not yet supported by GCC 4.6 at the
time of this writing, so examples using those features have not been tested:
- The final and override keyword
- User defined literals
- In-class non-static data member initialization
- Template aliases
- Delegating constructors
- Inheriting constructors

Microsoft Visual C++ 2010 supports less C++11 features compared to GCC 4.6.
The online (www.wrox.com) Bonus Chapter 2 lists the C++11 features mentioned
in this book and whether a compiler supports that feature.


Compiling with g++ on Linux
---------------------------

You can compile the examples that do not use third-party libraries with
a simple command line:

> g++ -o <executable_name> <source1.cpp> [source2.cpp ...]

For example, you can compile the AirlineTicket example from Chapter 1 by
changing to its directory and running:

> g++ -std=c++0x -o AirlineTicket AirlineTicket.cpp AirlineTicketTest.cpp 

Now you can run the AirlineTicket program:

> ./AirlineTicket

The -std=c++0x is required to tell GCC to enable C++11 support.
The parameter is c++0x, which was the working name during the standardization
process of the new C++ standard. At the time of this writing, g++ still
requires c++0x as parameter, and not yet c++11.


Compiling with Visual Studio
----------------------------

Create a new project using the Visual C++ Win32 Console Project template.
Enter a name and accept the defaults for each step of the wizard. Remove the
files under "Source Files" and add the example files by dragging them onto
"Source Files."

Select "Start without Debugging" from the "Debug" menu to build and run the
program.

If you get an error similar to:

"Unexpected end of file while looking for precompiled header directive"

You need to turn off precompiled headers. Right click on the project in the
Solution Explorer and select "Properties". Go to C/C++ Precompiled Headers and
set the Create/Use Precompiled Header option to "Not Using Precompiled
Headers".

If your program exits before you have a chance to view the output, use the
"Start without Debugging" menu item instead of the "Start" menu item. It will
add a pause to the end of the program so you can view the output.


Using Third-Party Libraries
---------------------------

A few examples make use of third-party libraries discussed in the associated
chapter, such as cppunit. To use those libraries, download them
from the web site given in the text and build them according to the
accompanying instructions. The README file with the library will usually
describe how to use it. In most cases, you simply need to link the library or
libraries when compiling. In g++, the command would look similar to this:

g++ source.cpp -Lthirdparty/lib -Ithirdparty/include -lthirdparty

The -L flag gives g++ a directory to search for additional libraries. The -I
flag gives g++ a directory to look for user-defined headers, and the -l flag
gives g++ the name of a library to link with. If the library file is
libcppunit.so, for example, specify -lcppunit

To run the program, you will need to put the compiled library in a system
directory, or add it to the current user's dynamic library path as follows
(assuming the bash shell):

> export LD_LIBRARY_PATH=thirdparty/lib

Then you will be able to run the program normally:

> ./a.out
