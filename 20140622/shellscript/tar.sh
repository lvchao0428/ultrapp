#!/bin/sh

cd ./

tarFile="shell.tar.gz"

tar czvf $tarFile *.sh

cd ../

mkdir backup
code=$?

if [ $code -eq 0 ]
then
cd -
cp shell.tar.gz ../backup/
else
	cd -
	rm -rf ../backup/*
	cd -
	cp $tarFile ../backup/l.tar.gz
fi

