echo "Input directory"
read dir
d=0
while output=`find $dir -mindepth $d -maxdepth $d` && [[ -n $output ]]
do
    find $dir -mindepth $d -maxdepth $d   
    ((d++))
done
