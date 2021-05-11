BEGIN TRANSACTION

------------------------------------------------------------------------------------------------------------------------

-- Очистим базу
DELETE FROM [Сделка] WHERE 1 > 0;
DELETE FROM [Клиент] WHERE 1 > 0;
DELETE FROM [Склад] WHERE 1 > 0;
DELETE FROM [Поставщик] WHERE 1 > 0;
DELETE FROM [Сотрудник] WHERE 1 > 0;
DELETE FROM [Товар] WHERE 1 > 0;

-- Обновим ключи
DBCC CHECKIDENT ([Сделка], RESEED, 1);
DBCC CHECKIDENT ([Клиент], RESEED, 1);
DBCC CHECKIDENT ([Склад], RESEED, 1);
DBCC CHECKIDENT ([Поставщик], RESEED, 1);
DBCC CHECKIDENT ([Сотрудник], RESEED, 1);
DBCC CHECKIDENT ([Товар], RESEED, 1);
go

------------------------------------------------------------------------------------------------------------------------

-- Генерируем клиентов
INSERT INTO [Клиент]([Имя], [Телефон], [Адрес], [Пол])
VALUES (N'Агафонова Милана Фёдоровна',        '3361876906', N'985019, Свердловская область, город Талдом, шоссе Бухарестская, 82', '0'),
       (N'Давыдова Александра Александровна', '9114695687', N'264202, Ярославская область, город Воскресенск, шоссе Космонавтов, 60', '0'),
       (N'Демина Мария Александровна',        '9461046614', N'266856, Самарская область, город Шаховская, проезд Домодедовская, 00', '0'),
       (N'Иванов Иван Александрович',         '9968051776', N'581486, Тюменская область, город Наро-Фоминск, пр. Будапештсткая, 49', '1'),
       (N'Никифоров Руслан Александрович',    '8331275435', N'624218, Новгородская область, город Озёры, въезд Домодедовская, 45', '1'),
       (N'Руднев Олег Владимирович',          '9004552583', N'157285, Оренбургская область, город Мытищи, пл. 1905 года, 52', '1'),
       (N'Самсонов Георгий Кириллович',       '9817892552', N'157598, Амурская область, город Талдом, наб. Домодедовская, 71', '1'),
       (N'Семенова Екатерина Марковна',       '9479462287', N'303011, Астраханская область, город Воскресенск, наб. Гоголя, 43', '0'),
       (N'Тимофеев Михаил Михайлович',        '9514816307', N'303937, Белгородская область, город Воскресенск, наб. Ленина, 46', '1'),
       (N'Фролова Елена Игоревна',            '9807420852', N'364746, Иркутская область, город Кашира, пер. Чехова, 27', '0');

------------------------------------------------------------------------------------------------------------------------

-- Генерируем поставщиков
INSERT INTO [Поставщик]([Имя])
VALUES (N'Андреева София Константиновна'),
       (N'Булгаков Егор Тихонович'),
       (N'Жукова Виктория Матвеевна'),
       (N'Иванова София Владиславовна'),
       (N'Левина Яна Александровна'),
       (N'Максимов Макар Богданович'),
       (N'Назаров Савелий Степанович'),
       (N'Полякова Мария Михайловна'),
       (N'Соколов Илья Дмитриевич'),
       (N'Фомин Михаил Сергеевич');

------------------------------------------------------------------------------------------------------------------------

-- Генерируем сотрудников
-- Создадим менеджера
INSERT INTO [Сотрудник]([Имя]) VALUES (N'Баженова Д.');
DECLARE @manager INT;
set @manager = (SELECT TOP 1 [ID] FROM [Сотрудник] WHERE [КодНачальника] IS NULL);

-- Начальников отделов
INSERT INTO [Сотрудник]([КодНачальника], [Имя])
VALUES (@manager, N'Демина Д.'),
       (@manager, N'Иванов З.');
DECLARE @depHead1 INT;
DECLARE @depHead2 INT;
set @depHead1 = (SELECT TOP 1 [ID] FROM [Сотрудник] WHERE [КодНачальника] IS NOT NULL);
set @depHead2 = @depHead1 + 1

-- И их подчинённых
INSERT INTO [Сотрудник]([КодНачальника], [Имя])
VALUES (@depHead1, N'Иванова А.'),
       (@depHead1, N'Иванова П.'),
       (@depHead1, N'Марков Д.'),
       (@depHead2, N'Наумов И.'),
       (@depHead2, N'Попов И.'),
       (@depHead2, N'Смирнов И.');

------------------------------------------------------------------------------------------------------------------------

-- Генерируем товары
INSERT INTO [Товар]([Имя], [Количество], [Категория], [Описание])
VALUES (N'Золотая мотыга',              1, N'Инструмент', N'Лучшая на рынке мотыга, самая быстрая и прочная'),
       (N'Перфоратор "Сосед"',          1, N'Иснтрумент', N'Перфорирует всё и вся'),
       (N'Смектит диоктаэдрический',   10, N'Лекарство',  N'Порошок для приготовления суспензии для приёма внутрь'),
       (N'Ретто',                       1, N'Лекарство',  N'Таблетки против изжоги'),
       (N'Панкреатин',                  1, N'Лекарство',  N'Комплекс ферментов поджелудочной железы'),
       (N'Хлорпромазин',                1, N'Лекарство',  N'Лекарственное средство, обладающее транквилизирующим, ' +
                                                          N'противосудорожным, снотворным, миорелаксантным и ' +
                                                          N'седативным действием'),
       (N'Сосиски "Столичные"',        20, N'Продукт',    N'Мясные сосиски'),
       (N'Сарсапарилла',                1, N'Продукт',    N'Корневое пиво, сливочный карамельно-мятный вкус'),
       (N'Масло Сливочное',             1, N'Продукт',    N'Сливочное масло от местного изготовителя'),
       (N'Подсолнечное масло',          1, N'Продукт',    N'Растительное масло, получаемое из семян масличных сортов ' +
                                                          N'подсолнечника масличного');

------------------------------------------------------------------------------------------------------------------------

-- Закинем товары на склады
DECLARE @ignoreGoodStart INT;
DECLARE @ignoreProviderStart INT;

SET @ignoreGoodStart = (SELECT TOP 1 ID
                        FROM [Товар]
                        ORDER BY NEWID()) - 2;
SET @ignoreProviderStart = (SELECT TOP 1 ID
                            FROM [Поставщик]
                            ORDER BY NEWID()) - 2;

INSERT INTO [Склад]([КодПоставщика], [КодТовара], [Количество], [Цена], [Дата])
SELECT *,
       ABS(CHECKSUM(NEWID())) % 10 + 1                          as AMOUNT,
       ROUND(ABS(CHECKSUM(NEWID())) % 5000 + 1000, -2)          as PRICE,
       DATEADD(DAY, ABS(CHECKSUM(NEWID()) % 364), '2019-01-01') as DATE
FROM (SELECT [Поставщик].ID as PID, [Товар].ID as GID
      FROM [Поставщик]
               JOIN [Товар] ON ([Товар].ID NOT BETWEEN @ignoreGoodStart AND @ignoreGoodStart + 3) AND
                               ([Поставщик].ID NOT BETWEEN @ignoreProviderStart AND @ignoreProviderStart + 3)) as SQGP
ORDER BY DATE

DECLARE @lastDay DATE;

SET @lastDay = (SELECT TOP 1 [Дата]
                FROM [Склад]
                ORDER BY [Дата] DESC);

-- Закинем ещё товаров, сдвинутых по дате, отличных по цене
INSERT INTO [Склад]([КодПоставщика], [КодТовара], [Количество], [Цена], [Дата])
SELECT TOP 5 [КодПоставщика],
             [КодТовара],
             [Количество],
             ROUND([Цена] + (CHECKSUM(NEWID()) % 4000), -2),
             DATEADD(DAY, ABS(CHECKSUM(NEWID()) % 30), @lastDay) as DATE
FROM Склад
ORDER BY NEWID();

SET @lastDay = (SELECT TOP 1 [Дата]
                FROM [Склад]
                ORDER BY [Дата] DESC);

-- Закинем ещё товаров, которые отсутствуют
INSERT INTO [Склад]([КодПоставщика], [КодТовара], [Количество], [Цена], [Дата])
SELECT TOP 5 [КодПоставщика],
             [КодТовара],
             0,
             [Цена],
             DATEADD(DAY, ABS(CHECKSUM(NEWID()) % 30), @lastDay) as DATE
FROM Склад
ORDER BY NEWID();

------------------------------------------------------------------------------------------------------------------------

-- Проводим сделки
DECLARE @ignoreStoreStart INT;
DECLARE @lastManagerId INT;

SET @ignoreStoreStart = (SELECT TOP 1 ID
                         FROM [Склад]
                         ORDER BY NEWID()) - 2;
set @lastManagerId = (SELECT TOP 1 [КодНачальника]
                      FROM [Сотрудник]
                      ORDER BY [КодНачальника] DESC);

INSERT INTO [Сделка]([Дата], [КодСклада], [КодКлиента], [КодСотрудника], [Количество], [Скидка])
SELECT DATEADD(DAY, ABS(CHECKSUM(NEWID()) % 20), SDATE) as DATE,
       SID,
       CID,
       (SELECT TOP 1 [Сотрудник].ID
        FROM [Сотрудник]
        WHERE [Сотрудник].ID = @lastManagerId + 1 + (ABS(CHECKSUM(NEWID())) % 6)
        ORDER BY NEWID())                                       as WID,
       ABS(CHECKSUM(NEWID())) % 10                              as AMOUNT,
       ROUND(ABS(CHECKSUM(NEWID())) % 5000 + 1000, -2)          as DISCOUNT
FROM (SELECT [Клиент].ID as CID, [Склад].ID as SID, [Склад].[Дата] as SDATE
      FROM [Клиент]
               JOIN [Склад] ON ([Склад].ID NOT BETWEEN @ignoreStoreStart AND @ignoreStoreStart + 10)) as SQGP
ORDER BY DATE

------------------------------------------------------------------------------------------------------------------------

COMMIT TRANSACTION

-- Сколько товаров
DECLARE @goodsCount INT;
SET @goodsCount = (SELECT count(ID)
                   FROM [Товар]);
SELECT @goodsCount as GOODS_COUNT;

-- Сколько товаров нет на складе
DECLARE @goodsInStorage INT;
SET @goodsInStorage = (SELECT count(*)
                       FROM (SELECT DISTINCT [Склад].[КодТовара]
                             FROM [Склад]
                                      JOIN [Товар] ON [Товар].ID = [Склад].[КодТовара]) as GIDONS);
SELECT @goodsCount - @goodsInStorage as GOODS_NOT_ON_STORAGE;

-- Сколько есть поставщиков
DECLARE @providersCount INT;
SET @providersCount = (SELECT count(ID)
                       FROM [Поставщик]);
SELECT @providersCount as PROVIDERS_COUNT;

-- Сколько поставщиков не поставляют товары
DECLARE @providersProvideCount INT;
SET @providersProvideCount = (
    SELECT count(*)
    FROM (
             SELECT DISTINCT [Склад].[КодПоставщика]
             from [Склад]
                      JOIN [Поставщик] ON [Поставщик].ID = [Склад].[КодПоставщика]
         ) as PIDPG
)
SELECT @providersCount - @providersProvideCount as PROVIDERS_DONT_PROVIDE_COUNT;

-- Менеджер и кол-во менеджеров
DECLARE @managerId INT;
SET @managerId = (SELECT ID FROM [Сотрудник] WHERE [КодНачальника] IS NULL);
SELECT N'Начальник', * FROM [Сотрудник] WHERE ID = @managerId;

-- Главы отделов и кол-во подчинённых
DECLARE @depHead1_ INT;
DECLARE @depHead2_ INT;

SET @depHead1_ = (SELECT TOP 1 ID FROM [Сотрудник] WHERE [КодНачальника] = @managerId);
SET @depHead2_ = @depHead1_ + 1;

SELECT N'Глава отдела', * FROM [Сотрудник] WHERE [КодНачальника] = @managerId;

-- Сотрудники отделов
SELECT N'Глава отдела', * FROM [Сотрудник] WHERE [КодНачальника] BETWEEN @depHead1_ AND @depHead2_;

-- Кол-во записей на складе
SELECT count(ID) FROM [Склад];

-- Один товар поставлен разными поставщиками по разной цене.
DECLARE @randGood INT;
SET @randGood = (SELECT TOP 1 [Склад].[КодТовара] FROM [Склад] ORDER BY NEWID());
SELECT DISTINCT * FROM [Склад] WHERE [КодТовара] = @randGood;

-- Один товар одного поставщика в разные даты поставлялся по разным ценам.
DECLARE @randProvider INT;
SET @randProvider = (SELECT TOP 1 [Склад].[КодПоставщика] FROM [Склад] ORDER BY NEWID());
SET @randGood = (SELECT TOP 1 [Склад].[КодТовара] FROM [Склад] WHERE [КодПоставщика] = @randProvider ORDER BY NEWID());
SELECT * FROM [Склад] WHERE [КодПоставщика] = @randProvider AND [КодТовара] = @randGood;

-- Некоторые товары закончились на складе.
SELECT * FROM [Склад] WHERE [Количество] = 0;

-- Кол-во клиентов, а так же мужчин и женщин среди них
DECLARE @clients INT;
DECLARE @maleClients INT;
DECLARE @femaleClients INT;

SET @clients = (SELECT count(ID)
                FROM [Клиент]);
SET @maleClients = (SELECT count(ID)
                    FROM [Клиент]
                    WHERE [Пол] = 1);
SET @femaleClients = @clients - @maleClients;
SELECT @clients as CLIENTS, @maleClients as MALES, @femaleClients AS FEMALES;

-- Все клиенты совершили покупку единожды
DECLARE @doneDeal INT;
SET @doneDeal = (SELECT count(*)
                 FROM (SELECT DISTINCT [Сделка].[КодКлиента]
                       FROM [Сделка]) as CIDDD);
SELECT @clients as CLIENT, @doneDeal as DONE_DEAL_AT_LEAST_ONCE;

-- Не все товары, имеющиеся на складе, продавались
DECLARE @storagesAmount INT;
SET @storagesAmount = (SELECT count(ID) FROM [Склад]);
SELECT @storagesAmount as STORAGES_AMOUNT, count(*) as UNIQUE_STORAGES_IN_DEALS FROM (SELECT [КодСклада] FROM [Сделка] INTERSECT SELECT ID FROM [Склад]) as SIDWD;
