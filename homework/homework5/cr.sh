#!/bin/bash
#sets the path for this file to run
gcc -c *.c 2> gcc_error.txt
gcc -fopenmp -o main *.c -lm
RESULT=$?
#echo ${RESULT}
if [ ${RESULT} = 0 ]
then
  if [ $# != 5 ]
  then
    echo "script requires 5 arguments!"
  else
    rm gcc_error.txt
    ./main $1 $2 $3 $4 $5

  fi
else
  echo "compile failed"
  cat gcc_error.txt
fi
