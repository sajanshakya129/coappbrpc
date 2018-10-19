#!/bin/bash

LIB_PATH="/usr/local/lib"
INCLUDE_PATH="/usr/local/include"
BIN_PATH="/usr/local/bin"

echo "******Uninstall COAPPBRPRC library******"
read -p "Are you sure to you want to continue(y/n)? " -n 1 -r choice
echo
if [[ $choice =~ ^[Yy]$ ]]
then
	echo "Removing library files "
	rm -rf $LIB_PATH/libcoappbrpc.a $LIB_PATH/coappbrpc.so

	echo "Removing binary files"
	rm -rf $BIN_PATH/coappbrpc.sh $BIN_PATH/uninstall_coappbrpc.sh

	echo "Removing header files"
	rm -rf $INCLUDE_PATH/coappbrpc
fi
