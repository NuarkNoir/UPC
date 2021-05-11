-- Сортировать поставщиков в алфавитном (обратном) порядке.
SELECT * FROM [Поставщик] ORDER BY [Имя] DESC;

-- Вывести поставщика(ов) с самым длинным названием.
SELECT TOP 2 * FROM [Поставщик] ORDER BY LEN([Имя]) DESC;

-- Вывести всех покупателей с фамилией, начинающейся на букву «В».
SELECT * FROM [Клиент] WHERE [Клиент].[Имя] LIKE N'И%';

-- Вывести всех покупателей с фамилией, начинающейся с букв в диапазоне от "В" до
-- "К", где вторая буква «о».
-- АБ[ВГДЕЁЖЗИК]ЛМНОПРСТУФХЦЧШЩЭЮЯ
SELECT * FROM [Клиент] WHERE [Клиент].[Имя] LIKE N'[ВГДЕЁЖЗИК]е%';

-- Определите количество сделок за текущий календарный месяц.
SELECT count(*) FROM [Сделка] WHERE MONTH(Дата) = MONTH(GETDATE());

-- Определите количество сделок, зафиксированных в заданные дни недели
-- (например, по вторникам и средам).
DECLARE @MON INT = 1;
DECLARE @TUE INT = 2;
DECLARE @WED INT = 3;
DECLARE @THU INT = 4;
DECLARE @FRI INT = 5;
DECLARE @SAT INT = 6;
DECLARE @SUN INT = 7;
DECLARE @daysList TABLE (ID INT);
INSERT @daysList(ID) VALUES (@MON),(@TUE);
SELECT count(*) FROM [Сделка] WHERE DATEPART(DW, [Дата]) in (SELECT ID FROM @daysList);