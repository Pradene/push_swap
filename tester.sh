#!/bin/bash

# Path to your push_swap exe
PUSH_SWAP="./push_swap"

# Number of tests for each case
TESTS_2=5
TESTS_3=10
TESTS_5=10
TESTS_100=100
TESTS_500=100

# Range for random numbers
MIN=-1000
MAX=1000

# Colors
GREEN="\033[1;32m"
RED="\033[1;31m"
RESET="\033[0m"

# Function to generate N unique random numbers
generate_numbers() {
    local count=$1
    local range=$((MAX - MIN + 1))
    if (( count > range )); then
        echo "Error: Cannot generate $count unique numbers in range $MIN..$MAX"
        exit 1
    fi
    seq $MIN $MAX | shuf -n $count
}

# Function to run tests
run_tests() {
    local n=$1
    local tests=$2

    echo "Testing with $n numbers ($tests runs)"

    local min_ops=-1
    local max_ops=0
    local total_ops=0

    for ((i=1; i<=tests; i++)); do
        nums=$(generate_numbers $n | tr '\n' ' ')
        output=$($PUSH_SWAP $nums)
        ret=$?
        ops=$(echo "$output" | wc -l)

        if [[ $ret -eq 0 ]]; then
            echo -e "Test $i: ${GREEN}SUCCESS${RESET} | Ops: $ops"
        else
            echo -e "Test $i: ${RED}FAIL${RESET}"
        fi

        # update stats only if success
        if [[ $ret -eq 0 ]]; then
            (( total_ops += ops ))
            if (( min_ops == -1 || ops < min_ops )); then
                min_ops=$ops
            fi
            if (( ops > max_ops )); then
                max_ops=$ops
            fi
        fi
    done

    # print stats
    if (( total_ops > 0 )); then
        avg_ops=$(( total_ops / tests ))
        echo -e ">>> Stats for $n numbers: min=$min_ops, avg=$avg_ops, max=$max_ops"
    else
        echo -e ">>> Stats for $n numbers: ${RED}NO SUCCESSFUL TESTS${RESET}"
    fi
    echo
}

# Run all test cases
run_tests 2 $TESTS_2
run_tests 3 $TESTS_3
run_tests 5 $TESTS_5
run_tests 100 $TESTS_100
run_tests 500 $TESTS_500
