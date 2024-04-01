#!/bin/bash

g++ komitet.cpp -o komitet

for i in $(seq 7)
do
    ./komitet < test$i.in
done
