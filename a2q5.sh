echo "Input a Existing directory"
read dir1
echo "Input a new directory"
read dir2
mkdir $dir2
mv "`$dir1`/.*" $dir2
echo " Hidden files moved succesfully" 