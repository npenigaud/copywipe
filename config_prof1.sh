#!/bin/bash

mkdir profil
rocprofv3 --kernel-trace --stats -S -T -d profil -o cwd -- ./test.x
rocprofv3 --pmc OccupancyPercent -T -d profil -o cwd -- ./test.x 

rocprofv3 --kernel-trace --hip-trace --output-format pftrace -d profil -o cwd -- ./test.x
#consultation de pftrace via navigateur sur le site https://ui.perfetto.dev
