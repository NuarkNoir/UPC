BEGIN TRANSACTION

DECLARE @firstSpecialityID INT = (SELECT TOP 1 ID
                                  FROM [Специальность]
                                  ORDER BY ID);

-- Создайте группу студентов, обучающихся по специальности, на которую студентов
-- не набирали.
INSERT INTO [Группа]([Название], [КодСпециальности], [ЗачётнаяКнижкаСтаросты], [ТабельныйНомерКуратора])
VALUES (N'КИ20-09Б', @firstSpecialityID + 1, NULL, 1);

-- Одну из групп, которых две по одной специальности (см. требования Лаб. раб. №9),
-- перевести в созданную группу (на другую специальность).
-- КИ20-07Б -> КИ20-09Б
DECLARE @firstGroupID INT = (SELECT TOP 1 ID
                             FROM [Группа]
                             ORDER BY ID);
DECLARE @newGroupID INT = (SELECT ID
                           FROM [Группа]
                           WHERE [Название] = N'КИ20-09Б');
UPDATE [Студент]
SET Группа = @newGroupID
FROM [Студент]
WHERE Группа = @firstGroupID;

-- Назначьте старосту и куратора тех же людей, которые были в теперь уже пустой
-- группе.
UPDATE [Группа]
SET ЗачётнаяКнижкаСтаросты = (SELECT [ЗачётнаяКнижкаСтаросты] FROM [Группа] WHERE ID = @firstGroupID),
    ТабельныйНомерКуратора = (SELECT [ТабельныйНомерКуратора] FROM [Группа] WHERE ID = @firstGroupID)
FROM [Группа]
WHERE ID = @newGroupID;

-- Удалите пустую группу из таблицы.
DELETE
FROM Группа
WHERE ID = @firstGroupID;

COMMIT TRANSACTION