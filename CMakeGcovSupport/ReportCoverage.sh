#!/bin/sh

echo "start report lcov coverage"
lcov -d build -b . --no-external -c -o CMakeGcovSupportCoverage.info
genhtml -o CMakeGcovSupportCoverageReport --prefix=`pwd` CMakeGcovSupportInitialCoverage.info CMakeGcovSupportCoverage.info

exit 1