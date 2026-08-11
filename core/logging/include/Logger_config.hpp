#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <optional>

namespace Core {

    enum class LogLevel : uint8_t {
        Trace,
        Debug,
        Info,
        Warn,
        Error,
        Fatal,
        Off
    };
    
    enum class LogType : uint8_t {
        Access_Logs, /* для фиксация запросов к приложению*/
        Error_Logs, /* для багов, сбоев, исключений и критических ошибок*/
        Audit_Logs, /* для пользовательских логов, удаление файлов , создание профилей и т.д */
        Transaction_Logs /* для цепочек действий, для отслеживания  сложных багов */
    };

    struct SinkConfig {
        enum class Type {
            Console,
            FileDaily,
            FileRotating,
            Syslog
        };
        
    };
    

    struct LoggerConfig {

        bool async = {true};
        std::string formatting_date_time = "[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%t] %v";
        std::string log_dir = {"logs"};
        

       
       /* struct DateTime {
            std::chrono::hours log_hours;
            std::chrono::day log_day; 
            std::chrono::moth log_moth;
            std::chrono::year log_year;    
        };*/
    }

};