#!/bin/sh

echo "Display CpuProfilerExample CPU profile in Kcachegrind"
pprof --callgrind CpuProfilerExample CpuProfilerExample.prof > CpuProfilerExample.callgrind
nohup kcachegrind CpuProfilerExample.callgrind > /dev/null &

exit 1



