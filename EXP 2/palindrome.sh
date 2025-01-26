//Swaliha_59
echo "enter the number"
read a
num=$a
rev=0
while [ $a -gt 0 ]
do
 digits=$(( $a % 10 ))
 rev=$((rev * 10 + $digits ))
 a=$(( $a / 10 ))
done
if [ $rev -eq $num ] 
then
  echo " it is palindrome "
else
   echo " it is not palindrome"
fi

