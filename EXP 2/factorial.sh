#swaliha_59
echo "enter a number "
read n
fact=1
if [ $n -eq 0 ];
then 
  echo "the factorial is 1"
else
  while [ $n -gt 1 ]
do
 fact=$((fact*$n))
 n=$(( $n -1 ))
  done
echo " the factorial is : $fact"
fi
