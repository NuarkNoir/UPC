use bus_routes;

-- Создадим таблицы

CREATE TABLE bus_routes.dbo.busses (
	ID int IDENTITY(0,1) NOT NULL,
	title nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	sits int NOT NULL,
	CONSTRAINT busses_PK PRIMARY KEY (ID)
);

CREATE TABLE bus_routes.dbo.cities (
	ID int IDENTITY(0,1) NOT NULL,
	title nvarchar(100) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	CONSTRAINT cities_PK PRIMARY KEY (ID)
);

CREATE TABLE bus_routes.dbo.passengers (
	ID int IDENTITY(0,1) NOT NULL,
	second_name nvarchar(40) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	first_name nvarchar(40) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	patronymic nvarchar(40) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	CONSTRAINT passengers_PK PRIMARY KEY (ID)
);

CREATE TABLE bus_routes.dbo.cashbox (
	ID int IDENTITY(0,1) NOT NULL,
	city_id int NOT NULL,
	CONSTRAINT cash_box_PK PRIMARY KEY (ID),
	CONSTRAINT cash_box_FK FOREIGN KEY (city_id) REFERENCES bus_routes.dbo.cities(ID)
);

CREATE TABLE bus_routes.dbo.driver (
	ID int IDENTITY(0,1) NOT NULL,
	second_name nvarchar(40) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	first_name nvarchar(40) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	patronymic nvarchar(40) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	home_city int NOT NULL,
	CONSTRAINT driver_PK PRIMARY KEY (ID),
	CONSTRAINT driver_FK_1 FOREIGN KEY (home_city) REFERENCES bus_routes.dbo.cities(ID)
);

CREATE TABLE bus_routes.dbo.passages (
	ID int IDENTITY(0,1) NOT NULL,
	city_from int NOT NULL,
	city_to int NOT NULL,
	price int NOT NULL,
	passage_time time(7) NOT NULL,
	CONSTRAINT passages_PK PRIMARY KEY (ID),
	CONSTRAINT passages_FK FOREIGN KEY (city_from) REFERENCES bus_routes.dbo.cities(ID),
	CONSTRAINT passages_FK_1 FOREIGN KEY (city_to) REFERENCES bus_routes.dbo.cities(ID)
);

CREATE TABLE bus_routes.dbo.runs (
	ID int IDENTITY(0,1) NOT NULL,
	bus_id int NOT NULL,
	driver_id int NOT NULL,
	passage_id int NOT NULL,
	passage_date datetime NOT NULL,
	CONSTRAINT runs_PK PRIMARY KEY (ID),
	CONSTRAINT runs_FK FOREIGN KEY (bus_id) REFERENCES bus_routes.dbo.busses(ID) ON UPDATE CASCADE,
	CONSTRAINT runs_FK_1 FOREIGN KEY (driver_id) REFERENCES bus_routes.dbo.driver(ID),
	CONSTRAINT runs_FK_2 FOREIGN KEY (passage_id) REFERENCES bus_routes.dbo.passages(ID)
);

CREATE TABLE bus_routes.dbo.tickets (
	ID int IDENTITY(0,1) NOT NULL,
	run_id int NOT NULL,
	passenger_id int NOT NULL,
	cashbox_id int NOT NULL,
	sold_dt datetime DEFAULT getdate() NOT NULL,
	CONSTRAINT tickets_PK PRIMARY KEY (ID),
	CONSTRAINT tickets_FK FOREIGN KEY (run_id) REFERENCES bus_routes.dbo.runs(ID),
	CONSTRAINT tickets_FK_1 FOREIGN KEY (passenger_id) REFERENCES bus_routes.dbo.passengers(ID),
	CONSTRAINT tickets_FK_2 FOREIGN KEY (cashbox_id) REFERENCES bus_routes.dbo.cashbox(ID)
);

-- Создадим нужные функции

CREATE OR ALTER PROCEDURE dbo.SetRunDriver(@driverID INT, @runID INT) AS BEGIN
	DECLARE @driverCity INT = (SELECT TOP 1 home_city FROM driver WHERE ID = @driverID); 
	DECLARE @runCity INT = (SELECT TOP 1 home_city FROM driver WHERE ID = @driverID); 
	IF @driverCity = @runCity BEGIN
		UPDATE runs 
		SET runs.driver_id = @driverID
		WHERE runs.ID = @runID;
	END
	ELSE 
		RAISERROR ('Driver cannot drive from this city', 16, 1);
END

CREATE OR ALTER PROCEDURE dbo.BuyTicket(@runID INT, @passengerID INT, @cashboxID INT) AS BEGIN 
	DECLARE @sitsTaken INT = (SELECT COUNT(*) FROM tickets WHERE tickets.run_id = @runID);
	DECLARE @busSits INT = (SELECT B.sits 
							FROM runs 
								INNER JOIN busses AS B ON B.ID = runs.bus_id
							WHERE runs.ID = @runID);
	
	IF @sitsTaken < @busSits BEGIN
		INSERT INTO tickets(run_id,passenger_id,cashbox_id) VALUES (@runID, @passengerID, @cashboxID);
	END
	ELSE
		RAISERROR ('No free sits!', 16, 1);
END

CREATE OR ALTER PROCEDURE dbo.ReturnTicket(@runID INT, @passengerID INT, @ticketID INT) AS BEGIN 
	DELETE FROM tickets
	WHERE run_id = @runID AND passenger_id = @passengerID AND ID = @ticketID;

	IF (SELECT @@ROWCOUNT) = 0 BEGIN
		RAISERROR ('Ticket not found!', 16, 1);
	END
END

CREATE OR ALTER PROCEDURE dbo.SetRunBus(@runID INT, @busId INT) AS BEGIN 
	DECLARE @sitsTaken INT = (SELECT COUNT(*) FROM tickets WHERE tickets.run_id = @runID);
	DECLARE @newBusSits INT = (SELECT sits FROM busses WHERE busses.ID = @busId);

	IF @newBusSits < @sitsTaken BEGIN
		RAISERROR ('This bus couldn`t care all the passengers', 16, 1);
	END
	ELSE BEGIN
		UPDATE runs 
		SET runs.bus_id = @busId
		WHERE runs.ID = @runID;
	END
END

BEGIN TRANSACTION
-- 1. Получить данные (время, цену на билет) о рейсах в город Томск из города Новосибирск.

DECLARE @tomskID INT = (SELECT TOP 1 ID FROM cities WHERE title = 'Tomsk');
DECLARE @novosibirskID INT = (SELECT TOP 1 ID FROM cities WHERE title = 'Novosibirsk');

SELECT R.passage_date, 
	   PSGS.price
FROM runs as R 
	JOIN passages as PSGS ON PSGS.ID = R.passage_id 
	WHERE PSGS.city_from  = @novosibirskID and PSGS.city_to = @tomskID;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 2. Получить суммарный доход какой-либо кассы.

DECLARE @randomCashboxID INT = (SELECT TOP 1 ID FROM cashbox ORDER BY NEWID());

SELECT @randomCashboxID AS cashbox_id,
	   COALESCE(sum(P.price), 0) AS profit
FROM tickets AS T
	INNER JOIN runs AS R ON R.ID = T.run_id 
	INNER JOIN passages AS P ON P.ID = R.passage_id 
	WHERE T.cashbox_id = @randomCashboxID;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 3. Получить суммарные доходы касс в городе Томске.

SELECT T.cashbox_id AS cashbox_id,
	   COALESCE(sum(P.price), 0) AS profit
FROM tickets AS T
	INNER JOIN cashbox AS C ON C.ID = T.cashbox_id 
	INNER JOIN runs AS R ON R.ID = T.run_id 
	INNER JOIN passages AS P ON P.ID = R.passage_id 
	WHERE C.city_id = 0 -- Tomsk ID
	GROUP BY T.cashbox_id;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 4. Получить число рейсов, совершѐнных данным водителем за год.

SELECT COUNT(D.ID)
FROM runs AS R
	INNER JOIN driver AS D ON D.ID = R.driver_id
	WHERE DATEPART(YEAR, R.passage_date) = '2021' AND D.ID = 1;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 5. Назначить водителя на рейс.

-- not working
EXECUTE dbo.SetRunDriver 5, 4; -- driverID, runID

-- working
EXECUTE dbo.SetRunDriver 4, 24;

ROLLBACK TRANSACTION


BEGIN TRANSACTION
-- 6. Оформить билет для клиента в город Новосибирск из Томска, с учѐтом занятых мест в автобусе.

EXECUTE dbo.BuyTicket 4,0,0

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 7. Получить число рейсов, совершѐнных автобусами «Икарус» и «ПАЗ».

SELECT COUNT(*) AS IKARUS_ROUTES FROM tickets AS T
	INNER JOIN runs AS R ON R.ID = T.run_id
	INNER JOIN busses AS B ON B.ID = R.bus_id
	WHERE B.title = 'Ikarus'

SELECT COUNT(*) AS PAZ_ROUTES FROM tickets AS T
	INNER JOIN runs AS R ON R.ID = T.run_id
	INNER JOIN busses AS B ON B.ID = R.bus_id
	WHERE B.title = 'PAZ'

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 8. Проверить все свободные места на рейс.

	DECLARE @runID INT = 4;
	SELECT 	((SELECT B.sits FROM runs INNER JOIN busses AS B ON B.ID = runs.bus_id WHERE runs.ID = @runID) -
			 (SELECT COUNT(*) FROM tickets WHERE tickets.run_id = @runID)) AS FREE_SITS

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 9. Показать число билетов, проданных кассами.

SELECT T.cashbox_id AS cashbox_id,
	   COUNT(T.ID) AS TICKETS_SOLD
FROM tickets AS T
	INNER JOIN cashbox AS C ON C.ID = T.cashbox_id 
	INNER JOIN runs AS R ON R.ID = T.run_id 
	INNER JOIN passages AS P ON P.ID = R.passage_id
	GROUP BY T.cashbox_id;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 10. Показать среднюю цену билетов.

SELECT AVG(CAST(P.price AS FLOAT))
FROM runs AS R
	INNER JOIN passages AS P ON P.ID = R.passage_id;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 11. Показать рейсы, цена на которые выше средней цены на билеты.

DECLARE @avgTicketPrice FLOAT = (SELECT AVG(CAST(P.price AS FLOAT)) FROM runs AS R INNER JOIN passages AS P ON P.ID = R.passage_id);
SELECT *
FROM passages AS P 
WHERE P.price > @avgTicketPrice;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 12. Отменить клиенту билет, после того как он его вернул.

-- working
EXECUTE dbo.ReturnTicket 4,0,53; -- run, passenger, ticket

-- not working
EXECUTE dbo.ReturnTicket 4,0,88;

ROLLBACK TRANSACTION


BEGIN TRANSACTION
-- 13. Показать информацию о рейсах из города Томск (включая цену на билет, время рейса).

SELECT  B.title,
		D.second_name, D.first_name, D.patronymic,
		C.title, R.passage_date 
FROM runs AS R 
	INNER JOIN passages AS P ON P.ID = R.passage_id 
	INNER JOIN busses AS B ON B.ID = R.bus_id 
	INNER JOIN driver AS D ON D.ID = R.driver_id
	INNER JOIN cities AS C ON C.ID = P.city_to 
WHERE P.city_from = 0 -- Tomsk ID

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 14. Посчитать количество билетов, проданных по рейсам Томск – Новосибирск за 2020-2021.

SELECT COUNT(T.ID)
FROM tickets AS T 
	INNER JOIN runs AS R ON R.ID = T.run_id
	INNER JOIN passages AS P ON P.ID = R.passage_id 
WHERE DATEPART(YEAR, R.passage_date) BETWEEN '2019' AND '2020' AND P.city_from = 0 AND P.city_to = 1 -- Tomsk ID

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 15. Назначить автобус на рейс.

-- working
EXECUTE dbo.SetRunBus 11,1;

-- not working
EXECUTE dbo.SetRunBus 4,1


COMMIT TRANSACTION


BEGIN TRANSACTION
-- 16. Получить список рейсов, на которые может быть назначен данный водитель и данный автобус с числом мест, равным 30.

DECLARE @driverID INT = 1;
DECLARE @busID INT = 0;

DECLARE @driverCity INT = (SELECT home_city FROM driver WHERE driver.ID = @driverID);
DECLARE @busSits INT = (SELECT sits FROM busses WHERE busses.ID = @busId);

SELECT R.ID, P.city_from, COUNT(T.ID) AS SITS_TAKEN
FROM runs AS R 
	INNER JOIN busses AS B ON B.ID = R.bus_id 
	RIGHT JOIN tickets AS T ON T.run_id = R.ID 
	INNER JOIN passages AS P ON P.ID = R.passage_id 
WHERE P.city_from = @driverCity
GROUP BY R.ID, P.city_from
HAVING COUNT(T.ID) <= @busSits;

COMMIT TRANSACTION


BEGIN TRANSACTION
-- 17. После ремонта в автобусе добавили 3 места, добавить эти места и в БД.

DECLARE @busID INT = 0; -- Ikarus ID
UPDATE busses 
SET busses.sits = busses.sits+3
WHERE busses.ID = @busID;

ROLLBACK TRANSACTION
