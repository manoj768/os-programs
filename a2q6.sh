echo "Input name"
read nd
if [ -d $nd ]
    then
        echo "Directory exists."
elif [ -f $nd ]
    then
        rm -f $nd
fi
mkdir $nd
