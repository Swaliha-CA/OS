#swaliha_59
echo "enter the number"
read n
sum=0
while [ $n -gt 0 ]; do
  digits=$(( n % 10 ))
  sum=$(( sum + digits ))
  n=$(( n /10 ))
done
echo "sum is:$sum"

