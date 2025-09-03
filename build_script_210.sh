#!/bin/bash

FFLAGS="-DUSE_STACK ${FFLAGS} ${BIGENDIAN} ${OPENMP}"
FFLAGS="$(echo ${FFLAGS} | sed -e 's/-Ofast/-O3 -ffast-math -fstack-arrays/g' -e "s: -I${PREFIX_DIR}/include::g")"
LDFLAGS="$(echo ${LDFLAGS} | sed -e 's/-Ofast/-O3 -ffast-math/g')" 

FFLAGS="-DUSE_STACK -march=znver5 -ffp-contract=fast -O1 -ffast-math -fPIC -ffree-form -cpp -fconvert=big-endian -fopenmp "
HIP_FFLAGS="--offload-arch=gfx90a "

LDFLAGS=" -march=znver5 -ffp-contract=fast -O1 -ffast-math -fPIC -lm -lrt "
OPENMP="-fopenmp "
HIP_LDFLAGS="--offload-arch=gfx90a -lflang_rt.hostdevice "


FC=flang
SRCS=(yomt1.F90 util_tt_mod.F90 util_uu_mod.F90 util_vv_mod.F90 util_uu2_mod.F90 util_ww_mod.F90 test.F90)	
SRC=${SRCS[-1]}

for SRC in ${SRCS[@]} ; do 
  OBJ=${SRC%.*}.o
  OBJS="${OBJS} ${OBJ}"

  if [ ! -f ${OBJ} ] ; then  
    echo "${FC} ${FFLAGS} ${HIP_FFLAGS} -c ${SRC} -o ${OBJ}"
    ${FC} ${FFLAGS} ${OPENMP} ${HIP_FFLAGS} -c ${SRC} -o ${SRC%.*}.o 
    [ ! -f ${OBJ} ] && abort "[error] $SRC"
  fi
done

##milestone "link"

OBJS=( ${OBJS} )
EXE=test.x

echo "${FC} ${LDFLAGS} ${OPENMP} ${HIP_LDFLAGS} ${OBJS[@]} -o ${EXE}"
${FC} ${LDFLAGS} ${OPENMP} ${HIP_LDFLAGS} ${OBJS[@]} -o ${EXE}
[ ! -f ${EXE} ] && abort "[error] $EXE"

