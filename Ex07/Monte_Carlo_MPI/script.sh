#!/bin/bash

EXEC=main
MPICXX=mpicxx
MPIEXEC=mpiexec
N=4


eval "$MPICXX main.cpp montecarlo.cpp montecarlo.h -o $EXEC"
eval "rm -rf *.o *.h.*"
eval "$MPIEXEC -n $N ./$EXEC"
