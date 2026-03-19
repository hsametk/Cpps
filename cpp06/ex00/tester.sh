#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Kullanim: ./tester.sh ./convert"
    exit 1
fi

EXEC="$1"
OUTFILE="tester_output.txt"

if [ ! -x "$EXEC" ]; then
    echo "Hata: '$EXEC' calistirilabilir degil."
    echo "Once projeyi derle. Ornek: make"
    exit 1
fi

tests=(
    "'a'"
    "'z'"
    "'0'"
    "' '"
    "0"
    "42"
    "-42"
    "127"
    "128"
    "255"
    "256"
    "2147483647"
    "-2147483648"
    "0.0f"
    "42.0f"
    "-42.0f"
    "4.2f"
    "-4.2f"
    "inff"
    "+inff"
    "-inff"
    "nanf"
    "0.0"
    "42.0"
    "-42.0"
    "4.2"
    "-4.2"
    "inf"
    "+inf"
    "-inf"
    "nan"
    "abc"
    "42ff"
    "--42"
    "++42"
    "."
    "f"
    ""
)

echo "CPP06 ex00 tester output" > "$OUTFILE"
echo "Executable: $EXEC" >> "$OUTFILE"
echo "========================================" >> "$OUTFILE"

for test in "${tests[@]}"; do
{
    echo
    echo "----------------------------------------"
    echo "INPUT: [$test]"
    echo "----------------------------------------"

    if [ -z "$test" ]; then
        "$EXEC"
    else
        "$EXEC" "$test"
    fi
} >> "$OUTFILE" 2>&1
done

echo
echo "Testler bitti."
echo "Cikti dosyasi: $OUTFILE"#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Kullanim: ./tester.sh ./convert"
    exit 1
fi

EXEC="$1"
OUTFILE="tester_output.txt"

if [ ! -x "$EXEC" ]; then
    echo "Hata: '$EXEC' calistirilabilir degil."
    echo "Once projeyi derle. Ornek: make"
    exit 1
fi

tests=(
    "'a'"
    "'z'"
    "'0'"
    "' '"
    "0"
    "42"
    "-42"
    "127"
    "128"
    "255"
    "256"
    "2147483647"
    "-2147483648"
    "0.0f"
    "42.0f"
    "-42.0f"
    "4.2f"
    "-4.2f"
    "inff"
    "+inff"
    "-inff"
    "nanf"
    "0.0"
    "42.0"
    "-42.0"
    "4.2"
    "-4.2"
    "inf"
    "+inf"
    "-inf"
    "nan"
    "abc"
    "42ff"
    "--42"
    "++42"
    "."
    "f"
    ""
)

echo "CPP06 ex00 tester output" > "$OUTFILE"
echo "Executable: $EXEC" >> "$OUTFILE"
echo "========================================" >> "$OUTFILE"

for test in "${tests[@]}"; do
{
    echo
    echo "----------------------------------------"
    echo "INPUT: [$test]"
    echo "----------------------------------------"

    if [ -z "$test" ]; then
        "$EXEC"
    else
        "$EXEC" "$test"
    fi
} >> "$OUTFILE" 2>&1
done

echo
echo "Testler bitti."
echo "Cikti dosyasi: $OUTFILE"