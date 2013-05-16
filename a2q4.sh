echo "Input the directory in which all files are to be deleted"
read dir
cd $dir
rm -rf *
if ["$(ls -A $dir)"];
then
echo "OOPS. Something went wrong"
else 
echo "Specified directory has been emptied"
fi