#!/bin/bash

generate()
{
    bench_pool=$1
    echo ${bench_pool[@]}
    cd ispass2009-benchmarks
    for bench in ${bench_pool[@]};
    do
        cd $bench
        OUT=results.$2.txt
        if [ -f $OUT ]
        then
            rm $OUT
        fi
	if [ ! -f $SCHED.cpl ]
	then
            echo "generating oracle counter for $bench with $SCHED"
            sh README.GPGPU-Sim > $OUT
	fi
        cd ..
    done
}