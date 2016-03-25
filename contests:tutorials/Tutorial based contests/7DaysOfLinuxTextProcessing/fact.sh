#Objective:
#
#In this challenge, we will practice writing a bash or awk program to compute factorials.
#
#Task:
#
#Write a bash or awk program to compute the factorial of a given set of integers. The factorial of a number #n is defined as follows:
#
#Factorial(n)=1∗2∗...(n−1)∗n
#
#Input Format:
#
#The first line of input contains T, the number of test cases. 
#T lines follow each containing an integer n.
#
#Constraints:
#
#1 < n < 1000
#
#Output Format:
#
#Output T lines, each containing the factorial for the corresponding n input.
#
#Sample Input:
#
#2
#10
#5
#
#Sample Output:
#
#3628800
#120

fact ()
{
#assume will pass one value in...

num=$1

if [ $num -lt 1 ]; then
    echo "1"
    return 1
elif [ $num == 1 ]; then
    echo "1"
    return 1
fi

f+=(1);   #base case: fact(1)=1 

for ((i=1; i < $num ;i++))
do
    prevFact=${f[$i-1]}                         # f(i-1)
    nextFact=$(($prevFact * $(($i + 1))))       # f(i-1) * i
    f+=("$nextFact");
    #echo $nextFact
done

size=${#f[*]}
echo ${f[size-1]}
}


#read input into array
#while read line
#do
 #   array+=("$line")
    #i=0
    #echo ${array[i]}
    #i=$(($i+1))
#done

while read -r LINE || [[ -n $LINE ]]; do
    array2+=("$LINE")
done

size=${#array2[0]}
T=${array2[0]:0:size-1}
t=${array2[0]}

for ((i=1; i<T; i++))
do  
    #echo ${array2[i]}
    size2=${#array2[i]}
    size=${#array2[$(($i+1))]}
    n=${array2[i]:0:size2-1}
    N=${array2[i]}
    #echo $n
    #fact $n
    seq -s "*" 1 $n | bc
    #fact $N
    #n=${array[i+1]:0:1}
    #echo $n
    #if [ $n -lt 2 ] 
    #then
    #    echo "8"
    #fi
    #fact $n
    #fact ${array[i+1]:0:${#array[$(($i+1))]}}
done

last=${array2[T]}
seq -s "*" 1 $last | bc