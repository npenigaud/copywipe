#!/bin/bash

#module load rocm/6.4.1
module load uprof/5.1.701
export AMDUPROF_ROCM_PATH=/opt/rocm-6.4.1
export AMDUPROF_ROCM_LIB_PATH=/opt/rocm-6.4.1/lib

#mkdir profil
#AMDuProfCLI collect --config gpu -o profil ./test.x
