DROP TRIGGER IF EXISTS dbo.NoDeleteUsedDiscipline;
DROP TRIGGER IF EXISTS dbo.NoSetWrongCaptain;
DROP TRIGGER IF EXISTS dbo.NoInsertWrongExam;
GO;

CREATE TRIGGER dbo.NoDeleteUsedDiscipline ON [Дисциплина] INSTEAD OF DELETE AS BEGIN
    SET NOCOUNT ON;

    DECLARE @d_discID TABLE (DISC INT);
    INSERT INTO @d_discID(DISC) SELECT ID FROM DELETED;

    IF EXISTS(SELECT * FROM [Изучение] AS L WHERE EXISTS(SELECT * FROM @d_discID WHERE DISC = L.[Дисциплина])) BEGIN
            RAISERROR ('Deletion is not allowed: discipline is in use', 16, 1);
            RETURN;
    END;

    DELETE FROM [Дисциплина] WHERE EXISTS(SELECT * FROM @d_discID WHERE DISC = ID);
END;
GO;

CREATE TRIGGER dbo.NoSetWrongCaptain ON [Группа] AFTER UPDATE AS BEGIN
    SET NOCOUNT ON;

    DECLARE @c_groupID TABLE (GRP INT, NCPT INT);
    INSERT INTO @c_groupID(GRP, NCPT) SELECT ID, INSERTED.[ЗачётнаяКнижкаСтаросты] FROM INSERTED;

    IF UPDATE([ЗачётнаяКнижкаСтаросты]) AND EXISTS(SELECT * FROM [Студент] AS S WHERE EXISTS(SELECT * FROM @c_groupID WHERE GRP = S.[Группа] AND S.[НомерЗачетнойКнижки] = NCPT))
        RETURN;

    RAISERROR ('New captain not from this group', 16, 1);
END;
GO;

CREATE TRIGGER dbo.NoInsertWrongExam ON [Изучение] AFTER INSERT AS BEGIN
    SET NOCOUNT ON;

    DECLARE @i_learnID TABLE (SID INT, DID INT);
    INSERT INTO @i_learnID(SID, DID) SELECT INSERTED.Студент, INSERTED.Дисциплина FROM INSERTED;

    IF EXISTS(SELECT * FROM [Студент] AS S
        JOIN [Группа] AS G on S.[Группа] = G.ID
        RIGHT JOIN [Дисциплина] AS D on D.[КодСпециальности] = G.[КодСпециальности]
        WHERE EXISTS(SELECT * FROM @i_learnID WHERE SID = S.[НомерЗачетнойКнижки] AND D.ID = DID))
        RETURN;

    RAISERROR ('Student is not learning that discipline', 16, 1);
END;
GO;

BEGIN TRANSACTION

DELETE FROM [Дисциплина] WHERE ID = 33;
UPDATE [Группа] SET [Группа].[ЗачётнаяКнижкаСтаросты] = 25 WHERE ID = 4;
INSERT INTO [Изучение]([Студент], [Дисциплина], [Дата], [Оценка]) VALUES (13, 9, '2020-09-05', 1);

ROLLBACK TRANSACTION