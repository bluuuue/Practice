countnum=1
cat 10Lines.txt | while read LINE
do
    if [ $countnum == 10 ]
    then
        echo $LINE
    fi
    countnum=$((countnum+1))
done
