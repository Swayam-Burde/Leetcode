# Write your MySQL query statement below
SELECT(
    SELECT DISTINCT e.salary
    FROM Employee e
    ORDER by salary DESC
    LIMIT 1 OFFSET 1
) as SecondHighestSalary;