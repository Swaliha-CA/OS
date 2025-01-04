#swaliha_59
echo " enter a number"
read n
if [ $(( $n % 2 )) -eq 0 ]
then
  echo " $n is even"
  else
  echo " $n is odd"
 fi
