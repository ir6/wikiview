#!/usr/bin/env python

import sys

offset = -1
b = 0
for line in sys.stdin:
    if offset == -1:
        x = line.find ("<page>")
        if x >= 0:
            offset = b + x
    else:
        if "<title>" in line:
            title = line[line.find("<title>") + len("<title>"):
                             line.find("</title>")] 
            print ("0x%010X %s" % (offset, title))
            offset = -1

    b += len (line)
