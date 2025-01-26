#!/bin/bash

# => $1 is Server
# => $2 is Local
# => $3 is Target

sftp $1 << EOF
	cd $3
	put $(pwd)/$2
	ls
	exit
	EOF
	
