/*
Enter your query here.
*/

/*SELECT CONCAT(O.Name ,'('),CONCAT(SUBSTR(O.Occupation,1,1),')')*/

/*SELECT O.Occupation, COUNT(O.Occupation) AS occupation_count
FROM OCCUPATIONS O
GROUP BY O.Occupation
ORDER BY occupation_count ASC;*/

/*SELECT *
FROM OCCUPATIONS O
ORDER BY O.Name ASC;*/


SELECT CONCAT( CONCAT(O.Name,'('), CONCAT(SUBSTR(O.Occupation,1,1),')') ) AS name
FROM OCCUPATIONS O
ORDER BY O.Name ASC;

SELECT CONCAT( CONCAT( CONCAT("There are total ",TABLE2.occupation_count), CONCAT(" ", LCASE(TABLE2.Occupation)) ), "s.")
FROM (
        SELECT O.Occupation, COUNT(O.Occupation) AS occupation_count
        FROM OCCUPATIONS O
        GROUP BY O.Occupation
        ORDER BY occupation_count ASC
     ) AS TABLE2
ORDER BY TABLE2.occupation_count ASC, TABLE2.Occupation ASC;

