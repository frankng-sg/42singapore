#!/bin/bash
ifconfig | awk '/ether/ {print $2}'
