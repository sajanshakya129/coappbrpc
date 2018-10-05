#!/bin/bash
echo "Creating Stub for $1"
protoc --plugin=protoc-gen-custom=coappbrpcPlugin.py --custom_out=./ $1
echo "Creating h and cc files from $1"
protoc  --cpp_out=./ $1

echo "Creating Client stub file"
cog -d  @cogFiles.txt
