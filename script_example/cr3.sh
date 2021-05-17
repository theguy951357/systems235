#!/bin/bash
#sets the path for this file to run
gcc -o my_exe *.c -lm 2> gcc_error.txt
RESULT=$?
#echo ${RESULT}
if [ ${RESULT} = 0 ]
then
  if [ $# != 1 ]
  then
    echo "script requires an argument!"
  else
    rm gcc_error.txt
    ./my_exe $1

  fi
else
  echo "compile failed"
  cat gcc_error.txt
fi
