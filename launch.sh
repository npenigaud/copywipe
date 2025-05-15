#!/bin/bash

module purge
module load nvhpc/24.5

set -x

echo " ===   launch with nvfortran  ==="

#SBATCH -p ndl
#SBATCH --gres=gpu:4
#SBATCH -N 1
#SBATCH --verbose
#SBATCH --exclusive
#SBATCH --time=00:02:00

module purge
module load nvhpc/24.5

echo " ===   compile with nvfortran  ==="

nvfortran -acc=gpu -cuda -target=gpu -gopt -O1 -gpu=cc70,cc80 -gopt -lrt -Minfo=accel,all,ccff -o test.x yomt1.F90 util_tt_mod.F90 util_uu_mod.F90 util_vv_mod.F90 util_uu2_mod.F90 util_ww_mod.F90 test.F90 


set -x

echo " ===   launch with nvfortran  ==="

srun -o sortie.txt --gres=gpu:4 test.x 
