#define _WINSOCK_DEPRECATED_NO_WARNINGS  // отключаем предупреждения о несовместимости кода с более новыми версиями Winsock
#pragma comment(lib, "ws2_32.lib")  // подключаем библиотеку ws2_32.lib

#include <winsock2.h>  // подключаем Winsock2
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");  // устанавливаем локаль для вывода русских символов

    // инициализация Winsock
    WSADATA wsaData;
    int initRes = WSAStartup(MAKEWORD(2, 2), &wsaData);  // запускаем Winsock с версией 2.2
    if (initRes != 0)  // проверяем успешность инициализации
    {
        cout << "Ошибка инициализации Winsock: " << initRes << endl;
        return 1;
    }

    // создание сокета
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // создаем сокет типа TCP пример: socket(int domain, int type, int protocol); AF_INET - семейство протоколов IPv4, SOCK_STREAM - потоковый сокет, IPPROTO_TCP - протокол TCP
    if (listenSocket == INVALID_SOCKET)  // проверяем успешность создания сокета
    {
        cout << "Ошибка создания сокета: " << WSAGetLastError() << endl;  // получаем код ошибки
        WSACleanup();  // очищаем Winsock
        return 1;
    }

    sockaddr_in service;
    service.sin_family = AF_INET;  // устанавливаем семейство протоколов
    service.sin_addr.s_addr = inet_addr("127.0.0.1");  // устанавливаем адрес localhost
    service.sin_port = htons(8080);  // устанавливаем порт. Функция htons() (host to network short) преобразует 16-битное целое число из порядка байтов хост-порядка в порядок байтов сети.
    /*
    htons(8080) преобразует порт 8080 в порядок байтов сети и возвращает значение в виде 16-битного целого числа, готового для использования в сокетах.
    */
    if (bind(listenSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)  // проверка связался ли сокет с адресом
    {
        cout << "Ошибка связывания сокета: " << WSAGetLastError() << endl;  // получаем код ошибки
        closesocket(listenSocket);  // закрываем сокет
        WSACleanup();  // очищаем Winsock
        return 1;
    }

    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)  // начинаем прослушивание сокета
    {
        cout << "Ошибка начала прослушивания сокета: " << WSAGetLastError() << endl;  // получаем код ошибки
        closesocket(listenSocket);  // закрываем сокет
        WSACleanup();  // очищаем Winsock
        return 1;
    }

    // обработка входящих соединений
    cout << "Сервер запущен. Ожидание подключений..." << endl;

    while (true) // Бесконечный цикл для ожидания входящих подключений
    {
        
        SOCKET clientSocket = accept(listenSocket, NULL, NULL); // Приём входящего соединения
        
        if (clientSocket == INVALID_SOCKET) // Обработка ошибок приёма входящего соединения
        {
            cout << "Ошибка приема входящего соединения: " << WSAGetLastError() << endl;
            closesocket(listenSocket);
            WSACleanup();
            return 1;
        }

        // обработка запроса от клиента
        char buffer[1024];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytesReceived == SOCKET_ERROR) // Обработка ошибок приёма данных от клиента
        {
            cout << "Ошибка приема данных от клиента: " << WSAGetLastError() << endl;
            closesocket(clientSocket);
            continue;
        }

        buffer[bytesReceived] = '\0'; // вывод данных запроса на консоль
        cout << "Получен запрос от клиента:" << endl;
        cout << buffer << endl;

        // формирование ответа
        //const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1><font color=\"red\">Simple web-server on winsocks2</font></h1><p>It's kinda works</p></body></html>";
        
        const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
            "<html>"
            "<head>"
            "<title>Заголовок страницы</title>"
            "</head>"
            "<body>"
            "<h1>Заголовок первого уровня</h1>"
            "<h2 style=\"color:red;\">Заголовок второго уровня красного цвета</h2>"
            "<p>Обычный текст</p>"
            "<button onclick=\"alert('Кнопка нажата!');\">Нажми на меня</button>"
            "</body>"
            "</html>";

        // const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
        
        int responseLength = strlen(response); // Получение длины ответа
        int bytesSent = send(clientSocket, response, responseLength, 0); // отправка ответа клиенту
        if (bytesSent == SOCKET_ERROR) // Обработка ошибок отправки ответа клиенту
        {
            cout << "Ошибка отправки данных клиенту: " << WSAGetLastError() << endl;
            closesocket(clientSocket);
            continue;
        }
        closesocket(clientSocket); // закрытие сокета клиента
    }
    closesocket(listenSocket); // закрытие сокета сервера
    WSACleanup(); // выход из Winsock
    return 0;
}

/*
Данный код является примером простого веб-сервера на основе Winsock2 для Windows. 
Он позволяет установить соединение с локальным хостом (127.0.0.1) по определенному порту (8080), 
принимать запросы от клиентов и отправлять им ответ в виде HTML-страницы.

Для начала, используется директива #define для отключения предупреждений
о несовместимости кода с более новыми версиями Winsock. 
Затем с помощью директивы #pragma comment указывается компилятору подключить библиотеку ws2_32.lib.

Далее происходит инициализация Winsock с помощью функции WSAStartup,
которая запускает Winsock с заданной версией (2.2) и заполняет структуру WSADATA,
содержащую информацию о версии и реализации Winsock. Если инициализация прошла успешно,
то программа продолжит работу, иначе будет выведено сообщение об ошибке и программа завершится с кодом 1.

Затем создается сокет типа TCP с помощью функции socket. 
Если сокет создан успешно, то будет выполнен блок кода, 
который устанавливает адрес и порт для сокета, используя структуру sockaddr_in.
Если связывание адреса и порта с сокетом прошло успешно, то сокет начинает прослушивать входящие соединения
с помощью функции listen. Если же какой-либо из вышеописанных этапов завершился ошибкой,
то программа завершится с соответствующим сообщением об ошибке.

Далее программа переходит в бесконечный цикл, в котором ожидается 
входящее соединение от клиента с помощью функции accept. Если соединение установлено успешно,
то программа принимает данные от клиента с помощью функции recv и выводит их на экран. 
Затем программа формирует ответ в виде HTML-страницы и отправляет его клиенту с помощью функции send. 
Если произошла ошибка при приеме входящего соединения или приеме данных от клиента, то программа 
закрывает соответствующие сокеты и продолжает ожидание новых подключений. 
Если же произошла ошибка при отправке данных клиенту, то программа завершится с соответствующим сообщением об ошибке.
*/