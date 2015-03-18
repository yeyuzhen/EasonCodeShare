#!/bin/sh

echo "start initialize lcov coverage"
lcov -d build -z
lcov -d build -b . --no-external --initial -c -o CMakeGcovSupportInitialCoverage.info

exit 1