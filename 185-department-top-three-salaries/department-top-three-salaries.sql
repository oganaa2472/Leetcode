SELECT department, employee, salary
FROM (
    SELECT
        e.name AS employee,
        e.salary,
        d.name AS department,
        DENSE_RANK() OVER (
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        ) AS salary_rank
    FROM Employee e
    JOIN Department d ON e.departmentId = d.id
) AS ranked_salaries
WHERE salary_rank <= 3;
