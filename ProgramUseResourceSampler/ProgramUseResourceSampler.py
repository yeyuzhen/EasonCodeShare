#! /usr/bin/env python
# encoding=utf-8

import sys
import os
import time
import getopt

def Usage():
    print 'Usage:'
    print "'-p pid' or '--pid=pid'"
    print "'-f file' or '--file=file'"
    print "example 'python ProgramUseResourceSampler.py -p 12345 -f sample.csv'"

def Sampler(pid):
    cmd = 'ps -p '
    cmd += str(pid)
    cmd += ' -o pid,stat,etime,%cpu,%mem,vsz,rss,command'
    
    return os.popen(cmd).read()

if __name__ == '__main__':
    try:
        opts, args = getopt.getopt(sys.argv[1:], "hp:f:", ["help", "pid=", "file="])
    except getopt.GetoptError:
        Usage()
        sys.exit(0)
    
    pid = -1
    samplingFileName = 'Sampling.csv'
    for opt, arg in opts:
        if opt in ('-h', '--help'):
            Usage()
            sys.exit(0)
        elif opt in ('-p', '--pid'):
            pid = int(arg)
        elif opt in ('-f', '--file'):
            samplingFileName = arg
    
    if pid == -1:
        Usage()
        sys.exit(0)
    
    samplingFile = file(samplingFileName, 'w', 1)
    
    isFirst = True
    isRun = False
    while True:
        if isFirst:
            samplingFile.write(Sampler(pid))
            isFirst = False
        else:
            result = Sampler(pid).split('\n')
            if len(result) < 3:
                if isRun:
                    samplingFile.write('program %d stopped.\n' % pid)
                    break
                else:
                    samplingFile.write('program %d not start.\n' % pid)
            else:
                samplingFile.write(result[1] + '\n')
                isRun = True
        time.sleep(1)
    
    samplingFile.close()
