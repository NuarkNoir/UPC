DROP VIEW IF EXISTS dbo.ExcellentStudents;
GO;

CREATE VIEW dbo.ExcellentStudents AS
SELECT SSQ.[Фамилия], SSQ.[Имя], SSQ.[Отчество], SSQ.[Группа], SSQ.[Семестр]
FROM (SELECT S.[Фамилия], S.[Имя], S.[Отчество], S.[Группа], D.[Семестр], AVG(L.[Оценка]) AS AVG_MARK
      FROM [Изучение] AS L
               JOIN [Дисциплина] AS D on L.[Дисциплина] = D.ID
               JOIN [Студент] AS S on L.[Студент] = S.[НомерЗачетнойКнижки]
      GROUP BY S.[Фамилия], S.[Имя], S.[Отчество], S.[Группа], D.[Семестр]) AS SSQ
WHERE SSQ.AVG_MARK = 5
   OR SSQ.AVG_MARK = 1
GROUP BY SSQ.[Фамилия], SSQ.[Имя], SSQ.[Отчество], SSQ.[Группа], SSQ.[Семестр];
GO;

SELECT *
FROM dbo.ExcellentStudents;