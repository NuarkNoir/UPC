-- Вывести наименования товаров, количество которых на складе максимально (на
-- складе должно быть как минимум два товара, количество которых одинаково и
-- равно максимальному).
SELECT DISTINCT (SELECT TOP 1 [Товар].[Имя] FROM [Товар] WHERE [Товар].ID = [Склад].КодТовара) as NAME
FROM [Склад]
WHERE [Склад].[Количество] = (SELECT MAX([Склад].[Количество]) FROM [Склад]);

-- Вывести в порядке, обратном алфавитному, наименования товаров, количество
-- которых на складе находится в заданном диапазоне.
DECLARE @goodsAmountFrom INT = 3;
DECLARE @goodsAmountTo INT = 7;
SELECT DISTINCT (SELECT TOP 1 [Товар].[Имя] FROM [Товар] WHERE [Товар].ID = [Склад].КодТовара) as NAME
FROM [Склад]
WHERE [Склад].[Количество] BETWEEN @goodsAmountFrom AND @goodsAmountTo
ORDER BY NAME DESC;

-- Вывести поставщиков, которые хотя бы раз осуществили поставку, в алфавитном
-- порядке.
SELECT DISTINCT (SELECT TOP 1 [Поставщик].Имя
                 FROM [Поставщик]
                 WHERE NOT EXISTS(SELECT * FROM [Склад] WHERE [Склад].КодПоставщика = [Поставщик].ID)) as NAME
FROM [Склад]
ORDER BY NAME;

-- 30 дней с даты последней покупки действует дополнительная скидка на все товары.
-- Вывести список покупателей, имеющих возможность воспользоваться указанной
-- скидкой.
-- YYYY-MM-DD
DECLARE @desiredDate DATE = '2020-04-20';
SELECT DISTINCT (SELECT [Клиент].[Имя] FROM [Клиент] WHERE [Клиент].ID = [Сделка].[КодКлиента]) as NAME
FROM [Сделка]
WHERE DATEDIFF(DAY, [Сделка].[Дата], @desiredDate) <= 30;

-- Вывести список товаров, названия которых начинающиеся с букв «д» и «л»,
-- стоимость которых не более 20% от максимальной.
SELECT (SELECT [Товар].[Имя] FROM [Товар] WHERE [Товар].ID = [Склад].[КодТовара]) as NAME
FROM [Склад]
WHERE ([Склад].Цена / (SELECT MAX([Склад].[Цена]) FROM [Склад])) <= .8
  AND EXISTS(SELECT * FROM [Товар] WHERE [Товар].ID = [Склад].[КодТовара] AND [Товар].[Имя] LIKE N'[мс]%');

-- Вывести поставщиков, которые не поставляют товары, названия которых
-- начинающиеся с букв «д» и «л»
SELECT DISTINCT [Поставщик].[Имя]
FROM [Поставщик]
WHERE NOT EXISTS(SELECT *
                 FROM [Склад]
                 WHERE [Склад].[КодПоставщика] = [Поставщик].ID
                   AND EXISTS(SELECT *
                              FROM [Товар]
                              WHERE [Склад].[КодТовара] = [Товар].ID
                                AND [Товар].[Имя] LIKE N'[мс]%'));

-- Показать список клиентов с указанием их пола («мужчина» или «женщина»).
SELECT [Имя], (IIF([Пол] = 0, N'Женщина', N'Мужчина'))
FROM [Клиент];