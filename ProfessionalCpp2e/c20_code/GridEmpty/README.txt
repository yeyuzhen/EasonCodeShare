There are three source files in this directory that define main(). Include
SpreadsheetCell.cpp and one of GridTest.cpp, GridTestRefNonType.cpp, or
GridTestZeroInitialized.cpp in your project.

Notes:
	GridTest.cpp will not compile.

	GridTestRefNonType.cpp causes an internal compiler error with
	g++ 3.2.2 on Linux and g++ 3.4.1 on Solaris 9. It compiles
	without errors with g++ 4.6 on Linux and MS VC++ 2010.

