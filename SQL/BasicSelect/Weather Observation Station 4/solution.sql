/*
Enter your query here.
*/
/*SELECT COUNT(DISTINCT S.CITY) AS DistinctCities
FROM STATION S; 

SELECT COUNT(S.CITY) AS CitiesInList
FROM STATION S;
*/
SELECT List.CitiesInList - UniqueList.DistinctCities
FROM (SELECT COUNT(DISTINCT S.CITY) AS DistinctCities
      FROM STATION S) AS UniqueList,
     (SELECT COUNT(S.CITY) AS CitiesInList
      FROM STATION S) AS List;
