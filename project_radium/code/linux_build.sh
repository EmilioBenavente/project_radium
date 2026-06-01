#!/bin/bash

COMMON_CMD_FLAGS="-g"
COMMON_LINKER_FLAGS="-L../project_radium/code/ -lray -lm"

if [ ! -d ../../build ]; then
  mkdir ../../build
fi

pushd ../../build

rm -rdf *

gcc $COMMON_CMD_FLAGS ../project_radium/code/ray_radium.c $COMMON_LINKER_FLAGS

popd
