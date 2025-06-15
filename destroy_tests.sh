#!/usr/bin/env bash
# destroy_tests.sh — Stress‐test per push_swap secondo la spec 42

EXEC=./push_swap
CHECKER=./checker_linux

# 1) Ricompila e controlla che esista
make re
if [ ! -x "$EXEC" ]; then
    echo "✗ Eseguibile $EXEC mancante"
    exit 1
fi

# 1. Error management
echo "=== Error tests ==="
error_inputs="foo
1 2 2
1 2147483648
"  
echo "$error_inputs" | while IFS= read -r line; do
    echo "- Input: '$line'"
    $EXEC $line > /dev/null 2>&1
    status=$?
    if [ $status -eq 1 ]; then
        echo "  ✔ exit code 1"
    else
        echo "  ✗ exit code $status (atteso 1)"
    fi
done

# 2. Identity tests (già ordinati)
echo; echo "=== Identity tests ==="
id_tests="0
0 1
0 1 2 3
0 1 2 3 4 5"  
echo "$id_tests" | while IFS= read -r line; do
    echo "- Input: '$line'"
    out="$($EXEC $line)"
    if [ -z "$out" ]; then
        echo "  ✔ nessuna mossa"
    else
        echo "  ✗ mosse emesse: '$out'"
    fi
done

# 3. Permutazioni complete di 3 elementi
echo; echo "=== All perms of 3 ==="
perms="0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0"
echo "$perms" | while IFS= read -r line; do
    echo "- Perm: '$line'"
    moves="$($EXEC $line)"
    echo "  moves: $moves"
    echo "$moves" | $CHECKER $line | sed 's/^/  checker: /'
done

# 4. Casi small (4 e 5 elementi)
echo; echo "=== Small cases (4,5) ==="
small_tests="3 2 1 0
1 3 2 4
2 4 1 5 3
5 1 4 2 3"
echo "$small_tests" | while IFS= read -r line; do
    echo "- Input: '$line'"
    $EXEC $line | $CHECKER $line | sed 's/^/  checker: /'
done

# 5. Casi medi (100 elementi, 3 run)
echo; echo "=== Medium cases (n=100) ==="
i=1
while [ $i -le 3 ]; do
    input="$(shuf -i 1-100 -n 100 | tr '\n' ' ')"
    echo "- Run $i: n=100"
    moves="$($EXEC $input)"
    count="$(echo "$moves" | wc -l)"
    echo "  moves: $count"
    echo "$moves" | $CHECKER $input | sed 's/^/  checker: /'
    i=$((i + 1))
done

# 6. Casi grandi (500 elementi, 2 run)
echo; echo "=== Large cases (n=500) ==="
i=1
while [ $i -le 2 ]; do
    input="$(shuf -i 1-500 -n 500 | tr '\n' ' ')"
    echo "- Run $i: n=500"
    moves="$($EXEC $input)"
    count="$(echo "$moves" | wc -l)"
    echo "  moves: $count"
    echo "$moves" | $CHECKER $input | sed 's/^/  checker: /'
    i=$((i + 1))
done

# 7. Memory leaks (valgrind)
echo; echo "=== Memory leaks ==="
valgrind --leak-check=full --error-exitcode=1 $EXEC 3 2 1 0 > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "✔ No leaks on (3 2 1 0)"
else
    echo "✗ Leak detected!"
fi

echo; echo "=== Fine dei test di distruzione ==="

