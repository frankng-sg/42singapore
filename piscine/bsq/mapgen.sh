mv mapgen/mapgen.x mapgen/mapgen.c
cc -Wall -Wextra -Werror mapgen/mapgen.c -o genmap
./genmap $1 $2 $3
mv mapgen/mapgen.c mapgen/mapgen.x
