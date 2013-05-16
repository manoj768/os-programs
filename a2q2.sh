echo "Enter a filename"
read file1
echo "Enter another filename"
read file2
if cmp -s "$file1" "$file2" ;
then echo "Files are similar"
else echo "Files are not similar"
fi