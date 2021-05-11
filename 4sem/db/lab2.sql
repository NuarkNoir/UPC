drop table if exists [Сделка];
drop table if exists [Склад];
drop table if exists [Сотрудник];
drop table if exists [Поставщик];
drop table if exists [Клиент];
drop table if exists [Товар];
go

CREATE TABLE [Сотрудник]
(
    ID            int IDENTITY (1,1),
    Имя           nvarchar(300) NOT NULL,
    КодНачальника int           NOT NULL,
    CONSTRAINT [PK_СОТРУДНИК] PRIMARY KEY CLUSTERED
        (
         [ID] ASC
            ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Поставщик]
(
    ID  int IDENTITY (1,1),
    Имя nvarchar(300) NOT NULL,
    CONSTRAINT [PK_ПОСТАВЩИК] PRIMARY KEY CLUSTERED
        (
         [ID] ASC
            ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Клиент]
(
    ID      int IDENTITY (1,1),
    Имя     nvarchar(300) NOT NULL,
    Телефон nvarchar(10)  NOT NULL,
    Адрес   nvarchar(300) NOT NULL,
    Пол     bit           NOT NULL,
    CONSTRAINT [PK_КЛИЕНТ] PRIMARY KEY CLUSTERED
        (
         [ID] ASC
            ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Товар]
(
    ID         int IDENTITY (1,1),
    Имя        nvarchar(300) NOT NULL,
    Количество int           NOT NULL,
    Описание   nvarchar(300) NOT NULL,
    Категория  nvarchar(300) NOT NULL,
    CONSTRAINT [PK_ТОВАР] PRIMARY KEY CLUSTERED
        (
         [ID] ASC
            ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Склад]
(
    ID            int IDENTITY (1,1),
    КодПоставщика int   NOT NULL,
    КодТовара     int   NOT NULL,
    Количество    int   NOT NULL,
    Цена          money NOT NULL,
    Дата          date  NOT NULL,
    CONSTRAINT [PK_СКЛАД] PRIMARY KEY CLUSTERED
        (
         [ID] ASC
            ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
CREATE TABLE [Сделка]
(
    ID            int IDENTITY (1,1),
    Дата          date  NOT NULL,
    КодСклада     int   NOT NULL,
    КодКлиента    int   NOT NULL,
    КодСотрудника int   NOT NULL,
    Количество    int   NOT NULL,
    Скидка        money NOT NULL,
    CONSTRAINT [PK_СДЕЛКА] PRIMARY KEY CLUSTERED
        (
         [ID] ASC
            ) WITH (IGNORE_DUP_KEY = OFF)

)
GO
ALTER TABLE [Сотрудник]
    WITH CHECK ADD CONSTRAINT [Сотрудник_fk0] FOREIGN KEY ([КодНачальника]) REFERENCES [Сотрудник] ([ID])
        ON UPDATE NO ACTION
GO
ALTER TABLE [Сотрудник]
    CHECK CONSTRAINT [Сотрудник_fk0]
GO



ALTER TABLE [Склад]
    WITH CHECK ADD CONSTRAINT [Склад_fk0] FOREIGN KEY ([КодПоставщика]) REFERENCES [Поставщик] ([ID])
        ON UPDATE CASCADE
GO
ALTER TABLE [Склад]
    CHECK CONSTRAINT [Склад_fk0]
GO
ALTER TABLE [Склад]
    WITH CHECK ADD CONSTRAINT [Склад_fk1] FOREIGN KEY ([КодТовара]) REFERENCES [Товар] ([ID])
        ON UPDATE CASCADE
GO
ALTER TABLE [Склад]
    CHECK CONSTRAINT [Склад_fk1]
GO

ALTER TABLE [Сделка]
    WITH CHECK ADD CONSTRAINT [Сделка_fk0] FOREIGN KEY ([КодСклада]) REFERENCES [Склад] ([ID])
        ON UPDATE CASCADE
GO
ALTER TABLE [Сделка]
    CHECK CONSTRAINT [Сделка_fk0]
GO
ALTER TABLE [Сделка]
    WITH CHECK ADD CONSTRAINT [Сделка_fk1] FOREIGN KEY ([КодКлиента]) REFERENCES [Клиент] ([ID])
        ON UPDATE CASCADE
GO
ALTER TABLE [Сделка]
    CHECK CONSTRAINT [Сделка_fk1]
GO
ALTER TABLE [Сделка]
    WITH CHECK ADD CONSTRAINT [Сделка_fk2] FOREIGN KEY ([КодСотрудника]) REFERENCES [Сотрудник] ([ID])
        ON UPDATE CASCADE
GO
ALTER TABLE [Сделка]
    CHECK CONSTRAINT [Сделка_fk2]
GO
