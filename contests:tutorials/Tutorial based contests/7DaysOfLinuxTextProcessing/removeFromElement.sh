#Task:
#
#You are given a list of countries, each on a new line. Your task is to read them into an array and then #transform them in the following way:
#
#The first capital letter (if present) in each element of the array should be replaced with a dot ('.'). #Then, display the entire array with a space between each country's names.
#
#Input Format:
#
#The input format consists of a list of country names each on a separate line. The only characters present #in the country names will be upper or lower case characters and hyphens.
#
#Output Format:
#
#Transform the names as described and display the entire array of country names with a space between each of #them.
#
#Sample Input:
#
#Namibia
#Nauru
#Nepal
#Netherlands
#NewZealand
#Nicaragua
#Niger
#Nigeria
#NorthKorea
#Norway
#
#Sample Output:
#
#.amibia .auru .epal .etherlands .ewZealand .icaragua .iger .igeria .orthKorea .orway


#read file into array
while read line
do
    array+=("$line")
done

#first = ${array[0]:0:1}

#a=7     #variable assignment...make sure no spaces

#print items in array
for ((i=0; i < ${#array[*]};i++))
do
    first=${array[i]:0:1}
    if (first==[A-Z]) then
        size=${#array[i]}
        dot="."
        rest=${array[i]:1:size}
        array[i]=$dot$rest
    fi
    echo -n "${array[i]} " #| tr '[:upper:]' '.'
done
#echo -n "some"