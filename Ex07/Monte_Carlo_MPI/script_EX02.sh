#!/bin/bash

EXEC=mainEX02
MPICXX=mpicxx
MPIEXEC=mpiexec
N=4


eval "$MPICXX specific_object_EX02.cpp -o $EXEC"
eval "rm -rf *.o *.h.*"
eval "$MPIEXEC -n $N ./$EXEC"
