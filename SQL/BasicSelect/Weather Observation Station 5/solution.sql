/*
Enter your query here.
*/

SELECT S1.CITY AS temp, Length(S1.CITY)
FROM STATION S1
WHERE LENGTH(S1.CITY) = (SELECT MIN(LENGTH(S.CITY)) AS minLength
                        FROM STATION S
                        )
ORDER BY temp ASC LIMIT 1 OFFSET 0;

SELECT S.CITY AS temp, Length(S.CITY)
FROM STATION S
WHERE LENGTH(S.CITY) = (SELECT MAX(LENGTH(S.CITY)) AS maxLength
                        FROM STATION S
                        )
ORDER BY temp ASC LIMIT 1 OFFSET 0;

/*UNION*/


