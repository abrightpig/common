#!/bin/sh

if [ $# == 0 ]; then
        echo $0 [file]
        exit
fi

file=$1
cat $1 | awk '{ if($1<10) {n0++;}
                else if ($1>=10 && $1<100) {n10++;}
                else if ($1>=100 && $1<1000) {n100++;}
                else if ($1>=1000 && $1<10000) {n1000++;}
                else if ($1>=10000 && $1<100000) {n10000++;}
                else if ($1>=100000 && $1<500000) {n100000++;}
                else if ($1>=500000 && $1<1000000) {n500000++;}
                else if ($1>=1000000 && $1<2000000) {n1000000++;}
                else if ($1>=2000000 && $1<3000000) {n2000000++;}
                else  {n3000000++;}
} END {print "n0", n0, 10000*n0/NR,
        "n10", n10, 10000*n10/NR,
        "n100", n100, 10000*n100/NR,
        "n1000", n1000, 10000*n1000/NR,
        "n10000", n10000, 10000*n10000/NR,
        "n100000", n100000, 10000*n100000/NR,
        "n500000", n500000, 10000*n500000/NR,
        "n1000000", n1000000, 10000*n1000000/NR,
        "n2000000", n2000000, 10000*n2000000/NR,
        "n3000000", n3000000, 10000*n3000000/NR
        }'