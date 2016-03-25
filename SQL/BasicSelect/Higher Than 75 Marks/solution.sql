/*
Enter your query here.
*/

SELECT TABLE1.StudentFullName
FROM (
    SELECT IF(LENGTH(S.Name) < 3, 'cant', SUBSTR(S.Name,LENGTH(S.Name) - 2,LENGTH(S.Name))) AS lastThreeChar,         S.name as StudentFullName, S.ID as studentID 
    FROM STUDENTS S
    WHERE S.Marks > 75
    ) AS TABLE1
ORDER BY TABLE1.lastThreeChar ASC, TABLE1.studentID ASC;

