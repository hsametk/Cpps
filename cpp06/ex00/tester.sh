#!/bin/bash

set -u

if [ $# -gt 1 ]; then
    echo "Usage: ./tester.sh [./convert]"
    exit 1
fi

EXEC="${1:-./convert}"
OUTFILE="tester_output.txt"

if [ ! -x "$EXEC" ]; then
    echo "Error: '$EXEC' is not executable."
    echo "Build first with: make"
    exit 1
fi

run_case() {
    local label="$1"
    local input="$2"

    {
        echo
        echo "========================================"
        echo "CASE: $label"
        echo "INPUT: [$input]"
        echo "----------------------------------------"
        if [ "$input" = "__NO_ARG__" ]; then
            "$EXEC"
        else
            "$EXEC" "$input"
        fi
    } >> "$OUTFILE" 2>&1
}

run_group() {
    local title="$1"
    shift

    {
        echo
        echo
        echo "########################################"
        echo "GROUP: $title"
        echo "########################################"
    } >> "$OUTFILE"

    while [ $# -gt 0 ]; do
        run_case "$1" "$2"
        shift 2
    done
}

echo "CPP06 ex00 scalar converter tester" > "$OUTFILE"
echo "Executable: $EXEC" >> "$OUTFILE"
echo "Generated at: $(date '+%Y-%m-%d %H:%M:%S')" >> "$OUTFILE"

run_group "Argument Handling" \
    "no argument" "__NO_ARG__" \
    "empty string" ""

run_group "Char Inputs" \
    "plain alpha" "a" \
    "plain digit char rejected as char" "7" \
    "plain symbol" "*" \
    "single space" " " \
    "quoted alpha" "'a'" \
    "quoted space" "' '" \
    "quoted digit" "'0'"

run_group "Integer Inputs" \
    "zero" "0" \
    "positive" "42" \
    "negative" "-42" \
    "plus sign" "+42" \
    "int max" "2147483647" \
    "int min" "-2147483648" \
    "int overflow positive" "2147483648" \
    "int overflow negative" "-2147483649" \
    "char upper bound" "127" \
    "char overflow" "128"

run_group "Float Inputs" \
    "float zero" "0.0f" \
    "float integer value" "42.0f" \
    "float decimal value" "4.2f" \
    "float negative" "-4.2f" \
    "float leading dot" ".5f" \
    "float trailing dot" "42.f" \
    "float signed leading dot" "-.5f" \
    "float pseudo nan" "nanf" \
    "float pseudo inf" "+inff" \
    "float pseudo neg inf" "-inff"

run_group "Double Inputs" \
    "double zero" "0.0" \
    "double integer value" "42.0" \
    "double decimal value" "4.2" \
    "double negative" "-4.2" \
    "double leading dot" ".5" \
    "double trailing dot" "42." \
    "double signed leading dot" "-.5" \
    "double pseudo nan" "nan" \
    "double pseudo inf" "+inf" \
    "double pseudo neg inf" "-inf"

run_group "Invalid Inputs" \
    "letters" "abc" \
    "double sign plus" "++42" \
    "double sign minus" "--42" \
    "mixed suffix" "42ff" \
    "single dot" "." \
    "single f" "f" \
    "dangling sign" "+" \
    "trailing chars" "12.3foo" \
    "embedded spaces" "4 2" \
    "multiple dots" "1.2.3"

echo
echo "Tests finished."
echo "Output file: $OUTFILE"
