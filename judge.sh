#!/bin/bash
ls | grep results.txt &>/dev/null
    if [ $? -eq 0 ];
    then
        rm results.txt
    fi

questions=4
for j in $( seq 1 $questions)
    do
    g++ Q$j.cpp
    echo "$j"
    if [ $? -eq 0 ];
    then
        total=10
        wrong=0
        if [ $j -eq 2 ]
        then
            total=9
        fi
        for i in $( seq 1 $total )
        do
            ./a.out < ./tests/Q$j/$i/$i.in > judge.out
            cmp -s judge.out ./tests/Q$j/$i/$i.out
            if [ $? -eq 1 ];
            then
                wrong=$((wrong+1))
                echo "question number $j, test number $i: " >> results.txt
                diff judge.out ./tests/Q$j/$i/$i.out >> results.txt
                echo "________________________________" >> results.txt
            fi
        done
        echo "question $j: $total tests, $(expr $total - $wrong) right, $wrong wrong"
    fi
done
rm judge.out
rm a.out

