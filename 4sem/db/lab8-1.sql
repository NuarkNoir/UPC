-- Провести оценку количества товара на складе по наименованиям: менее 10 – мало,
-- от 10 до 100 – достаточно, более 100 – избыточно.
SELECT G.[Имя],
       SUM([Склад].[Количество]) as AMOUNT,
       case
           when SUM([Склад].[Количество]) < 10 then N'Мало'
           when SUM([Склад].[Количество]) < 101 then N'Достаточно'
           else N'Избыточно'
           end                   as ESTIMATION
FROM [Склад]
         JOIN [Товар] as G on G.ID = [Склад].[КодТовара]
GROUP BY G.[Имя];

-- Вывести наименования товаров, количество которых на складе от 1 до 10 (35 и 45)
SELECT *
FROM (SELECT G.[Имя],
             SUM([Склад].[Количество]) as AMOUNT
      FROM [Склад]
               JOIN [Товар] as G on G.ID = [Склад].[КодТовара]
      GROUP BY G.[Имя]) as SQNG
WHERE AMOUNT BETWEEN 35 AND 45;

-- Определить тройку товаров, выручка за которые самая большая.
SELECT TOP 3 G.[Имя],
             SUM(D.[Количество] * [Склад].[Цена]) as AMOUNT
FROM [Склад]
         JOIN [Товар] as G on G.ID = [Склад].[КодТовара]
         JOIN [Сделка] as D on D.[КодСклада] = [Склад].ID
GROUP BY G.Имя
ORDER BY AMOUNT DESC;

-- Определить суммарную стоимость продаж каждого товара по месяцам.
SELECT G.[Имя],
       YEAR(D.[Дата])                       as YEAR,
       DATENAME(MONTH, D.[Дата])            as MONTH,
       SUM(D.[Количество] * [Склад].[Цена]) as AMOUNT
FROM [Склад]
         JOIN [Товар] as G on G.ID = [Склад].[КодТовара]
         JOIN [Сделка] as D on D.[КодСклада] = [Склад].ID
GROUP BY G.[Имя], YEAR(D.[Дата]), DATENAME(MONTH, D.[Дата])
ORDER BY AMOUNT DESC;

-- Показать месяца, в которых продажи Молока 3,2% (или любого другого товара,
-- хранящегося на складе с разными ID) были ниже 300 денег.
DECLARE @randomGoodsId INT = (SELECT TOP 1 ID
                              FROM [Товар]
                              ORDER BY NEWID());
DECLARE @thresholdPrice INT = 200000;
SELECT *
FROM (SELECT G.[Имя],
             YEAR(D.[Дата])                       as YEAR,
             DATENAME(MONTH, D.[Дата])            as MONTH,
             SUM(D.[Количество] * [Склад].[Цена]) as AMOUNT
      FROM [Склад]
               JOIN [Товар] as G on G.ID = [Склад].[КодТовара]
               JOIN [Сделка] as D on D.[КодСклада] = [Склад].ID
        WHERE [Склад].КодТовара = @randomGoodsId
      GROUP BY G.[Имя], YEAR(D.[Дата]), DATENAME(MONTH, D.[Дата])) as SQG
WHERE AMOUNT <= @thresholdPrice;