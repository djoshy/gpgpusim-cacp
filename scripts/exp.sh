#!/bin/bash
set -e
echo "Compiling..."
./scripts/run.sh compile
echo "running lrr(+cacp)"
./scripts/run.sh $1 lrr yes yes
echo "running lrr+cacp"
./scripts/run.sh $1 lrr yes yes yes
echo "running gto(+cacp)"
./scripts/run.sh $1 gto yes yes
echo "running gto+cacp"
./scripts/run.sh $1 gto yes yes yes
echo "running caws(oracle)"
./scripts/run.sh $1 caws no yes
echo "running gcaws(oracle)"
./scripts/run.sh $1 gcaws no yes
echo "running cawa(oracle)"
./scripts/run.sh $1 gcaws no yes yes
echo "running caws(actual)"
./scripts/run.sh $1 caws yes yes
echo "running gcaws(actual)"
./scripts/run.sh $1 gcaws yes yes
echo "running cawa(actual)"
./scripts/run.sh $1 gcaws yes yes yes