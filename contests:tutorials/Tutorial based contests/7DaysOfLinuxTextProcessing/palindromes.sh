#Objective:
#
#In this challenge, we practice using the awk command or a shell script to detect palindromes.
#
#Task:
#
#You are given a list of words with each word on a new line. Each word contains only lowercase letters #(a−z). Your task is to write a program to display only those words that are palindromes. Palindromes are #strings that read the same when reversed.
#
#Input Format:
#
#The input format consists of a list of words, each on a new line. The words will only contain lowercase #letters (a−z).
#
#Output Format:
#
#Output only the palindromes from the original list of words. Their ordering should be the same as in the #original list.
#
#Sample Input:
#
#test
#toy
#bob
#bil
#cow
#noon
#
#Sample Output:
#
#bob
#noon

#read file into array and initialize boolean Array
while read line
do
    array+=("$line")
    boolArray+="true"
done

for ((i=0; i < ${#array[*]};i++))
do
    size=${#array[i]}
    stringArr=(${array[i]})
    for((j=0; j < size-1;j++))
    do
        leftChar=${array[i]:j:1};
        rightChar=${array[i]:(size-j-2):1}
        if [ "$leftChar" != "$rightChar" ]; then
            boolArray[i]="false"
        fi
    done
    if [ "${boolArray[i]}" != "false" ]; then
        boolArray[i]="true"
    fi
    
    if [ "${boolArray[i]}" == "true" ]; then
        echo ${array[i]}
    fi
done
