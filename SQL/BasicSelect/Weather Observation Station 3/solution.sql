/*
Enter your query here.
*/

SELECT DISTINCT S.CITY
FROM STATION S
WHERE S.ID % 2 = 0;