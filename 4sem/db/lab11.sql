DROP FUNCTION IF EXISTS dbo.AverageMark;
DROP FUNCTION IF EXISTS dbo.CreditsList;
GO;

CREATE FUNCTION dbo.AverageMark(@disciplineId int) RETURNS float AS BEGIN;
    DECLARE @out float = (SELECT AVG(CAST(Оценка AS FLOAT)) FROM Изучение WHERE Дисциплина = @disciplineId);
    RETURN IIF(@out < 2, ROUND(@out, 0), @out);
END;
GO;

CREATE FUNCTION dbo.CreditsList(@groupId int, @semester int) RETURNS table AS RETURN (
    SELECT DISTINCT D.[Название], D.[Отчётность] FROM [Дисциплина] AS D
    JOIN [Группа] as G on G.ID = @groupId
    WHERE D.[Семестр] = @semester AND G.[КодСпециальности] = D.[КодСпециальности]
);
GO;

SELECT dbo.AverageMark(4), dbo.AverageMark(12), dbo.AverageMark(2);
SELECT * FROM dbo.CreditsList(2, 2);
SELECT * FROM dbo.CreditsList(4,1);

