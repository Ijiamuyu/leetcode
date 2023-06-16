# Write your MySQL query statement below
SELECT
    emp_id,
    firstname,
    lastname,
    max(salary) AS salary,
    department_id
FROM Salary
GROUP BY emp_id
ORDER BY emp_id;
