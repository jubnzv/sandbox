#!/bin/bash
# https://www.codewars.com/kata/reverser
rev <<< "$1" | sed 's/^0*//'
