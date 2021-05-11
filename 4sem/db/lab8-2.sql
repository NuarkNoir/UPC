-- Ранжируйте сотрудников по объемам продаж и выведите тройку лидеров.
WITH trades AS (
    SELECT DISTINCT W.[Имя]                                                                 AS NAME,
                    SUM([Сделка].[Количество] * S.Цена) OVER (PARTITION BY [КодСотрудника]) AS DEALS_SUM

    FROM [Сделка]
             JOIN [Склад] AS S ON S.ID = [Сделка].[КодСклада]
             JOIN [Сотрудник] AS W ON W.ID = [Сделка].[КодСотрудника]
)

SELECT TOP 3 NAME,
             DEALS_SUM,
             DENSE_RANK() OVER (ORDER BY DEALS_SUM DESC) AS RANK
FROM trades
ORDER BY DEALS_SUM DESC;

-- Вывести суммы сделок по месяцам для каждого сотрудника и показать разницу с
-- предыдущим месяцем, в котором были зафиксированы сделки
WITH trades AS (
    SELECT DISTINCT W.[Имя]                                                                                AS NAME,
                    YEAR([Сделка].[Дата])                                                                  AS CURR_YEAR,
                    MONTH([Сделка].[Дата])                                                                 AS CURR_MONTH,
                    SUM([Сделка].[Количество] * S.Цена)
                        OVER (PARTITION BY [КодСотрудника], YEAR([Сделка].[Дата]), MONTH([Сделка].[Дата])) AS DEALS_SUM_CURR_MONTH

    FROM [Сделка]
             JOIN [Склад] AS S ON S.ID = [Сделка].[КодСклада]
             JOIN [Сотрудник] AS W ON W.ID = [Сделка].[КодСотрудника]
)

SELECT NAME,
       CURR_YEAR,
       CURR_MONTH,
       DEALS_SUM_CURR_MONTH,
       DEALS_SUM_CURR_MONTH - COALESCE(LAG(DEALS_SUM_CURR_MONTH) OVER (PARTITION BY NAME ORDER BY NAME), 0.0) AS DIFF_WITH_LAST_MONTH
FROM trades;