#!/bin/bash

# Create chapters 11 throgh 20 directories
# inside each directory, create the exercises directory and create the projects directory

for i in {11..20}; do
    mkdir chapter$i
    cd chapter$i
    mkdir exercises
    mkdir projects
    cd ..
done

# Path: create_dirs.sh
