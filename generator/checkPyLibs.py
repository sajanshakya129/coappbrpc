#!/usr/bin/env python

import sys
import pip

def install(package):
    pip.main(['install', package])

try:
    import json
    print ('Python: Json library is already installed')
except ImportError:
    print ('json library is not installed, installing it now!')
    install('json')

try:
    import cogapp
    print ('Python: Cog library is already installed')
except ImportError:
    print ('Cog library is not installed, installing it now!')
    install('cogapp')

try:
    import protobuf
    print ('Python: Protobuf library is already installed')
except ImportError:
    print ('Protobuf library is not installed, installing it now!')
    install('protobuf')     

sys.exit(1)