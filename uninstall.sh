#!/bin/bash

LIB_PATH="/usr/local/lib"
INCLUDE_PATH="/usr/local/include"
BIN_PATH="/usr/local/bin"

echo "removing libs"
rm -rf $BIN_PATH/coappbrpc $LIB_PATH/libcoappbrpc.a $LIB_PATH/coappbrpc.so

echo "removing header files"
rm -rf $INCLUDE_PATH/pbrpc $INCLUDE_PATH/coappbrpc
