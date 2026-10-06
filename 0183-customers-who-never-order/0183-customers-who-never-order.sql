# Write your MySQL query statement below
SELECT name as Customers
FROM Customers AS c
LEFT JOIN Orders AS o
ON c.id = o.customerId
Where o.id IS NULL