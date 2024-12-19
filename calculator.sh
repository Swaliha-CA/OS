#swaliha_59
echo "enter the first number"
read a
echo "enter the second number"
read b
echo "choose the operation"
read op
case $op in
1) r=$(( $a + $b ))
   echo " result is $r";;
2) r=$(( $a - $b ))
   echo "result is $r";;
3) r=$(( $a * $b ))
   echo "result is $r";;
4) if [ $b -ne 0 ]
 then
   r=$(( $a / $b ))
    echo "result is $r"
    else
    echo " division by zero not possible"
 fi ;;
*) echo "invalid";;
esac
 
   
   
