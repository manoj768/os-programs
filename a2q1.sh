echo "Enter a number to check if even or odd"
read n
rem = $((n%2))
if [$rem -eq 0]
then echo " $n is Even"
else echo " $n is odd"
fi