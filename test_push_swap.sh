#!/usr/bin/env bash

# test_push_swap.sh: script per testare push_swap senza usare 'for'

# 1) Ricompila da zero
make re

# 2) Verifica che l’eseguibile esista
if [ ! -x ./push_swap ]; then
    echo "Executable not found! Run make."
    exit 1
fi

# 3) Test fissi
echo "Running fixed tests..."
fixed_tests="1
2 1
1 2 3 4 5
5 4 3 2 1
3 1 2
2 3 1
8 3 5 1 9 4 7 6 2"

echo "$fixed_tests" | while IFS= read -r input; do
    echo
    echo "Input: $input"
    moves="$(./push_swap $input)"
    echo "$moves"
    count="$(echo "$moves" | wc -l)"
    echo "Operation count: $count"
done

# 4) Test casuali
echo
echo "Running random tests..."
i=1
while [ "$i" -le 5 ]; do
    input="$(shuf -i 1-20 -n 10 | tr '\n' ' ')"
    echo
    echo "Input: $input"
    moves="$(./push_swap $input)"
    echo "$moves"
    count="$(echo "$moves" | wc -l)"
    echo "Operation count: $count"
    i=$((i + 1))
done

