#!/bin/sh

if [ $# == 0 ]; then
        echo $0 [file]
        exit
fi

file=$1
total=`wc -l ${file} | awk '{print $1}'`

cat $1 | awk -v total=${total} '
BEGIN {
p50=int(5000*total/10000);
p90=int(9000*total/10000);
p95=int(9500*total/10000);
p99=int(9900*total/10000);
p999=int(9990*total/10000);
p9999=int(9999*total/10000);
p99999=int(99999*total/100000);
p999999=int(999999*total/1000000);
}

{       if(NR==p50) {print "p50", $1}
                else if (NR==p90) {print "p90", $1}
                else if (NR==p95) {print "p95", $1}
                else if (NR==p99) {print "p99", $1}
                else if (NR==p999) {print "p999", $1}
                else if (NR==p9999) {print "p9999", $1}
                else if (NR==p99999) {print "p99999", $1}
                else if (NR==p999999) {print "p999999", $1}
                else  { }
}
'
