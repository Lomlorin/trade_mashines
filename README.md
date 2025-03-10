### Разработка приложений для сети торговых терминалов

_Розничному магазину требуется программное обеспечение (ПО) для продажи и учета товаров. В магазине имеется N-количество торговых терминалов и склад с товарами._

Требуется разработать клиентское и серверное приложение для работы сети торговых терминалов с собственным протоколом взаимодействия.

#### Основные технические компоненты:
* База данных (БД) товаров
* Сервер обработки транзакций
* Торговый терминал (клиент)

#### Функциональные требования:
Сервер имеет карточки доступных товаров на складе (описание, цена, доступное количество). Клиенты подключаются к серверу и синхронизируют эти данные. Клиент имеет интерфейс для просмотра карточек и регистрации покупки (выполнение транзакции). При получении транзакции клиент отправляет ее на сервер, сервер изменяет количество доступных единиц этого товара и рассылает эту транзакцию всем клиентам, чтобы все терминалы поддерживали карточки в актуальном состоянии.

#### Требования к программным средствам:
* Язык программирования - Си 
* При необходимости могут быть использованы Bash-скрипты
* Минимальное использование сторонних библиотек (требуется использовать стандартный инструментарий выбранного языка для реализации своих функциональных модулей)

#### Общие требования:
* Сборка проекта при помощи make/Cmake
* Взаимодействие между клиентами и сервером через inet сокеты
* Наличие внутренней системы логирования
* Простота распространения и развертывания системы
* Презентабельный и интуитивно понятный для среднего потребителя интерфейс управления ПО
* Работа приложений на системах семейства Linux (предпочтение - Ubuntu)
* _(Доп.задание) Наличие системы авторизации клиентов для безопасного доступа к серверу_
* _(Доп.задание) Защита канала взаимодействия клиента и сервера_
* _(Доп.задание) Кроссплатформенная реализация приложений_

#### Требования к базе данных:
* Использование документной БД
* Выбор формата хранения данных остается за разработчиками
* Разрешено использование сторонней библиотеки для базовых методов работы с форматом

#### Требования к серверу:
* Работа в многопользовательском режиме (одновременное поддержание сессий с несколькими клиентами)
* Консольный интерфейс управления
* _(Доп.задание) Мониторинг подключений клиентов и оповещение администратора при потере связи с клиентом_

#### Требования к клиенту:
* Консольный интерфейс управления
* _(Доп.задание) Поддержка работы клиента в оффлайн режиме - запись транзакций, которые будут отправлены на сервер при следующем обычном подключении_

#### Для начала работы с проектом необходмо установить следующие компоненты и библиотеки:
###### Если необходимо установить все компоненты разом:

sudo apt update

sudo apt install build-essential libc6-dev make

###### Подробнее разберём отдельные аспекты:

* Компилятор и базовые инструменты разработки

sudo apt install build-essential

* Библиотека pthread и работа с сокетами

sudo apt install libc6-dev

* Make (управление сборкой проекта):

sudo apt install make

#### Далее команды для сборки и запуска проекта
###### Для сборки серверной части проекта:

make -f Makefile_server

###### Для запуска сервера проекта необходимо сделать следующие шаги:
* Запустить серверную машину с помощью следующей команды:

./server.x 

* ЗЧтобы узнать серверный ip-адрес можно с помощью  этой команды:

ifconfig

###### Для сборки клиентской части проекта:

make -f Makefile_client

###### Для запуска клиентской проекта необходимо сделать следующие шаги:
* В файле conf.ini указать локальный ip машины на которой запущен сервер
* Запустить клиента с помощью следующей команды:

./client.x 
