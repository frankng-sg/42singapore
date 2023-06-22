#!/bin/bash
cat /etc/passwd | sed '/^#/d' | sed -n '0~2p' | cut -d ':' -f 1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ', ' | sed 's/,$/./' | sed 's/,/, /g'

