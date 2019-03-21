#!/bin/bash
while :; do nc 192.168.2.2 -l -p $1; sleep 1; done
