#!/bin/bash

RUSH_02="./rush-02"
NORMAL_DICT="numbers.dict"
EMPTY_DICT="dict_with_empty_lines.dict"
NEW_DICT="dict_with_new_entries.dict"
PARSING_DICT="dict_with_parsing_error.dict"
RANDOM_DICT="dict_with_random_entry_order.dict"
filtered_lines=$(grep "20" $EMPTY_DICT)

INPUT_NUMBER="123456"
UNSIGNED_NUM="123.123"
F2_NUM="42"
ZERO_NUM="0"
HUNTHOU_NUM="100000"
UNSIGNTEST_NUM="10.4"
F20_NUM="20"

make re

$RUSH_02 $NORMAL_DICT $F2_NUM | cat -e
$RUSH_02 $NORMAL_DICT $ZERO_NUM | cat -e
$RUSH_02 $NORMAL_DICT $UNSIGNTEST_NUM | cat -e
$RUSH_02 $NORMAL_DICT $HUNTHOU_NUM | cat -e
echo "$filtered_lines" | cat -e
$RUSH_02 $EMPTY_DICT $F20_NUM | cat -e
$RUSH_02 $EMPTY_DICT $INPUT_NUMBER
$RUSH_02 $NEW_DICT $INPUT_NUMBER
$RUSH_02 $PARSING_DICT $INPUT_NUMBER
$RUSH_02 $RANDOM_DICT $INPUT_NUMBER
