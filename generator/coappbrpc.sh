#!/bin/bash

if [ -z $1 ]
  then
    echo "Syntax Error: Command must be in following format \"coappbrpc <file.proto>\""
  else
  	if [[ ${1: -6} = ".proto" ]]
  		then
  			echo "Creating Stub for $1"
			protoc --plugin=protoc-gen-custom=/usr/local/lib/coappbrpc/templates/coappbrpcPlugin.py --custom_out=./ $1
			echo "Creating h and cc files from $1"
			protoc  --cpp_out=./ $1
			echo "Creating Client stub file"
			python -m cog -d  @/usr/local/lib/coappbrpc/templates/cogFiles.txt
 		else
 			echo "File must be .proto files."
	fi
fi

