#ifndef _OPENACC

#define GPU_DATA_ENTER_PRESENT(...) !$omp target enter data map(present: __VA_ARGS__)
#define GPU_DATA_PRESENT(...) !$omp target data map(present: __VA_ARGS__)
#define GPU_DATA_PRESENT_IF(condition_arg, ...) !$omp target enter data if(condition_arg) map(present: __VA_ARGS__)
#define GPU_DATA_PRESENT_COPY(condition_arg, copyin_arg, copy_arg, ...) !$omp target enter data if(condition_arg) map(present: __VA_ARGS__) map(to: copyin_arg) map(tofrom: copy_arg)
#define GPU_DATA_PRESENT_CREATE(...) map(create: __VA_ARGS__)

#define GPU_DATA_ALLOC(...) !$omp target enter data map(alloc: __VA_ARGS__)
#define GPU_DATA_ALLOC_IF(condition_arg, ...) !$omp target data if(condition_arg) map(alloc: __VA_ARGS__)
#define GPU_DATA_ALLOC_IF_ASYNC(condition_arg,...) !$omp target enter data if(condition_arg) map(alloc: __VA_ARGS__)
#define GPU_DATA_ALLOC_IF_NOWAIT(condition_arg,...) !$omp target enter data if(condition_arg) map(alloc: __VA_ARGS__)  nowait
#define GPU_DATA_ALLOC_ASYNC(...) !$omp target enter data map(alloc: __VA_ARGS__)
#define GPU_DATA_ALLOC_NOWAIT(...) !$omp target enter data map(alloc: __VA_ARGS__) nowait


#define GPU_DATA_UPDATE_HOST_WAIT_IF(condition_arg, wait_arg, ...) \
    !$omp target update from(__VA_ARGS__) if(condition_arg) depend(wait:wait_arg)
#define GPU_DATA_UPDATE_HOST_ASYNC_IF(condition_arg, async_arg, ...) \
    !$omp target update from(__VA_ARGS__) if(condition_arg) nowait depend(async:async_arg)
#define GPU_DATA_UPDATE_HOST_IF_ASYNC(condition_arg, ...)    !$omp target update from(__VA_ARGS__) if(condition_arg)
#define GPU_DATA_UPDATE_HOST_IF_NOWAIT(condition_arg, ...)    !$omp target update from(__VA_ARGS__) if(condition_arg) nowait
#define GPU_DATA_UPDATE_HOST_IF(condition_arg, ...) \
    !$omp target update from(__VA_ARGS__) if(condition_arg)
#define GPU_DATA_UPDATE_HOST_ASYNC(async_arg, ...) \
    !$omp target update from(__VA_ARGS__) nowait depend(async:async_arg)
#define GPU_DATA_UPDATE_HOST_WAIT(wait_arg, ...) \
    !$omp target update from(__VA_ARGS__) depend(wait:wait_arg)
#define GPU_DATA_UPDATE_HOST(...) \
    !$omp target update from(__VA_ARGS__)

#define GPU_ROUTINE !$omp declare target
#define GPU_ROUTINE(...) !$omp declare target
#define GPU_ROUTINE_SEQ(...) !$omp declare target
#define GPU_ROUTINE_VECTOR(...) !$omp declare target
#define GPU_ROUTINE_WORKER(...) !$omp declare target
#define GPU_ROUTINE_GANG(...) !$omp declare target

#define GPU_END_PARALLEL           !$omp end target teams distribute parallel for
#define GPU_END_PARALLEL_LOOP      !$omp end target teams distribute parallel for
#define GPU_END_DATA               !$omp end target data
#define GPU_END_SERIAL             !$omp end target
#define GPU_END_KERNELS            !$omp end target
#define GPU_END_KERNELS_LOOP       !$omp end target
#define GPU_END_HOST_DATA          
#define GPU_END_ATOMIC             !$omp end atomic

#define GPU_WAIT()                       !$omp taskwait
#define GPU_WAIT_IF(condition)           !$omp taskwait if(condition)
#define GPU_WAIT_STREAM(...)              !$omp taskwait  
#define GPU_WAIT_STREAM_IF(condition, ...)     !$omp taskwait if(condition)  

#define GPU_DATA_DELETE(...)                      !$omp target exit data map(delete: __VA_ARGS__)
#define GPU_DATA_DELETE_IF(condition, ...)        !$omp target exit data if(condition) map(delete: __VA_ARGS__)
#define GPU_DATA_DELETE_ASYNC(...)         !$omp target exit data map(delete: __VA_ARGS__)
#define GPU_DATA_DELETE_NOWAIT(...)         !$omp target exit data map(delete: __VA_ARGS__) nowait
#define GPU_DATA_DELETE_IF_ASYNC(condition, ...)      !$omp target exit data if(condition) map(delete: __VA_ARGS__)
#define GPU_DATA_DELETE_IF_NOWAIT(condition, ...)      !$omp target exit data if(condition) map(delete: __VA_ARGS__) nowait
#define GPU_DATA_DETACH(...)                      !$omp target exit data map(release:__VA_ARGS__)
#define GPU_DATA_DETACH_DELETE(...)             map(delete: __VA_ARGS__)
#define GPU_DATA_ATTACH(ARGS) 

#define GPU_UPDATE_DEVICE(...)                              !$omp target update to(__VA_ARGS__)
#define GPU_UPDATE_DEVICE_IF(condition, ...)                !$omp target update to(__VA_ARGS__) if(condition)
#define GPU_UPDATE_DEVICE_ASYNC(...)                !$omp target update to(__VA_ARGS__)
#define GPU_UPDATE_DEVICE_NOWAIT(...)                !$omp target update to(__VA_ARGS__) nowait
#define GPU_UPDATE_DEVICE_IF_ASYNC(condition, ...)  !$omp target update to(__VA_ARGS__) if(condition)
#define GPU_UPDATE_DEVICE_IF_NOWAIT(condition, ...)  !$omp target update to(__VA_ARGS__) if(condition) nowait
#define GPU_UPDATE_DEVICE_ASYNC_IF(condition, ...)  !$omp target update to(__VA_ARGS__) if(condition)
#define GPU_UPDATE_DEVICE_NOWAIT_IF(condition, ...)  !$omp target update to(__VA_ARGS__) nowait if(condition)

#define GPU_KERNELS()                                      !$omp target
#define GPU_KERNELS_DEFAULT(...)                             !$omp target default(__VA_ARGS__)
#define GPU_KERNELS_DEFAULT_ASYNC(...)                    !$omp target default(__VA_ARGS__)
#define GPU_KERNELS_DEFAULT_NOWAIT(...)                    !$omp target default(__VA_ARGS__) nowait 
#define GPU_KERNELS_DEFAULT_IF(condition, ...)                       !$omp target default(__VA_ARGS__) if(condition)
#define GPU_KERNELS_DEFAULT_ASYNC_IF(condition, ...)              !$omp target default(__VA_ARGS__) if(condition)
#define GPU_KERNELS_DEFAULT_NOWAIT_IF(condition, ...)              !$omp target default(__VA_ARGS__) if(condition) nowait

#define GPU_KERNELS_PRESENT_IF(condition, ...)                       !$omp target if(condition) map(to:__VA_ARGS__)
#define GPU_KERNELS_DEFAULT_PRESENT_IF(condition, default_args, ...)            !$omp target default(default_args) map(to:__VA_ARGS__) if(condition)
#define GPU_KERNELS_DEFAULT_PRESENT_ASYNC_IF(condition, default_args, ...)   !$omp target default(default_args) map(to:__VA_ARGS__) if(condition)
#define GPU_KERNELS_DEFAULT_PRESENT_NOWAIT_IF(condition, default_args, ...)   !$omp target default(default_args) map(to:__VA_ARGS__) if(condition) nowait

#define GPU_KERNELS_IF(...)                                  !$omp target if(__VA_ARGS__)
#define GPU_KERNELS_COPYOUT(...)                             !$omp target map(from:__VA_ARGS__)
#define GPU_KERNELS_DEVICEPTR(...)                           !$omp target use_device_ptr(__VA_ARGS__)
#define GPU_KERNELS_COPYOUT_DEVICEPTR(copyout_args, ...)                !$omp target map(from:__VA_ARGS__) use_device_ptr(copyout_args)
#define GPU_KERNELS_COPYOUT_DEVICEPTR_IF(condition, copyout_args, ...)          !$omp target map(from:__VA_ARGS__) use_device_ptr(copyout_args) if(condition)

#define GPU_ATOMIC_UPDATE()  !$omp atomic update
#define GPU_CACHE(...)  

#define GPU_DECLARE_COPYIN(...)   !$omp declare target to(__VA_ARGS__)
#define GPU_DECLARE_CREATE(...)   !$omp declare target(__VA_ARGS__) 

#define GPU_PARALLEL_DEFAULT_ASYNC_IF(condition, ...) !$omp target teams distribute parallel for default(__VA_ARGS__) if(condition)
#define GPU_PARALLEL_DEFAULT_NOWAIT_IF(condition, ...) !$omp target teams distribute parallel for default(__VA_ARGS__) if(condition) nowait
#define GPU_PARALLEL_LOOP_COLLAPSE_DEFAULT(collapse_args, ...) !$omp target teams distribute parallel for collapse(collapse_args) default(__VA_ARGS__)
#define GPU_PARALLEL !$omp target teams distribute parallel for
#define GPU_PARALLEL_LOOP !$omp target teams distribute parallel for
#define GPU_PARALLEL_PRIVATE(...) !$omp target teams distribute parallel for private(__VA_ARGS__)
#define GPU_PARALLEL_GPU_LOOP !$omp target teams distribute parallel for !$omp loop
#define GPU_PARALLEL_LOOP_GANG_PRIVATE(...) !$omp target teams distribute parallel for private(__VA_ARGS__)
#define GPU_PARALLEL_ASYNC() !$omp target teams distribute parallel for
#define GPU_PARALLEL_NOWAIT() !$omp target teams distribute parallel for nowait
#define GPU_PARALLEL_LOOP_DEFAULT(...) !$omp target teams distribute parallel for default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_PRESENT(...) !$omp target teams distribute parallel for  
#define GPU_PARALLEL_LOOP_REDUCTION(...) !$omp target teams distribute parallel for reduction(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_REDUCTION_REDUCTION(arg1, arg2) !$omp target teams distribute parallel for reduction(arg1) reduction(arg2)
#define GPU_PARALLEL_LOOP_VECTOR_LENGTH(...) !$omp target teams distribute parallel for simd simdlen(__VA_ARGS__)
#define GPU_PARALLEL_WORKER_GANG_COPY(n_workers, n_gangs, ...) !$omp target teams num_teams(n_gangs) thread_limit(n_workers) map(tofrom:__VA_ARGS__) !$omp distribute parallel for
#define GPU_PARALLEL_WORKER_GANG_COPY_IF(n_workers, n_gangs, copy_arg, ...) !$omp target teams num_teams(n_gangs) thread_limit(n_workers) if(__VA_ARGS__) map(tofrom:copy_arg) !$omp distribute parallel for
#define GPU_PARALLEL_DEFAULT(...) !$omp target teams distribute parallel for default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_WORKER_DEFAULT(...) !$omp target teams distribute parallel for default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_DEFAULT(collapse_args, ...) !$omp target teams distribute parallel for simd collapse(collapse_args) default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_PRESENT(collapse_args, ...) !$omp target teams distribute parallel for simd collapse(collapse_args)
#define GPU_PARALLEL_LOOP_GANG_DEFAULT(...) !$omp target teams distribute parallel for default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT(...) !$omp target teams distribute parallel for simd
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRIVATE(...) !$omp target teams distribute parallel for simd private(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_PRIVATE_DEFAULT(default_args, ...) private(__VA_ARGS__) default(default_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRIVATE_PRESENT_COLLAPSE_DEFAULT(default_args, collapse_args, ...) private(__VA_ARGS__) collapse(collapse_args) default(default_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRIVATE_PRESENT_COLLAPSE(collapse_args, ...) private(__VA_ARGS__) collapse(collapse_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRIVATE_PRESENT_DEFAULT(default_args, ...) present(__VA_ARGS__) default(default_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_PRIVATE_VECTOR_LEN(vector_length, ...) private(__VA_ARGS__) simdlen(vector_length)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_PRIVATE_COLLAPSE(collapse_args, ...)  private(__VA_ARGS__) collapse(collapse_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_DEFAULT_REDUCTION_IF(condition, default_args, ...) !$omp target teams distribute parallel for simd default(default_args) reduction(__VA_ARGS__) if(condition)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_DEFAULT_ASYNC_IF(collapse_args, default_args, ...) !$omp target teams distribute parallel for simd collapse(collapse_args) default(default_args) if(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_DEFAULT_NOWAIT_IF(collapse_args, default_args, ...) !$omp target teams distribute parallel for simd collapse(collapse_args) default(default_args) if(__VA_ARGS__) nowait
#define GPU_PARALLEL_LOOP_GANG_VECTOR_VECTOR_LEN_COLLAPSE_PRESENT(vector_length, collapse_args, ...) !$omp target teams distribute parallel for simd simdlen(vector_length) collapse(collapse_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_VECTOR_LEN_PRESENT(collapse_args, vector_length, ...) !$omp target teams distribute parallel for simd collapse(collapse_args) simdlen(vector_length)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_COLLAPSE_IF(collapse_args, condition, ...) !$omp target teams distribute parallel for simd collapse(collapse_args) if(condition)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_LEN_PRESENT(vector_length, ...) !$omp target teams distribute parallel for simd simdlen(vector_length)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_LEN_PRESENT_PRIVATE_FIRST_PRIVATE(firstprivate_args, ...) private(__VA_ARGS__) firstprivate(firstprivate_args)
#define GPU_PARALLEL_LOOP_GANG_PRESENT_PRIVATE_VECTOR_LEN(...) private(__VA_ARGS__)
#define GPU_PARALLEL_PRIVATE_DEFAULT(default_args, ...) !$omp target teams distribute parallel for private(__VA_ARGS__) default(default_args)
#define GPU_PARALLEL_COPYOUT_COLLAPSE_PRESENT(copyout_args, collapse_args, ...) !$omp target teams distribute parallel for collapse(collapse_args) map(from:copyout_args)
#define GPU_PARALLEL_PRESENT_IF(condition, ...) !$omp target teams distribute parallel for if(condition)
#define GPU_PARALLEL_DEFAULT_PRESENT_ASYNC_IF(default_args, condition, ...) !$omp target teams distribute parallel for default(default_args) if(condition)
#define GPU_PARALLEL_DEFAULT_PRESENT_NOWAIT_IF(default_args, condition, ...) !$omp target teams distribute parallel for default(default_args) if(condition) nowait
#define GPU_PARALLEL_PRESENT_DEFAULT_IF(default_args, condition, ...) !$omp target teams distribute parallel for default(default_args) if(condition)
#define GPU_PARALLEL_PRIVATE_ASYNC(...) !$omp target teams distribute parallel for private(__VA_ARGS__)
#define GPU_PARALLEL_PRIVATE_NOWAIT(...) !$omp target teams distribute parallel for private(__VA_ARGS__) nowait
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE(...) !$omp target teams distribute parallel for simd collapse(__VA_ARGS__)

#define GPU_PARALLEL_PRIVATE_PRESENT_DEFAULT(default_args, ...) private(__VA_ARGS__) default(default_args)
#define GPU_PARALLEL_PRIVATE_PRESENT(...) private(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_PRESENT(...)  !$omp target teams distribute parallel for
#define GPU_PARALLEL_LOOP_GANG_PRESENT_PRIVATE_CREATE(create_args, ...) private(__VA_ARGS__) create(create_args)
#define GPU_PARALLEL_LOOP_GANG_PRESENT_PRIVATE(...) private(__VA_ARGS__)


#define GPU_ENTER_DATA_COPYIN(...) !$omp target enter data map(to: __VA_ARGS__)
#define GPU_DATA_COPYIN_ASYNC(...) !$omp target enter data map(to: __VA_ARGS__)
#define GPU_DATA_COPYIN_NOWAIT(...) !$omp target enter data map(to: __VA_ARGS__) nowait
#define GPU_ENTER_DATA_COPYIN_IF(COND, ...) !$omp target enter data map(to: __VA_ARGS__) if(COND)
#define GPU_DATA_COPYIN_IF_ASYNC(COND, ...) !$omp target enter data map(to: __VA_ARGS__) if(COND)
#define GPU_DATA_COPYIN_IF_NOWAIT(COND, ...) !$omp target enter data map(to: __VA_ARGS__) if(COND) nowait


#define GPU_LOOP_VECTOR()                !$omp parallel do simd
#define GPU_LOOP_GANG()                  !$omp parallel do
#define GPU_LOOP_SEQ()                   !$omp for
#define GPU_LOOP_WORKER()                !$omp parallel for
#define GPU_LOOP() 


#define GPU_LOOP_VECTOR_REDUCTION(...)         !$omp parallel do simd reduction(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_REDUCATION(...)   !$omp parallel do simd reduction(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_REDUCATION2(...)  !$omp parallel do simd reduction(__VA_ARGS__)  
#define GPU_LOOP_WORKER_VECTOR_REDUCTION(...)  !$omp parallel for simd reduction(__VA_ARGS__)

#define GPU_LOOP_GANG_VECTOR_TILE(...)              !$omp parallel do 
#define GPU_LOOP_GANG_VECTOR_TILE_PRIVATE(tile_arg,...)      !$omp parallel do 

#define GPU_LOOP_GANG_VECTOR()                              !$omp parallel do simd
#define GPU_LOOP_GANG_NEW_VECTOR(...)                       !$omp parallel do simd gang(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_COLLAPSE(...)                  !$omp parallel do simd collapse(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_PRIVATE(...)                   !$omp parallel do simd private(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_TILE(...)                      !$omp parallel do simd 
#define GPU_LOOP_GANG_VECTOR_PRIVATE_COLLAPSE(collapse_args,...)         !$omp parallel do simd private(__VA_ARGS__) collapse(__VA_ARGS__)
#define GPU_LOOP_GANG_COLLAPSE_PRIVATE(collapse_args, ...)                !$omp parallel do collapse(collapse_args) private(__VA_ARGS__)

#define GPU_LOOP_WORKER_VECTOR()                            !$omp parallel for simd
#define GPU_LOOP_WORKER_VECTOR_PRIVATE(...)                 !$omp parallel for simd private(__VA_ARGS__)

#define GPU_LOOP_VECTOR_PRIVATE(...)                        !$omp parallel do simd private(__VA_ARGS__)
#define GPU_LOOP_VECTOR_COLLAPSE(...)                       !$omp parallel do simd collapse(__VA_ARGS__)
#define GPU_LOOP_VECTOR_PRIVATE_COLLAPSE(collapse_args, ...)              !$omp parallel do simd private(__VA_ARGS__) collapse(collapse_args)
#define GPU_LOOP_VECTOR_COLLAPSE_PRIVATE(collapse_args, ...)              !$omp parallel do simd collapse(collapse_args) private(__VA_ARGS__)
#define GPU_LOOP_VECTOR_ACC_PRIVATE(...)                    !$omp parallel do simd private(__VA_ARGS__)
#define GPU_LOOP_SEQ_PRIVATE(...)                           !$omp for private(__VA_ARGS__)
#define GPU_LOOP_WORKER_PRIVATE(...)                        !$omp parallel for private(__VA_ARGS__)
#define GPU_LOOP_GANG_PRIVATE(...)                          !$omp parallel do private(__VA_ARGS__)
#define GPU_LOOP_GANG_COLLAPSE(...)                         !$omp parallel do collapse(__VA_ARGS__)
#define GPU_LOOP_GANG_PRIVATE_COLLAPSE(collapse_args, ...)                !$omp parallel do private(__VA_ARGS__) collapse(collapse_args)
#define GPU_LOOP_VECTOR_PRIVATE_REDUCTION(...)              !$omp parallel do simd private(__VA_ARGS__) reduction(__VA_ARGS__)
#define GPU_LOOP_VECTOR_REDUCTION(...)                      !$omp parallel do simd reduction(__VA_ARGS__)


#define GPU_HOSTDATA_USE_DEVICE(...) !$omp host_data use_device(__VA_ARGS__)
#define GPU_HOSTDATA_USE_DEVICE_IF(cond, ...) !$omp host_data use_device(__VA_ARGS__) if(cond)

#define GPU_DATA_CREATE(...) !$omp target data map(alloc:__VA_ARGS__)
#define GPU_DATA_CREATE_PRESENT(...) map(present:__VA_ARGS__)
#define GPU_DATA_CREATE_IF(COND, ...) !$omp target data if(COND) map(alloc:__VA_ARGS__)
#define GPU_DATA_CREATE_IF_ASYNC(COND, ...) !$omp target data if(COND) nowait map(alloc:__VA_ARGS__)
#define GPU_DATA_CREATE_IF_NOWAIT(COND, ...) !$omp target data if(COND) nowait map(alloc:__VA_ARGS__)
#define GPU_DATA_CREATE_ASYNC(...) !$omp target data nowait map(alloc:__VA_ARGS__)
#define GPU_DATA_CREATE_NOWAIT(...) !$omp target data nowait map(alloc:__VA_ARGS__)

#define GPU_DATA_CREATE_PRESENT_IF(COND, CREATE_ARGS, PRESENT_ARGS) !$omp target data if(COND) map(alloc:CREATE_ARGS) map(present:PRESENT_ARGS)
#define GPU_DATA_CREATE_PRESENT_ASYNC_IF(COND, CREATE_ARGS, PRESENT_ARGS) !$omp target data if(COND) nowait map(alloc:CREATE_ARGS) map(present:PRESENT_ARGS)
#define GPU_DATA_CREATE_PRESENT_NOWAIT_IF(COND, CREATE_ARGS, PRESENT_ARGS) !$omp target data if(COND) nowait map(alloc:CREATE_ARGS) map(present:PRESENT_ARGS)

#define GPU_DATA_CREATE_COPYIN(CREATE_ARGS, COPYIN_ARGS) !$omp target data map(alloc:CREATE_ARGS) map(to:COPYIN_ARGS)
#define GPU_DATA_CREATE_COPYIN_IF_NOWAIT(COND, CREATE_ARGS, COPYIN_ARGS) !$omp target data if(COND) nowait map(alloc:CREATE_ARGS) map(to:COPYIN_ARGS)

#define GPU_DATA_CREATE_COPYOUT(CREATE_ARGS, COPYOUT_ARGS) !$omp target data map(alloc:CREATE_ARGS) map(from:COPYOUT_ARGS)

#define GPU_DATA_CREATE_COPYIN_PRESENT_IF(COND, CREATE_ARGS, COPYIN_ARGS, PRESENT_ARGS) !$omp target data if(COND) map(alloc:CREATE_ARGS) map(to:COPYIN_ARGS) map(present:PRESENT_ARGS)


    
#define GPU_DATA_COPYOUT_PRESENT(copyout_args, ...) !$omp target data map(from: copyout_args) map(present: __VA_ARGS__)
#define GPU_DATA_COPYIN_NOWAIT_IF(condition, ...) !$omp target data map(to: __VA_ARGS__) if(condition) nowait
#define GPU_DATA_COPYIN_ASYNC_IF(condition, ...) !$omp target data map(to: __VA_ARGS__) if(condition)
#define GPU_DATA_COPYIN_IF(condition, ...) !$omp target data map(to: __VA_ARGS__) if(condition)
#define GPU_DATA_COPYIN(...) !$omp target data map(to: __VA_ARGS__)


#else

#define GPU_DATA_PRESENT(...) !$acc data present(__VA_ARGS__)
#define GPU_DATA_PRESENT_IF(condition_arg, ...) !$acc data present(__VA_ARGS__) if(condition_arg)
#define GPU_DATA_PRESENT_COPY(condition_arg, copyin_arg, copy_arg, ...) !$acc data present(__VA_ARGS__) copyin(copyin_arg) copy(copy_arg) if(condition_arg)
#define GPU_DATA_PRESENT_CREATE(...) create(__VA_ARGS__)

#define GPU_DATA_ALLOC(...) !$acc enter data create(__VA_ARGS__)
#define GPU_DATA_ALLOC_IF(condition_arg, ...) !$acc enter data create(__VA_ARGS__) if(condition_arg)
#define GPU_DATA_ALLOC_IF_ASYNC(condition_arg, ...) !$acc enter data create(__VA_ARGS__) if(condition_arg) async(0)
#define GPU_DATA_ALLOC_IF_NOWAIT(condition_arg, ...) !$acc enter data create(__VA_ARGS__) if(condition_arg) async(1)
#define GPU_DATA_ALLOC_ASYNC(...) !$acc enter data create(__VA_ARGS__) async(0)
#define GPU_DATA_ALLOC_NOWAIT(...) !$acc enter data create(__VA_ARGS__) async(1)

#define GPU_DATA_UPDATE_HOST_WAIT_IF(condition_arg, wait_arg, ...) \
    !$acc update host(__VA_ARGS__) wait(wait_arg) if(condition_arg) 
#define GPU_DATA_UPDATE_HOST_ASYNC_IF(condition_arg, async_arg, ...) \
    !$acc update host(__VA_ARGS__) async(async_arg) if(condition_arg) 
#define GPU_DATA_UPDATE_HOST_IF_ASYNC(condition_arg, ...) \
    !$acc update host(__VA_ARGS__) if(condition_arg) async(0)
#define GPU_DATA_UPDATE_HOST_IF_NOWAIT(condition_arg, ...) \
    !$acc update host(__VA_ARGS__) if(condition_arg) async(1)
#define GPU_DATA_UPDATE_HOST_IF(condition_arg, ...) \
    !$acc update host(__VA_ARGS__) if(condition_arg)
#define GPU_DATA_UPDATE_HOST_ASYNC(async_arg, ...) \
    !$acc update host(__VA_ARGS__) async(async_arg)
#define GPU_DATA_UPDATE_HOST_WAIT(wait_arg, ...) \
    !$acc update host(__VA_ARGS__) wait(wait_arg)
#define GPU_DATA_UPDATE_HOST(...) \
    !$acc update host(__VA_ARGS__)

#define GPU_ROUTINE(...) !$acc routine(__VA_ARGS__)
#define GPU_ROUTINE_SEQ(...) !$acc routine(__VA_ARGS__) seq
#define GPU_ROUTINE_VECTOR(...) !$acc routine(__VA_ARGS__) vector
#define GPU_ROUTINE_WORKER(...) !$acc routine(__VA_ARGS__) worker
#define GPU_ROUTINE_GANG(...) !$acc routine(__VA_ARGS__) gang

#define GPU_END_PARALLEL !acc end parallel
#define GPU_END_PARALLEL_LOOP !$acc end parallel loop
#define GPU_END_DATA !acc end data
#define GPU_END_SERIAL !$acc end serial
#define GPU_END_KERNELS !$acc end kernels
#define GPU_END_KERNELS_LOOP !$acc end kernels loop
#define GPU_END_HOST_DATA !$acc end host_data
#define GPU_END_ATOMIC !$acc end atomic

#define GPU_WAIT()                        !$acc wait
#define GPU_WAIT_IF(...)           !$acc wait if(__VA_ARGS__)
#define GPU_WAIT_STREAM(...)              !$acc wait(__VA_ARGS__)
#define GPU_WAIT_STREAM_IF(condition, ...)     !$acc wait(__VA_ARGS__) if(condition)

#define GPU_DATA_DELETE(...)                      !$acc exit data delete(__VA_ARGS__)
#define GPU_DATA_DELETE_IF(condition, ...)        !$acc exit data delete(__VA_ARGS__) if(condition)
#define GPU_DATA_DELETE_ASYNC(...) \
    !$acc exit data delete(__VA_ARGS__) async(0)

#define GPU_DATA_DELETE_NOWAIT(...) \
    !$acc exit data delete(__VA_ARGS__) async(1)

#define GPU_DATA_DELETE_IF_ASYNC(condition, ...) \
    !$acc exit data delete(__VA_ARGS__) if(condition) async(0)

#define GPU_DATA_DELETE_IF_NOWAIT(condition, ...) \
    !$acc exit data delete(__VA_ARGS__) if(condition) async(1)
#define GPU_DATA_DETACH(...)                      !$acc exit data detach(__VA_ARGS__)
#define GPU_DATA_DETACH_DELETE(...) delete(__VA_ARGS__)

#define GPU_DATA_ATTACH(...) !$acc enter data attach(__VA_ARGS__)

#define GPU_UPDATE_DEVICE(...)                              !$acc update device(__VA_ARGS__)
#define GPU_UPDATE_DEVICE_IF(condition, ...)                !$acc update device(__VA_ARGS__) if(condition)
#define GPU_UPDATE_DEVICE_ASYNC(...) \
    !$acc update device(__VA_ARGS__) async(0)
#define GPU_UPDATE_DEVICE_NOWAIT(...) \
    !$acc update device(__VA_ARGS__) async(1)
#define GPU_UPDATE_DEVICE_IF_ASYNC(condition, ...) \
    !$acc update device(__VA_ARGS__) if(condition) async(0)
#define GPU_UPDATE_DEVICE_IF_NOWAIT(condition, ...) \
    !$acc update device(__VA_ARGS__) if(condition) async(1)
#define GPU_UPDATE_DEVICE_ASYNC_IF(condition, ...) \
    !$acc update device(__VA_ARGS__) async(0) if(condition)
#define GPU_UPDATE_DEVICE_NOWAIT_IF(condition, ...) \
    !$acc update device(__VA_ARGS__) async(1) if(condition)

#define GPU_KERNELS()                                      !$acc kernels
#define GPU_KERNELS_DEFAULT(...)                             !$acc kernels default(__VA_ARGS__)
#define GPU_KERNELS_DEFAULT_ASYNC(...) \
    !$acc kernels default(__VA_ARGS__) async(0)

#define GPU_KERNELS_DEFAULT_NOWAIT(...) \
    !$acc kernels default(__VA_ARGS__) async(1)

#define GPU_KERNELS_DEFAULT_IF(condition, ...)                       !$acc kernels default(__VA_ARGS__) if(condition)
#define GPU_KERNELS_DEFAULT_ASYNC_IF(condition, ...) \
    !$acc kernels default(__VA_ARGS__) async(0) if(condition)
#define GPU_KERNELS_DEFAULT_NOWAIT_IF(condition, ...) \
    !$acc kernels default(__VA_ARGS__) async(1) if(condition)


#define GPU_KERNELS_PRESENT_IF(condition, ...)                       !$acc kernels present(__VA_ARGS__) if(condition)
#define GPU_KERNELS_DEFAULT_PRESENT_IF(condition, default_args, ...)            !$acc kernels default(default_args) present(__VA_ARGS__) if(condition)
#define GPU_KERNELS_DEFAULT_PRESENT_ASYNC_IF(condition, default_args, ...) \
    !$acc kernels default(default_args) present(__VA_ARGS__) async(0) if(condition)
#define GPU_KERNELS_DEFAULT_PRESENT_NOWAIT_IF(condition, default_args, ...) \
    !$acc kernels default(default_args) present(__VA_ARGS__) async(1) if(condition)


#define GPU_KERNELS_IF(...)                                  !$acc kernels if(__VA_ARGS__)
#define GPU_KERNELS_COPYOUT(...)                             !$acc kernels copyout(__VA_ARGS__)
#define GPU_KERNELS_DEVICEPTR(...)                           !$acc kernels deviceptr(__VA_ARGS__)
#define GPU_KERNELS_COPYOUT_DEVICEPTR(copyout_args, ...)                !$acc kernels copyout(copyout_args) deviceptr(__VA_ARGS__)
#define GPU_KERNELS_COPYOUT_DEVICEPTR_IF(condition, copyout_args, ...)          !$acc kernels copyout(copyout_args) deviceptr(__VA_ARGS__) if(condition)

#define GPU_ATOMIC_UPDATE()  !$acc atomic update
#define GPU_CACHE(...)  !$acc cache(__VA_ARGS__)

#define GPU_DECLARE_COPYIN(...)   !$acc declare copyin(__VA_ARGS__)
#define GPU_DECLARE_CREATE(...)   !$acc declare create(__VA_ARGS__)


#define GPU_PARALLEL_DEFAULT_ASYNC_IF(condition, ...) \
    !$acc parallel default(__VA_ARGS__) async(0) if(condition)
#define GPU_PARALLEL_DEFAULT_NOWAIT_IF(condition, ...) \
    !$acc parallel default(__VA_ARGS__) async(1) if(condition)

#define GPU_PARALLEL_LOOP_COLLAPSE_DEFAULT(collapse_args, ...) !$acc parallel loop collapse(collapse_args) default(__VA_ARGS__)
#define GPU_PARALLEL !$acc parallel
#define GPU_PARALLEL_LOOP !$acc parallel loop
#define GPU_PARALLEL_PRIVATE(...) !$acc parallel private(__VA_ARGS__)
#define GPU_PARALLEL_GPU_LOOP !$acc parallel !$acc loop
#define GPU_PARALLEL_LOOP_GANG_PRIVATE(...) !$acc parallel loop gang private(__VA_ARGS__)
#define GPU_PARALLEL_ASYNC() \
    !$acc parallel async(0)

#define GPU_PARALLEL_NOWAIT() \
    !$acc parallel async(1)

#define GPU_PARALLEL_LOOP_DEFAULT(...) !$acc parallel loop default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_PRESENT(...) !$acc parallel loop present(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_REDUCTION(...) !$acc parallel loop reduction(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_REDUCTION_REDUCTION(arg1, arg2) !$acc parallel loop reduction(arg1) reduction(arg2)
#define GPU_PARALLEL_LOOP_VECTOR_LENGTH(...) !$acc parallel loop vector vector_length(__VA_ARGS__)
#define GPU_PARALLEL_WORKER_GANG_COPY(n_workers, n_gangs, ...) !$acc parallel num_workers(n_workers) num_gangs(n_gangs) copy(__VA_ARGS__)
#define GPU_PARALLEL_WORKER_GANG_COPY_IF(n_workers, n_gangs, copy_arg, ...) !$acc parallel num_workers(n_workers) num_gangs(n_gangs) copy(copy_arg) if(__VA_ARGS__)
#define GPU_PARALLEL_DEFAULT(...) !$acc parallel default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_WORKER_DEFAULT(...) !$acc parallel loop gang worker default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_DEFAULT(collapse_args, ...) !$acc parallel loop gang vector collapse(collapse_args) default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_PRESENT(collapse_args, ...) !$acc parallel loop gang vector collapse(collapse_args) present(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_DEFAULT(...) !$acc parallel loop gang default(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT(...) !$acc parallel loop gang vector present(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRIVATE(...) !$acc parallel loop gang vector private(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_PRIVATE_DEFAULT(default_args, ...) private(__VA_ARGS__) default(default_args)

#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRIVATE_PRESENT_COLLAPSE(collapse_args, ...)  present(__VA_ARGS__) collapse(collapse_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRIVATE_PRESENT_DEFAULT(default_args, ...) present(__VA_ARGS__) default(default_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_PRIVATE_VECTOR_LEN(vector_length, ...) private(__VA_ARGS__) vector_length(vector_length)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_PRIVATE_COLLAPSE(collapse_args, ...) private(__VA_ARGS__) collapse(collapse_args)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_DEFAULT_REDUCTION_IF(condition, default_args, ...) !$acc parallel loop gang vector default(default_args) reduction(__VA_ARGS__) if(condition)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_DEFAULT_ASYNC_IF(collapse_args, default_args, ...) \
    !$acc parallel loop gang vector collapse(collapse_args) default(default_args) async(0) if(__VA_ARGS__)

#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_DEFAULT_NOWAIT_IF(collapse_args, default_args, ...) \
    !$acc parallel loop gang vector collapse(collapse_args) default(default_args) async(1) if(__VA_ARGS__)

#define GPU_PARALLEL_LOOP_GANG_VECTOR_VECTOR_LEN_COLLAPSE_PRESENT(vector_length, collapse_args, ...) !$acc parallel loop gang vector vector_length(vector_length) collapse(collapse_args) present(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE_VECTOR_LEN_PRESENT(collapse_args, vector_length, ...) !$acc parallel loop gang vector collapse(collapse_args) vector_length(vector_length) present(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_PRESENT_COLLAPSE_IF(collapse_args, condition, ...) !$acc parallel loop gang vector present(__VA_ARGS__) collapse(collapse_args) if(condition)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_LEN_PRESENT(vector_length, ...) !$acc parallel loop gang vector_length(vector_length) present(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_VECTOR_LEN_PRESENT_PRIVATE_FIRST_PRIVATE(firstprivate_args, ...)  private(...) firstprivate(firstprivate_args)
#define GPU_PARALLEL_LOOP_GANG_PRESENT_PRIVATE_VECTOR_LEN(...) private(__VA_ARGS__)
#define GPU_PARALLEL_PRIVATE_DEFAULT(default_args, ...) !$acc parallel private(__VA_ARGS__) default(default_args)
#define GPU_PARALLEL_COPYOUT_COLLAPSE_PRESENT(copyout_args, collapse_args, ...) !$acc parallel loop copyout(copyout_args) collapse(collapse_args) present(__VA_ARGS__)
#define GPU_PARALLEL_PRESENT_IF(condition, ...) !$acc parallel present(__VA_ARGS__) if(condition)
#define GPU_PARALLEL_DEFAULT_PRESENT_ASYNC_IF(default_args, condition, ...) \
    !$acc parallel default(default_args) present(__VA_ARGS__) async(0) if(condition)
#define GPU_PARALLEL_DEFAULT_PRESENT_NOWAIT_IF(default_args, condition, ...) \
    !$acc parallel default(default_args) present(__VA_ARGS__) async(1) if(condition)

#define GPU_PARALLEL_PRESENT_DEFAULT_IF(default_args, condition, ...) !$acc parallel present(__VA_ARGS__) default(default_args) if(condition)

#define GPU_PARALLEL_PRIVATE_PRESENT_DEFAULT(default_args, ...) present(__VA_ARGS__) default(default_args)
#define GPU_PARALLEL_PRIVATE_PRESENT(...) present(__VA_ARGS__)
#define GPU_PARALLEL_PRIVATE_ASYNC(...) \
    !$acc parallel private(__VA_ARGS__) async(0)

#define GPU_PARALLEL_PRIVATE_NOWAIT(...) \
    !$acc parallel private(__VA_ARGS__) async(1)

#define GPU_PARALLEL_LOOP_GANG_VECTOR_COLLAPSE(...) \
    !$acc parallel loop gang vector collapse(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_PRESENT(...)  !$acc parallel loop gang present(__VA_ARGS__)
#define GPU_PARALLEL_LOOP_GANG_PRESENT_PRIVATE_CREATE(create_args, ...) private(__VA_ARGS__) create(create_args)
#define GPU_PARALLEL_LOOP_GANG_PRESENT_PRIVATE(...) private(__VA_ARGS__)
#define GPU_ENTER_DATA_COPYIN(VAR) !$acc enter data copyin(VAR)

#define GPU_DATA_COPYIN_ASYNC(...) !$acc enter data copyin(__VA_ARGS__) async(0)
#define GPU_DATA_COPYIN_NOWAIT(...) !$acc enter data copyin(__VA_ARGS__) async(1)
#define GPU_ENTER_DATA_COPYIN_IF(COND, ...) !$acc enter data copyin(__VA_ARGS__) if(COND)
#define GPU_DATA_COPYIN_IF_ASYNC(COND, ...) !$acc enter data copyin(__VA_ARGS__) if(COND) async(0)
#define GPU_DATA_COPYIN_IF_NOWAIT(COND, ...) !$acc enter data copyin(__VA_ARGS__) if(COND) async(1)


#define GPU_LOOP_VECTOR()                !$acc loop vector
#define GPU_LOOP_GANG()                  !$acc loop gang
#define GPU_LOOP_SEQ()                   !$acc loop seq
#define GPU_LOOP_WORKER()                !$acc loop worker
#define GPU_LOOP()                       !$acc loop

#define GPU_LOOP_VECTOR_REDUCTION(...)         !$acc loop vector reduction(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_REDUCATION(...)   !$acc loop vector reduction(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_REDUCATION2(...)  !$acc loop vector reduction(__VA_ARGS__)
#define GPU_LOOP_WORKER_VECTOR_REDUCTION(...)  !$acc loop worker vector reduction(__VA_ARGS__)

#define GPU_LOOP_GANG_VECTOR_TILE(...)              !$acc loop gang vector tile(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_TILE_PRIVATE(tile_arg, ...)     !$acc loop gang vector tile(tile_arg) private(__VA_ARGS__)

#define GPU_LOOP_GANG_VECTOR()                              !$acc loop gang vector
#define GPU_LOOP_GANG_NEW_VECTOR(...)            !$acc loop gang(__VA_ARGS__) VECTOR
#define GPU_LOOP_GANG_VECTOR_COLLAPSE(...)                  !$acc loop gang vector collapse(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_PRIVATE(...)                   !$acc loop gang vector private(__VA_ARGS__)
#define GPU_LOOP_GANG_VECTOR_PRIVATE_COLLAPSE(collapse_args, ...)         !$acc loop gang vector private(__VA_ARGS__) collapse(collapse_args)
#define GPU_LOOP_GANG_COLLAPSE_PRIVATE(collapse_args, ...)                !$acc loop gang collapse(collapse_args) private(__VA_ARGS__)


#define GPU_LOOP_WORKER_VECTOR()                            !$acc loop worker vector
#define GPU_LOOP_WORKER_VECTOR_PRIVATE(...)                 !$acc loop worker vector private(__VA_ARGS__)

#define GPU_LOOP_VECTOR_PRIVATE(...)                        !$acc loop vector private(__VA_ARGS__)
#define GPU_LOOP_VECTOR_COLLAPSE(...)                       !$acc loop vector collapse(__VA_ARGS__)
#define GPU_LOOP_VECTOR_PRIVATE_COLLAPSE(collapse_args, ...)              !$acc loop vector private(__VA_ARGS__) collapse(collapse_args)
#define GPU_LOOP_VECTOR_COLLAPSE_PRIVATE(collapse_args,...)              !$acc loop vector collapse(collapse_args) private(__VA_ARGS__)
#define GPU_LOOP_VECTOR_ACC_PRIVATE(...)                    !$acc loop vector private(__VA_ARGS__)
#define GPU_LOOP_SEQ_PRIVATE(...)                           !$acc loop seq private(__VA_ARGS__)
#define GPU_LOOP_WORKER_PRIVATE(...)                        !$acc loop worker private(__VA_ARGS__)
#define GPU_LOOP_GANG_PRIVATE(...)                          !$acc loop gang private(__VA_ARGS__)
#define GPU_LOOP_GANG_COLLAPSE(...)                         !$acc loop gang collapse(__VA_ARGS__)
#define GPU_LOOP_GANG_PRIVATE_COLLAPSE(collapse_args, ...)                !$acc loop gang private(__VA_ARGS__) collapse(collapse_args)
#define GPU_LOOP_VECTOR_PRIVATE_REDUCTION(...)              !$acc loop vector private(__VA_ARGS__) reduction(__VA_ARGS__)

#define GPU_HOSTDATA_USE_DEVICE(...) !$acc host_data use_device(__VA_ARGS__)
#define GPU_HOSTDATA_USE_DEVICE_IF(cond, ...) !$acc host_data use_device(__VA_ARGS__) if(cond)


#define GPU_DATA_CREATE(...) !$acc data create(__VA_ARGS__)
#define GPU_DATA_CREATE_PRESENT(...) present(__VA_ARGS__)
#define GPU_DATA_CREATE_IF(COND, ...) !$acc data if(COND) create(__VA_ARGS__)
#define GPU_DATA_CREATE_IF_ASYNC(COND, ...) !$acc data if(COND) async(0) create(__VA_ARGS__)
#define GPU_DATA_CREATE_IF_NOWAIT(COND, ...) !$acc data if(COND) async(1) create(__VA_ARGS__)
#define GPU_DATA_CREATE_ASYNC(...) !$acc data async(0) create(__VA_ARGS__)
#define GPU_DATA_CREATE_NOWAIT(...) !$acc data async(1) create(__VA_ARGS__)

#define GPU_DATA_CREATE_PRESENT_IF(COND, CREATE_ARGS, PRESENT_ARGS) !$acc data if(COND) create CREATE_ARGS present PRESENT_ARGS
#define GPU_DATA_CREATE_PRESENT_ASYNC_IF(COND, CREATE_ARGS, PRESENT_ARGS) !$acc data if(COND) async(0) create CREATE_ARGS present PRESENT_ARGS
#define GPU_DATA_CREATE_PRESENT_NOWAIT_IF(COND, CREATE_ARGS, PRESENT_ARGS) !$acc data if(COND) async(1) create CREATE_ARGS present PRESENT_ARGS

#define GPU_DATA_CREATE_COPYIN(CREATE_ARGS, COPYIN_ARGS) !$acc data create CREATE_ARGS copyin COPYIN_ARGS
#define GPU_DATA_CREATE_COPYIN_IF_NOWAIT(COND, CREATE_ARGS, COPYIN_ARGS) !$acc data if(COND) async(1) create CREATE_ARGS copyin COPYIN_ARGS

#define GPU_DATA_CREATE_COPYOUT(CREATE_ARGS, COPYOUT_ARGS) !$acc data create CREATE_ARGS copyout COPYOUT_ARGS

#define GPU_DATA_CREATE_COPYIN_PRESENT_IF(COND, CREATE_ARGS, COPYIN_ARGS, PRESENT_ARGS) !$acc data if(COND) create CREATE_ARGS copyin COPYIN_ARGS present PRESENT_ARGS



#define GPU_DATA_COPYOUT_PRESENT(copyout_args, ...) !$acc data copyout (copyout_args) present(__VA_ARGS__)
#define GPU_DATA_COPYIN_NOWAIT_IF(condition,...) !$acc data copyin (__VA_ARGS__) async(1) if(condition)
#define GPU_DATA_COPYIN_ASYNC_IF(condition,...) !$acc data copyin (__VA_ARGS__) async(0) if(condition)
#define GPU_DATA_COPYIN_IF(condition, ...) !$acc data copyin (__VA_ARGS__) if(condition)
#define GPU_DATA_COPYIN(...) !$acc data copyin (__VA_ARGS__)

#endif
