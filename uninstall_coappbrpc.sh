#!/bin/bash

LIB_PATH="/usr/local/lib"
INCLUDE_PATH="/usr/local/include"
BIN_PATH="/usr/local/bin"

echo "******Uninstall COAPPBRPC library******"
while :
do

	read -p "Are you sure to you want to continue(y/n)? " -n 1 -r choice
	case $choice in 
	  y|Y )
		echo -e "\nRemoving library files "
		rm -rf $LIB_PATH/libcoappbrpc.a $LIB_PATH/coappbrpc.so

		echo -e "Removing binary files"
		rm -rf $BIN_PATH/coappbrpc.sh $BIN_PATH/uninstall_coappbrpc.sh

		echo -e "Removing header files"
		rm -rf $INCLUDE_PATH/coappbrpc
		echo -e "\n Coappbrpc library is removed successfully from your system."
		break
		;;

	  n|N ) echo -e "\n"
		echo "'No' Selected:: Coappbrpc library still exists in your system."
		break
		;;

	  * ) echo -e "\nInvalid choice:: Please press 'Y|y' or 'N|n'."
	esac
done
