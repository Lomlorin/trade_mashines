#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h> 
#include "QueueRcv.h"
#include "request_response.h"
#include "lib_json_db.h"
#include "Product_list.h"
#include "Product.h"

#define CONFIG_FILE "conf.ini"
#define PORT 8055
#define BUFFER_SIZE 350

// Очередь сообщений
extern QueueRcv* message_queue;

// лист товаров
extern Product_list *price_list;

// IP-адрес сервера
extern char* server_ip;

// Функция для потока, который получает команды от пользователя
void get_user_input();

// Функция для потока, который отправляет сообщения на сервер
void* send_to_server(void* arg);

// Функция для потока, который получает сообщения от сервера
void* receive_from_server(void* arg);

// Функция для запуска клиента
int start_client();

// отправка запроса на синхронизацию данных серверу 
void put_sync_request();

// отчистка ресурсов
void clean_up();

// Обработчик сигналов
void handle_signal(int signum);

// Функция для установки обработчиков сигналов
void setup_signal_handlers();

char* read_server_ip_from_config(const char* config_file);
#endif // CLIENT_H