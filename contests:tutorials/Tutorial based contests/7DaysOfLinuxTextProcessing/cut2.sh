#Task:
#
#Display the 2nd and 7th character from each line of text.
#
#Input Format:
#
#A text file with N lines of ASCII text only.
#
#Constraints:
#
#1 ≤ N ≤ 100
#
#Note: These values don't really impact your command.
#
#Output Format:
#
#The output should contain N lines. Each line should contain just two characters at the 2nd and the 7th #position of the corresponding input line.
#
#Do not code defensively for situations where the text is short, and the required characters may not be #present in a line of text. The cut command will handle it and will not display any character or line in #such a situation.
#
#Sample Input:
#
#Hello
#World
#how are you
#
#Sample Output:
#
#e
#o
#oe


cut -c2,7