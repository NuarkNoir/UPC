SELECT
    -- Вывести количество сделок, зафиксированных в БД.
    (SELECT count(*) FROM [Сделка]) AS DEALS_COUNT,

    -- Определить среднее арифметическое значение количества товаров на складе.
    (SELECT AVG([Склад].Количество) FROM [Склад]) AS AVERAGE_GOODS_COUNT,

    -- Определить общее количество товаров на складе.
    (SELECT SUM([Склад].Количество) FROM [Склад]) AS ALL_GOODS_COUNT,

    -- Определить максимальное количество товаров на складе.
    (SELECT MAX([Склад].Количество) FROM [Склад]) AS MAX_GOODS_COUNT,

    -- Вывести значение косинуса для угла 60º.
    COS(RADIANS(60.0)) AS COS60,

    -- Получить целое случайное число в диапазоне [-7; 2].
    -- [-7; 3) -> [-7; 2]
    FLOOR(RAND() * (3 - (-7)) + -7) AS RAND_IN_m7_TO_p2,

    -- Определить (вывести в виде числа от 1 до 7) текущий день недели.
    DAY(GETDATE()) AS CURRENT_DAY;