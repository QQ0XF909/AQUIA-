#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace Core {

    enum class LogLevel : uint8_t {
        Trace = 0,
        Debug,
        Info,
        Warn,
        Error,
        Fatal,
        Off
    };
    
    enum class LogType : uint8_t {
        Access_Logs = 0, /* для фиксация запросов к приложению*/
        Error_Logs, /* для багов, сбоев, исключений и критических ошибок*/
        Audit_Logs, /* для пользовательских логов, удаление файлов , создание профилей и т.д */
        Transaction_Logs /* для цепочек действий, для отслеживания  сложных багов */
    };

    struct LoggerConfig {
        struct DateTime {
            std::chrono::hours log_hours;
            std::chrono::day log_day; 
            std::chrono::moth log_moth;
            std::chrono::year log_year;    
        };
    }

}